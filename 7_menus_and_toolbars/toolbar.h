/**
 * Toolbar.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QApplication>
#include <QMainWindow>

class ToolBar : public QMainWindow {

    Q_OBJECT

public:
    ToolBar(QWidget *parent = nullptr);

private slots:
    void newFileClicked();
    void openFileClicked();
};




