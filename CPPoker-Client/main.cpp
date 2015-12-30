#include "view/pokerclientgui.h"
#include <QApplication>
#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokerClientGui w;

    //Controller controller(&w);

    w.show();

    return a.exec();
}
