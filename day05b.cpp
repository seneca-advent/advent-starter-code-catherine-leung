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
	int total=127*8 + 7 + 1;
	int* seated=new int[total];
	for(int i=0;i<total;i++){
		seated[i]=0;
	}
	for(int i=0;i<numLines;i++){
		getSeat(lines[i],row,col,id);
		seated[id]=1;
	}
	int start=0;
	while(seated[start]!=1){
		start++;
	}
	while(seated[start]!=0){
		start++;
	}
	delete [] seated;
	std::cout << start << std::endl;

}
