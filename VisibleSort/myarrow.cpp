#include "myarrow.h"
#include <QDebug>

MyArrow::MyArrow(QWidget * parent,const QString &text ,const QPointF &BeginPoint,const QPointF &EndPoint,
                 const qreal& ArrowSize,
                 const QColor& color,const QColor &bgcolor,const Qt::PenStyle &LineStyle
                 ):
    MyVirtualGraph(parent,text,
                   QPointF(qMin(BeginPoint.x(),EndPoint.x()),qMin(BeginPoint.y(),EndPoint.y())),
                   qAbs(BeginPoint.x()-EndPoint.x()),
                   qAbs(BeginPoint.y()-EndPoint.y()),
                   color,
                   bgcolor
                   ),
    _BeginPoint (BeginPoint),
    _EndPoint   (EndPoint),
    _ArrowSize  (ArrowSize),
    _LineStyle  (LineStyle)

{
    qDebug()<<"MyArrow::MyArrow(const QString &text ,const QPointF &BeginPoint,const QPointF &EndPoint,const QColor & color,const QColor &bgcolor,QWidget * parent)";
    qDebug()<<"MyArrow::LeftUpPoint: "<<_leftUpPoint;
    qDebug()<<"MyArrow::BeginPoint:  "<<_BeginPoint;
    qDebug()<<"MyArrow::EndPoint:    "<<_EndPoint;

}
void MyArrow::paintEventExtra(QPaintEvent *event)
{
    qDebug()<<"MyArrow::paintEventExtra(QPaintEvent *event)";
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    painter.setPen(_LineStyle);
    painter.setPen(_color);
    painter.setBrush(_color);
    QPointF localBegin = _BeginPoint - _leftUpPoint;
    QPointF localEnd = _EndPoint - _leftUpPoint;


    QLineF line(localEnd,localBegin);

    double angle = std::atan2(-line.dy(), line.dx());
    QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * _ArrowSize,
                                          cos(angle + M_PI / 3) * _ArrowSize);
    QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * _ArrowSize,
                                          cos(angle + M_PI - M_PI / 3) * _ArrowSize);

    QPolygonF arrowHead;
    arrowHead.clear();
    arrowHead << line.p1() << arrowP1 << arrowP2;
    painter.drawLine(line);

    painter.drawPolygon(arrowHead);
}

void MyArrow::SetBeginPoint(const QPointF &BeginPoint)
{
    qDebug()<<"void MyArrow::SetBeginPoint(const QPointF &BeginPoint)";
    _BeginPoint=BeginPoint;
    qDebug()<<_BeginPoint;
    update();
}
void MyArrow::SetEndPoint(const QPointF &EndPoint)
{
    qDebug()<<"void MyArrow::SetEndPoint(const QPointF &EndPoint)";
    _EndPoint=EndPoint;
    qDebug()<<_EndPoint;
    update();
}
void MyArrow::SetArrowSize(const qreal &ArrowSize)
{
    qDebug()<<"void MyArrow::SetArrowSize(const qreal &ArrowSize)";

    _ArrowSize=ArrowSize;
    qDebug()<<_ArrowSize;
    update();
}
void MyArrow:: prepareToUpdate(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPointF newLeftUp(
                qMin(_BeginPoint.x(), _EndPoint.x()),
                qMin(_BeginPoint.y(), _EndPoint.y())
                );

    // 计算新的宽度和高度
    qreal newWidth = qAbs(_BeginPoint.x() - _EndPoint.x());
    if (newWidth<=_ArrowSize*2){
        newWidth=_ArrowSize*3;
        newLeftUp.rx()-=_ArrowSize;
    }

    qreal newHeight = qAbs(_BeginPoint.y() - _EndPoint.y());
    if (newHeight<=_ArrowSize*2){
        newHeight=_ArrowSize*3;
        newLeftUp.ry()-=_ArrowSize;

    }


    // 更新基类的几何属性
    _leftUpPoint = newLeftUp;
    _lenth = newWidth;
    _height = newHeight;

}
