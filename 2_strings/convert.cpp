/**
 * convert.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out { stdout };

    QString s1 { "12" };
    QString s2 { "15" };
    out << s1.toInt() << ' ' << s2.toInt() << endl;

    /** NOTE: you can setNum with many bases: here I use 40 and 40000 in base 40 is p00. */
    QString s3, s4;
    int n1 = 30;
    int n2 = 40'000;
    out << s3.setNum(n1) << ' ' << s4.setNum(n2, 40) << endl;

    return 0;
}