#include "automatarenderarea.h"

AutomataRenderArea::AutomataRenderArea(QWidget *parent, int r, int c, std::vector<std::vector<int>> &g)
    : QWidget{parent}, rows{r}, cols{c}
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    grid = g;
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
            painter.fillRect(QRect(x, y, w, h), QBrush(colors[grid[r][c]], Qt::SolidPattern));
        }
    }

}
