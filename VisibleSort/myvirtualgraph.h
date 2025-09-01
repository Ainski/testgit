#ifndef MYVIRTUALGRAPH_H
#define MYVIRTUALGRAPH_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <QToolTip>
#include <QLabel>
#include <QTimer>
class MyVirtualGraph:public QWidget
{
public:
    explicit MyVirtualGraph(QWidget *parent=nullptr,
                            const QString& text="MyVirtualGraph" ,const QPointF &leftUpPoint=QPointF(0,0),
                            const qreal& lenth=100.0,const qreal &height=100.0 ,
                            const QColor& color=Qt::blue,const QColor &bgcolor=Qt::transparent);
    void settext(const QString &text);
    void setPointF (const QPointF lpp);
    void setcolor(const QColor &color);
    void setbgcolor(const QColor &bgcolor);
    void setlenth(const qreal &lenth);
    void setheight(const qreal &height);
    void paintEvent(QPaintEvent *event) ;  // 移除override关键字
    virtual void paintEventExtra(QPaintEvent *event);
    virtual void prepareToUpdate(QPaintEvent *event);

signals:
    void clicked();

protected:
    QString _text;
    QPointF _leftUpPoint;
    qreal   _height;
    qreal   _lenth;
    QColor  _color;
    QColor  _bgcolor;
    QLabel  *_tipLabel;
    void enterEvent(QEvent *event);  // 使用QEvent*而不是QEnterEvent*
    void leaveEvent(QEvent *event);
};

#endif // MYVIRTUALGRAPH_H
