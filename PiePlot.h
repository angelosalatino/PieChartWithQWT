#include <qwt_plot.h>

#define HISTORY 1 // number of items

class QwtPlotCurve;

class PiePlot : public QwtPlot
{
    Q_OBJECT
public:
    enum Data
    {

        Plot1,
        Plot2,
        Plot3,
        Plot4,


        NumPlots
    };

    PiePlot(QWidget * = 0);
    const QwtPlotCurve *pieCurve(int id) const
        { return data[id].curve; }

    void plotStaticValues(QVector<double> *inputData);

protected:
    void timerEvent(QTimerEvent *e);

private Q_SLOTS:
    void showCurve(QwtPlotItem *, bool on);

private:
    struct
    {
        QwtPlotCurve *curve;
        double data[HISTORY];
    } data[NumPlots];
    double timeData[HISTORY];

    int dataCount;

};
