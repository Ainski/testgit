#ifndef MYARROW_H
#define MYARROW_H
#include "myvirtualgraph.h"
#include <cmath>
class MyArrow:public MyVirtualGraph
{
public:
    explicit MyArrow(QWidget * parent=nullptr,const QString &text="MyArrow" ,const QPointF &BeginPoint=QPointF(400.0,420.0),
                     const QPointF &EndPoint=QPointF(300.0,320.0),
                     const qreal& ArrowSize=20,
                     const QColor& color=Qt::blue,const QColor& bgcolor=Qt::transparent,
                     const Qt::PenStyle& LineStyle=Qt::SolidLine
                     );
    void paintEventExtra(QPaintEvent *event);
    void SetBeginPoint(const QPointF &BeginPoint=QPointF(400.0,420.0));
    void SetEndPoint(const QPointF &EndPoint=QPointF(300.0,320.0));
    void SetArrowSize(const qreal& ArrowSize=20);
    void prepareToUpdate(QPaintEvent *event) ;
signals:
    void clicked();

protected:
    QPointF _BeginPoint;
    QPointF _EndPoint;
    qreal _ArrowSize;
    Qt::PenStyle _LineStyle;


};

#endif // MYARROW_H
