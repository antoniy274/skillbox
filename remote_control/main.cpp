#include "remote_control.h"
#include <QApplication>

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   remote_control rc;
   rc.setWindowTitle("TV remote control");
   rc.resize(300,250);
   rc.setFixedSize(240,680);
   rc.show();
   return app.exec();
}
