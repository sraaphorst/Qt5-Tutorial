/**
 * substrings.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString str = "The night train";
    out << str.right(5) << endl;
    out << str.left(9) << endl;
    out << str.mid(4,5) << endl; /** start at pos 4 and take 5 chars */

    QString str2("The big apple");
    QStringRef sub(&str2, 0, 7);
    out << sub.toString() << endl;

    return 0;
}