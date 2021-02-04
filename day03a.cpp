#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;

int main(int argc, char* argv[]){
	char* data[MAX]={0};
	int numData=readLines("day03input.txt",data,MAX);
	int length=strlen(data[0]);
	int pos=0;
	int treeCount=0;
	for(int i=0;i<numData;i++){
		if(data[i][pos]=='#'){
			treeCount++;
		}
		pos=(pos+3)%length;
	}
	std::cout << treeCount << std::endl;
}