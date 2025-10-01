#include "q1_part2.h"

int main()                                                                                     
{
    ArrayStack a1;
    a1.push(1);
    a1.push(2);
    a1.push(3);
    a1.display();
    a1.pop();
    a1.peek();
    a1.isempty();

    a1.display();

    return 0;
}