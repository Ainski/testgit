#include "numberinputwindow.h"
#include <QDebug>
NumberInputWindow::NumberInputWindow(QWidget *parent) : QWidget(parent)
{
    NumberPrepared=false;
    setWindowTitle("数字输入窗口");
    QVBoxLayout*layout=new QVBoxLayout(this);
    QLabel *label=new QLabel("请在这里输入即将排序的数字，文本框中仅支持数字输入，\n为方便演示，不允许1000个以上的数据输入", this);
    layout->addWidget(label);

    textEdit=new QLineEdit(this);
    QRegularExpressionValidator *validator=
            new QRegularExpressionValidator(
                QRegularExpression("^[0-9]+(\\s+[0-9]+)*$"),textEdit);
    textEdit->setValidator(validator);
    layout->addWidget(textEdit);

    QPushButton*ConfirmButton=new QPushButton("确认",this);
    layout->addWidget(ConfirmButton);

    connect(ConfirmButton ,&QPushButton::clicked,this,&NumberInputWindow::CheckOut);

    setLayout(layout);
}
void NumberInputWindow::CheckOut()
{
    QString res=textEdit->text();

    QString buffer;
    unsigned int num;
    bool ok;
    qDebug()<<res;
    if(res.isEmpty()){
        QMessageBox::warning(this, "警告", "请输入数字!");
        NumberPrepared=false;
        return ;
    }
    else{
        buffer=buffer.trimmed();
        QTextStream iss(&res);
        while(!iss.atEnd()){

            buffer.clear();
            iss>>buffer;
            if(buffer.isEmpty()) break;
            num=buffer.toUInt(&ok);
            qDebug()<<num;
            if(!ok){
                QMessageBox::warning(this, "警告", "不是有效的整数或超出范围");
                NumberPrepared=false;
                return ;
            }
            if(results.size()>=1000){
                QMessageBox::warning(this, "警告", "超出1000个数据");
                NumberPrepared=false;
                return ;
            }
            results.push_back(num);

        }
    }
    NumberPrepared=true;
    emit NumsReady(results);

    close();

}

bool NumberInputWindow::IsPrepared()
{
    return NumberPrepared;
}
