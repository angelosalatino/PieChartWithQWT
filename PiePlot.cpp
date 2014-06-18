#include <qapplication.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qpainter.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_curve.h>
#include <qwt_scale_draw.h>
#include <qwt_scale_widget.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_canvas.h>
#include "PieMarker.h"
#include "PiePlot.h"

/*!
 * \brief The PiePlotCurve class that creates a curve.
 */
class PiePlotCurve: public QwtPlotCurve
{
public:
    PiePlotCurve(const QString &title):
        QwtPlotCurve(title)
    {
        setRenderHint(QwtPlotItem::RenderAntialiased);
    }

    void setColor(const QColor &color)
    {
        QColor c = color;
        c.setAlpha(150);

        setPen(c);
        setBrush(c);
    }
};

/*!
 * \brief PiePlot::PiePlot Constructor of PiePlot Class, it initializes all the curves ready to be plotted
 * \param parent is the widget that will contain the plot (Pie Chart)
 */
PiePlot::PiePlot(QStringList pieNames, QVector<QColor> pieColors, int sizeOfPie, QWidget *parent):
    QwtPlot(parent),
    dataCount(0)
{
    //setAutoReplot(false);

    canvas()->setBorderRadius( 10 );

    plotLayout()->setAlignCanvasToScales(true);

    QwtLegend *legend = new QwtLegend;
    legend->setItemMode(QwtLegend::ReadOnlyItem);
    insertLegend(legend, QwtPlot::RightLegend);


    numPlots = pieNames.size();

    /*
     In situations, when there is a label at the most right position of the
     scale, additional space is needed to display the overlapping part
     of the label would be taken by reducing the width of scale and canvas.
     To avoid this "jumping canvas" effect, we add a permanent margin.
     We don't need to do the same for the left border, because there
     is enough space for the overlapping label below the left scale.
     */

    enableAxis(QwtPlot::yLeft,false);
    enableAxis(QwtPlot::xBottom,false);

    PieMarker *pie = new PieMarker(numPlots, sizeOfPie);
    pie->attach(this);

    /*
     * Every following curve represents a single part in pie chart.
     * For this reason every part in pie chart needs a specific curve
     */

    data = new struct pieCurves[numPlots];
    
    PiePlotCurve *curve;
    // iterative allocation
    for (int i  = 0; i < numPlots; i++)
    {
        curve = new PiePlotCurve(pieNames.at(i));
        curve->setColor(pieColors.at(i));
        curve->attach(this);
        data[i].curve = curve;

        showCurve(data[i].curve, false);
    }


}

PiePlot::~PiePlot()
{
    if(numPlots > 0)
    {
        for (int i = 0; i < numPlots; i++)
        {
            delete data[i].curve;
        }

        delete data;
    }
}

/*!
 * \brief PiePlot::plotStaticValues this function updates the value of Pie Chart and then replot them.
 * \param inputData is a vector with same size of NumPlots
 */
void PiePlot::plotStaticValues(QVector<double> *inputData)
{
    if(inputData->size() == numPlots)
        for (int i = 0; i < inputData->size(); i++)
            data[i].data[0] = inputData->at(i);


    if ( dataCount < HISTORY )
        dataCount++;

    for ( int j = 0; j < HISTORY; j++ )
        timeData[j]++;

    for ( int c = 0; c < numPlots; c++ )
    {
        data[c].curve->setRawSamples(
                    timeData, data[c].data, dataCount);
    }
    replot();
}

/*!
 * \brief PiePlot::showCurve this method makes possible to hide curves that will appear behind the Pie Chart
 * \param item the object to set visible
 * \param on true for visible, false for hided
 */
void PiePlot::showCurve(QwtPlotItem *item, bool on)
{
    item->setVisible(on);
    QWidget *w = legend()->find(item);
    if ( w && w->inherits("QwtLegendItem") )
        ((QwtLegendItem *)w)->setChecked(on);
    
    replot();
}



