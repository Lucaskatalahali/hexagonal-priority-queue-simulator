/**
* @file         HexagonList.hpp
* @description  Altıgen nesnelerini bağlayan Dairesel Liste sınıfını tanımlar. Liste yönetimi metotlarını ve zikzak modunda yazdırma rutinini içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef HEXAGONLIST_HPP
#define HEXAGONLIST_HPP
#include "Hexagon.hpp"

struct HexagonNode{
    Hexagon* data;
    HexagonNode* next;

    HexagonNode(Hexagon* data);
};

class HexagonList{
private:
    HexagonNode* head;
    HexagonNode* tail;
    int size;
public:
    HexagonList();
    ~HexagonList();
    void addHexagon(Hexagon* data);
    void clear();
    void printAll();
    HexagonNode* getHead();
    HexagonNode* getTail(); 
    int getSize();
};

#endif