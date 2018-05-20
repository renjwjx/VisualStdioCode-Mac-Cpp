#include "ReplaceAlgorithm.h"
#include <iostream>
using namespace std;

//三种具体的替换算法
void LRU_ReplaceAlgorithm::Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }

void FIFO_ReplaceAlgorithm::Replace() { cout<<"First in First out replace algorithm"<<endl; }

void Random_ReplaceAlgorithm::Replace() { cout<<"Random replace algorithm"<<endl; }