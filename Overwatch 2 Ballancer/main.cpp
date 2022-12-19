#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include "JSONParser.h"
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
