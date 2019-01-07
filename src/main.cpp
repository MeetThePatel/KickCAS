#include <iostream>
#include "../include/parser.h"

using namespace std;

int main() {
    parseIntoStringVector("(+ 2 (- 3 5))");
    _Parser_CPP_Assertions();
    return 0;
}
