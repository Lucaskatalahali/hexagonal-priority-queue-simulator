/**
* @file         BST.hpp
* @description  BST veri yapısını ve öncelik hesaplama (height) ve düğüm dolaşımı (postOrder) gibi gerekli metotlarını tanımlar.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef BST_HPP
#define BST_HPP

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right);
};

class BST{
private:
    Node* root;
    void searchAndAdd(Node*& subNode, int data);
    int height(Node* subNode);
    void postOrder(Node* subNode);
    void clear(Node*& subNode);
public:
    BST();
    ~BST();
    bool isEmpty();
    void add(int data);
    int height();
    void postOrder();
    int peekRoot();
    void clear();
};
#endif