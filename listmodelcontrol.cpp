#include "listmodelcontrol.h"
#include "testlistmodel.h"
#include <QDebug>
#include <QApplication>
#include "testthread.h"

ListModelControl * listModelControlInstance = NULL;


ListModelControl::ListModelControl(QObject *parent)
    : QObject(parent)
    , mList(new TestListModel)
    , mQmlEngine(NULL)
    , mThread(new TestThread(this))
{
    listInit();
}

ListModelControl *ListModelControl::instance()
{
    if (listModelControlInstance == NULL)
    {
        listModelControlInstance = new ListModelControl;
    }
    else
    {

    }
    return listModelControlInstance;
}

void ListModelControl::listInit()
{
    qDebug() << QString ("[%1] "
                         "row Count is [%2]")
                .arg(Q_FUNC_INFO)
                .arg(mList->rowCount());


    if (mList->rowCount() != 0)
    {

        mList->listClean();
    }
    else
    {

    }
    addListModel(100);

}

void ListModelControl::addListModel(const int nValue)
{
    //임의의 리스트 항목을 입력 받은 숫자 만큼 추가

    //thread 돌리기

    for (int i = 0 ; i < 2 ; i++)
    {
        mList->addItem(TestListElement(999 , "add Item"));
    }

    qDebug() << QString (" add List Model Complete [%1] ").arg(Q_FUNC_INFO);
//    mList->addItem();

}

void ListModelControl::removListModel(const int startOffSet, const int endOffSet)
{

    qDebug() << QString ("[%1] "
                         "row count [%2]"
                         "start off set [%3]"
                         "end off set [%4]"
                         )
                .arg(Q_FUNC_INFO)
                .arg(mList->rowCount())
                .arg(startOffSet)
                .arg(endOffSet)
                ;
    if (mList->rowCount() <=  endOffSet && mList->rowCount() >= startOffSet)
    {
        qDebug() << QString ("[%1] "
                             "delete possible")
                    .arg(Q_FUNC_INFO)
                    ;
        mList->removeRows(startOffSet ,endOffSet);
    }
    else
    {
        qDebug() << QString ("[%1] "
                             "delete impossible")
                    .arg(Q_FUNC_INFO)
                    ;
    }
}

void ListModelControl::allRemoveListModel()
{
    mList->listClean();
}

void ListModelControl::addListModelThread(const int nValue)
{
    //임의의 리스트 항목을 입력 받은 숫자 만큼 추가

    //thread 돌리기

    mThread->start();
    qDebug() << QString (" add List Model Complete [%1] ").arg(Q_FUNC_INFO);

}

void ListModelControl::setRootContext(QQmlContext *context)
{
    context->setContextProperty("TestListModel", mList);
    context->setContextProperty("TestList", this);

}

bool ListModelControl::event(QEvent *e)
{
    switch (e->type())
    {
    case CalculateComplete:
        qDebug() << QString ("[%1] "
                             "Compolete INIT [%2]")
                    .arg(Q_FUNC_INFO)
                    .arg(mList->rowCount())
                    ;
        mList->resetRouteList(mThread->getModel()->getList());

        break;
    default:
        return QObject::event(e);
    }
}




