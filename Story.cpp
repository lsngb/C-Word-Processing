#include <iostream>
#include <fstream>
#include "Story.h"

using namespace std;

Story::Story(){
	P=NULL;
}

Story::~Story(){
	if (P!=NULL)
	{
		delete P;
	}
}
Story::Story(char filename[]){
	P=new Paragraph;
	char temp;
	int pos=0;
	int i=0;
	int j=-1;
	int size=0;
	ifstream Afile;
	ifstream afile;
	Afile.open(filename);
	while(!Afile.eof()){
		Afile.get(temp);
		pos++;
		if(temp=='\n'){
			Afile.get(temp);
			if(temp=='\n'||temp=='\0'){
				i=j+1;
				j=pos;
				size=j-i;
				if (size<6){break;}
				else{
					afile.open(filename);
					char AP[size];
					for(int k=0;k<pos;k++){
						if (k<i){afile.get(temp);}
						else{
							afile.get(AP[k-i]);
						}
					}
					afile.close();
					AP[size-1]='\0';
					(*P).add(AP,size);
					pos++;
				}
			}
		}
	}
	Afile.close();
}

Story::Story(const Story& Bstory) {
	P=new Paragraph(*(Bstory.P));
}
void Story::show(){
	(*P).show();
}

Paragraph Story::first(){
	Paragraph newP(*P);
	newP.getfirstparagraph();
	return newP;
}

Story Story::rest(){
	Story newS(*this);
	(*(newS.P)).getrestparagraph();
	return newS;
}

void Story::save(char filename[]){
	ofstream Afile;
	Afile.open(filename);
	Afile<<(*this);
	Afile.close();
}
void Story::addbegin(const Paragraph& p){
	Paragraph AP(p);
	char* temp=AP.tostring();
	(*P).addbegin(temp,AP.getsize());
	delete temp;
}

Story Story::operator=(const Story& Bstory){
	if (P!=NULL)
	{
		delete P;
	}
	P=new Paragraph(*(Bstory.P));
	return *this;
}

Story Story::operator+(const Story& Bstory){
	Story AS(Bstory);
	Paragraph* X=new Paragraph((*(*this).P)%(*(AS.P)));
	Story newS;
	newS.P=X;
	return newS;
}

Story Story::operator+(int x){
	if(x==1){
		(*P)+1;
	}
	return *this;
}

Story Story::operator+(const Paragraph& p){
	Story newS(*this);
	Paragraph newP(p);
	char* temp=newP.tostring();
	(*newS.P).add(temp,newP.getsize());
	delete temp;
	return newS;
}

Story Story::operator++(int x){
	(*(P))++;
	return *this;
}

Story Story::operator++(){
	++(*(P));
	return *this;
}

Story Story::operator--(int x){
	(*(P))--;
	return *this;
}

Story Story::operator--(){
	--(*(P));
	return *this;
}

ostream &operator<<(ostream &output, const Story &str){
	char* temp=(*(str.P)).tostring();
	output<<temp;
	delete temp;
    return output;
}