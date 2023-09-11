#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include "colorfulcircle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *circle = new ColorfulCircle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int newValue) {
        if (newValue >= 0 && newValue <= 33) circle->setGreen();
        else if (newValue > 33 && newValue <= 66) circle->setYellow();
        else if (newValue > 66 && newValue <= 100) circle->setRed();
    });

    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    //window->setFixedSize(400, 350);
    window->show();
    return QApplication::exec();
}
