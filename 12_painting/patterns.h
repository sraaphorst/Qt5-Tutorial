/**
 * patterns.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class Patterns : public QWidget {
public:
    Patterns(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    void doPainting();
};




