#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class remote_control : public QWidget
{
    Q_OBJECT
private:
    QLabel *displaystring;

    const int volmax = 100;
    const int volmin = 0;
    int vol = 0;
    int ch = 0;
public:
    explicit remote_control(QWidget *parent = nullptr);
    QPushButton* createButton (const QString& str);

public slots: //Общедоступные обработчики событий
   void slotButtonClicked ();

signals:

};

#endif // REMOTE_CONTROL_H
