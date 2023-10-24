#include "mainwindow.h"
#include "./ui_mainwindow.h"

#ifdef WIN32
#define HOMEDIR "USERPROFILE"
#else
#define HOMEDIR "HOME"
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider
        , &QSlider::valueChanged
        , ui->imageField
        , [&]()
        {
            ui->imageField->setPixmap(QPixmap::fromImage(blurImage(originalImage
                , ui->horizontalSlider->value()).scaled(ui->imageField->width()
                    , ui->imageField->height()
                    , Qt::KeepAspectRatio
                ))
            );
        }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr
        , "Open JPG image"
        , QString(std::getenv(HOMEDIR))
        , "JPG images (*.jpg *.jpeg)"
    );

    originalImage = QImage(filePath);
    ui->imageField->setPixmap(QPixmap::fromImage(originalImage).scaled(ui->imageField->width()
        , ui->imageField->height()
        , Qt::KeepAspectRatio)
    );

    if (!ui->imageField->pixmap()->isNull())
        ui->horizontalSlider->setEnabled(true);
}

QImage MainWindow::blurImage(QImage source, int blurRadius)
{
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    //
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(),QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter
        , QRectF()
        , QRectF(0, 0, source.width(), source.height())
    );
    return result;
}
