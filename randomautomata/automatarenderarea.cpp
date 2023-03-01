#include "automatarenderarea.h"

AutomataRenderArea::AutomataRenderArea(QWidget *parent, int r, int c, std::vector<std::vector<int>> &arr)
    : QWidget{parent}, rows{r}, cols{c}
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    color = QColor("magenta");
    data_array = arr;
}

void AutomataRenderArea::paintEvent(QPaintEvent * /* event */)
{
    std::cout << "Painting\n";
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    int x,y,w,h;
    w = width() / cols;
    h = height() / rows;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            x = r * w;
            y = c * h;
            painter.fillRect(QRect(x, y, w, h), QBrush(colors[data_array[r][c]], Qt::SolidPattern));
        }
    }

}

void AutomataRenderArea::changeColor()
{
    color = QColor("green");
    this->repaint();
}
