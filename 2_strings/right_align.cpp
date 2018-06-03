/**
 * right_align.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <algorithm>
#include <vector>
#include <boost/range/combine.hpp>

#include <QTextStream>

int main() {
    QTextStream out { stdout };

    std::vector< QString > fields { "Name:", "Occupation:", "Residence:", "Marital status:" };
    std::vector< int > lengths(fields.size());
    std::transform(fields.cbegin(), fields.cend(), lengths.begin(), [](auto f) { return f.size(); });
    auto width = *std::max_element(lengths.cbegin(), lengths.cend());

    std::vector< QString > person { "Sebastian", "Software Developer", "La Serena, Chile", "Married" };

    // When you use boost::combine, it doesn't create a normal tuple, so you still have to divide by using
    // boost::tie.
    QString f, v;
    for (auto tup : boost::combine(fields, person)) {
        boost::tie(f, v) = tup;
        out << f.rightJustified(width, ' ') << ' ' << v << endl;
    }

    return 0;
}