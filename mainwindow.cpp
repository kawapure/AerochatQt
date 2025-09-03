#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QResizeEvent>

CMainWindow::CMainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , _pUi(new Ui::MainWindow)
{
    _pUi->setupUi(this);

    _pUi->SceneBackground->raise();
    _pUi->SceneView->raise();
    _pUi->SceneOverlay->raise();
    _pUi->SignInLabel->raise();
}

CMainWindow::~CMainWindow()
{
    delete _pUi;
}

void CMainWindow::resizeEvent(QResizeEvent *pEvent)
{
    _pUi->Background->resize(pEvent->size());
}
