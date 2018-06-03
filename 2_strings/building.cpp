/**
 * building.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString s1 = "There are %1 white roses";
    int n = 12;
    out << s1.arg(n) << endl;

    QString s2 = "The tree is %1 m high";
    double h = 5.65;
    out << s2.arg(h) << endl;

    QString s3 = "We have %1 %2 and %3 %4";
    out << s3.arg(12).arg("lemons").arg(4).arg("oranges") << endl;

    return 0;
}