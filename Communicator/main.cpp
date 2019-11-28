#include "Widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  

    //Window
    Widget window;
    window.show();

    return a.exec();
}
