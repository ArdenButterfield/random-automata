#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    randomizeButton = std::make_unique<QPushButton>("Randomize", this);
    automataRenderArea = std::make_unique<AutomataRenderArea>(this);


    randomizeButton->setGeometry(10,10,80,30);
    automataRenderArea->setGeometry(100,10,80,80);


    connect(randomizeButton.get(),
            SIGNAL (clicked()),
            this,
            SLOT (randomizeCallback()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::randomizeCallback()
{
    std::cout << "button callback\n";
    automataRenderArea->changeColor();
}
