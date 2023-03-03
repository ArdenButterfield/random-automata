#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    automataModel = std::make_unique<AutomataModel>(rows, cols);
    randomizeButton = std::make_unique<QPushButton>("Randomize", this);
    automataRenderArea = std::make_unique<AutomataRenderArea>(this, rows, cols, &(automataModel->grid));


    randomizeButton->setGeometry(10,10,80,30);
    automataRenderArea->setGeometry(200,0,600,600);


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
    automataModel->setRule(2,2);
    automataModel->fill(true);
    automataRenderArea->update();
}
