/**
* @file         helper.cpp
* @description  FIFO ve LIFO Mantıklarını uygular. peekAndDelete için güvenlik kontrolünü ve zikzak efekti için ters yazdırma rutini içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali (lucas.katalahali@ogr.sakarya.edu.tr)
*/

#include "Helper.hpp"
#include<iostream>
using namespace std;

TreeNode::TreeNode(int value){
    this->value = value;
    next = nullptr;
}
//Inicialize the static values
TreeNode* SaveNodeQueue:: front = nullptr;
TreeNode* SaveNodeQueue:: back = nullptr;

bool SaveNodeQueue::isEmpty(){
    return front == nullptr;
}

void SaveNodeQueue::saveNodeValue(int value){
    TreeNode* newTreeNode = new TreeNode(value);
    if(isEmpty()){
        front = newTreeNode;
        back = newTreeNode;
    } 
    else{
        back->next = newTreeNode;
        back = newTreeNode;
    }
}

int SaveNodeQueue::peekAndDelete(){
    if(isEmpty()) return 0;
    int number = front->value;
    TreeNode* tmp = front;
    front = front->next;
    delete tmp;
    if(front == nullptr){
        back = nullptr;
    }
    return number;
}

InvertValue::InvertValue(int value){
    this->value = value;
    next = nullptr;
}

//Inicialize the static values
InvertValue*  InvertStack::topOfStack = nullptr;

bool InvertStack::isEmpty(){
    return topOfStack == nullptr;
}

void InvertStack::push(int value){
    InvertValue* number = new InvertValue(value);
    number->next = topOfStack;
    topOfStack = number;
}

void InvertStack::printAndDelete(){
    while(!isEmpty()){
        cout<< topOfStack->value <<"\t";
        InvertValue* tmp = topOfStack;
        topOfStack = topOfStack->next;
        delete tmp;
    }
}
