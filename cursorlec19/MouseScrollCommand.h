#ifndef MOUSESCROLLCOMMAND_H
#define MOUSESCROLLCOMMAND_H

#include "Command.h"

class MouseScrollCommand : public Command
{
public:
    MouseScrollCommand(QWidget *windowAccess, Cursor *cursor)
        : Command(windowAccess, cursor)
    {

    }

    void execute(QInputEvent *inputEvent)
    {
        QWheelEvent *wheelEvent = dynamic_cast<QWheelEvent*>(inputEvent);
        m_cursor->getCurrentState()->processMouseEvent(wheelEvent, m_windowAccess);
    }
};


#endif // MOUSESCROLLCOMMAND_H
