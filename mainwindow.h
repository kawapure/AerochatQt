#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *pParent = nullptr);
    ~CMainWindow();

private:
    Ui::MainWindow *_pUi;
};
#endif // MAINWINDOW_H
