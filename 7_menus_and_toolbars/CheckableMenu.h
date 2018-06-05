/**
 * CheckableMenu.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QApplication>
#include <QMainWindow>

class CheckableMenu : public QMainWindow {

    Q_OBJECT

public:
    CheckableMenu(QWidget *parent = 0);

private slots:
            void toggleStatusBar();

private:
    QAction *viewst;
};