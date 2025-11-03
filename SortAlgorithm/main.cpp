#include<iostream>
#include "SortAlgorithm.h"
using namespace std;

int main(){

// <===============================冒泡排序===============================>
    cout << "<===============================冒泡排序===============================>" << endl;
    #if 1
    bubblingSort_main();
    cout << endl;
    #endif

// <===============================选择排序===============================>
    cout << "<===============================选择排序===============================>" << endl;
    #if 1
    selectSort_main();
    cout << endl;
    #endif




    return 1;
}