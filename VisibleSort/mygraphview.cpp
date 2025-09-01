#include "mygraphview.h"
#include <QDebug>
MyGraphView::MyGraphView(const QVector<unsigned int> &_nums,QWidget *parent ,
                         const QPointF _LeftUpPer,
                         const qreal _WidthPer,
                         const qreal _HeightPer) :
    QGraphicsView(parent),
    nums(_nums),
    LeftUpPer(_LeftUpPer.x()>=0.05&&_LeftUpPer.x()<=0.5&&
              _LeftUpPer.y()>=0.05&&_LeftUpPer.y()<=0.5?
                  _LeftUpPer:QPointF(0.05,0.05)),
    HeightPer(_HeightPer<=0.95-_LeftUpPer.y()&&_HeightPer>=0.5
              ?_HeightPer
             :0.95-_LeftUpPer.y()),
    WidthPer(_WidthPer<=0.95-_LeftUpPer.x()&&_WidthPer>=0.5
             ?_WidthPer
            :0.95-_LeftUpPer.x())

{
    connect(this ,&MyGraphView::toupdate,this,&MyGraphView::updating);
    qDebug()<<"MyGraphView::MyGraphView(const QVector<unsigned int> &_nums,QWidget *parent ,const QPointF _LeftUpPer,const qreal _WidthPer,const qreal _HeightPer)";
    scene=new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    HorizontalAxis =new MyArrow(this,"Horizontal Coordinate Axis");
    HorizontalAxis->SetArrowSize(10);
    HorizontalAxis->setVisible(false);
    VerticalAxis = new MyArrow(this,"Vertical Coordinate Axis");
    VerticalAxis->SetArrowSize(10);
    VerticalAxis->setVisible(false);

}
void MyGraphView::draw()
{
    qDebug()<<"void MyGraphView::draw()";
    qDebug()<<"LeftUpPer :"<<LeftUpPer;
    qDebug()<<"HeightPer :"<<HeightPer;
    qDebug()<<"WidthPer  :"<<WidthPer;
    if(nums.empty()){
        HorizontalAxis->setVisible(false);
        VerticalAxis->setVisible(false);
        return ;
    }

    int _height=height();
    int _width=width();
    HorizontalAxis->setVisible(true);
    VerticalAxis->setVisible(true);

    HorizontalAxis->SetBeginPoint(QPointF((LeftUpPer.x()+0.05)*_width,
                                          (LeftUpPer.y()+HeightPer)*_height));
    HorizontalAxis->SetEndPoint(QPointF((LeftUpPer.x()+0.05)*_width,
                                        (LeftUpPer.y())*_height));
    VerticalAxis->SetBeginPoint(QPointF((LeftUpPer.x())*_width,
                                        (LeftUpPer.y()+HeightPer-0.05)*_height));
    VerticalAxis->SetEndPoint(QPointF((LeftUpPer.x()+WidthPer)*_width,
                                      (LeftUpPer.y()+HeightPer-0.05)*_height));
//    HorizontalAxis= new MyArrow(
//                this,
//                "Horizontal Coordinate Axis",
//                QPointF((LeftUpPer.x()+0.05)*_width,
//                        (LeftUpPer.y()+HeightPer)*_height),
//                QPointF((LeftUpPer.x()+0.05)*_width,
//                        (LeftUpPer.y())*_height),
//                5
//                );
//    VerticalAxis=new MyArrow(
//                this,
//                "Vertical Coodinate Axis",
//                QPointF((LeftUpPer.x())*_width,
//                        (LeftUpPer.y()+HeightPer-0.05)*_height
//                    ),
//                QPointF((LeftUpPer.x()+WidthPer)*_width,
//                        (LeftUpPer.y()+HeightPer-0.05)*_height),
//                5
//                );

}
void MyGraphView::updating()
{
}
