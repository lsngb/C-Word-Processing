#include "Word.h"
#include "Sentence.h"
#include <iostream>
using namespace std;

Word::Word(){
	head=new Node;
	head->w=NULL;
	head->next=NULL;
}
Word::Word(const Word& w){
	head=new Node;
	head->w=NULL;
	head->next=NULL;
	Node* cur=(w.head)->next;
	while(cur){
		int size=1;
		for (int i=0;i<50;i++){
			if((cur->w)[i]!='\0'){
				size++;
			}
			else{break;}
		}
		char* word=new char[size];
		for (int i = 0; i < size; i++){
			word[i]=(cur->w)[i];
		}
		Node *newNode = new Node;
		newNode->w = word;
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

Word::~Word(){
	if( head == NULL ) {return;}
	Node* cur=head->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->w;
		delete cur;
		cur=temp;
	}
	delete head;
}
void Word::add(char* word){
	Node *newNode = new Node;
	newNode->w = word;
	newNode->next = NULL;
	Node* cur=head;
	while(cur){
		if(cur->next == NULL) {
			cur->next = newNode;
			break;
		}
		cur = cur->next;
	}
}
void Word::show(){
	Node* cur=head->next;
	while(cur){
		cout<<cur->w;
		cur = cur->next;
	}
}
void Word::getfirstword(){
	if (head->next==NULL)
	{
		return;
	}
	Node* cur=head->next->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->w;
		delete cur;
		cur=temp;
	}
	head->next->next=NULL;
}
void Word::getrestword(){
	Node* cur=head->next;
	Node* temp=head->next->next;
	delete cur->w;
	delete cur;
	head->next=temp;
}
int Word::getsize(){
	int result=0;
	Node* cur=head->next;
	while(cur){
		int size=0;
		for (int i=0;i<50;i++){
			if((cur->w)[i]!='\0'){
				size++;
			}
			else{break;}
		}
		result=result+size;
		cur=cur->next;
	}
	result++;
	return result;
}
char* Word::tostring(){
	int size=(*this).getsize();
	char* wordstring=new char[size];
	int pos=0;
	Node* cur=head->next;
	while(cur){
		for (int i=0;i<50;i++){
			if((cur->w)[i]!='\0'){
				wordstring[pos]=(cur->w)[i];
				pos++;
			}
			else{break;}
		}
		cur=cur->next;
	}
	wordstring[size-1]='\0';
	return wordstring;
}
void Word::capitalfirstword(){
	Node* cur=(head->next);
	if ((cur->w)[0]>96&&(cur->w)[0]<123){
		(cur->w)[0]=(cur->w)[0]-32;
	}
}
Word Word::operator+(int x){
	Word newword;
	newword.head=head;
	if (x==1){
		Node* cur=(head->next);
		while(cur){
			if ((cur->w)[0]>96&&(cur->w)[0]<123){
				(cur->w)[0]=(cur->w)[0]-32;
			}
			cur = cur->next;
		}
	}
	return newword;
}

Sentence Word::operator+(const Word& w){
	Sentence newsentence;
	Node* cur=(*this).head->next;
	while(cur){
		int size=0;
		for (int i = 0; i < 50; i++){
			if(cur->w[i]=='\0'){break;}
			size++;
		}
		newsentence.add(cur->w,size);
		cur=(cur->next);
	}
	cur=(w.head)->next;
	while(cur){
		int size=0;
		for (int i = 0; i < 50; i++){
			if((cur->w)[i]=='\0'){break;}
			size++;
		}
		newsentence.add(cur->w,size);
		cur=(cur->next);
	}
	return newsentence;
}

Sentence Word::operator+(const Sentence& s){
	Sentence newsentence(s);
	Node* cur=(*this).head->next;
	while(cur){
		int size=0;
		for (int i = 0; i < 50; i++){
			if(cur->w[i]=='\0'){break;}
			size++;
		}
		newsentence.insertbeginning(cur->w,size);
		cur=cur->next;
	}
	return newsentence;
}

Word Word::operator++(int x){
	Node* cur=(head->next);
	while(cur){
		for (int i = 0; i < 50; i++){
			if((cur->w)[i]=='\0'){
				break;
			}
			if ((cur->w)[i]>96&&(cur->w)[i]<123){
				(cur->w)[i]=(cur->w)[i]-32;
			}
		}
		cur = cur->next;
	}
	return *this;
}

Word Word::operator++(){
	(*this)--;
	Node* cur=(head->next);
	while(cur){
		int size=0;
		if((cur->w)[0]=='\t'){
			for (int i = 0; i < 50; i++){
				cur->w[i]=cur->w[i+1];
				if(cur->w[i+1]=='\0'){break;}
			}
		}
		for (int i = 0; i < 50; i++){
			if((cur->w)[i]=='\0'){
				size=i+2;
				break;
			}
		}

		if((cur->w)[0]=='a'||(cur->w)[0]=='e'||(cur->w)[0]=='i'||(cur->w)[0]=='o'||(cur->w)[0]=='u'||(cur->w)[0]=='A'||(cur->w)[0]=='E'||(cur->w)[0]=='I'||(cur->w)[0]=='O'||(cur->w)[0]=='U'){
			size++;
			char* newword=new char[size];
			for (int i = 0; i < size-3; i++)
			{
				newword[i]=(cur->w)[i];
			}
			if ((cur->w)[size-5]=='?'||(cur->w)[size-5]=='!'||(cur->w)[size-5]=='.'){
				newword[size-5]='w';
				newword[size-4]='a';
				newword[size-3]='y';
				newword[size-2]=(cur->w)[size-5];
				newword[size-1]=' ';
			}
			else{newword[size-4]='w';
			newword[size-3]='a';
			newword[size-2]='y';
				newword[size-1]=' ';}
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		else if(((cur->w)[0]=='T'&&(cur->w)[1]=='h')||((cur->w)[0]=='t'&&(cur->w)[1]=='h')||((cur->w)[0]=='C'&&(cur->w)[1]=='h')||((cur->w)[0]=='c'&&(cur->w)[1]=='h')||((cur->w)[0]=='S'&&(cur->w)[1]=='h')||((cur->w)[0]=='s'&&(cur->w)[1]=='h')||((cur->w)[0]=='Z'&&(cur->w)[1]=='h')||((cur->w)[0]=='z'&&(cur->w)[1]=='h')){
			char* newword=new char[size];
			for (int i = 0; i < size-4; i++)
			{
				newword[i]=(cur->w)[i+2];
			}
			
			if ((cur->w)[size-4]=='?'||(cur->w)[size-4]=='!'||(cur->w)[size-4]=='.'){
				newword[size-6]=(cur->w)[0];
				newword[size-5]='h';
				newword[size-4]='a';
				newword[size-3]='y';
				newword[size-2]=(cur->w)[size-4];
				newword[size-1]=' ';
			}
			else{
				newword[size-5]=(cur->w)[0];
				newword[size-4]='h';
				newword[size-3]='a';
				newword[size-2]='y';
				newword[size-1]=' ';}
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		else{
			char* newword=new char[size];
			for (int i = 0; i < size-3; i++)
			{
				newword[i]=(cur->w)[i+1];
			}
			
			if ((cur->w)[size-4]=='?'||(cur->w)[size-4]=='!'||(cur->w)[size-4]=='.'){
				newword[size-5]=(cur->w)[0];
			newword[size-4]='a';
			newword[size-3]='y';
				newword[size-2]=(cur->w)[size-4];
				newword[size-1]=' ';
				newword[size]='\0';
			}
			else{
				newword[size-4]=(cur->w)[0];
			newword[size-3]='a';
			newword[size-2]='y';
				newword[size-1]=' ';}
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		cur = cur->next;
	}
	return *this;
}

Word Word::operator--(int x){
	Node* cur=(head->next);
	while(cur){
		for (int i = 0; i < 50; i++){
			if((cur->w)[i]=='\0'){
				break;
			}
			if ((cur->w)[i]>64&&(cur->w)[i]<91){
				(cur->w)[i]=(cur->w)[i]+32;
			}
		}
		cur = cur->next;
	}
	return *this;
}

Word Word::operator--(){
	(*this)--;
	Node* cur=(head->next);
	while(cur){
		int size=0;
		for (int i = 0; i < 50; i++){
			if((cur->w)[i]=='\0'){
				size=i+1;
				break;
			}
		}
		if ((cur->w)[size-3]=='.'||(cur->w)[size-3]=='?'||(cur->w)[size-3]=='!'){
			if((cur->w)[size-6]=='w'){
				size=size-4;
				char* newword=new char[size];
				for (int i = 0; i < size; i++)
				{
					newword[i]=(cur->w)[i];
				}
				
				newword[size-2]=(cur->w)[size+1];
				newword[size-1]=' ';
				
				newword[size]='\0';
				delete cur->w;
				cur->w=newword;
			}

			else if(((cur->w)[size-6]=='h'&&(cur->w)[size-7]=='t')||((cur->w)[size-6]=='h'&&(cur->w)[size-7]=='c')||((cur->w)[size-6]=='h'&&(cur->w)[size-7]=='s')||((cur->w)[size-6]=='h'&&(cur->w)[size-7]=='z')) {
				size=size-3;
				char* newword=new char[size];
				newword[0]=(cur->w)[size-4];
				newword[1]='h';
				for (int i = 2; i < size; i++){
					newword[i]=(cur->w)[i-2];
				}
				newword[size-2]=(cur->w)[size];
				newword[size-1]=' ';
				newword[size]='\0';
				delete cur->w;
				cur->w=newword;
			}
			else{
				size=size-3;
				char* newword=new char[size];
				newword[0]=(cur->w)[size-3];
				for (int i = 1; i < size; i++)
				{
					newword[i]=(cur->w)[i-1];
				}
				newword[size-2]=(cur->w)[size];
				newword[size-1]=' ';
				newword[size]='\0';
				delete cur->w;
				cur->w=newword;
			}

		}
		else{
			if((cur->w)[size-5]=='w'){
			size=size-4;
			char* newword=new char[size];
			for (int i = 0; i < size; i++)
			{
				newword[i]=(cur->w)[i];
			}
			newword[size-1]=' ';
			
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		else if(((cur->w)[size-5]=='h'&&(cur->w)[size-6]=='t')||((cur->w)[size-5]=='h'&&(cur->w)[size-6]=='c')||((cur->w)[size-5]=='h'&&(cur->w)[size-6]=='s')||((cur->w)[size-5]=='h'&&(cur->w)[size-6]=='z')) {
			size=size-3;
			char* newword=new char[size];
			newword[0]=(cur->w)[size-3];
			newword[1]='h';
			for (int i = 2; i < size; i++)
			{
				newword[i]=(cur->w)[i-2];
			}
			newword[size-1]=' ';
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		else{
			size=size-3;
			char* newword=new char[size];
			newword[0]=(cur->w)[size-2];
			for (int i = 1; i < size; i++){
				newword[i]=(cur->w)[i-1];
			}
			newword[size-1]=' ';
			newword[size]='\0';
			delete cur->w;
			cur->w=newword;
		}
		}
		cur=cur->next;
	}
	return *this;
}


ostream &operator<<(ostream &output, const Word &w){
	output<<w.head->next->w;
    return output;
}

Word Word::operator=(const Word& w){
	if(head!=NULL){Node* cur=head->next;
	Node* temp;
	while(cur){
		temp=cur->next;
		delete cur->w;
		delete cur;
		cur=temp;
	}
	delete head;}
	head=new Node;
	head->w=NULL;
	head->next=NULL;
	Node* cur=(w.head)->next;
	while(cur){
		int size=1;
		for (int i=0;i<50;i++){
			if((cur->w)[i]!='\0'){
				size++;
			}
			else{break;}
		}
		char* word=new char[size];
		for (int i = 0; i < size; i++){
			word[i]=(cur->w)[i];
		}
		Node *newNode = new Node;
		newNode->w = word;
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