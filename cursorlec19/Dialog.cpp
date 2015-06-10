#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::Dialog)
    , m_cursor(new Cursor())
    , m_keyPressCommand(new KeyPressCommand(this, m_cursor))
    , m_mouseClick(new MouseClickCommand(this, m_cursor))
    , m_mouseScrollCommand(new MouseScrollCommand(this, m_cursor))
{
    m_ui->setupUi(this);
    m_cursor->setDefaultState(new StandardCursorState());
    m_cursor->setPassiveState(new EraserState("eraser.gif"));
}

Dialog::~Dialog()
{
    delete m_ui;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    m_keyPressCommand->execute(event);
}

void Dialog::wheelEvent(QWheelEvent *event)
{
     m_mouseScrollCommand->execute(event);
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    m_mouseClick->execute(event);
}
