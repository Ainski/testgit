#include "mycircle.h"
#include <QDebug>

MyCircle::MyCircle(QWidget *parent,const QString& text,const QPointF& center,const qreal& radius,
                   const QColor &color, const QColor &bgcolor)
    :MyVirtualGraph(parent,text,center-QPointF(radius,radius),2*radius,2*radius,color,bgcolor)
{
    qDebug()<<"MyCircle::MyCircle(QString text, QPointF center, qreal radius,QColor color, QColor bgcolor,QWidget *parent)";
    setMouseTracking(true);
    _radius=radius;

//    qDebug() << "MyCircle created:";
//    qDebug() << "  Text:" << text;
//    qDebug() << "  Original center:" << center;
//    qDebug() << "  Radius:" << radius;
//    qDebug() << "  Size:" << size();
}

void MyCircle::paintEventExtra(QPaintEvent *event)
{
    qDebug()<<"void MyCircle::paintEventExtra(QPaintEvent *event)";
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    // 绘制圆形 - 确保使用正确的颜色
    painter.setPen(Qt::NoPen);
    painter.setBrush(_color); // 这应该是绿色

    // 计算圆形边界
    QRectF circleRect(0,0,_radius * 2, _radius * 2);

    painter.drawEllipse(circleRect);

//    // 添加调试输出
//    qDebug() << "Drawing circle with color:" << _color;
//    qDebug() << "Background color:"<<_bgcolor;
}
