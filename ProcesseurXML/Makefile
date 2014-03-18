#Where to build
BUILDDIR= ./build


#with what build(headers paths)
CFLAGS=-std=c++11 -g -DYYDEBUG
CFLAGS+=-Isrc/model/inc/ -I./


vpath %.cpp src/model/src
#what to build
	#essential
SRC=main.cpp $(BUILDDIR)/xml.tab.c $(BUILDDIR)/lex.xml.c
	#Our project
SRC+=${wildcard src/model/src/*.cpp}

#target file name
OBJ= $(BUILDDIR)/$(SRC:.cpp=.o)

.PHONY: clean

all: commun
commun: 
	@echo $(SRC)
	@echo "--------------------------"
	flex -P xml --outfile=$(BUILDDIR)/lex.xml.c xml.l 
	bison -p xml --debug --verbose --defines=$(BUILDDIR)/xml.tab.h --output=$(BUILDDIR)/xml.tab.c xml.y
	g++ $(CFLAGS)  -o xmltool $(SRC)
	touch commun

%.o: %.cpp
	@echo "coucou !!"
	g++ $(CFLAGS) -c $(CFLAGS) -o $@ $<


clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun $(BUILDDIR)/*
test:
	cd Tests; ./mktest.sh