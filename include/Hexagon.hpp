/**
* @file         Hexagon.hpp
* @description  Öncelik Kuyruğu tanımlar; 6 BST dizisini yönetir ve çıkarma mantığını ve değer kuralını uygular.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef HEXAGON_HPP
#define HEXAGON_HPP
#include "BST.hpp"

class Hexagon{
private:
    static const int capacity = 6;
    BST* treeArray[capacity];
    int front;
    //int length;
public:
    Hexagon(); 
    ~Hexagon();
    bool isEmpty();
    void removeAt(int roundNumber);
    void receiveNodes();
    //Priority is determined by tree height.
    int peekMax(); 
    int getHexagonValue();
    void addTree(BST* tree);
};
#endif