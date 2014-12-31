#include <iostream>
#include "Paragraph.h"
#include "Story.h"
using namespace std;

Paragraph::Paragraph(){
	head=new Node;
	head->S=NULL;
	head->next=NULL;
}
Paragraph::Paragraph(const Paragraph& p){
	head=new Node;
	head->S=NULL;
	head->next=NULL;
	Node* cur=(p.head)->next;
	while(cur){
		Node *newNode = new Node;
		newNode->S = new Sentence(*(cur->S));
		newNode->next = NULL;
		Node* pos=head;
		while(pos){
			if(pos->next == NULL) {
				pos->next = newNode;
				break;
			}
			pos = pos->next;
		}
			cur = cur->next;
	}
}
//tbc
Paragraph::~Paragraph(){
	if( head == NULL ) {return;}
	Node* cur=head->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->S;
		delete cur;
		cur=temp;
	}
	delete head;
}
void Paragraph::add(char paragraph[],int Psize){
	int x,y=-2;
	Node *newNode = new Node;
	newNode->S = new Sentence;
	newNode->next = NULL;
	Node* cur=head;
	while(cur){
		if(cur->next == NULL) {
			cur->next = newNode;
			break;
		}
		cur = cur->next;
	}

	for (int i = 0; i < Psize; i++){
		if (paragraph[i]=='.'||paragraph[i]=='?'||paragraph[i]=='!'){
			x=y+2;
			y=i;
			int size=y-x+2;
			char sentence[size];
			for (int j = 0; j<size; j++){
				sentence[j]=paragraph[x+j];
			}
			sentence[size-1]=' ';
			sentence[size]='\0';
			if (sentence[0]=='\t'){
				for (int i = 0; i < size; i++)
				{
					sentence[i]=sentence[i+1];
				}
				size--;
			}
			(*(newNode->S)).add(sentence,size);
		}
	}
}
void Paragraph::getfirstparagraph(){
	if (head->next==NULL)
	{
		return;
	}
	Node* cur=head->next->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->S;
		delete cur;
		cur=temp;
	}
	head->next->next=NULL;
	
}
void Paragraph::getrestparagraph(){
	Node* cur=head->next;
	Node* temp=head->next->next;
	delete cur->S;
	delete cur;
	head->next=temp;
}
void Paragraph::addbegin(char paragraph[],int Psize){
	int x,y=-2;
	Node *newNode = new Node;
	newNode->S = new Sentence;
	newNode->next = head->next;
	head->next=newNode;
	for (int i = 0; i < Psize; i++){

		if (paragraph[i]=='.'||paragraph[i]=='?'||paragraph[i]=='!'){
			x=y+2;
			y=i;
			int size=y-x+2;
			char sentence[size];
			for (int j = 0; j<size; j++){
				sentence[j]=paragraph[x+j];
			}
			sentence[size-1]=' ';
			sentence[size]='\0';
			if (sentence[0]=='\t'){
				for (int i = 0; i < size; i++)
				{
					sentence[i]=sentence[i+1];
				}
				size--;
			}
			(*(newNode->S)).add(sentence,size);
		}
	}
}

void Paragraph::insertbeginning(char paragraph[],int Psize){
	Node *newNode;
	newNode= head->next;
	head->next=newNode;
	(*(newNode->S)).insertbeginning(paragraph,Psize);
}

void Paragraph::show(){
	Node* cur=head->next;
	while(cur){
		(*(cur->S)).show();
		cur = cur->next;
		cout<<"\n"<<endl;
	}
}
int Paragraph::getsize(){
	int size=0;
	Node* cur=head->next;
	while(cur){
		size=size+(*(cur->S)).getsize()+2;
		cur = cur->next;
	}
	size=size-1;
	return size;
}
char* Paragraph::tostring(){
	int size=(*this).getsize();
	//cout<<"size"<<size<<endl;
	char* sstring=new char[size];
	int pos=0;
	Node* cur=head->next;
	while(cur){
		pos++;
		char*temp=(*(cur->S)).tostring();
		for (int i = 0; i < (*(cur->S)).getsize()-1; i++)
		{
			sstring[pos+i]=temp[i];
		}
		sstring[pos-1]='\t';
		//sstring[(*(cur->S)).getsize()-1]=' ';
		//cout<<"sstring "<<sstring<<endl;
		pos=pos+(*(cur->S)).getsize()+1;
		//cout<<"pos"<<pos<<endl;
		//sstring[pos+1]='\n';
		sstring[pos-2]='\n';
		sstring[pos-1]='\n';
		cur=cur->next;
		delete temp;
	}
	sstring[size]='\0';
	//cout<<"sstring "<<sstring[133]<<endl;
	return sstring;
	
}

Sentence Paragraph::first(){
	Sentence newS(*(head->next->S));
	newS.getfirstsentence();
	return newS;
}

Paragraph Paragraph::rest(){
	Paragraph newP(*this);
	(*(newP.head->next->S)).getrestsentence();
	return newP;
}

Paragraph Paragraph::operator=(const Paragraph& p){
	if(head!=NULL){Node* cur=head->next;
	//cout<<"1"<<endl;
	Node* temp;
	//cout<<"2"<<endl;
	while(cur){
		//cout<<"3"<<endl;
		//cout<<cur->next<<endl;
		temp=cur->next;
		//cout<<temp;
		delete cur->S;
		delete cur;
		cur=temp;
		//cout<<cur<<endl;
	}
	//cout<<"~Pxyz"<<endl;
	delete head;}
	head=new Node;
	head->S=NULL;
	head->next=NULL;
	Node* cur=(p.head)->next;
	while(cur){
		Node *newNode = new Node;
		newNode->S = new Sentence(*(cur->S));
		newNode->next = NULL;
		Node* pos=head;
		while(pos){
			if(pos->next == NULL) {
				pos->next = newNode;
				break;
			}
			pos = pos->next;
		}
			cur = cur->next;
	}
	return *this;
}

Paragraph Paragraph::operator+(int x){
	Paragraph newP;
	newP.head=head;
	if (x==1){
		Node* cur=(head->next);
		while(cur){
			(*(cur->S))+1;
			cur = cur->next;
		}
	}
	return newP;
}
Paragraph Paragraph::operator+(const Paragraph& p){
	Paragraph newP;
	Sentence S1(*((*this).head->next->S));
	Sentence S2(*(p.head->next->S));
	Node *newNode = new Node;
	newNode->S = new Sentence(S1*S2);
	newP.head->next=newNode;
	return newP;
}
//story + story
Paragraph Paragraph::operator%(const Paragraph& p){
	Paragraph P1(*this);
	Paragraph P2(p);
	Node* cur=P1.head->next;
	while(cur->next){
		cur=cur->next;
	}
	cur->next=P2.head->next;
	P2.head->next=NULL;
	return P1;
}

Story Paragraph::operator+(const Story& str){
	Story AS(str);
	AS.addbegin(*this);
	return AS;
}

Paragraph Paragraph::operator+(const Sentence& s){
	Paragraph newP(*this);
	Sentence newS(s);
	char *temp=newS.tostring();
	(*(newP.head->next->S)).add(temp,newS.getsize());
	delete temp;
	return newP;
}

Paragraph Paragraph::operator++(int x){
	Node* cur=(head->next);
	while(cur){
		(*(cur->S))++;
		cur = cur->next;
	}
	return *this;
}
//tbc
Paragraph Paragraph::operator++(){
	Node* cur=(head->next);
	while(cur){
		++(*(cur->S));
		cur = cur->next;
	}
	return *this;
}

Paragraph Paragraph::operator--(int x){
	Node* cur=(head->next);
	while(cur){
		(*(cur->S))--;
		cur = cur->next;
	}
	return *this;
}
//tbc
Paragraph Paragraph::operator--(){
	Node* cur=(head->next);
	while(cur){
		--(*(cur->S));
		cur = cur->next;
	}
	return *this;
}
ostream &operator<<(ostream &output, const Paragraph &P){
	Paragraph newP(P);
	char* temp=newP.tostring();
	//cout<<"P tostring"<<temp;
	output<<temp;
	delete temp;
    return output;
}