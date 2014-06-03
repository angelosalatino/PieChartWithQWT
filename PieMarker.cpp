#include <qpainter.h>
#include <qwt_scale_map.h>
#include <qwt_plot_curve.h>
#include "PiePlot.h"
#include "PieMarker.h"

/*!
 * \brief PieMarker::PieMarker constructor of PieMarker class
 */
PieMarker::PieMarker()
{
    setZ(1000);
    setRenderHint(QwtPlotItem::RenderAntialiased, true);
}


int PieMarker::rtti() const
{
    return QwtPlotItem::Rtti_PlotUserItem;
}

void PieMarker::draw(QPainter *p,
    const QwtScaleMap &, const QwtScaleMap &,
    const QRectF &rect) const
{
    const PiePlot *piePlot = (PiePlot *)plot();

    const QwtScaleMap yMap = piePlot->canvasMap(QwtPlot::yLeft);

    const int margin = 10;
    
    QRect pieRect;
    pieRect.setX(rect.x() + margin);
    pieRect.setY(rect.y() + margin);
        pieRect.setHeight( 300);
        pieRect.setWidth( 300 );
//    pieRect.setHeight( qRound(yMap.transform(80.0)) );
//    pieRect.setWidth( pieRect.height() );
    
    const int dataType[] = { PiePlot::Plot1,PiePlot::Plot2,PiePlot::Plot3,PiePlot::Plot4};

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

