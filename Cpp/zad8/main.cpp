#include <iostream>
#include "bst.h"

using namespace std;
using namespace structures;

int main() {
    BST<int> b;
    b.insert(10);
    b.insert(12);
    b.insert(1);
    b.insert(-1);
    b.insert(30);

    b.print();

    cout << endl << "search 10: ";
    cout << b.search(10) << endl;
    cout << "search 12: ";
    cout << b.search(12) << endl;
    cout << "search 1: ";
    cout << b.search(1) << endl;
    cout << "search -1: ";
    cout << b.search(-1) << endl;
    cout << "search 29: ";
    cout << b.search(29) << endl;
    cout << "search 30: ";
    cout << b.search(30) << endl;

    return 0;
}
