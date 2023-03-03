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
    explicit AutomataRenderArea(QWidget *parent, int rows, int cols, std::vector<std::vector<int>> &grid);
    void changeColor();
protected:
    void paintEvent(QPaintEvent *event) override;
    QColor color;
signals:
private:
    const int rows;
    const int cols;
    std::vector<std::vector<int>> grid;

    std::array<QColor, 10> colors {QColor("white"), 
                                   QColor("black"),
                                   QColor("red"),
                                   QColor("green"),
                                   QColor("blue"),
                                   QColor("yellow"),
                                   QColor("magenta"),
                                   QColor("cyan"),
                                   QColor("purple"),
                                   QColor("orange"),
                               };
};
#endif // AUTOMATARENDERAREA_H
