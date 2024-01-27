#include "log.hpp"

Log lg;

int main() {
    lg.changeMode(Onefile);
    for (int i = 0; i < 5; i++)
        lg(Warning, "%s %d", "logtxt:", i);
    return 0;
}