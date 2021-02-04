#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "utils.h"

const int MAX = 2000;   //max number of lines

int main(int argc, char* argv[]){
	char* lines[MAX]={0};
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
//		std::cout << data[i] << std::endl;
		table[data[i]]=1;
	}
	for(int i=0;i<numdata;i++){
		if(table[2020-data[i]]==1){
			std::cout<< "number 1: "<< data[i] << std::endl;
			std::cout<< "number 2: " << 2020-data[i] << std::endl;
			std::cout << "product: " << data[i]*(2020-data[i]) << std::endl;
		}
	}
	delete [] table;
}
