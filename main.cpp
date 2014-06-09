#include <QApplication>
#include "PiePlot.h"
#include "QVBoxLayout"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    //////////////////////////////////////////////////SETTING SOME PARAMETERS
    QStringList pieNames;
    pieNames<<"Plot 1"<<"Plot 2"<<"Plot 3"<<"Plot 4"<<"Plot 5";
    QVector<QColor> pieColors;
    pieColors<<QColor(255,0,0)<<QColor(0,255,0)<<QColor(0,0,255)<<QColor(0,128,0)<<QColor(128,128,128);
    /////////////////////////////////////////////////////////////////

    if(pieColors.size() == pieNames.size())
    {
        QWidget vBox;
        PiePlot *plot = new PiePlot(pieNames, pieColors, &vBox);

        const int margin = 5;
        plot->setContentsMargins(margin, margin, margin, margin);

        QVBoxLayout *layout = new QVBoxLayout(&vBox);
        layout->addWidget(plot);

        /////////////////////////////////////////SETTING VALUES
        QVector<double> pieValues;
        pieValues<<15<<25<<35<<20<<5;
        ///////////////////////////////////////////////////////

        if(pieValues.size() == pieNames.size())
        {
            plot->plotStaticValues(&pieValues);


            vBox.resize(450,360);
            vBox.show();

            return a.exec();
        }
        else
        {
            qDebug()<<"Error 2";
            return 0;
        }
    }
    else{
        qDebug()<<"Error 1";
        return 0;
    }

}
