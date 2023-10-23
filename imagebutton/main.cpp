#include "imagebutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageButton redButton(nullptr);
    redButton.setFixedSize(200, 200);
    redButton.move(800, 400);
    redButton.show();
    return a.exec();
}
