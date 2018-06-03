/**
 * date_validity.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QDate>

int main() {
    QTextStream out { stdout };

    QList<QDate> dates {
        QDate(2016,  5, 11),
        QDate(2015,  8,  1),
        QDate(2015,  2, 30)
    };

    int i=1;
    for(auto d : dates) {
        if (d.isValid())
            out << d.toString() << " is a valid date." << endl;
        else
            out << "Date #" << i << " is not a valid date." << endl;
        ++i;
    }

    return 0;
}