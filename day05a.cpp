#include <cstring>
#include <cstdio>
#include <iostream>
#include "utils.h"

const int maxField=100;
void getSeat(const char* s,int& row, int& col, int& id){
	int low=0;
	int high=127;
	int mid;
	for(int i=0;i<7;i++){
		row=(low+high)/2;
		if(s[i]=='F'){
			high=row;
		}
		else if(s[i]=='B'){
			low=row+1;
		}
	}
	row=low;
	low=0;
	high=7;
	for(int i=7;i<10;i++){
		col=(low+high)/2;
		if(s[i]=='L'){
			high=col;
		}
		else if(s[i]=='R'){
			low=col+1;
		}
	}
	col=low;
	id=row*8 + col;
}
int main(void){
	char* lines[1000]={0};
	int numLines=readLines("day05input.txt",lines,1000);
	int row;
	int col;
	int id;
	int max;
	std::cout <<sizeof(0b1) << std::endl;
	getSeat(lines[0],row,col,id);
	max=id;
	for(int i=1;i<numLines;i++){
		getSeat(lines[i],row,col,id);
		if(id > max){
			max=id;
		}
	}
	std::cout <<  max << std::endl;

}
