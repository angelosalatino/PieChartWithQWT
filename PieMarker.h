//-----------------------------------------------------------------
// This class shows how to extend QwtPlotItems. It displays a
// pie chart of user/total/idle cpu usage in percent.
//-----------------------------------------------------------------

#include <qwt_plot_item.h>

class PieMarker: public QwtPlotItem
{
public:
    PieMarker();

    virtual int rtti() const;

    virtual void draw(QPainter *p,
        const QwtScaleMap &, const QwtScaleMap &,
        const QRectF &rect) const;
};
