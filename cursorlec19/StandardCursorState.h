#ifndef STANDARDCURSORSTATE_H
#define STANDARDCURSORSTATE_H

#include "CursorState.h"

class StandardCursorState : public CursorState
{
public:
    StandardCursorState();
    virtual ~StandardCursorState();

    void processMouseEvent(QMouseEvent *event, QWidget *dialog);
    void processMouseEvent(QWheelEvent *event, QWidget *dialog);

    void updateCursorDisplay(QWidget *dialog);
};

#endif // STANDARDCURSORSTATE_H
