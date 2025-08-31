#ifndef CNINESLICE_H
#define CNINESLICE_H

#include <QWidget>

#include <QPixmap>
#include <QPixmapCache>

class CNineSlice : public QWidget
{
    Q_OBJECT

    QPixmap *_pixmap;
public:
    explicit CNineSlice(QWidget *pParent = nullptr);
    explicit CNineSlice(const QString &rFileName, QWidget *pParent = nullptr);
    ~CNineSlice();

    void paintEvent(QPaintEvent *pEvent) override;

signals:
};

#endif // CNINESLICE_H
