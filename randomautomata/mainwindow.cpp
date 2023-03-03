#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setStyleSheet("background-color: #EEEEEE;");

    length = 3;
    num_states = 3;
    randomize_first_row = false;

    automataModel = std::make_unique<AutomataModel>(rows, cols, length, num_states);
    randomizeButton = std::make_unique<QPushButton>("New Rule", this);
    randomizeButton->setStyleSheet("background-color: #EEEECC; color: #222222");
    automataRenderArea = std::make_unique<AutomataRenderArea>(this, rows, cols, &(automataModel->grid));

    statesBox = std::make_unique<QSpinBox>(this);
    lengthBox = std::make_unique<QSpinBox>(this);
    statesBox->setStyleSheet("QSpinBox{background-color: #EEEECC; color: #222222;}");
    lengthBox->setStyleSheet("background-color: #EEEECC; color: #222222");


    firstRowRandom = std::make_unique<QCheckBox>("Random first row", this);
    firstRowRandom->setStyleSheet("background-color: #CCCC99; color: #222222; border-color: #111111; QCheckBox::indicator{color:magenta;}");

    statesBox->setRange(1, 10);
    lengthBox->setRange(1, 10);


    lengthBox->setValue(length);
    statesBox->setValue(num_states);

    randomizeButton->setGeometry(10,10,80,30);
    automataRenderArea->setGeometry(200,0,600,600);
    statesBox->setGeometry(10, 50, 45, 20);
    lengthBox->setGeometry(60,50,45,20);
    firstRowRandom->setGeometry(10, 80, 180, 30);

    connect(randomizeButton.get(),
            SIGNAL (clicked()),
            this,
            SLOT (randomizeCallback()));
    connect(statesBox.get(),
            SIGNAL (valueChanged(int)),
            this,
            SLOT (numStatesChanged(int)));
    connect(lengthBox.get(),
            SIGNAL (valueChanged(int)),
            this,
            SLOT (lengthChanged(int)));
    connect(firstRowRandom.get(),
            SIGNAL (stateChanged(int)),
            this,
            SLOT (firstRowRandomChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::randomizeCallback()
{
    std::cout << "button callback\n";
    automataModel->setRule(length, num_states);
    automataModel->fill(randomize_first_row);
    automataRenderArea->update();
}

void MainWindow::lengthChanged(int new_length)
{
    length = new_length;
    randomizeCallback();
}

void MainWindow::numStatesChanged(int new_num_states)
{
    num_states = new_num_states;
    randomizeCallback();
}

void MainWindow::firstRowRandomChanged(int new_status)
{
    randomize_first_row = (new_status > 0);
    automataModel->fill(randomize_first_row);
    automataRenderArea->update();
}
