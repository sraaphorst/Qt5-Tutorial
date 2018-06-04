/**
 * file_write.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QFile>
#include <QTextStream>

int main() {
    QTextStream out{stdout};

    QString filename{"distros"};
    QFile file{filename};
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream fout(&file);
        fout << "Xubuntu" << endl
             << "Arch" << endl
             << "Debian" << endl
             << "Redhat" << endl
             << "Slackware" << endl;
    } else
        qWarning("Could not open file distros for writing");
    file.close();

    if (file.open(QIODevice::ReadOnly)) {
        while (!file.atEnd()) {
            out << file.readLine();
        }
    } else
        qWarning("Could not open file distros for reading");
    file.close();

    if (file.remove())
        out << "*** File deleted." << endl;
    else
        out << "Could not delete file." << endl;

    return 0;
}