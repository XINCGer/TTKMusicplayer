#include "musiclrcmanagerfordesktop.h"
#include "musicnumberdefine.h"

MusicLrcManagerForDesktop::MusicLrcManagerForDesktop(QWidget *parent)
    : MusicLrcManager(parent)
{
    m_font.setPointSize(30);
    m_speedLevel = 50;
}

QString MusicLrcManagerForDesktop::getClassName()
{
    return staticMetaObject.className();
}



MusicLrcManagerHorizontalDesktop::MusicLrcManagerHorizontalDesktop(QWidget *parent)
    : MusicLrcManagerForDesktop(parent)
{

}

QString MusicLrcManagerHorizontalDesktop::getClassName()
{
    return staticMetaObject.className();
}

void MusicLrcManagerHorizontalDesktop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(m_font);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    int begin = (rect().height() - QFontMetrics(m_font).height())/2;
    m_linearGradient.setFinalStop(0, QFontMetrics(m_font).height());
    m_maskLinearGradient.setFinalStop(0, QFontMetrics(m_font).height());

    if(m_geometry.x() + m_intervalCount >= m_lrcPerWidth &&
       m_lrcMaskWidth >= m_lrcPerWidth / 2)
    {
        m_intervalCount -= m_lrcMaskWidthInterval;
    }

    //Draw the underlying text, such as shadow, will make the effect more clearly,
    //and more texture
    painter.setPen(QColor(0, 0, 0, 2*m_transparent));
    painter.drawText(m_intervalCount + 1, begin + 1, m_geometry.x(), m_geometry.y(), Qt::AlignLeft, text());

    //Then draw a gradient in the above
    painter.setPen(QPen(m_linearGradient, 0));
    painter.drawText(m_intervalCount, begin, m_geometry.x(), m_geometry.y(), Qt::AlignLeft, text());

    //Set lyrics mask
    painter.setPen(QPen(m_maskLinearGradient, 0));
    painter.drawText(m_intervalCount, begin, m_lrcMaskWidth, 60, Qt::AlignLeft, text());
    painter.end();
}


MusicLrcManagerVerticalDesktop::MusicLrcManagerVerticalDesktop(QWidget *parent)
    : MusicLrcManagerForDesktop(parent)
{

}

QString MusicLrcManagerVerticalDesktop::getClassName()
{
    return staticMetaObject.className();
}

void MusicLrcManagerVerticalDesktop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(m_font);

    m_linearGradient.setFinalStop(0, QFontMetrics(m_font).height());
    m_maskLinearGradient.setFinalStop(0, QFontMetrics(m_font).height());

    if(m_geometry.x() + m_intervalCount >= m_lrcPerWidth &&
       m_lrcMaskWidth >= m_lrcPerWidth / 2)
    {
        m_intervalCount -= m_lrcMaskWidthInterval;
    }

    painter.translate(m_geometry.y(), 0);
    painter.rotate(MA_90);
    //Draw the underlying text, such as shadow, will make the effect more clearly,
    //and more texture
    painter.setPen(QColor(0, 0, 0, 2*m_transparent));
    painter.drawText(m_intervalCount + 1, 1, m_geometry.x(), m_geometry.y(), Qt::AlignLeft, text());

    //Then draw a gradient in the above
    painter.setPen(QPen(m_linearGradient, 0));
    painter.drawText(m_intervalCount, 0, m_geometry.x(), m_geometry.y(), Qt::AlignLeft, text());

    //Set lyrics mask
    painter.setPen(QPen(m_maskLinearGradient, 0));
    painter.drawText(m_intervalCount, 0, m_lrcMaskWidth, 60, Qt::AlignLeft, text());
    painter.translate(-m_geometry.y(), 0);
    painter.end();
}
