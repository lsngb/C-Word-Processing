#ifndef Sentence_H
#define Sentence_H
class Sentence;
class Paragraph;
#include "Word.h"

class Sentence{
	struct Node {
		Word* W;
		Node *next;
	};
public:
	Sentence();
	Sentence(const Sentence& s);
	~Sentence();
	void add(char sentence[],int Ssize);
	void insertbeginning(char sentence[],int Ssize);
	void getfirstsentence();
	void getrestsentence();
	void show();
	Word first();
	Sentence rest();
	int getsize();
	char* tostring();
	Sentence operator*(const Sentence& s);
	Sentence operator=(const Sentence& s);
	Sentence operator+(int x);
	Paragraph operator+(const Paragraph& p);
	Sentence operator+(const Word& w);
	Paragraph operator+(const Sentence& s);
	Sentence operator++(int x);//a++
	Sentence operator++();//++a
	Sentence operator--(int x);//a--
	Sentence operator--();//--a
	friend ostream &operator<<(ostream &output, const Sentence &S);
private:
	Node* head;
};
#endif