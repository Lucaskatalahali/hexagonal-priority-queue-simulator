/**
* @file         main.cpp
* @description  Başlangıç yapısını oluşturmak için metin dosyasını okur, tur yürütme mantığını yönetir, düğüm kaldırma ve dağıtımını düzenler ve terminaldeki oyun ilerlemesinin gösterimini kontrol eder.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   2. Ödev
* @date         12/12/2025
* @author       Lucas Isaac Cassoma Katalahali (lucas.katalahali@ogr.sakarya.edu.tr)
*/

#include "HexagonList.hpp"
#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

int main(){

    HexagonList list;
    ifstream file("Data.txt");
    if(!file){
        cout<<"Error while opening file"<<endl;
        return 1;
    }
    int lines = 0;
    string tmpLine;

    while(getline(file, tmpLine)){
        if(!tmpLine.empty()) lines++;
    }
    int numberOfHexagon = (lines + 5)/6; //how many hexagon we will have

    for(int i = 0; i < numberOfHexagon; i++){
        Hexagon* h = new Hexagon();
        list.addHexagon(h);
    }
    system("cls");
    list.printAll();
    file.clear(); 
    file.seekg(0, ios::beg); // 2. Go back to the beginning

    if(!file){
        cout << "Error while opening file!" << endl;
        return 1;
    }

    int count = 0; //IT MUST GO UNTILL 6
    int isSixHexagon = 0;
    HexagonNode* temp_hexagon = list.getHead();
    system("cls");

    while(getline(file, tmpLine)){
        if(tmpLine.empty()) continue;
        BST* tree = new BST();

        stringstream ss(tmpLine);
        int value;
        while(ss >> value){
            tree->add(value);
        }
        temp_hexagon->data->addTree(tree);
        count++;
        if(count == 6){
            cout<<temp_hexagon->data->getHexagonValue() << "\t";
            temp_hexagon = temp_hexagon->next;
            count = 0;
            isSixHexagon++;
        }
        if(isSixHexagon == 6){
            cout<<"\n";
            isSixHexagon = 0;
        }
    }
    if(count > 0) cout << temp_hexagon->data->getHexagonValue() << "\t";

    int round;
    cout<< "\nHow many rounds do you want to do: ";
    cin>> round;
    temp_hexagon = list.getHead();
    int length = list.getSize();
    for(int index = 1; index <= round; index++){
        for(int i = 0; i < length; i++){
            temp_hexagon->data->removeAt(index);
            temp_hexagon->next->data->receiveNodes();
            temp_hexagon = temp_hexagon->next;
        }

        //printing the round
        system("cls");
        list.printAll();
        cout<<"\n---------- ROUND " << index << " ----------" <<endl;
    }
    system("pause");
    return 0;
}