#include <cstdio>
#include <iostream>
#include "utils.h"

const int MAX=1000;
struct PassWord{
	int min_;
	int max_;
	char let_;
	char password_[100];
};
void parseLines(char* line[], PassWord pass[] ,int max){
	int i=0;
	while(i<max){
		sscanf(line[i],"%d-%d %c:%s\n",&pass[i].min_,&pass[i].max_,
								&pass[i].let_,pass[i].password_);
		i++;
	}

}
int countChar(const char* s, char let){
	int rc=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==let){
			rc++;
		}
	}
	return rc;
}
int main(void){
	char* lines[2000]={0};
	int numdata=readLines("day02input.txt",lines,MAX);

	PassWord passwords[MAX];
	parseLines(lines,passwords,numdata);
	int numValid=0;
	for(int i=0;i<numdata;i++){
		int let=passwords[i].let_;
		const char* pass=passwords[i].password_;
		int numChar= countChar(pass,let);

		if(numChar>=passwords[i].min_ && numChar<=passwords[i].max_){
			numValid++;
		}
	}
	std::cout << numValid << std::endl;
}