#ifndef MOUSECLICKCOMMAND_H
#define MOUSECLICKCOMMAND_H

#include "Command.h"

class MouseClickCommand : public Command
{
public:
    MouseClickCommand(QWidget *windowAccess, Cursor *cursor)
        : Command(windowAccess, cursor)
    {

    }

    void execute(QInputEvent *inputEvent)
    {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(inputEvent);
        m_cursor->getCurrentState()->processMouseEvent(mouseEvent, m_windowAccess);
    }
};

#endif // MOUSECLICKCOMMAND_H
