/**
 * init_datetime.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QDateTime>

int main() {
    QTextStream out(stdout);

    QDate d1 { 2015, 4, 12 };
    out << "The date is " << d1.toString() << endl;

    QDate d2 { 2015, 3, 4 };
    out << "The date is " << d2.toString(Qt::ISODate) << endl;

    QTime t1 { 17, 30, 5 };
    out << "The time is " << t1.toString() << endl;
    QTime t1_1 { t1.addSecs(55) };
    out << "The time was " << t1.toString() << " but is now " << t1_1.toString() << endl;

    QTime t2 { 9, 30 };
    out << "The time is " << t2.toString("hh:mm:ss.zzz") << endl;

    out << "The date and time are " << QDateTime::currentDateTime().toString(Qt::ISODateWithMs) << endl;
    out << "     In terms of UTC: " << QDateTime::currentDateTime().toUTC().toString(Qt::ISODateWithMs) << endl;

    /** Using a Date and Time to create a DateTime makes a copy of the Date and Time. */
    QDate d3 { 2018, 6, 2 };
    QTime t3 { 21, 0 };
    QDateTime dt1 { d3, t3 };
    out << "The date and time are " << dt1.toString() << endl;

    d3.setDate(2017, 6, 2);
    t3.setHMS(8, 0, 0);
    out << "The date and time are still " << dt1.toString() << endl;

    QDateTime dt2 { d3, t3 };
    out << "Now the date and time are " << dt2.toString("yyyy-MM-dd (dddd) h:mm AP") << endl;

    /** You can directly compare QDate, QTime, and QDateTime. */
    out << dt1.toString() << " >= " << dt2.toString() << " = " << (dt1 >= dt2) << endl;

    return 0;
}