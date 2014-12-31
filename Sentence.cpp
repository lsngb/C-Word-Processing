#include "Sentence.h"
#include "Paragraph.h"
#include <iostream>
using namespace std;

Sentence::Sentence(){
	head=new Node;
	head->W=NULL;
	head->next=NULL;
}
Sentence::Sentence(const Sentence& s){
	head=new Node;
	head->W=NULL;
	head->next=NULL;
	Node* cur=(s.head)->next;
	while(cur){
		Node *newNode = new Node;
		newNode->W = new Word(*(cur->W));
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

Sentence::~Sentence(){
	if( head == NULL ) {return;}
	Node* cur=head->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->W;
		delete cur;
		cur=temp;
	}
	delete head;
}
void Sentence::add(char sentence[],int Ssize){
	Node *newNode = new Node;
	newNode->W = new Word;
	newNode->next = NULL;
	Node* cur=head;
	while(cur){
		if(cur->next == NULL) {
			cur->next = newNode;
			break;
		}
		cur = cur->next;
	}
	int x=0,y=-1;
	for (int i = 0; i < Ssize; i++){
		if (sentence[i]==' '){
			x=y+1;
			y=i;
			int size=y-x+1;
			char* word=new char[size];
			for (int j = 0; j<size; j++){
				word[j]=sentence[x+j];
			}
			word[size]='\0';
			(*(newNode->W)).add(word);
		}
	}
}
void Sentence::insertbeginning(char sentence[],int Ssize){
	Node *newNode = new Node;
	newNode->W = new Word;
	newNode->next = head->next;
	head->next=newNode;
	int x=0,y=0;
	for (int i = 0; i < Ssize; i++){
		if (sentence[i]==' '){
			x=y;
			y=i+1;
			int size=y-x;
			char* word=new char[size];
			size++;
			for (int j = 0; j<size; j++){
				word[j]=sentence[x+j];
			}
			word[size-1]='\0';
			cout<<"word "<<word<<endl;
			(*(newNode->W)).add(word);
		}
	}
}
void Sentence::show(){
	Node* cur=head->next;
	while(cur){
		(*(cur->W)).show();
		cur = cur->next;
	}
}
void Sentence::getfirstsentence(){
	if (head->next==NULL)
	{
		return;
	}
	Node* cur=head->next->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->W;
		delete cur;
		cur=temp;
	}
	head->next->next=NULL;
}
void Sentence::getrestsentence(){
	Node* cur=head->next;
	Node* temp=head->next->next;
	delete cur->W;
	delete cur;
	head->next=temp;
}

Word Sentence::first(){
	Word newW(*(head->next->W));
	newW.getfirstword();
	return newW;
}

Sentence Sentence::rest(){
	Sentence newS(*this);
	(*(newS.head->next->W)).getrestword();
	return newS;
}
int Sentence::getsize(){
	int size=0;
	Node* cur=head->next;
	while(cur){
		size=size+(*(cur->W)).getsize()-1;
		cur = cur->next;
	}
	size++;
	return size;
}
char* Sentence::tostring(){
	int size=(*this).getsize();
	char* sstring=new char[size];
	int pos=0;
	Node* cur=head->next;
	while(cur){
		char* temp=(*(cur->W)).tostring();
		for (int i = 0; i < (*(cur->W)).getsize()-1; i++)
		{
			sstring[pos+i]=temp[i];
		}
		
		pos=pos+(*(cur->W)).getsize()-1;
		cur=cur->next;
		delete temp;
	}
	sstring[size-1]='\0';
	return sstring;
	
}
Sentence Sentence::operator=(const Sentence& s){
	if(head!=NULL){
	Node* cur=head->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->W;
		delete cur;
		cur=temp;
	}
	delete head;}
	head=new Node;
	head->W=NULL;
	head->next=NULL;
	Node* cur=(s.head)->next;
	while(cur){
		Node *newNode = new Node;
		newNode->W = new Word(*(cur->W));
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
Sentence Sentence::operator+(int x){
	Sentence newsentence;
	newsentence.head=head;
	if (x==1){
		Node* cur=(head->next);
		while(cur){
			(*(cur->W)).capitalfirstword();
			cur = cur->next;
		}
	}
	return newsentence;
}

Sentence Sentence::operator+(const Word& w){
	Node* cur=((*this)).head->next;
	Sentence newsentence((*(cur->W))+w);
	return newsentence;
}
//P+P
Sentence Sentence::operator*(const Sentence& s){
	Sentence P1(*this);
	Sentence P2(s);
	Node* cur=P1.head->next;
	while(cur->next){
		cur=cur->next;
	}
	cur->next=P2.head->next;
	P2.head->next=NULL;
	return P1;
}

Paragraph Sentence::operator+(const Sentence& s){
	Paragraph newP;
	Node* cur=(head->next);
	while(cur){
		cur = cur->next;
		if (cur->next==NULL){break;}
	}
	int size=(*(cur->W)).getsize()+(*((s.head)->next->W)).getsize()-1;
	char newp[size];
	int i=0;
	int j=0;
	char* temp=(*(cur->W)).tostring();
	while(temp[i]!='\0'){
		newp[i]=temp[i];
		i++;j++;
	}
	delete temp;
	temp=(*((s.head)->next->W)).tostring();
	i=0;
	while(temp[i]!='\0'){
		newp[j]=temp[i];
		i++;j++;
	}
	delete temp;
	newp[size]='\0';
	newP.add(newp,size);
	return newP;
}

Paragraph Sentence::operator+(const Paragraph& p){
	Paragraph newP(p);
	int size=(*((head)->next->W)).getsize();
	char* temp=(*((head)->next->W)).tostring();
	newP.insertbeginning(temp,size);
	delete temp;
	return newP;
}
Sentence Sentence::operator++(int x){
	Node* cur=(head->next);
	while(cur){
		(*(cur->W))++;
		cur = cur->next;
	}
	return *this;
}

Sentence Sentence::operator++(){
	Node* cur=(head->next);
	while(cur){
		++(*(cur->W));
		cur = cur->next;
	}
	return *this;
}

Sentence Sentence::operator--(int x){
	Node* cur=(head->next);
	while(cur){
		(*(cur->W))--;
		cur = cur->next;
	}
	return *this;
}

Sentence Sentence::operator--(){
	Node* cur=(head->next);

	while(cur){
		--(*(cur->W));
		cur = cur->next;
	}
	return *this;
}
ostream &operator<<(ostream &output, const Sentence &S){
	Sentence newS(S);
	char* temp=newS.tostring();
	output<<temp;
	delete temp;
    return output;
}