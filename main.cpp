#include "Node.h"
#include <iostream>
using namespace std;


template <typename T>
void addNode(Node<T> *&tree, int value) {
    Node<T> *newNode = new Node<T>(value);
    if(tree == nullptr) {
        tree = newNode;
    }
    else {
        if(value < tree->getValue()) {
            if(tree->getLeft() == nullptr) {
                tree->setLeft(newNode);
            }
            else {
                Node<T>* nextBranch = tree->getLeft();
                addNode(nextBranch, value);
            }
        }
        else {
            if(tree->getRight() == nullptr) {
                tree->setRight(newNode);
            }
            else {
                Node<T>* nextBranch = tree->getRight();
                addNode(nextBranch, value);
            }
        }
    }
}


int main() {
    Node<int> *tree = nullptr;
    addNode(tree, 1);
    addNode(tree, 2);
    addNode(tree, 3);
    return 0;
}