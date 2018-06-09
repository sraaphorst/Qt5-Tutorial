/**
 * basic.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString a { "love" };
    a.append(" Qt5");
    a.prepend("I ");

    out << a << endl;
    out << "The a string has " << a.count() << " characters" << endl;

    out << a.toUpper() << endl;
    out << a.toLower() << endl;

    return 0;
}