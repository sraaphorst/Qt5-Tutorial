/**
 * statusbar.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QMainWindow>

class StatusBar : public QMainWindow {

    Q_OBJECT

public:
    StatusBar(QWidget *parent = nullptr);

private slots:
    void OnOkPressed();
    void OnApplyPressed();
};




