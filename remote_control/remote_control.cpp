#include "remote_control.h"

remote_control::remote_control(QWidget *parent)
    : QWidget{parent}
{
    displaystring = new QLabel("");
    displaystring->setMinimumSize (150, 50);
    QString aButtons[4][4] = {
     {"1", "2", "3", "+/vol"},
     {"4", "5", "6", "-/vol"},
     {"7", "8", "9", "+/ch"},
     {"", "0", "", "-/ch"}
    };

    QGridLayout *myLayout = new QGridLayout;
    myLayout->addWidget(displaystring, 0, 0, 1, 4);

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
       myLayout->addWidget(createButton(aButtons[i][j]), i + 13, j);
      }
     }
     setLayout(myLayout);
}

QPushButton* remote_control::createButton (const QString& str) {
QPushButton* pcmd = new QPushButton(str);
pcmd->setMinimumSize(40, 40);
connect(pcmd, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
return pcmd;
}

void remote_control::slotButtonClicked() {
    QString text;
    QString str = ((QPushButton*)sender())->text(); //Получаем текст с нажатой кнопки

    if(str == "0"){
        ch = 0;
        displaystring->setText("0");
    }
    if(str == "1"){
        ch = 1;
        displaystring->setText("1");
    }
    if(str == "2"){
        ch = 2;
        displaystring->setText("2");
    }
    if(str == "3"){
        ch = 3;
        displaystring->setText("3");
    }
    if(str == "4"){
        ch = 4;
        displaystring->setText("4");
    }
    if(str == "5"){
        ch = 5;
        displaystring->setText("5");
    }
    if(str == "6"){
        ch = 6;
        displaystring->setText("6");
    }
    if(str == "7"){
        ch = 7;
        displaystring->setText("7");
    }
    if(str == "8"){
        ch = 8;
        displaystring->setText("8");
    }
    if(str == "9"){
        ch = 9;
        displaystring->setText("9");
    }
    if(str == "+/vol"){
        vol+=10;
        if(vol > volmax){
            vol = 100;
            displaystring->setText("Max volume 100");
        }
        else
            displaystring->setNum(vol);
    }
    if(str == "-/vol"){
        vol-=10;
        if(vol < 0){
            vol = 0;
            displaystring->setText("Min volume 0");
        }
        else
            displaystring->setNum(vol);
    }
    if(str == "+/ch"){
        ch+=1;
        displaystring->setNum(ch);
    }
    if(str == "-/ch"){
        ch-=1;
        if(ch < 0){
            ch = 0;
            displaystring->setText("Min chanel 0");
        }
        else
            displaystring->setNum(ch);
    }
}
