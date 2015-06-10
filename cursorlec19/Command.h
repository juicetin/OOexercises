#ifndef COMMAND_H
#define COMMAND_H

#include <QtWidgets>
#include "Cursor.h"

class Command
{
public:
    Command(QWidget *windowAccess, Cursor *cursor)
        : m_windowAccess(windowAccess)
        , m_cursor(cursor)
    {

    }
    ~Command() {}

    virtual void execute(QInputEvent *inputEvent) = 0;

protected:
    QWidget *m_windowAccess;
    Cursor *m_cursor;
};

#endif // COMMAND_H
