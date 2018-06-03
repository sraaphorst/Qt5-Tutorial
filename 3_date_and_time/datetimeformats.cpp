/**
 * datetimeformats.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <algorithm>

int main() {
    QTextStream out { stdout };

    QList<Qt::DateFormat> dtfs {
            Qt::TextDate, Qt::ISODate, Qt::SystemLocaleShortDate, Qt::SystemLocaleLongDate,
            Qt::DefaultLocaleShortDate, Qt::DefaultLocaleLongDate, Qt::SystemLocaleDate, Qt::LocaleDate
    };

    /***** DATES *****/
    QDate cd { QDate::currentDate() };

    auto datePrinter = [&out, &cd](auto df) {
        out << "Today is " << cd.toString(df) << endl;
    };

    std::for_each(dtfs.begin(), dtfs.end(), datePrinter);

    QList<QString> custom_dfs { "yyyy-MM-dd", "yy/M/dd", "d. M. yyyy", "d-MMMM-yyyy" };
    std::for_each(custom_dfs.begin(), custom_dfs.end(), datePrinter);


    /***** TIMES *****/
    QTime ct { QTime::currentTime() };

    auto timePrinter = [&out, &ct](auto tf) {
        out << "The time is " << ct.toString(tf) << endl;
    };

    std::for_each(dtfs.begin(), dtfs.end(), timePrinter);

    QList<QString> custom_tfs { "hh:mm:ss.zzz", "h:m:s a", "H:m:s A", "h:m AP" };
    std::for_each(custom_tfs.begin(), custom_tfs.end(), timePrinter);

    return 0;
}