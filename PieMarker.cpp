#include <qpainter.h>
#include <qwt_scale_map.h>
#include <qwt_plot_curve.h>
#include "PiePlot.h"
#include "PieMarker.h"


/*!
 * \brief PieMarker::PieMarker constructor of PieMarker class
 */
PieMarker::PieMarker(int numPlots, int size)
{
    setZ(1000);
    setRenderHint(QwtPlotItem::RenderAntialiased, true);

    /* Defining some parameters*/
    this->height = size;
    this->width = size;
    this->margin = 10;
    this->numPlots = numPlots;
}


/*!
 * \brief PieMarker::rtti
 * \return
 */
int PieMarker::rtti() const
{
    return QwtPlotItem::Rtti_PlotUserItem;
}


/*!
 * \brief PieMarker::draw
 * \param p
 * \param rect
 */
void PieMarker::draw(QPainter *p,
                     const QwtScaleMap &, const QwtScaleMap &,
                     const QRectF &rect) const
{
    const PiePlot *piePlot = (PiePlot *)plot();

    const QwtScaleMap yMap = piePlot->canvasMap(QwtPlot::yLeft);

    
    QRect pieRect;
    pieRect.setX(rect.x() + margin);
    pieRect.setY(rect.y() + margin);
    pieRect.setHeight( height );
    pieRect.setWidth( width );
    //    pieRect.setHeight( qRound(yMap.transform(80.0)) );
    //    pieRect.setWidth( pieRect.height() );


    //////////////////////////////////////////
    /*
      With the following line is possible to set how many and which component should be whown in the pie chart
     */
    int dataType[numPlots];
    for (int i = 0; i < numPlots; i++ )
        dataType[i] = i;

    //////////////////////////////////////////

    int angle = (int)(5760 * 0.75);
    for ( unsigned int i = 0;
          i < sizeof(dataType) / sizeof(dataType[0]); i++ )
    {
        const QwtPlotCurve *curve = piePlot->pieCurve(dataType[i]);
        if ( curve->dataSize() > 0 )
        {
            const int value = (int)(5760 * curve->sample(0).y() / 100.0);

            p->save();
            p->setBrush(QBrush(curve->pen().color(), Qt::SolidPattern));
            if ( value != 0 )
                p->drawPie(pieRect, -angle, -value);
            p->restore();

            angle += value;
        }
    }
}

