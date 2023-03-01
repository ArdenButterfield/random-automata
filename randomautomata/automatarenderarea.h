#ifndef AUTOMATARENDERAREA_H
#define AUTOMATARENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <iostream>

class AutomataRenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit AutomataRenderArea(QWidget *parent = nullptr);
    void changeColor();
protected:
    void paintEvent(QPaintEvent *event) override;
    QColor color;
signals:

};

#endif // AUTOMATARENDERAREA_H
