#ifndef COLORFULCIRCLE_H
#define COLORFULCIRCLE_H
#include <QApplication>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include<QPaintEvent>

#include<iostream>

class ColorfulCircle: public QWidget
{
           Q_OBJECT
public:
    ColorfulCircle() = default;
    ColorfulCircle (QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;
public slots:
    void setYellow();
    void setGreen();
    void setRed();
private:
    QPixmap mCurrentCirclePixmap;
    QPixmap mGreenCirclePixmap;
    QPixmap mYellowCirclePixmap;
    QPixmap mRedCirclePixmap;
};
#endif // COLORFULCIRCLE_H
