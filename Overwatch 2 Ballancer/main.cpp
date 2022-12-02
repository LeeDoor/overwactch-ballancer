#include "Overwatch2Ballancer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Overwatch2Ballancer w;
    w.show();
    return a.exec();
}
