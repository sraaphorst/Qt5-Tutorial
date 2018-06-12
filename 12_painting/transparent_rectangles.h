/**
 * transparent_rectangles.h
 *
 * By Sebastian Raaphorst, 2018.
 *
 * Playing with alpha compositing.
 */

#pragma once

#include <QWidget>

class TransparentRectangles : public QWidget {
public:
    TransparentRectangles(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    void doPainting();
};




