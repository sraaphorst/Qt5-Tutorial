/**
 * listwidget.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <algorithm>
#include "listwidget.h"

#include <QApplication>
#include <QInputDialog>
#include <QPushButton>
#include <QVBoxLayout>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);

    QStringList titles {
        "The Omen", "The Exorcist", "Notes on a Scandal", "Fargo", "Capote"
    };

    lw = new QListWidget;
    lw->setSelectionMode(QListWidget::SingleSelection);
    lw->addItems(titles);

    auto add = new QPushButton("Add");
    auto rename = new QPushButton("Rename");
    auto remove = new QPushButton("Remove");
    auto removeAll = new QPushButton("Remove All");
    auto sort = new QPushButton("Sort");

    auto vbox = new QVBoxLayout;
    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeAll);
    vbox->addWidget(sort);
    vbox->addStretch(1);

    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    connect(add, &QPushButton::clicked, this, &ListWidget::addItem);
    connect(rename, &QPushButton::clicked, this, &ListWidget::renameItem);
    connect(remove, &QPushButton::clicked, this, &ListWidget::removeItem);
    connect(removeAll, &QPushButton::clicked, lw, &QListWidget::clear);

    // QListWidget::sortItems, oddly, is not a slot.
    connect(sort, &QPushButton::clicked, this, &ListWidget::sortItems);
}

void ListWidget::addItem() {
    auto c_text = QInputDialog::getText(this, "Item", "Enter new item");
    auto s_text = c_text.simplified();

    if (!s_text.isEmpty()) {
        lw->addItem(s_text);
        auto r = lw->count() - 1;
        lw->setCurrentRow(r);
    }
}

void ListWidget::renameItem() {
    auto curitem = lw->currentItem();
    auto r = lw->row(curitem);
    auto c_text = curitem->text();
    auto r_text = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, c_text);
    auto s_text = r_text.simplified();

    if (!s_text.isEmpty()) {
        lw->item(r)->setText(s_text);
    }
}

void ListWidget::removeItem() {
    auto r = lw->currentRow();
    if (r != -1) {
        auto item = lw->takeItem(r);
        delete item;
    }
}

void ListWidget::sortItems() {
    auto curitem = lw->currentItem();
    lw->sortItems();
    auto r = lw->row(curitem);
    lw->setCurrentRow(r);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ListWidget window;
    window.setWindowTitle("QListWidget");
    window.show();

    return app.exec();
}