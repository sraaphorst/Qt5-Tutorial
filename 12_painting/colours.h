/**
 * colours.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class Colours : public QWidget {
public:
    Colours(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    void doPainting();
};




