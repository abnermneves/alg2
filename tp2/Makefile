CC := g++
SRCDIR := 
OBJDIR := build
BINDIR := bin

MAIN := main.cpp

SRCEXT := cpp
SOURCES := $(shell find -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# -g debug, --coverage para cobertura
CFLAGS := -g -Wall -O3 -std=c++11
INC := 

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o tp2

all: main

run: main
	./tp2

clean:
	$(RM) -r $(OBJDIR) $(BINDIR) coverage/* *.o *.gcda *.gcno *.gcov tp1 testes/*.z78

.PHONY: clean coverage
