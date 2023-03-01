#include "automatarenderarea.h"

AutomataRenderArea::AutomataRenderArea(QWidget *parent)
    : QWidget{parent}
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    color = QColor("magenta");
}

void AutomataRenderArea::paintEvent(QPaintEvent * /* event */)
{
    std::cout << "Painting\n";
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(color);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(1, 1, width() - 1, height() - 1));
}

void AutomataRenderArea::changeColor()
{
    color = QColor("green");
    this->repaint();
}
