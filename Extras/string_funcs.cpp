/**
 * string_funcs.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out { stdout };

    QString str1 { "   There  is    lots of \t whitespace here   "};
    out << "original:   " << '"' << str1 << '"' << endl;
    out << "trimmed:    " << '"' << str1.trimmed() << '"' << endl;
    out << "simplified: " << '"' << str1.simplified() << '"' << endl;

    return 0;
}