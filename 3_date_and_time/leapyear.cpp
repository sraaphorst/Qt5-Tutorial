/**
 * leapyear.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QDate>

int main() {
    QTextStream out(stdout);

    QList<int> years { 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020 };
    years << 2021 << 2022 << 2023 << 2024;

    for (auto year: years)
        out << QString("Year %1 is %2a leap year").arg(year).arg(QDate::isLeapYear(year) ? "" : "not") << endl;

    return 0;
}