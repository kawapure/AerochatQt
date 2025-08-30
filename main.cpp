#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/qmenubar.h>

#ifdef Q_OS_MACOS
// macos_shit.mm
extern "C" void SetMacWindowMenu(NSMenu *pMenu);
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CMainWindow mainWindow;

#ifdef Q_OS_MACOS
    QMenuBar *pMenuBar = new QMenuBar(nullptr);

    // Older versions of Qt don't automatically manage the macOS "window" menu, so
    // we need to set it up manually.
    QMenu *pWindowMenu = new QMenu(nullptr);
    pWindowMenu->setTitle("Window");
    SetMacWindowMenu(pWindowMenu->toNSMenu());

    pMenuBar->addMenu(pWindowMenu);

    mainWindow.setMenuBar(pMenuBar);
#endif

    mainWindow.show();
    return app.exec();
}
