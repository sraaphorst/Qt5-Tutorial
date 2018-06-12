/**
 * donut.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QResizeEvent>
#include <QWidget>

class Donut : public QWidget {

    Q_OBJECT

public:
    Donut(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;

private:
    void doPainting();
};


