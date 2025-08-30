#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CMainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
