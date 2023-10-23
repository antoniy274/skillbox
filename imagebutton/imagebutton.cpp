#include "imagebutton.h"

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Click");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("..\\imagebutton\\redbutton_up.png");
    mButtonDownPixmap = QPixmap("..\\imagebutton\\redbutton_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(QFileInfo("..\\imagebutton\\zvuk-klaviatura.mp3").absoluteFilePath()));
    audioOutput->setVolume(100);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(200, 200);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);

    player->stop();
    player->play();
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    //player->play();
    update();
}
