/**
 * looping.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

/** NOTE: This contains the interesting foreach and forever loops of Qt. */
int main() {
    QTextStream out(stdout);

    QString str = "There are many stars.";

    foreach(auto qc, str)
        out << qc << " ";
    out << endl;

    for (auto qc: str)
        out << qc << " ";
    out << endl;

    for (QChar *it=str.begin(); it != str.end(); ++it)
        out << *it << " ";
    out << endl;

    for (auto i=0; i < str.size(); ++i)
        out << str[i] /** or str.at(i) */ << " ";
    out << endl;

    auto i = 0;
    forever {
        out << str.at(i) << " ";
        ++i;
        if (i == str.size()) break;
    };

    return 1;
}