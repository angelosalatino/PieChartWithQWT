//-----------------------------------------------------------------
// This class shows how to extend QwtPlotItems. It displays a
// pie chart of user/total/idle cpu usage in percent.
//-----------------------------------------------------------------

#include <qwt_plot_item.h>


/*!
 * \brief The PieMarker class creates the pie chart
 */
class PieMarker: public QwtPlotItem
{
private:
    int height;
    int width;
    int margin;
    int numPlots;

public:
    PieMarker(int numPlots);

    virtual int rtti() const;

    virtual void draw(QPainter *p,
        const QwtScaleMap &, const QwtScaleMap &,
        const QRectF &rect) const;
};
