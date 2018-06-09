/**
 * dirs.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <vector>

#include <algorithm>
#include <QDir>
#include <QTextStream>
#include <QMap>
#include <QVector>

int main() {
    QTextStream out{stdout};

    /***** CREATING AND CHECKING DIRECTORIES *****/
    QDir dir;
    if (dir.mkdir("mydir"))
        out << "mydir successfully created" << endl;

    dir.mkdir("mydir2");
    if (dir.exists("mydir2"))
        dir.rename("mydir2", "newdir1");

    dir.mkpath("temp/newdir");

    /***** SPECIAL PATHS *****/
    QMap<QString, QString(*)(void)> paths {
            {QString("Current path"), QDir::currentPath},
            {QString("Home path"), QDir::homePath},
            {QString("Temporary path"), QDir::tempPath},
            {QString("Root path"), QDir::rootPath}
    };


    const auto &ref = paths.keys();
    QVector< int > lengths;
    lengths.resize(ref.size());
    std::transform(ref.begin(), ref.cend(), lengths.begin(), [](auto f) { return f.size(); });
    const auto maxLength = *std::max_element(lengths.cbegin(), lengths.cend());

    for (auto k: paths.keys())
        out << k.rightJustified(maxLength, ' ') << ": " << paths[k]() << endl;


    return 0;
}