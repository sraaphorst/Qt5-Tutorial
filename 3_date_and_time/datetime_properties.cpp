/**
 * weekday.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <algorithm>
#include <boost/range/irange.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <QTextStream>
#include <QDate>
#include <QVector>

int main() {
    QTextStream out { stdout };

    QDate d { QDate::currentDate() };
    int wd = d.dayOfWeek();

    auto fmts = QList { QDate::shortDayName, QDate::longDayName };
    std::for_each(fmts.begin(), fmts.end(),
                  [&out, wd](auto fmt) { out << "Today is " << fmt(wd, QDate::DateFormat) << '.' << endl; });


    // A foray into ridiculousness, just for fun, to demonstrate QDate::longMonthName.
    const int year = 2001;
    out << "Year " << year << " had " << QDate(year, 1, 1).daysInYear() << " days:" << endl;

    QVector<QString> monthNames(12);
    auto monthNums = boost::irange(1, 13);
    std::transform(monthNums.begin(), monthNums.end(), monthNames.begin(),
                   [](auto i) { return QDate::longMonthName(i, QDate::DateFormat); });
    std::for_each(boost::make_zip_iterator(boost::make_tuple(monthNums.begin(), monthNames.begin())),
                  boost::make_zip_iterator(boost::make_tuple(monthNums.end(), monthNames.end())),
                  [&out, year](auto pr) {
        int mi;
        QString mn;
        boost::tie(mi, mn) = pr;
        out << "\tMonth " << mi << " was " << mn << " and had " << QDate(year, mi, 1).daysInMonth() << " days." << endl;
    });

    return 0;
}