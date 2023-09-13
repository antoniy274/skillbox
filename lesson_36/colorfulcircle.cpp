#include "colorfulcircle.h"

ColorfulCircle::ColorfulCircle(QWidget *parent){
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCirclePixmap = QPixmap("..\\lesson_36\\green.png");
    mYellowCirclePixmap = QPixmap("..\\lesson_36\\yellow.png");
    mRedCirclePixmap = QPixmap("..\\lesson_36\\red.png");
    mCurrentCirclePixmap = mGreenCirclePixmap;
    setGeometry(mCurrentCirclePixmap.rect());
}

void ColorfulCircle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCirclePixmap);
}

QSize ColorfulCircle::minimumSizeHint() const {
     return QSize(100, 100);
}

void ColorfulCircle::setGreen(){
    mCurrentCirclePixmap = mGreenCirclePixmap;
    update();
    std::cout<<"setGreen";
}

void ColorfulCircle::setRed(){
    mCurrentCirclePixmap = mRedCirclePixmap;
    update();
    std::cout<<"setRed";
}

void ColorfulCircle::setYellow(){
    mCurrentCirclePixmap = mYellowCirclePixmap;
    update();
    std::cout<<"setYellow";
}
