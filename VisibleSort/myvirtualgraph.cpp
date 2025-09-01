#include "myvirtualgraph.h"
#include <QDebug>


MyVirtualGraph::MyVirtualGraph(QWidget *parent,const QString& text ,const QPointF &leftUpPoint,
                               const qreal &lenth,const qreal& height ,
                               const QColor &color,const QColor &bgcolor)
    : QWidget(parent),_text(text),_leftUpPoint(leftUpPoint),_height(height),_lenth(lenth),
      _color(color),_bgcolor(bgcolor),_tipLabel(nullptr)
{
    setMouseTracking(true);
    setFixedSize(lenth,height);
    move(int(_leftUpPoint.x()),int(_leftUpPoint.y()));
    qDebug()<<"MyVirtualGraph::MyVirtualGraph(const QString& text ,const QPointF &leftUpPoint,const qreal &lenth,const qreal& height , const QColor & color,const QColor& bgcolor,QWidget *parent)";



}
void MyVirtualGraph::paintEvent(QPaintEvent *event)
{

    qDebug()<<"void MyVirtualGraph::paintEvent(QPaintEvent *event)";
    Q_UNUSED(event);
    prepareToUpdate(event);
    setFixedSize(_lenth,_height);
    move(int(_leftUpPoint.x()),int(_leftUpPoint.y()));
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制浅灰色背景（用于调试）
    painter.fillRect(rect(), _bgcolor);
    paintEventExtra(event);


}
void MyVirtualGraph::prepareToUpdate(QPaintEvent *event)
{
    /* This virtual function is used to set up the property that dedicates the relationship
     * between this widget and the parent widget
     * for example: LeftUpPoint Width Height
     */
    Q_UNUSED(event);
    qDebug()<<"void MyVirtualGraph::prepareToUpdate(QPaintEvent *event)";
}
void MyVirtualGraph::paintEventExtra(QPaintEvent *event)
{
    Q_UNUSED(event);
    qDebug()<<"void MyVirtualGraph::paintEventExtra(QPaintEvent *event)";
}
void MyVirtualGraph::settext(const QString &text)
{
    _text=text;
    update();
}
void MyVirtualGraph::setPointF (const QPointF lpp)
{
    _leftUpPoint=lpp;
    move(int(_leftUpPoint.x()),int(_leftUpPoint.y()));
    update();
}
void MyVirtualGraph::setcolor(const QColor &color)
{
    _color=color;
    update();
}
void MyVirtualGraph::setbgcolor(const QColor &bgcolor)
{
    _bgcolor=bgcolor;
    update();
}
void MyVirtualGraph::setlenth(const qreal &lenth)
{
    _lenth=lenth;
    update();
}
void MyVirtualGraph::setheight(const qreal &height)
{
    _height=height;
    update();
}

void MyVirtualGraph::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    qDebug()<<"void MyVirtualGraph::enterEvent(QEvent *event)";

    QPoint globalPos = mapToGlobal(QPoint(0,0));
    QToolTip::showText(globalPos, _text, this);
}

void MyVirtualGraph::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "void MyVirtualGraph::leaveEvent(QEvent *event)";
    QToolTip::hideText();
}
