#include "EraserState.h"

EraserState::EraserState(const char * cursorImageFileName)
    : CursorState()
    , m_cursorImage(cursorImageFileName)
    , m_currentHeight(100)
    , m_currentWidth(100)
{

}

EraserState::~EraserState()
{

}

void EraserState::processMouseEvent(QMouseEvent *event, QWidget *dialog)
{
    if (event->button() == Qt::LeftButton)
    {
        std::cout << "Remove all objects in Cursor area" << std::endl;
    }
    else if (event->button() == Qt::RightButton)
    {
        std::cout << "Right Click Not Support" << std::endl;
    }
}

void EraserState::processMouseEvent(QWheelEvent *event, QWidget *dialog)
{
    if (event->delta()> 0)
    {
        m_currentHeight *= 1.25;
        m_currentWidth *= 1.25;
        std::cout << "Increasing Eraser Size, Scaling Factor is now " << m_currentHeight << std::endl;
        QPixmap newPixmap = m_cursorImage.scaled(QSize(m_currentHeight, m_currentWidth),  Qt::KeepAspectRatio);
        QCursor curser(newPixmap);
        dialog->setCursor(curser);
    }
    else
    {
        m_currentHeight /= 1.25;
        m_currentWidth /= 1.25;
        std::cout << "Decreasing Eraser Size, Scaling Factor is now " << m_currentHeight << std::endl;
        QPixmap newPixmap = m_cursorImage.scaled(QSize(m_currentHeight, m_currentWidth),  Qt::KeepAspectRatio);
        QCursor curser(newPixmap);
        dialog->setCursor(curser);
    }
}

void EraserState::updateCursorDisplay(QWidget *dialog)
{
    m_currentHeight = m_currentWidth = 100;
    QPixmap newPixmap = m_cursorImage.scaled(QSize(m_currentHeight, m_currentWidth),  Qt::KeepAspectRatio);
    QCursor curser(newPixmap);
    dialog->setCursor(curser);
}
