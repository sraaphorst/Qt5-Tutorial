/**
 * length.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString strs[] { "Eagle", "Eagle\n", "Eagle ", "орел"};
    for (auto s: strs) {
        out << s << " has length " << s.length() << endl << endl;
    }

    return 0;
}