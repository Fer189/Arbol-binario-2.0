#pragma once

class Node {
    public:
    Node(int value = 0, Node* left = nullptr, Node* right = nullptr) {
        this -> left = left;
        this -> right = right;
        this -> value = value;
    }
    void setLeft(Node* left) {
        this -> left = left;
    }
    void setRight(Node* right) {
        this -> right = right;
    }
    void setValue(int value) {
        this -> value = value;
    }
    Node* getLeft() {
        return this -> left;
    }
    Node* getRight() {
        return this -> right;
    }
    int getValue() {
        return this -> value;
    }
    private:
    Node* left;
    Node* right;
    int value;
};