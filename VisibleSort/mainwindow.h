#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mycircle.h"
#include "myvirtualgraph.h"
#include "myarrow.h"
#include "numberinputwindow.h"
#include "mygraphview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MyGraphView* MyGraphViewUut;
    Ui::MainWindow *ui;
    QVector<unsigned int> nums;

};
#endif // MAINWINDOW_H
