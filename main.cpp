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

template<typename T>
void printTree(Node<T> *&tree, int adder) {
    if(tree == nullptr) {
        return;
    }
    else {
        Node<T>* tree2 = tree->getRight();
        printTree(tree2, adder + 1);
        for(int i = 0; i < adder; i++) {
            cout << "   ";
        }
        cout << tree->getValue() << endl;
        Node<T>* tree3 = tree->getLeft();
        printTree<T>(tree3, adder + 1);
    }
}

int main() {
    Node<int> *tree = nullptr;
    addNode(tree, 10);
    addNode(tree, 2);
    addNode(tree, 5);
    addNode(tree, 7);
    addNode(tree, 9);
    addNode(tree, 4);
    addNode(tree, 12);
    addNode(tree, 11);
    addNode(tree, 3);
    int adder = 0;
    printTree(tree, adder);
    return 0;
}