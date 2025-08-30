#include "mainwindow.h"
#include "./ui_mainwindow.h"

CMainWindow::CMainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , _pUi(new Ui::MainWindow)
{
    _pUi->setupUi(this);
}

CMainWindow::~CMainWindow()
{
    delete _pUi;
}
