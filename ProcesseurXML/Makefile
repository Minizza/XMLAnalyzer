#Where to build
BUILDDIR= ./build


#with what build(headers paths)
CFLAGS=-std=c++11 -g -DYYDEBUG
CFLAGS+=-Isrc/model/inc -I./ -I./build


vpath %.cpp src/model/src build/
#what to build
	#essential
SRC=main.cpp 
	# src/model/src/enTete.cpp \
	# src/model/src/contructeurRegex.cpp \
	# src/model/src/doctype.cpp \
	# src/model/src/document.cpp \
	# src/model/src/elementComz.cpp \
	# src/model/src/abstractElement.cpp \
	# src/model/src/elementCastre.cpp \
	# src/model/src/elementDonnees.cpp \
	# src/model/src/elementNoeud.cpp \
	# src/model/src/elementBurne.cpp \
	# src/model/src/elementPI.cpp
	#Our project
SRC+=${wildcard src/model/src/*.cpp}
SRC+=${wildcard build/*.cpp}

#target file name
OBJ= $(addprefix $(BUILDDIR)/,$(SRC:.cpp=.o))

.PHONY: clean

all: commun
commun: $(SRC) xml.l xml.y
	@echo $(SRC)
	@echo "--------------------------"
	@echo $(OBJ)
	@echo "--------------------------"
	flex -P xml --outfile=$(BUILDDIR)/lex.xml.cpp xml.l 
	bison -p xml --debug --verbose --defines=$(BUILDDIR)/xml.tab.h --output=$(BUILDDIR)/xml.tab.cpp xml.y
	g++ $(CFLAGS)  -o xmltool $(SRC) $(BUILDDIR)/lex.xml.cpp $(BUILDDIR)/xml.tab.cpp
	touch commun

$(BUILDDIR)/%.o: %.cpp
	@echo "coucou !!"
	g++ $(CFLAGS) -c $(CFLAGS) -o $@ $<



tempo:
	g++ $(CFLAGS)  -o ksjdfkjshdufhlsfdg src/model/src/enTete.cpp
clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun $(BUILDDIR)/*
test:
	cd Tests; ./mktest.sh