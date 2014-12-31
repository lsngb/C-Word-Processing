#ifndef Word_H
#define Word_H
#include <iostream>
using namespace std;

class Word;
class Sentence;
class Word{
	struct Node {
		char *w;
		Node *next;
	};
private:
	Node* head;
public:
	Word();
	Word(const Word& w);
	~Word();
	void add(char* word);
	void show();
	void capitalfirstword();
	void getfirstword();
	void getrestword();
	Word operator+(int x);
	Sentence operator+(const Word& w);
	Sentence operator+(const Sentence& s);
	Word operator=(const Word& w);
	Word operator++(int x);//a++
	Word operator++();//++a
	Word operator--(int x);//a--
	Word operator--();//--a
	int getsize();
	char* tostring();
	friend ostream &operator<<( ostream &output, const Word &w);
};
#endif