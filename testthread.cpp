#include "testthread.h"
#include "testlistmodel.h"
#include "testlistelement.h"
#include "listmodelcontrol.h"
#include <QDebug>
#include <QCoreApplication>



TestThread::TestThread(QObject *parent)
    : QThread(parent)
{
    qDebug() << QString ("[%1] "
                         "call construction")
                .arg(Q_FUNC_INFO)
                ;
    mList = new TestListModel;
}

TestThread::~TestThread()
{
    qDebug() << QString ("[%1] "
                         "call destruction  ")
                .arg(Q_FUNC_INFO)
                ;
}

void TestThread::run()
{
    //뮤텍스 필요

    mList->listClean();
    for (int i = 0 ; i < 1000000 ; i++)
    {
        mList->addItem(TestListElement(i , "add Item"));
    }

    QCoreApplication::postEvent(this->parent(), new QEvent(ListModelControl::INIT));
}
