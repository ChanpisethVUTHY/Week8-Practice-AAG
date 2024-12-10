#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node*& getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
        // Base Cases: root is null or key 
        // is present at root
        if (root==NULL || root ->data==key) return root;
        // Key is greater than root's key
        if(root->data<key) return search(root->right, key);
         // Key is smaller than root's key
        return search(root->left,key);
    }
    void insert(Node* &root, int newValue) {
    // If the tree is empty, create a new node and assign it to root
        if (root == NULL) {
            root = new Node(newValue);    
            return;
        }

    // If the value is already present in the tree, do nothing
    if (root->data == newValue) 
        return;

    // If the value to be inserted is greater than the node's value,
    // insert it in the right subtree
    if (root->data < newValue) 
        insert(root->right, newValue);
    
    // If the value to be inserted is smaller than the node's value,
    // insert it in the left subtree
    else 
        insert(root->left, newValue);
    }
    void deleteNode(Node*& root, int value) {
    // Base case: if the tree is empty
    if (root == nullptr)
        return;

    // Recur down the tree to find the node to delete
    if (value < root->data) {
        deleteNode(root->left, value);
    } else if (value > root->data) {
        deleteNode(root->right, value);
    } else {
        // Node to be deleted is found

        // Case 1: Node has no child or only one child (right)
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        // Case 2: Node has only one child (left)
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        // Case 3: Node has two children
        else {
            Node* succ = getSuccessor(root->right);
            root->data = succ->data; // Replace root's data with successor's data
            deleteNode(root->right, succ->data); // Delete the successor
        }
    }
}

// Helper function to find the in-order successor
Node* getSuccessor(Node* node) {
    Node* current = node;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

    //exercise 2
    std::string levelOrderTraverse(Node* root) {
    if (root == nullptr)
        return "";

    std::string result = "";
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();

        for (int i = 0; i < nodeCount; i++) {
            Node* node = q.front();
            q.pop();

            // Append the node's value to the result string
            result += std::to_string(node->data) + " ";

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    // Remove the trailing space and return the result
    if (!result.empty())
        result.pop_back();
    
    return result;
    }

    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

};

#endif // BINARYTREE_H
