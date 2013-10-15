CC=g++
CPPLIBS=-lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-graphics
#CPPFLAGS=

## Dependencies ##
CPP_FILES=$(wildcard src/*.cpp)
HPP_FILES=$(wildcard inc/*.hpp)
OBJ_FILES=$(addprefix obj/,$(notdir $(CPP_FILES)))

## Targets ##

all: src/Good-bye

src/Good-bye: $(OBJ_FILES)
	g++ -o $@ $^ $(OBJ_FILES)

obj/%.o: src/%.cpp inc/%.hpp
	g++ -c -o $@ $<

clean: 
	rm $(OBJ_FILES) src/Good-bye
