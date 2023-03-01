#ifndef AUTOMATARENDERAREA_H
#define AUTOMATARENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <iostream>
#include <array>
#include <vector>

class AutomataRenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit AutomataRenderArea(QWidget *parent, int rows, int cols, std::vector<std::vector<int>> &arr);
    void changeColor();
protected:
    void paintEvent(QPaintEvent *event) override;
    QColor color;
signals:
private:
    const int rows;
    const int cols;
    std::vector<std::vector<int>> data_array;

    std::array<QColor, 2> colors {QColor("green"), QColor("magenta")};
};

#endif // AUTOMATARENDERAREA_H
