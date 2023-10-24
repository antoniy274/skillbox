#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textEdit = ui->plainTextEdit;
    htmlView = ui->webEngineView;

    QObject::connect(textEdit
        , &QPlainTextEdit::textChanged
        , htmlView
        , [&](){ htmlView->setHtml(textEdit->toPlainText()); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
