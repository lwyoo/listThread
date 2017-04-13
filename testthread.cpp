#include "testthread.h"
#include "testlistmodel.h"
#include "testlistelement.h"
#include "listmodelcontrol.h"
#include <QDebug>
#include <QCoreApplication>



TestThread::TestThread(QObject *parent)
    : QThread(parent)
    , mList (new TestListModel)
    , state(ENABLED)
{
    qDebug() << QString ("[%1] "
                         "call construction")
                .arg(Q_FUNC_INFO)
                ;
}

TestThread::~TestThread()
{
    qDebug() << QString ("[%1] "
                         "call destruction  ")
                .arg(Q_FUNC_INFO)
                ;
}

TestListModel *TestThread::getModel()
{
    return mList;
}


void TestThread::run()
{
    //뮤텍스 필요

    switch(state)
    {
    case ENABLED:
        state = WORKING;
        mList->listClean();
        for (int i = 0 ; i < 1000000 ; i++)
        {
            mList->addItem(TestListElement(i , "add Item" , "123.jpg"));
        }

        QCoreApplication::postEvent(this->parent(), new QEvent(ListModelControl::CalculateComplete));
        state = ENABLED;
        break;
    case WORKING:
        break;
    }
}
