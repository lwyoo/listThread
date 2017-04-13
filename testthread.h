#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>

class TestListModel;
class TestListElement;
class TestThread : public QThread
{
    Q_OBJECT
public:
    enum State {
        ENABLED = 0,
        WORKING = 2,
    };
    TestThread(QObject *parent = 0);
    ~TestThread();

    TestListModel* getModel();
private:
    void run();
    TestListModel * mList;
    State state;

//signals:
//    void signalFinish(int nValue);
};

#endif // TESTTHREAD_H
