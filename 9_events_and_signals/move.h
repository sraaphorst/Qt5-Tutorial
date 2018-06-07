/**
 * move.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class Move : public QWidget {
public:
    Move(QWidget *parent = nullptr);

protected:
    // Triggered once the component moves!
    void moveEvent(QMoveEvent *e) override;
};




