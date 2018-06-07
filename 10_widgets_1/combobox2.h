/**
 * combobox2.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QComboBox>
#include <QLabel>
#include <QWidget>

class ComboBoxEx2 : public QWidget {

    Q_OBJECT

public:
    ComboBoxEx2(QWidget *parent = nullptr);

private:
    QLabel *label;
    QComboBox *combo;

private slots:
    void setLabel(int idx);
};




