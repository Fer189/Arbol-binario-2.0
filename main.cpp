#include "Node.h"
#include <iostream>
using namespace std;



void addNode(Node *&tree, int value, char position) {
    Node *newNode = new Node(value);
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
                Node* nextBranch = tree->getLeft();
                addNode(nextBranch, value, position); 
            }
            break;
            case 'r':
            if(tree->getRight() == nullptr) {
                tree->setRight(newNode);
            }
            else {
                Node* nextBranch = tree->getRight();
                addNode(nextBranch, value, position); 
            }
            break;
        }
    }
}


int main() {
    Node *tree = nullptr;
    addNode(tree, 9, 'l');
    addNode(tree, 8, 'l');
    addNode(tree, 7, 'l');
    cout << tree->getValue() << endl;
    cout << tree->getLeft()->getValue() << endl;
    cout << tree->getLeft()->getLeft()->getValue() << endl;
    return 0;
}