#include "keypress.h"

#include <QApplication>
#include <QKeyEvent>

static const QEvent::Type MY_ENUM_FIRST = QEvent::Type(QEvent::User + 1);
static const QEvent::Type MY_ENUM_SECOND = QEvent::Type(QEvent::User + 2);

KeyPress::KeyPress(QObject *parent) :
    QObject(parent)
{
    qDebug() << "create instance";
}

bool KeyPress::event(QEvent *e)
{
    qDebug() << "event Start";

    switch ( int ( e->type() ) )
    {
    case MY_ENUM_FIRST:
        qDebug() << "select event [MY_ENUM_FIRST]";

        break;
    case MY_ENUM_SECOND:
        qDebug() << "select event [MY_ENUM_SECOND]";

        break;
    default:
        qDebug() << "select event [?????]";
        break;
    }
}
