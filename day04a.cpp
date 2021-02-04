#include <cstring>
#include <cstdio>
#include <iostream>
#include "utils.h"

const int maxField=100;
int getField(const char* s,char field1[],char field2[]){
	int rc=sscanf(s,"%[^:]:%[^ ] ",field1,field2);
	if(rc!=2){
		return 0;
	}
	else{
		return strlen(field1) + strlen(field2) + 2;
	}
}
struct Passport{
	int byr_;
	int iyr_;
	int eyr_;
	char hgt_[30]; //height in cm
	char hcl_[50];
	char ecl_[50];
	char pid_[30];
	unsigned int cid_;
	void init(){
		byr_=-1;
		iyr_=-1;
		eyr_=-1;
		hcl_[0]='\0';
		ecl_[0]='\0';
		pid_[0]='\0';
		cid_=0;
		hgt_[0]='\0';

	}
	Passport(){
		init();
	}
	bool validHeight(){
		int value;
		char unit[10];
		bool rc=false;
		sscanf(hgt_,"%d%s",&value,unit);
		if(!strcmp(unit,"cm") && (value>=150 && value <=193)){
			rc=true;
		}
		else if(!strcmp(unit,"in") && (value >=59 && value <=76)){
			rc=true;
		}
		return rc;
	}

	bool validEye(){
		char validColour[7][4]={"amb","blu","brn","gry","hzl","oth","grn"};
		bool rc=false;
		int i;
		for(i=0;strcmp(validColour[i],ecl_);i++);
		if(i<7){
			rc=true;
		}
		return rc;
	}
	bool validHair(){
		bool rc=false;
		if(hcl_[0]=='#'  && hcl_[8]=='\0'){
			int i;
			int cnt=0;
			for(i=1;(hcl_[i]>='0' && hcl_[i]<='9') ||(hcl_[i]>='a' && hcl_[i]<='f') ; i++){
				cnt++;
			}
			if(cnt==6){
				rc=true;
			}
		}
		return rc;
	}
	bool validPID(){
		int i;
		int cnt=0;
		for(i=0;pid_[i]>='0' && pid_[i]<='9'; i++){
			cnt++;
		}
		return cnt==9;
	}

};
int main(void){
	char field1[maxField];
	char field2[maxField];
	Passport p;
	int numFields=0;
	int numValid=0;
	char* lines[1000]={0};
	int numLines=readLines("day04input.txt",lines,1000);
	int i=0;
	while (i<numLines){
		while(lines[i][0]!='\0'){
			int offset=0;
			int rc;
			while(rc=getField(lines[i]+offset,field1,field2)){
				offset+=rc;
				if(strcmp(field1,"byr")==0){
					if(strlen(field2)==4){
						p.byr_=atoi(field2);
					}
				}
				else if(strcmp(field1,"iyr")==0){
					if(strlen(field2)==4){
						p.iyr_=atoi(field2);
					}
				}
				else if(strcmp(field1,"eyr")==0){
					if(strlen(field2)==4){
						p.eyr_=atoi(field2);
					}
				}
				else if(strcmp(field1,"hgt")==0){
					strcpy(p.hgt_,field2);
				}
				else if(strcmp(field1,"hcl")==0){
					strcpy(p.hcl_,field2);
				}
				else if(strcmp(field1,"ecl")==0){
					strcpy(p.ecl_,field2);
				}
				else if(strcmp(field1,"pid")==0){
					strcpy(p.pid_,field2);
				}
				else if(strcmp(field1,"cid")==0){
					p.cid_=atoi(field2);
				}
				numFields++;
			}
			i++;
		}
		i++;
		if(numFields == 8 || (numFields==7 && p.cid_==0)){

				numValid++;

		}

		p.init();
		numFields=0;

/*		else{
			fscanf(fp,"\n");


			numFields=0;
		}*/
	}
	std::cout << numValid << std::endl;

}
