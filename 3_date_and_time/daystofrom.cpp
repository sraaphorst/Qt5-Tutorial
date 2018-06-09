/**
 * daystofrom.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QDate>
#include <QTime>

int main() {
    QTextStream out { stdout };

    QDate dt { 2015, 5, 11 };
    auto nd1 = dt.addDays(-10);
    auto nd2 = dt.addDays(10);
    out << nd1.toString() << " < " << dt.toString() << " < " << nd2.toString() << endl;

    QDate cur { QDate::currentDate() };
    auto year = (cur.month() > 9 || (cur.month() == 9 && cur.day() > 28)) ? cur.year() + 1 : cur.year();
    QDate nextBday { year, 9, 28 };
    out << "There are " << cur.daysTo(nextBday) << " days until my birthday." << endl;

    QDate lastBday { year-1, 9, 28 };
    out << "There have been " << -cur.daysTo(lastBday) << " days since my last birthday." << endl;

    // Julian days are numbered, and make it much easier to do calculations.
    QDate bd { 1977, 9, 28 };
    out << "I have been alive for " << cur.toJulianDay() - bd.toJulianDay() + 1 << " days." << endl;
    return 0;
}