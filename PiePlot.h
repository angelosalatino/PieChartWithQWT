#include <qwt_plot.h>

#define HISTORY 1 // number of items

class QwtPlotCurve;


/*!
 * \brief The PiePlot class makes possible the pie chart creation
 * Inside this class are defined the exact number of curves that should be shown in the
 * pie chart.
 */
class PiePlot : public QwtPlot
{
    Q_OBJECT
public:


    PiePlot(QStringList pieNames, QVector<QColor> pieColors, QWidget * = 0);
    ~PiePlot();

    const QwtPlotCurve *pieCurve(int id) const
        { return data[id].curve; }

    void plotStaticValues(QVector<double> *inputData);

private Q_SLOTS:
    void showCurve(QwtPlotItem *, bool on);

private:
    struct pieCurves
    {
        QwtPlotCurve *curve;
        double data[HISTORY];
    } * data;

    double timeData[HISTORY];

    int dataCount;

    int numPlots;

};
