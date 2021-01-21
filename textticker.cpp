
#include "textticker.h"
#include <QPainter>
#include <QTimer>


TextTicker::TextTicker(QWidget *parent)
    : QLabel(parent)
{
    setMinimumWidth(200);
    setMinimumHeight(40);


    m_curIndex = INIT_COUNT;//当前角码
    m_showText = tr("Welcome to the image processing software of Star Dragon Company");//显示的文字
    m_charWidth = 9;//fontMetrics().width("A");//每个字符的宽度
    type = 0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this,SLOT(updateIndex()));
    timer->start(400);
}

TextTicker::~TextTicker()
{


}

void TextTicker::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(type == 1)
    {
        painter.drawText(this->rect(), Qt::AlignVCenter, m_showText.left(INIT_COUNT));
        if(m_showText.count()<MAX_COUNT+INIT_COUNT)
        {
            painter.drawText(INIT_COUNT*m_charWidth,0,this->width(),this->height(), Qt::AlignVCenter, m_showText.mid(m_curIndex));
        }
        else
        {
            if((m_showText.count()-m_curIndex)<MAX_COUNT+INIT_COUNT)
            {
                painter.drawText(INIT_COUNT*m_charWidth,0,this->width(),this->height(), Qt::AlignVCenter,m_showText.mid(m_curIndex+INIT_COUNT)+m_showText.mid(INIT_COUNT,MAX_COUNT-(m_showText.count()-INIT_COUNT-m_curIndex)));
            }
            else
            {
                painter.drawText(INIT_COUNT*m_charWidth,0,this->width(),this->height(), Qt::AlignVCenter,m_showText.mid(m_curIndex+INIT_COUNT,MAX_COUNT));
            }
        }
    }
    else
    {
        if(m_showText.count()<=MAX_COUNT+INIT_COUNT)
        {
            painter.drawText(this->rect(), Qt::AlignVCenter, m_showText);
        }
        else
        {
            if((m_showText.count()-m_curIndex)<MAX_COUNT+INIT_COUNT)
            {
                painter.drawText(this->rect(), Qt::AlignVCenter,m_showText.mid(m_curIndex)+m_showText.left(MAX_COUNT+INIT_COUNT-(m_showText.count()-m_curIndex)));
            }
            else
            {
                painter.drawText(this->rect(), Qt::AlignVCenter,m_showText.mid(m_curIndex,MAX_COUNT+INIT_COUNT));
            }
        }
    }
}

void TextTicker::updateIndex()
{
    update();
    if(type == 1)
    {
        if(m_showText.count()>MAX_COUNT)
        {
            m_curIndex++;
            if (m_curIndex > m_showText.count()-INIT_COUNT)
            {
                m_curIndex = 1;
            }
        }
    }
    else
    {
        if(m_showText.count()>MAX_COUNT+INIT_COUNT)
        {
            m_curIndex++;
            if (m_curIndex > m_showText.count())
            {
                m_curIndex = 1;
            }
        }
    }

}

void TextTicker::setText(const QString &str)
{
    m_showText = str;
    if(type == 1)
    {
        if(m_showText.count()>MAX_COUNT)
            m_showText += "  ";
    }
    else
    {
        if(m_showText.count()>MAX_COUNT+INIT_COUNT)
            m_showText += "  ";
    }

}
