#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>
class KeyPress : public QObject
{
    Q_OBJECT
public:
    KeyPress(QObject * parent = 0);
private:
    bool event(QEvent *e) Q_DECL_OVERRIDE;

};

#endif // KEYPRESS_H
