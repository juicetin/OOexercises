#ifndef CURSOR_H
#define CURSOR_H

#include "EraserState.h"
#include "StandardCursorState.h"

#include <algorithm>

class Cursor
{
public:
    Cursor();
    ~Cursor();

    void setDefaultState(CursorState *defaultState);
    void setPassiveState(CursorState *passiveState);

    void switchState();

    CursorState* getCurrentState();


private:
    CursorState *m_currentState;
    CursorState *m_passiveState;
};

#endif // CURSOR_H
