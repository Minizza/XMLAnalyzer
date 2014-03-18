#Where to build
BUILDDIR= ./build

#with what build
CFLAGS=-I./build -I./

all: commun
commun: *.l *.y *.cpp *.h
	flex -P xml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	g++ -std=c++11 -g -DYYDEBUG -o xmltool main.cpp xml.tab.c lex.xml.c
	touch commun
clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun $(BUILDDIR)/*
test:
	cd Tests; ./mktest.sh

temp: *.l *.y *.cpp *.h
	flex -P xml --outfile=$(BUILDDIR)/lex.xml.c xml.l 
	bison -p xml --debug --verbose --defines=$(BUILDDIR)/xml.tab.h --output=$(BUILDDIR)/xml.tab.c xml.y
	g++ $(CFLAGS) -std=c++11 -g -DYYDEBUG -o xmltool main.cpp $(BUILDDIR)/xml.tab.c $(BUILDDIR)/lex.xml.c
	touch commun