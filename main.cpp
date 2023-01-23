#include <iostream>
#include "BinaryTree.h"
using  namespace std;
int main() {
    auto tree = new BinaryTree<int>();
    tree->Insert(8);
    tree->Insert(3);
    tree->Insert(10);
    tree->Remove(8);
    return 0;
}
