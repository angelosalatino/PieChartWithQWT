#include <QApplication>
#include "PiePlot.h"
#include "QVBoxLayout"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QWidget vBox;

    PiePlot *plot = new PiePlot(&vBox);


    const int margin = 5;
    plot->setContentsMargins(margin, margin, margin, margin);

    QVBoxLayout *layout = new QVBoxLayout(&vBox);
    layout->addWidget(plot);

    //SET VALUES
    QVector<double> al;
    al<<15<<30<<35<<20;
    plot->plotStaticValues(&al);

    vBox.resize(450,360);
    vBox.show();

    return a.exec();
}
