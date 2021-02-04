#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;

int main(int argc, char* argv[]){
	char* data[MAX]={0};
	int numData=readLines("day03input.txt",data,MAX);
	int slope[5][2]={{1,1},{3,1},{5,1},{7,1},{1,2}};
	for(int i=0;i<numData;i++){
		std::cout << data[i] << std::endl;
	}
	int length=strlen(data[0]);
	unsigned long long product=1;
	for(int i=0;i<5;i++){
		int pos=0;
		int treeCount=0;
		for(int j=0;j<numData;j+=slope[i][1]){
			if(data[j][pos]=='#'){
				treeCount++;
			}
			pos=(pos+slope[i][0])%length;
		}
		std::cout<< "run "<< i+1 << " : " << treeCount << std::endl;
		product*=treeCount;
	}
	std::cout << product << std::endl;
}
