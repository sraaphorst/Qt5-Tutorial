/**
 * linear_gradients.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class LinearGradients : public QWidget {
public:
    LinearGradients(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    void doPainting();
};


