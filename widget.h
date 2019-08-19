#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public slots:
    void slotTimeOut();
    void slotIsDone();
    void slotDestroyed();

public:
    explicit widget(QWidget *parent = 0);
    ~widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::widget *ui;
    QTimer *m_timer;
    MyThread *m_thread;
};

#endif // WIDGET_H
