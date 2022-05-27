#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
    public:
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
            printTree(tree3, adder + 1);
        }
    }
    private:
    Node<T>* tree;
};