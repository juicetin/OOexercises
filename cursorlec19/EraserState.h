#ifndef ERASERSTATE_H
#define ERASERSTATE_H

#include "CursorState.h"
#include <QCursor>

class EraserState : public CursorState
{
public:
    EraserState(const char * cursorImageFileName);
    virtual ~EraserState();

    void processMouseEvent(QMouseEvent *event, QWidget *dialog);
    void processMouseEvent(QWheelEvent *event, QWidget *dialog);

    void updateCursorDisplay(QWidget *dialog);

private:
    QPixmap m_cursorImage;
    float m_currentHeight;
    float m_currentWidth;
};

#endif // ERASERSTATE_H
