#include "BinarySearchTree.h"
#include <iostream>

int main() {
    BinarySearchTree bst;

    std::cout << "Binary Search Tree: Operations Demonstration\n" << std::endl;

    std::cout << "Inserting values: 10, 5, 15, 7" << std::endl;
    bst.insert(bst.getroot(), 10);
    bst.insert(bst.getroot(), 5);
    bst.insert(bst.getroot(), 15);
    bst.insert(bst.getroot(), 7);

    std::cout << "\nCurrent Tree Structure:" << std::endl;
    std::cout << bst.printTree();

    int searchKey = 7;
    std::cout << "\nSearching for value " << searchKey << "..." << std::endl;
    if (bst.search(bst.getroot(), searchKey)) {
        std::cout << searchKey << " exists in the tree." << std::endl;
    } else {
        std::cout << searchKey << " does not exist in the tree." << std::endl;
    }

    int deleteKey = 5;
    std::cout << "\nDeleting value " << deleteKey << "..." << std::endl;
    bst.deleteNode(bst.getroot(), deleteKey);

    std::cout << "\nTree Structure After Deletion:" << std::endl;
    std::cout << bst.printTree();

    return 0;
}
