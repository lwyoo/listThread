#include "listmodelcontrol.h"
#include "testlistmodel.h"
#include <QDebug>
#include <QApplication>

ListModelControl * listModelControlInstance = NULL;

ListModelControl::ListModelControl(QObject *parent)
{
    mList = new TestListModel;
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

    for (int i = 0 ; i < nValue ; i++)
    {
        mList->addItem(TestListElement(999 , "add Item"));
    }

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

void ListModelControl::setRootContext(QQmlContext *context)
{
//    QQmlContext * context = mQmlEngine->rootContext();
    context->setContextProperty("TestListModel", mList);
    context->setContextProperty("TestList", this);

}




