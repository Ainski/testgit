#ifndef NUMBERINPUTWINDOW_H
#define NUMBERINPUTWINDOW_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QIntValidator>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QObject>
#include <QTextStream>

class NumberInputWindow : public QWidget
{
    Q_OBJECT
public:
    explicit NumberInputWindow(QWidget *parent = nullptr);
    bool IsPrepared();
signals:
    void NumsReady(const QVector<unsigned int> numbers);
private:
    QLineEdit* textEdit;
    QVector<unsigned int> results;
    bool NumberPrepared;

private slots:
    void CheckOut();

};

#endif // NUMBERINPUTWINDOW_H
