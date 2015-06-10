#include "StandardCursorState.h"

StandardCursorState::StandardCursorState()
    : CursorState()
{

}

StandardCursorState::~StandardCursorState()
{

}

void StandardCursorState::processMouseEvent(QMouseEvent *event, QWidget *dialog)
{
    std::cout << "No mouse click functionality enabled by default" << std::endl;
}

void StandardCursorState::processMouseEvent(QWheelEvent *event, QWidget *dialog)
{
    if (event->delta()> 0)
    {
        std::cout << "No mouse wheel forward functionality enabled by default" << std::endl;
    }
    else
    {
        std::cout << "No mouse wheel backward functionality enabled by default" << std::endl;
    }
}

void StandardCursorState::updateCursorDisplay(QWidget *dialog)
{
    dialog->setCursor(Qt::ArrowCursor);
}
