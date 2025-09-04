#ifndef CCOLORIZEDNINESLICE_H
#define CCOLORIZEDNINESLICE_H

#include "../common.h"

#include <QWidget>

#include <QPixmap>
#include <QPixmapCache>

class CColorizedNineSlice : public QWidget
{
    Q_OBJECT

    // TODO: Does this have any reason to be allocated separately?
    QPixmap _pixmap;

    void LoadBackground(const QString &rFileName);
    void ApplyTint(QPixmap *pPixmap, QColor tintColor, double dDarken);

    inline BYTE ApplyDarken(BYTE colorChannel, double dDarken)
    {
        return (BYTE)((double)colorChannel * (1 - dDarken));
    }

    inline BYTE OverlayBlend(BYTE baseChannel, BYTE tintChannel)
    {
        double dBaseNormalized = baseChannel / 255.0;
        double dTintNormalized = tintChannel / 255.0;

        // Overlay blend formula
        double result;
        if (dBaseNormalized < 0.5)
        {
            result = 2 * dBaseNormalized * dTintNormalized;
        }
        else
        {
            result = 1 - 2 * (1 - dBaseNormalized) * (1 - dTintNormalized);
        }

        return (BYTE)(result * 255);
    }

    QString _backgroundFileName;
    QColor _tintColor;
    double _dDarken = 0;

    Q_PROPERTY(QString backgroundFileName
               MEMBER _backgroundFileName
               WRITE SetBackgroundFileName
               REQUIRED)
    Q_PROPERTY(QColor tintColor
               MEMBER _tintColor
               WRITE SetTintColor)
    Q_PROPERTY(double darken
               MEMBER _dDarken
               WRITE SetDarken)

public:
    explicit CColorizedNineSlice(QWidget *pParent = nullptr);
    explicit CColorizedNineSlice(const QString &rFileName, QWidget *pParent = nullptr);
    ~CColorizedNineSlice();

    void paintEvent(QPaintEvent *pEvent) override;

    void SetBackgroundFileName(QString backgroundFileName);
    void SetTintColor(QColor tintColor);
    void SetDarken(double darken);

signals:
};

#endif // CCOLORIZEDNINESLICE_H
