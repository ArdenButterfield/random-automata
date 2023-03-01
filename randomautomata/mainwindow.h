#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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

private:
    const int rows = 100;
    const int cols = 100;

    std::unique_ptr<QPushButton> randomizeButton;
    std::unique_ptr<AutomataRenderArea> automataRenderArea;
    std::unique_ptr<AutomataModel> automataModel;
};
#endif // MAINWINDOW_H
