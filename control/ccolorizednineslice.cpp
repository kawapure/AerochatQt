#include "ccolorizednineslice.h"

#include <QtGui/qpainter.h>
#include <QtGui/QPaintEvent>
#include <QPixmap>
#include <qdrawutil.h>

CColorizedNineSlice::CColorizedNineSlice(QWidget *pParent)
    : QWidget{pParent}
{
}

CColorizedNineSlice::CColorizedNineSlice(const QString &rFileName, QWidget *pParent)
    : QWidget{pParent}
{
    LoadBackground(rFileName);
}

CColorizedNineSlice::~CColorizedNineSlice()
{
}

void CColorizedNineSlice::paintEvent(QPaintEvent *pEvent)
{
    // TODO: Very inefficient for now (no caching or anything)
    // Doesn't really matter so much since this nine-slice control is now used
    // only for miscellaneous backgrounds, because button controls handle it
    // all natively.
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    qDrawBorderPixmap(&painter, pEvent->rect(), QMargins(0, 0, 0, 0), _pixmap);
}

void CColorizedNineSlice::LoadBackground(const QString &rFileName)
{
    // If we already have a background loaded, then make sure that
    // we unload that first.
    _pixmap.load(rFileName);

    ApplyTint(&_pixmap, _tintColor, _dDarken);

    update();
}

void CColorizedNineSlice::ApplyTint(QPixmap *pPixmap, QColor tintColor, double dDarken)
{
    // Get the pixel data of the original image
    int iWidth = pPixmap->width();
    int iHeight = pPixmap->height();

    BYTE tintR = ApplyDarken(_tintColor.red(), dDarken);
    BYTE tintG = ApplyDarken(_tintColor.green(), dDarken);
    BYTE tintB = ApplyDarken(_tintColor.blue(), dDarken);

    QImage image = pPixmap->toImage();

    for (int y = 0; y < iHeight; y++)
    {
        for (int x = 0; x < iWidth; x++)
        {
            QColor color = QColor::fromRgba(image.pixel(x, y));

            color.setRed(OverlayBlend(color.red(), tintR));
            color.setGreen(OverlayBlend(color.green(), tintG));
            color.setBlue(OverlayBlend(color.blue(), tintB));

            //image.setPixel(x, y, color.rgba());
            image.setPixelColor(x, y, color);
        }
    }

    _pixmap = QPixmap::fromImage(image);
}

void CColorizedNineSlice::SetBackgroundFileName(QString backgroundFileName)
{
    _backgroundFileName = backgroundFileName;
    LoadBackground(_backgroundFileName);
}

void CColorizedNineSlice::SetTintColor(QColor tintColor)
{
    _tintColor = tintColor;
    LoadBackground(_backgroundFileName);
}

void CColorizedNineSlice::SetDarken(double darken)
{
    _dDarken = darken;
    LoadBackground(_backgroundFileName);
}
