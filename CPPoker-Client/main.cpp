#include "view/pokerclientgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokerClientGui w;
    w.show();

    return a.exec();
}
