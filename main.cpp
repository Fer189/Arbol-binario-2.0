#include "Node.h"
#include <iostream>
using namespace std;


template <typename T>
void addNode(Node<T> *&tree, int value, char position) {
    Node<T> *newNode = new Node<T>(value);
    if(tree == nullptr) {
        tree = newNode;
    }
    else {
        //Funcion recursiva para añadir un nodo hijo si es que ya existe uno en la posicion seleccionada
        switch(position) {
            case 'l':
            if(tree->getLeft() == nullptr) {
                tree->setLeft(newNode);
            }
            else {
                Node<T>* nextBranch = tree->getLeft();
                addNode(nextBranch, value, position); 
            }
            break;
            case 'r':
            if(tree->getRight() == nullptr) {
                tree->setRight(newNode);
            }
            else {
                Node<T>* nextBranch = tree->getRight();
                addNode(nextBranch, value, position); 
            }
            break;
        }
    }
}


int main() {
    Node<char> *tree = nullptr;
    addNode(tree, 'o', 'l');
    addNode(tree, 'i', 'l');
    addNode(tree, 'q', 'l');
    Node<int> *tree2 = nullptr;
    addNode(tree2, 1, 'l');
    addNode(tree2, 2, 'l');
    addNode(tree2, 3, 'l');
    cout << tree->getValue() << endl;
    cout << tree->getLeft()->getValue() << endl;
    cout << tree->getLeft()->getLeft()->getValue() << endl;
    cout << tree2->getValue() << endl;
    cout << tree2->getLeft()->getValue() << endl;
    cout << tree2->getLeft()->getLeft()->getValue() << endl;
    return 0;
}