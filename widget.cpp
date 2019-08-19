#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    m_timer = new QTimer(this);
    m_thread = new MyThread(this);

    ui->setupUi(this);

    connect(m_timer,&QTimer::timeout,this,&widget::slotTimeOut);
    connect(m_thread,&MyThread::signalIsDone,this,&widget::slotIsDone);
    connect(this,&widget::destroyed,this,&widget::slotDestroyed);
}

widget::~widget()
{
    delete ui;
}

void widget::on_pushButton_clicked()
{
    if(m_timer->isActive() == false)
    {
        m_timer->start(100);
    }
    m_thread->start();
}

void widget::slotTimeOut()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void widget::slotIsDone()
{
    m_timer->stop();
}

void widget::slotDestroyed()
{
    m_thread->quit();
    m_thread->wait();
}
