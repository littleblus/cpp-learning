#include "bitset.h"
#include <iostream>

using namespace std;
using blus::bitset;

int main() {
    // 01011
    blus::bitset<80> foo;
    foo.set(1);
    foo.set(3);
    foo.set(4);

    cout << "foo contains:\n";
    cout << std::boolalpha;
    for (std::size_t i = 0; i < foo.size(); ++i)
        std::cout << foo.test(i) << '\n';
    cout << foo.count() << endl;
    foo.reset(4);
    cout << foo.count() << endl;

    return 0;
}