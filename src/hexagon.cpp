/**
* @file         Hexagon.cpp
* @description  Turlara göre çıkarma kurallarını, boşlukları doldurmak için Array Kaydırma mantığını ve alınan düğümlerin dairesel dağıtımını uygular.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali (lucas.katalahali@ogr.sakarya.edu.tr)
*/

#include "Hexagon.hpp"
#include "Helper.hpp"
#include<iostream>


Hexagon::Hexagon(){
    front = 0;
    //Inicialized all as null;
    for(int i = 0; i < capacity; i++){
        treeArray[i] = nullptr; 
    }
}

Hexagon::~Hexagon(){
    for(int i = 0; i < capacity; i++){
        if(treeArray[i] != nullptr){
            delete treeArray[i]; // Chama o destrutor da BST (que chama o clear)
            treeArray[i] = nullptr;
        }
    }
}

bool Hexagon::isEmpty(){ 
    return treeArray[0] == nullptr;
}

void Hexagon::removeAt(int roundNumber){
    int indexToRemove = -1;

    if(roundNumber % 2 != 0){
        indexToRemove = front;
    } 
    else{
        indexToRemove = peekMax();
    }
    if(indexToRemove != -1 && treeArray[indexToRemove] != nullptr){
        treeArray[indexToRemove]->postOrder(); //save (inside postorder method) the values before deleting
        delete treeArray[indexToRemove];
        for(int i = indexToRemove; i < capacity - 1; i++){
            treeArray[i] = treeArray[i+1];
        }
        treeArray[capacity - 1] = nullptr; //the last element must be now null 
    }
}

void Hexagon::receiveNodes(){
    int index = 0;
    while(!SaveNodeQueue::isEmpty()){
        if(treeArray[index] == nullptr){
            treeArray[index] = new BST();
        }
        treeArray[index]->add(SaveNodeQueue::peekAndDelete());
        index++;
        if(index >= capacity) index = 0;
    }
}

int Hexagon::peekMax(){
    int maxIndex = -1;
    int maxHeight = -1;

    for(int i = 0; i < capacity; i++){
        if(treeArray[i] != nullptr){
            int hight = treeArray[i]->height();
            if(hight > maxHeight){
                maxHeight = hight;
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

int Hexagon::getHexagonValue(){
    // 1. Primeira barreira
    if(treeArray[front] == nullptr) return 0;

    int maxIndex = peekMax();

    if (maxIndex == -1) return 0;
    if (treeArray[maxIndex] == nullptr) return 0;
    int maxValue = treeArray[maxIndex]->peekRoot();
    if(maxValue == 0) return 0;

    return treeArray[front]->peekRoot() / maxValue;
}

void Hexagon::addTree(BST *tree){
    for(int i = 0; i < capacity; i++){
        if(treeArray[i] == nullptr){
            treeArray[i] = tree;
            return;
        }
    }
}
