#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Message = new QTextEdit;

    Reply = new QTextEdit;
    Reply->setMinimumSize(400,400);

    Send = new QPushButton("Send", this);
    connect(Send, SIGNAL (released()), this, SLOT (SendMessage()));

    layoutText = new QHBoxLayout;
    layoutText->addWidget(Message);
    layoutText->addWidget(Send);

    layout = new QVBoxLayout;
    layout->addWidget(Reply);
    layout->addLayout(layoutText);
    setLayout(layout);

    setWindowTitle("Communicator");
    resize(800, 600);
}

void Widget::SendMessage()
{
    QString text = Message->toPlainText();
    Message->clear();
    Reply->append("Guest 1: "+text);
}

Widget::~Widget()
{
}

