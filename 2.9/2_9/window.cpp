#include "window.h"
#include<QTextCodec>
#include<QBoxLayout>

Window::Window() //конструктор виджета
{
    codec = QTextCodec::codecForName("UTF-8");

    this->setWindowTitle(codec->toUnicode("Обработка событий"));

    area = new Area( this );
    exitButton = new QPushButton(codec->toUnicode("Завершить"),this );

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(exitButton);
    connect(exitButton, SIGNAL(clicked(bool)),this,SLOT(close()));
};
