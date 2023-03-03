#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>

#include <memory>

#include "automatarenderarea.h"
#include "automatamodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void randomizeCallback();
    void lengthChanged(int new_length);
    void numStatesChanged(int new_num_states);
    void firstRowRandomChanged(int new_status);

private:
    const int rows = 300;
    const int cols = 300;

    std::unique_ptr<QPushButton> randomizeButton;
    std::unique_ptr<AutomataRenderArea> automataRenderArea;
    std::unique_ptr<AutomataModel> automataModel;
    std::unique_ptr<QSpinBox> statesBox;
    std::unique_ptr<QSpinBox> lengthBox;
    std::unique_ptr<QCheckBox> firstRowRandom;

    std::unique_ptr<QLabel> title;

    int length, num_states;
    bool randomize_first_row;
};
#endif // MAINWINDOW_H
