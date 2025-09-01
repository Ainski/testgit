#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyGraphViewUut= new MyGraphView(this->nums,this);
    ui->HZLayout->addWidget(MyGraphViewUut);


    connect(ui->InputToSort,&QAction::triggered,[this]{
        NumberInputWindow* inputer =new NumberInputWindow(nullptr);
        inputer->resize(500, 250);
        inputer->show();
        connect(inputer,&NumberInputWindow::NumsReady,[this](const QVector<unsigned int>&numbers){

            this->nums=numbers;
            MyGraphViewUut->draw();

        });

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

