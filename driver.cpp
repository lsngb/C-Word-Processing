#include "Story.h"
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Story Astory("Brady.txt");
	Astory=Astory.first()+Astory;
	cout<<Astory;
	cout<<Astory<<endl;
	cout<<"xxxxxxx "<<Astory.first().first().getsize()<<endl;
	cout<<Astory;
	Story Bstory(Astory);
	Bstory=Astory;
	Sentence S;
	S=Astory.first().first();
	++Astory;
	Paragraph P(Bstory.first());
	P++;
	P--;
	++P;
	--P;
	cout<<P;
	--Astory;
	cout<<Astory;
	Astory++;
	Astory--;
	Bstory=Astory.rest();
	cout<<"aaaaaaaaaaaaaaaaaa"<<Bstory<<endl;
	Bstory=Astory.rest();
	cout<<Bstory;
	cout<<"aaaaaaaaaaaaaaaaaa"<<Bstory<<endl;
	Astory.rest();
	S++;
	S--;
	++S;
	--S;
	S=Bstory.first().first();
	Word W;
	cout<<S<<endl;
	W=S.first();
	W++;
	W--;
	++W;
	--W;
	P+S;
	W+S;
	S+W;
	cout<<S<<endl;
	cout<<P<<endl;
	cout<<S+P;
	cout<<S.first()<<endl;
	cout<<W;
	Astory.first().first().rest()+S.first();
	Story Cstory(Astory);
	++Bstory;
	cout<<"aaaaaaaaaaaaaaaaaa"<<Bstory<<endl;
	--Bstory;
	cout<<Bstory;

	cout<<(Cstory.first()+Bstory.rest())<<endl;
	Bstory.save("out.txt");

	return 0;
}