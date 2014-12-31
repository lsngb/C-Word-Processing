#
# Specifiy the target
all:	story

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
story:	driver.o Story.o Paragraph.o Sentence.o Word.o
	g++  driver.o Story.o Paragraph.o Sentence.o Word.o -o story

# Specify how the object files should be created from source files
driver.o:	driver.cpp
	g++ -c -g driver.cpp
Story.o:	Story.cpp Story.h
	g++ -c -g Story.cpp
Paragraph.o: Paragraph.cpp Paragraph.h
	g++ -c -g Paragraph.cpp
Sentence.o:	Sentence.cpp Sentence.h
	g++ -c -g Sentence.cpp
Word.o:	Word.cpp Word.h
	g++ -c -g Word.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o story

