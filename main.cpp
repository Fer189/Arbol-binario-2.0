#include "Node.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;
Node<int>* tree1 = nullptr;
BinaryTree<int> binaryTree;

void menu() {
    int adder = 0;
    int input = 0;
    int value;
    do {
        cout << "1. Ingresar un nodo" << endl;
        cout << "2. Imprimir arbol binario" << endl;
        cout << "3. Salir" << endl;
        cin >> input;
        switch(input) {
            case 1:
            cout << "Ingrese un valor: " << endl;
            cin >> value;
            binaryTree.addNode(tree1, value);
            system("cls");
            break;
            case 2:
            system("cls");
            binaryTree.printTree(tree1, adder);
            system("pause");
            break;
        }
    }
    while(input != 3);
}

int main() {
    menu();
    return 0;
}