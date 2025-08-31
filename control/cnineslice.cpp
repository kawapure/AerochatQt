#include "cnineslice.h"

#include <QtGui/qpainter.h>
#include <QtGui/QPaintEvent>
#include <qdrawutil.h>

CNineSlice::CNineSlice(QWidget *pParent)
    : QWidget{pParent}
{
}

CNineSlice::CNineSlice(const QString &rFileName, QWidget *pParent)
    : QWidget{pParent}
{
    _pixmap = new QPixmap(rFileName);
}

CNineSlice::~CNineSlice()
{
    delete _pixmap;
}

void CNineSlice::paintEvent(QPaintEvent *pEvent)
{
    // TODO: Very inefficient for now (no caching or anything)
    // Doesn't really matter so much since this nine-slice control is now used
    // only for miscellaneous backgrounds, because button controls handle it
    // all natively.
    QPainter painter(this);
    qDrawBorderPixmap(&painter, pEvent->rect(), QMargins(0, 0, 0, 0), *_pixmap);
}
