#include "calculator.h"

Calculator::Calculator (QWidget *parent) : QWidget(parent) {
 displaystring = new QLabel("");
 displaystring->setMinimumSize (150, 50);
 QChar aButtons[4][4] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'0', '.', '=', '+'}
 };

 QGridLayout *myLayout = new QGridLayout;
 myLayout->addWidget(displaystring, 0, 0, 1, 4);
 myLayout->addWidget(createButton("CE"), 1, 3);
 for (int i = 0; i < 4; ++i) {
  for (int j = 0; j < 4; ++j) {
   myLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
  }
 }
 setLayout(myLayout);
}

QPushButton* Calculator::createButton (const QString& str) {
 QPushButton* pcmd = new QPushButton(str);
 pcmd->setMinimumSize(40, 40);
 connect(pcmd, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
 return pcmd;
}

void Calculator::calculate() {
 double dOperand2 = stack.pop().toDouble();
 QString strOperation = stack.pop();
 double dOperand1 = stack.pop().toDouble();
 double dResult = 0;
 if (strOperation == "+") { dResult = dOperand1 + dOperand2; }
 else if (strOperation == "-") { dResult = dOperand1 - dOperand2; }
 else if (strOperation == "/") { dResult = dOperand1 / dOperand2; }
 else if (strOperation == "*") { dResult = dOperand1 * dOperand2; }
 displaystring->setText(QString("%1").arg(dResult, 0, 'f', 3));
}

void Calculator::slotButtonClicked() {
 QString str = ((QPushButton*)sender())->text(); //Получаем текст с нажатой кнопки
 if (str == "CE") { //Кнопка Очистить
  stack.clear(); displaystring->setText(""); return;
 }

 QString text = displaystring->text(); //отображаемый текст
 int len = text.length();
 QString last = "";
 if (len>0) last = text.right(1); //самый правый символ ввода

 if (((len==0 && stack.count()==0) ||
      ((stack.count()==2 && len>1 && (last=="+"||last=="-"||last=="*"||last=="/")))) &&
     (str.contains(QRegularExpression("[0-9]")) || str=="-")) {
  //На экране пусто и стек пуст или введен 1-й операнд и операция
  //и при этом нажата цифра или "-"
  text=str; //Стереть то, что было отображено, и отобразить нажатый символ
 }
 else if ((text+str).contains(QRegularExpression("^-?[0-9]+\\.?[0-9]*$"))) {
  text+=str; //Пока вводим число - добавлять символ
 }
 else if (text.contains(QRegularExpression("^-?[0-9]+\\.?[0-9]*$"))) { //Уже набрано число
  if (str=="*"||str=="/"||str=="+"||str=="-"||str=="=") { //Вычислить
   if (stack.count()==2) { //Есть 1-й операнд и число
    stack.push(text); //Положить в стек 2-й операнд
    calculate(); //Вычислить
    text=displaystring->text(); //Показать результат
   }
   if (str!="=") { //Для вычисления "по цепочке"
    stack.push(text); //Положить в стек 1-й операнд
    text+=str; //Отобразить операцию до след.нажатия кнопки
    stack.push(str); //Положить в стек операцию
   }
  }
 }
 displaystring->setText(text);
}
