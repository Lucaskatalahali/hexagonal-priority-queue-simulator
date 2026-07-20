/**
* @file         HexagonList.cpp
* @description  Dairesel Liste mantığını uygulayarak "head" ve "tail" arasındaki bağlantıyı sağlar. Yığını ("InvertStack") kullanarak "printAll" (Zikzak) rutinini içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali (lucas.katalahali@ogr.sakarya.edu.tr)
*/

#include "HexagonList.hpp"
#include "Helper.hpp"
#include<iostream>
using namespace std;

HexagonNode::HexagonNode(Hexagon* data){
    this->data = data;
    next = nullptr;
}

HexagonList::HexagonList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

HexagonList::~HexagonList(){
    clear();
}

void HexagonList::addHexagon(Hexagon *data){
    HexagonNode* newNode = new HexagonNode(data); 
    if(head == nullptr){
        newNode->next = newNode;
        head = newNode;
        tail = newNode; 
    }
    else{
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }
    size++;
}

void HexagonList::clear(){
    if(head == nullptr) return;
    HexagonNode* current = head;
    for(int i = 0; i < size; i++){
        HexagonNode* toDelete = current;
        current = current->next;
        if(toDelete->data != nullptr) delete toDelete->data;
        
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void HexagonList::printAll(){
    HexagonNode* tmp = head;
    int control = 1;
    for(int i = 0; i < size;){
        if(control % 2 != 0){
            for(int j = 0; j < 6; j++){
                cout<< tmp->data->getHexagonValue() <<"\t";
                i++;
                tmp = tmp->next;
                if(i >= size) break; //It must stop printing in case i is now greater than size
            }
        }    
        else{
            for(int j = 0; j < 6; j++){
                InvertStack::push(tmp->data->getHexagonValue());
                i++;
                tmp = tmp->next;
                if(i >= size) break; //It must stop printing in case i is now greater than size
            }
            InvertStack::printAndDelete();
        }    
        cout<<"\n";
        control++;
    }
}

HexagonNode *HexagonList::getHead(){
    return head;
}

HexagonNode *HexagonList::getTail(){
    return tail;;
}

int HexagonList::getSize(){
    return size;
}
