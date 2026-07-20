/**
* @file         Helper.hpp
* @description  Altıgenler arası düğüm transferi için SaveNodeQueue (Kuyruk) ve zikzak baskı (satır ters çevirme) için InvertStack (Yığın).
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef HELPER_HPP
#define HELPER_HPP

struct TreeNode{
    int value;
    TreeNode* next;
    TreeNode(int value);
};

class SaveNodeQueue{
private:
    static TreeNode* front;
    static TreeNode* back;
public:
    static bool isEmpty();
    static void saveNodeValue(int value);
    static int peekAndDelete();
};


struct InvertValue{
    int value;
    InvertValue* next;
    InvertValue(int value);
};

class InvertStack{
private:
    static InvertValue* topOfStack;
public:
    static bool isEmpty();
    static void push(int value);
    static void printAndDelete();
}; 
#endif