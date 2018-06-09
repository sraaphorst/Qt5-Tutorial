/**
 * listwidget.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QListWidget>

class ListWidget : public QWidget {

    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);

private slots:
    void addItem();
    void renameItem();
    void removeItem();
    void sortItems();

private:
    QListWidget *lw;
};


