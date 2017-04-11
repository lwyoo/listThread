#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "listmodelcontrol.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ListModelControl::instance()->setRootContext(engine.rootContext());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    return app.exec();
}



//#include <QApplication>
//#include <QMainWindow>
//#include <QMouseEvent>
//#include <QMessageBox>
//#include <QDebug>
//static const QEvent::Type MY_ENUM_FIRST = QEvent::Type(QEvent::User + 1);
//static const QEvent::Type MY_ENUM_SECOND = QEvent::Type(QEvent::User + 2);

//class myMainWindow: public QMainWindow
//{
//  QMessageBox* msgBox;
//  public:
//    myMainWindow()
//    {};
//    ~ myMainWindow(){};

//    void mouseDoubleClickEvent ( QMouseEvent * event )
//    {
//        msgBox = new QMessageBox();
//        msgBox->setWindowTitle("Hello");
//        msgBox->setText("You Double Clicked Mouse Button");
//        msgBox->show();

//    };
//    void mousePressEvent( QMouseEvent * event)
//    {
////        msgBox = new QMessageBox();
////        msgBox->setWindowTitle("Hello");
////        msgBox->setText("You press Clicked Mouse Button");
////        msgBox->show();
//        qDebug() << "asdasd";
//        qApp->postEvent(this , new QEvent(QEvent::Type(MY_ENUM_FIRST)));

//    }


//    bool event(QEvent *e)
//    {
//        qDebug() << "eeee : " << ( int ( e->type() ) );

//        switch ( int ( e->type() ) )
//        {
//        case QEvent::MouseButtonPress:
//        qApp->postEvent(this , new QEvent(QEvent::Type(MY_ENUM_FIRST)));
//            break;
//        case MY_ENUM_FIRST:
//            msgBox = new QMessageBox();
//            msgBox->setWindowTitle("Hello");
//            msgBox->setText("111 Clicked Mouse Button");
//            msgBox->show();
//            break;
//        case MY_ENUM_SECOND:
//            msgBox = new QMessageBox();
//            msgBox->setWindowTitle("Hello");
//            msgBox->setText("222 Clicked Mouse Button");
//            msgBox->show();
//            break;
//        }
//    }



//};

//int main(int argc, char **argv)
//{
//    QApplication app(argc, argv);

//    myMainWindow *window = new myMainWindow();

//        window->setWindowTitle(QString::fromUtf8("QT - Capture Mouse Double Click"));
//        window->resize(300, 250);

//    window->show();
//    return app.exec();
//}
