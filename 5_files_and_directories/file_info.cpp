/**
 * file_info.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QFileInfo>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QTextStream out{stdout};

    if (argc != 2) {
        qWarning("Usage: file_info filename");
        return 1;
    }

    QString filename{argv[1]};
    QFileInfo fileInfo{filename};
    QString owner{fileInfo.owner()};
    QString group{fileInfo.group()};
    out << "Owner: " << owner << endl;
    out << "Group: " << group << endl;

    return 0;
}