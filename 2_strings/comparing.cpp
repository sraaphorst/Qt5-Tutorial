/**
 * comparing.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#define STR_EQUAL 0

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString a = "Rain";
    QString b  = "rain";
    QString c = "rain\n";

    if (QString::compare(a, b) == STR_EQUAL)
        out << "a, b are equal" << endl;
    else
        out << "a, b are not equal" << endl;

    out << "case insensitive ";
    if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL)
        out << "a, b are equal" << endl;
    else
        out << "a,b are not equal" << endl;

    if (b.compare(c) == STR_EQUAL)
        out << "b, c are equal" << endl;
    else
        out << "b, c are not equal" << endl;

    c.chop(1);
    out << "after removing the new line character ";
    if (c.compare(b) == STR_EQUAL)
        out << "b, c are equal" << endl;
    else
        out << "b, c are not equal";

    return 0;
}