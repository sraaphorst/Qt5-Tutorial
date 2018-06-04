/**
 * myvector.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <algorithm>
#include <sstream>

#include <QList>
#include <QMap>
#include <QSet>
#include <QTextStream>
#include <QVector>

template<typename C>
QString containerString(const C& c) {
    QString s;
    QTextStream ostr(&s);
    ostr << '[';
    int i=1;
    for (auto e: c) {
        ostr << e;
        if (i < c.size())
            ostr << ", ";
        ++i;
    }
    ostr << ']';
    return ostr.readAll();
}

int main() {
    QTextStream out{stdout};

    /***** QVECTOR *****/
    QVector<int> vals{1, 2, 3, 4, 5};
    out << "The vector is " << containerString(vals) << endl;
    out << "\tThe size of the vector is " << vals.size() << endl;
    out << "\tfront() = first() = " << vals.first() << ", back() = last() = " << vals.last() << endl;

    vals.first() = 6;
    vals.last()  = 0;
    out << "\tfirst is now " << vals.first() << ", last is now " << vals.last() << endl;

    vals.prepend(-1);
    vals.append(7);
    out << "After prepending -1 and appending 7: " << containerString(vals) << endl;
    out << endl;


    /***** QLIST *****/
    QList<QString> authors{"Balzac", "Tolstoy", "Gulbranssen", "London"};
    out << "The list is " << containerString(authors) << endl;
    authors << "Galsworthy" << "Sienkiewicz";
    QList<QString> moreAuthors{"Martin", "Tolkein", "Eddings"};
    authors << moreAuthors;
    out << "The list is " << containerString(authors) << endl;
    std::sort(authors.begin(), authors.end());
    out << "The sorted list is " << containerString(authors) << endl;
    out << endl;

    /***** QSTRINGLIST *****/
    QString string = "coin, book, 2 girls, 1 cup, clock, bookmark";
    QStringList items {string.split(",")};
    QStringListIterator it(items);
    while (it.hasNext())
        out << it.next().trimmed() << endl;
    out << endl;


    /***** QSET *****/
    QSet<QString> cols1 {"yellow", "red", "blue"};
    QSet<QString> cols2 {"blue", "pink", "orange"};
    out << "cols1 has size " << cols1.size() << ": " << containerString(cols1) << endl;
    cols1.insert("brown");
    out << "cols1 now has size " << cols1.size() << ": " << containerString(cols1) << endl;
    cols1.unite(cols2);
    out << "cols1 has size " << cols1.size() << ": " << containerString(cols1) << endl;
    QList<QString> lcols = cols1.toList();
    std::sort(lcols.begin(), lcols.end());
    out << "Sorted: " << containerString(lcols) << endl;
    out << endl;


    /***** QMAP *****/
    // By default, iterating over a QMap is the same as iterating over its keys.
    QMap<QString, int> inventory {{"coins", 3}, {"books", 5}};
    inventory.insert("bottles", 7);
    out << "Keys: " << containerString(inventory.keys());
    out << "Values: " << containerString(inventory.values());

    QMapIterator<QString, int> iter(inventory);
    while (iter.hasNext()) {
        iter.next();
        out << iter.key() << ": " << iter.value() << endl;
    }
    out << "dead babies: " << inventory.value("dead babies", 0) << endl;

    return 0;
}