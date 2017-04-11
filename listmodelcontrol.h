#ifndef LISTMODELCONTROL_H
#define LISTMODELCONTROL_H
#include <QObject>
#include <QQmlContext>

class TestListModel;
class ListModelControl : public QObject
{
    Q_OBJECT
private:
    ListModelControl(QObject * parent = 0);

public:
    static ListModelControl * instance();

public:

    // 리스트 초기화
    Q_INVOKABLE void listInit();
    // 리스트 x 개 추가
    Q_INVOKABLE void addListModel(const int nValue);
    // 리스트 삭제
    Q_INVOKABLE void removListModel(const int startOffSet , const int endOffSet);
    // 리스트 전체 삭제
    Q_INVOKABLE void allRemoveListModel();

    void setRootContext(QQmlContext * context);


private:
    TestListModel * mList;
    QQmlEngine* mQmlEngine;

};

#endif // LISTMODELCONTROL_H
