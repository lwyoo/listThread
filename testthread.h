#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>

class TestListModel;
class TestListElement;
class TestThread : public QThread
{
    Q_OBJECT
public:
    TestThread(QObject *parent = 0);
    ~TestThread();

//    TestListModel* getModel();
private:
    void run();
    TestListModel * mList;

//signals:
//    void signalFinish(int nValue);
};

#endif // TESTTHREAD_H
