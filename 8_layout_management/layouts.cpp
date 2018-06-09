#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Horizontal layout with 3 buttons
    auto hLayout = new QHBoxLayout;
    auto b1 = new QPushButton("A");
    auto b2 = new QPushButton("B");
    auto b3 = new QPushButton("C");
    hLayout->addWidget(b1);
    hLayout->addWidget(b2);
    hLayout->addWidget(b3);

    // Vertical layout with 3 buttons
    auto vLayout = new QVBoxLayout;
    auto b4 = new QPushButton("D");
    auto b5 = new QPushButton("E");
    auto b6 = new QPushButton("F");
    vLayout->addWidget(b4);
    vLayout->addWidget(b5);
    vLayout->addWidget(b6);

    // Outer Layer
    auto mainLayout = new QVBoxLayout;

    // Add the previous two inner layouts
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);

    // Create a widget
    auto w = new QWidget;

    // Set the outer layout as a main layout 
    // of the widget
    w->setLayout(mainLayout);

    // Window title
    w->setWindowTitle("layouts");

    // Display
    w->show();

    // Event loop
    return app.exec();
}