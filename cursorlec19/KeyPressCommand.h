#ifndef KEYPRESSCOMMAND_H
#define KEYPRESSCOMMAND_H

#include "Command.h"

class KeyPressCommand : public Command
{
public:
    KeyPressCommand(QWidget *windowAccess, Cursor *cursor)
        : Command(windowAccess, cursor)
    {

    }

    void execute(QInputEvent *inputEvent)
    {
        QKeyEvent *keyPressEvent = dynamic_cast<QKeyEvent*>(inputEvent);
        if(keyPressEvent->key() == 'E')
        {
            m_cursor->switchState();
            m_cursor->getCurrentState()->updateCursorDisplay(m_windowAccess);
        }
    }
};

#endif // KEYPRESSCOMMAND_H
