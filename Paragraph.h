#ifndef Paragraph_H
#define Paragraph_H
class Story;
class Paragraph;


#include "Sentence.h"


class Paragraph{
	struct Node {
		Sentence* S;
		Node *next;
	};
private:
	Node* head;
public:
	Paragraph();
	Paragraph(const Paragraph& p);
	~Paragraph();
	int getsize();
	char* tostring();
	void add(char paragraph[],int Psize);
	void addbegin(char paragraph[],int Psize);
	void insertbeginning(char paragraph[],int Psize);
	void getfirstparagraph();
	void getrestparagraph();
	void show();
	Sentence first();
	Paragraph rest();
	Paragraph operator%(const Paragraph& p);
	Paragraph operator=(const Paragraph& p);
	Paragraph operator+(int x);
	Paragraph operator+(const Paragraph& p);
	Story operator+(const Story& str);
	Paragraph operator+(const Sentence& s);
	Paragraph operator++(int x);//a++
	Paragraph operator++();//++a
	Paragraph operator--(int x);//a--
	Paragraph operator--();//--a
	friend ostream &operator<<(ostream &output, const Paragraph &P);
};

#endif