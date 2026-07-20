/**
* @file         BST.cpp
* @description  Ekleme için özyinelemeli mantığı, bellek yönetimini ve ağaç düğümlerini statik kuyruğa kaydetmek için Helper sınıfıyla entegrasyonu uygular.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali (lucas.katalahali@ogr.sakarya.edu.tr)
*/

#include "BST.hpp"
#include "Helper.hpp"
#include <algorithm>
#include<iostream>
using namespace std;

Node::Node(int data, Node *left = nullptr, Node *right = nullptr){
    this->data = data;
    this->left = left;
    this->right = right;
};

void BST::searchAndAdd(Node*& subNode, int data){
    if(subNode == nullptr) subNode = new Node(data);
    else if(subNode->data > data) searchAndAdd(subNode->left, data);
    else if(subNode->data < data) searchAndAdd(subNode->right, data);
    else searchAndAdd(subNode->left, data);   //if the datas are equal, add to left
}


int BST::height(Node *subNode){
    if(subNode == nullptr) return -1; 
    return 1 + max(height(subNode->left), height(subNode->right));
}

void BST::postOrder(Node *subNode){
    if(subNode != nullptr){
        postOrder(subNode->left);
        postOrder(subNode->right);
        //Here is where I am gonna save the values;
        SaveNodeQueue::saveNodeValue(subNode->data); 
    }
}

BST::BST(){
    root = nullptr;
}
BST::~BST(){
    clear(root);
}

bool BST::isEmpty(){
    return root == nullptr;
}

void BST::add(int data){
    searchAndAdd(root, data);
}

void BST::postOrder(){
    postOrder(root);
}
int BST::height(){
    return height(root);
}

int BST::peekRoot(){
    if(root == nullptr) return 0;
    return root->data;
}

void BST::clear(){
    clear(root);
}

void BST::clear(Node *&subNode){
    if(subNode != nullptr){
        clear(subNode->left);
        clear(subNode->right);
        delete subNode; // Apaga o nó
        subNode = nullptr;
    }
}
