#ifndef Story_H
#define Story_H
class Story;
#include "Paragraph.h"

class Story{
private:
	Paragraph* P;
public:
	Story();
	Story(char filename[]);
	Story(const Story& Bstory);
	~Story();
	void show();
	Paragraph first();
	Story rest();
	void save(char filename[]);
	void addbegin(const Paragraph& p);
	Story operator=(const Story& Bstory);
	Story operator+(const Story& Bstory);
	Story operator+(int x);
	Story operator+(const Paragraph& p);
	Story operator++(int x);//a++
	Story operator++();//++a
	Story operator--(int x);//a--
	Story operator--();//--a
	friend ostream &operator<<(ostream &output, const Story &str);
};
#endif