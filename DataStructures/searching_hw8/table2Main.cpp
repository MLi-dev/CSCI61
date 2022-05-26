#include <iostream>
#include <fstream>

using namespace std;
#include "table2.h"

struct record{
    int key;
};
int main() {
    record r;
    r.key = 812;
    main_savitch_12B::table<record> t;
    t.insert(r);
    record r2;
    r2.key = 1;
    t.insert(r2);

}



