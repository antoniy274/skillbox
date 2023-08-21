#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include<QPaintEvent>

class ColorfulCircle: public QWidget {
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

ColorfulCircle::ColorfulCircle(QWidget *parent){
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCirclePixmap = QPixmap("/green.png");
    mYellowCirclePixmap = QPixmap("/yellow.png");
    mRedCirclePixmap = QPixmap("/red.png");
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
}

void ColorfulCircle::setRed(){
    mCurrentCirclePixmap = mRedCirclePixmap;
    update();
}

void ColorfulCircle::setYellow(){
    mCurrentCirclePixmap = mYellowCirclePixmap;
    update();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ColorfulCircle cc (nullptr);
    cc.move(1000, 400);
    //cc.setFixedSize(200,250);
    cc.show();
    return app.exec();
}
