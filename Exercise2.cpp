#include "BinarySearchTree.h"
#include <iostream>

int main() {
    BinarySearchTree bst;

    std::cout << "Binary Search Tree: Level-Order Traversal Demonstration\n" << std::endl;

    std::cout << "Inserting values into the tree: 10, 5, 15, 7" << std::endl;
    bst.insert(bst.getroot(), 10);
    bst.insert(bst.getroot(), 5);
    bst.insert(bst.getroot(), 15);
    bst.insert(bst.getroot(), 7);

    std::cout << "\nTree structure after insertions:\n";
    std::cout << bst.printTree();

    std::cout << "\nPerforming level-order traversal:\n";
    std::string traversalResult = bst.levelOrderTraverse(bst.getroot());
    std::cout << (traversalResult.empty() ? "Tree is empty." : traversalResult) << std::endl;

    return 0;
}
