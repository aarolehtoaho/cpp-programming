EXE = intro
SUB = RGBA
OBJS = main.o intro.o $(SUB)/png.o $(SUB)/rgbapixel.o

COMPILER = g++
COMPILER_OPTS = -std=c++17 -c -g -O0 -Wall -Wextra -pedantic-errors -Werror
LINKER = g++
LINKER_OPTS = -lpng

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)

main.o : main.cpp intro.h $(SUB)/png.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

intro.o : intro.cpp intro.h $(SUB)/png.h $(SUB)/rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) intro.cpp

png.o : $(SUB)/png.cpp $(SUB)/png.h $(SUB)/rgba.h
	$(COMPILER) $(COMPILER_OPTS) $(SUB)/png.cpp

rgbapixel.o : $(SUB)/rgbapixel.cpp $(SUB)/rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) $(SUB)/rgbapixel.cpp

clean:
	-rm -f *.o $(EXE)
