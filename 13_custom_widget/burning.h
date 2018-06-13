/**
 * burning.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QSlider>
#include <QFrame>
#include "widget.h"

class Burning : public QFrame {

    Q_OBJECT

public:
    Burning(QWidget *parent = nullptr);
    int getCurrentWidth();

public slots:
    void valueChanged(int);

private:
    QSlider *slider;
    Widget *widget;

    // Used to determine the slider value.
    int cur_width;

    void initUI();
};


