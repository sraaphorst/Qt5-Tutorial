/**
 * file_read.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QFileInfo>
#include <QtDebug>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QTextStream out{stdout};

    if (argc != 2) {
        qInfo() << "Usage: " << argv[0] << " file";
        return 1;
    }

    QString filename {argv[1]};
    QFile f{filename};
    if (!f.exists()) {
        // Why is this so horrible?
        auto msg = QString("%1 does not exist").arg(filename);
        qFatal(msg.toStdString().c_str());
    }

    QFileInfo fileInfo(filename);
    auto size = fileInfo.size();
    out << "The size is: " << size << " bytes according to QFileInfo." << endl;
    out << "The size if: " << f.size() << " bytes according to QFile." << endl;

    if (!f.open(QIODevice::ReadOnly)) {
        qFatal("Cannot open file for reading");
    }

    // Create an input stream.
    QTextStream in(&f);
    auto i = 0;
    while (!in.atEnd()) {
        auto line = in.readLine();
        out << i << ": " << line << endl;
        ++i;
    }

    return 0;
}