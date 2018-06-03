/**
 * logging.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QtDebug>

// More info here: http://doc.qt.io/qt-5/debug.html
int main() {
    qDebug()    << "This is a debugging comment.";
    qInfo()     << "This is an info comment.";
    qWarning()  << "This is a warning comment.";
    qCritical() << "This is a critical comment.";

    /** NOTE: qFatal is terminal and ends execution immediately! */
    qFatal("This is a fatal comment.");
}