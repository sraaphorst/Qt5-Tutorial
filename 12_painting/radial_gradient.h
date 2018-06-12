/**
 * radial_gradient.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class RadialGradient : public QWidget {
public:
    RadialGradient(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    void doPainting();
};


