#ifndef MYGRAPHVIEW_H
#define MYGRAPHVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QVector>
#include <QPointF>
#include <QGraphicsScene>
#include "myvirtualgraph.h"
#include "myarrow.h"
class MyGraphView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphView(const QVector<unsigned int> &_nums,QWidget *parent = nullptr,
                         const QPointF _LeftUpPer=QPointF(0.05,0.05),
                         const qreal _WidthPer=0.9,
                         const qreal _HeightPer=0.9);
    virtual ~MyGraphView();
    void draw();
signals:
    void toupdate();
private:
    const QVector<unsigned int>& nums;
    const QPointF LeftUpPer;
    const qreal HeightPer;
    const qreal WidthPer;
    QVector<MyVirtualGraph*> Squares;
    MyArrow* HorizontalAxis;
    MyArrow* VerticalAxis;
    QGraphicsScene * scene;

private slots:
    void updating();


};

#endif // MYGRAPHVIEW_H
