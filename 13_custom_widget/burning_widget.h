/**
 * burning.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QSlider>
#include <QFrame>
#include "burning_scale.h"

class BurningWidget : public QFrame {

    Q_OBJECT

public:
    explicit BurningWidget(QWidget *parent = nullptr);
    int getCurrentWidth();

public slots:
    void valueChanged(int);

private:
    // Used to determine the slider value.
    int cur_width;
    BurningScale *widget;

    void initUI();
};


