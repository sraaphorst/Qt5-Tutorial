/**
 * letters.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

struct counts {
    int digits = 0;
    int letters = 0;
    int spaces = 0;
    int puncts = 0;
};

counts count(const QString &s) {
    counts count;

    for (auto c: s) {
        if (c.isDigit())  ++count.digits;
        if (c.isLetter()) ++count.letters;
        if (c.isSpace())  ++count.spaces;
        if (c.isPunct())  ++count.puncts;
    }

    return count;
}

int main() {
    QTextStream out { stdout };
    QTextStream in { stdin };

    QString response { "The text contains %1 digits, %2 characters, %3 spaces, and %4 punctuation marks." };
    forever {
        out << "Enter some text:" << endl;

        QString input { in.readLine() };
        if (input.isEmpty()) break;

        auto [d,l,s,p] = count(input);
        out << response.arg(d).arg(l).arg(s).arg(p) << endl;
    };

    return 0;
}