#include "view/pokerclientgui.h"
#include <QApplication>
#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller* controller = new Controller();

    PokerClientGui w(controller);
    controller->attachView(&w);

    w.show();

    return a.exec();
}
