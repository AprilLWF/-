#ifndef TEXTTICKER_H
#define TEXTTICKER_H

#include <QLabel>
#include <QTimer>
#define MAX_COUNT 25
#define INIT_COUNT 7

class TextTicker : public QLabel
{
    Q_OBJECT

public:
    TextTicker(QWidget *parent = 0);
    ~TextTicker();

    void setText(const QString &);
    int type;

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_charWidth;
    int m_curIndex;
    QString m_showText;
    QTimer *timer;

private slots:
    void updateIndex();
};
#endif // TEXTTICKER_H
