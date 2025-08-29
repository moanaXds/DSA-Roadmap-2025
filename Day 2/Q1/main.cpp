#include "vector.h"
#include <string>
using namespace std;

int main() {
    // TODO: Create three Vector objects of int, float, and string types
    Vector <int> V1(1);
    Vector <float> V2(1.1);
    Vector <string> V3;

    // and test them
    V1.push_back(1);
    V2.push_back(1);
    V3.push_back("1");

    V1.push_front(1);
    V2.push_front(2);
    V3.push_front("3");

    V1.display();
    V2.display();
    V3.display();

    return 0;
}

