#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    list = new QListWidget;
    list->addItem("@everyone");
    list->addItem("TEST");
    list->setDragDropMode(QAbstractItemView::InternalMove);
    list->setMaximumWidth(150);
    list->setMinimumWidth(150);

    Message = new QTextEdit;
    Message->setMaximumHeight(100);

    Reply = new QTextEdit;
    Reply->setReadOnly(true);

    Send = new QPushButton("Send", this);
    Send->setMinimumHeight(Message->height());
    connect(Send, SIGNAL (released()), this, SLOT (SendMessage()));

    layoutMB = new QHBoxLayout;
    layoutMB->addWidget(Message);
    layoutMB->addWidget(Send);

    layoutText = new QVBoxLayout;
    layoutText->addWidget(Reply);
    layoutText->addLayout(layoutMB);

    layout = new QHBoxLayout;
    layout->addWidget(list);
    layout->addLayout(layoutText);
    setLayout(layout);

    setWindowTitle("Communicator");
    resize(640, 360);
}

void Widget::SendMessage()
{
    if(Message->toPlainText()!= nullptr)
    {
        QString text = Message->toPlainText();
        Message->clear();
        Reply->append("Guest 1: "+text);
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter)
    {
        SendMessage();
    }
}

Widget::~Widget()
{
}

