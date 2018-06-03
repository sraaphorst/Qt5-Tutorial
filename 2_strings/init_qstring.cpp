/**
 * init_qstring.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>

int main() {
    QTextStream out(stdout);

    QString str1 = "With equals char[]";
    out << str1 << endl;

    QString str2("With constructor");
    out << str2 << endl;

    QString str3 { "With initializer_list" };
    out << str3 << endl;

    std::string s1 = "With equals std::string to c_str";
    QString str4 = s1.c_str();
    out << str4 << endl;

    // This one doesn't work.
//    std::string s2 = "With equals std::string";
//    QString str5 = s2;
//    out << str5 << endl;

    std::string s3 = "QString::fromLatin1";
    QString str6 = QString::fromLatin1(s3.data(), s3.size());
    out << str6 << endl;

    char s4[] = "From constructor with explicit char[]";
    QString str7(s4);
    out << str7 << endl;

    return 0;
}