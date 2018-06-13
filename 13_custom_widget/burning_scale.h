/**
 * widget.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QFrame>

class BurningWidget;

class BurningScale : public QFrame {
public:
    explicit BurningScale(BurningWidget *parent);

protected:
    void paintEvent(QPaintEvent *e) override;
    void drawWidget(QPainter &qp);

private:
    BurningWidget *burning;

    static constexpr auto DISTANCE = 19;
    static constexpr auto LINE_WIDTH = 5;
    static constexpr auto DIVISIONS = 10;
    static constexpr auto FULL_CAPACITY = 700.0;
    static constexpr auto MAX_CAPACITY = 750.0;
    static constexpr auto PANEL_HEIGHT = 30;

    static const QColor redColor;
    static const QColor yellowColor;
    static const QColor grayColor;
    static const QStringList labels;
};


