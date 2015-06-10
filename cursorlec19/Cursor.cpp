#include "Cursor.h"

Cursor::Cursor()
    : m_currentState(0)
    , m_passiveState(0)
{

}

Cursor::~Cursor() {}

void Cursor::setDefaultState(CursorState *defaultState)
{
    m_currentState = defaultState;
}

void Cursor::setPassiveState(CursorState *passiveState)
{
    m_passiveState = passiveState;
}

void Cursor::switchState()
{
    std::swap<CursorState*> (m_currentState, m_passiveState);
}

CursorState* Cursor::getCurrentState()
{
    return m_currentState;
}
