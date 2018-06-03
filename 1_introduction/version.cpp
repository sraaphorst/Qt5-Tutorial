/**
 * version.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QtCore>
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Qt version: " << qVersion() << std::endl;
    return 0;
}