#include <iostream>
#include <cstdlib>
#include "utils.h"

const int MAX = 1000;

int main(int argc, char* argv[]){
	char* lines[2000]={0};
	int data[MAX];
	int numdata=readLines("day01input.txt",lines,MAX);
	for(int i=0;i<numdata;i++){
		data[i]=atoi(lines[i]);
	}
	int* table=new int[2021];
	for(int i=0;i<2021;i++){
		table[i]=0;
	}
	for(int i=0;i<numdata;i++){
		table[data[i]]=1;
	}
	for(int i=0;i<numdata;i++){
		int num1 = data[i];
		for(int j=0;j<numdata;j++){
			int maxNum2=2020-num1;
			if(maxNum2-data[j] >= 0 && table[maxNum2-data[j]]==1){
				std::cout<< "number 1: "<< data[i] << std::endl;
				std::cout<< "number 2: "<< data[j] << std::endl;
				std::cout<< "number 3: " << maxNum2-data[j] << std::endl;
				std::cout << "product: " << data[i]*(maxNum2-data[j])*data[j] << std::endl;

			}
		}
	}
	delete [] table;
}

