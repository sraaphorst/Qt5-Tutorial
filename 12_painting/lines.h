/**
 * lines.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

class Lines : public QWidget {
public:
    Lines(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawLines(QPainter *qp);
};




