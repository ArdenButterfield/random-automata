#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int rows = 30;
    int cols = 30;
    automataModel = std::make_unique<AutomataModel>(rows, cols);
    randomizeButton = std::make_unique<QPushButton>("Randomize", this);
    automataRenderArea = std::make_unique<AutomataRenderArea>(this, rows, cols, automataModel->grid);


    randomizeButton->setGeometry(10,10,80,30);
    automataRenderArea->setGeometry(100,10,180,180);


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
    automataModel->setRule(5,6);
    automataModel->fill(true);

    automataRenderArea->repaint();
}
