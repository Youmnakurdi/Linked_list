#include <iostream>
#include "./scriptFiles/LinkedList.hpp"
using namespace std;

int main()
{
    LinkedList l({1, 2, 3, 4});
    LinkedList l1(l);
    LinkedList l2({5, 6, 7, 8});
    // l.afficher();
    // l2.afficher();
    // swap(l,l2);
    // l.afficher();
    // l2.afficher();

    bool x = (l == l1);
    bool y = (l == l2);
    cout << x << y;

    return 0;
}

