#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include "myvirtualgraph.h"
class MyCircle : public MyVirtualGraph
{
    Q_OBJECT
public:
    explicit MyCircle(QWidget *parent=nullptr,
                      const QString& text="MyCircle",const QPointF& center=QPointF(100.0,100.0),
                      const qreal& radius=50.0,
                      const QColor& color=Qt::blue,const QColor& bgcolor=Qt::transparent
                      );

    void paintEventExtra(QPaintEvent *event);

signals:
    void clicked();

protected:
    qreal _radius;

};

#endif // MYCIRCLE_H
