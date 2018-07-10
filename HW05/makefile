FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		=
BINDIR		= bin
OBJDIR 		= obj
SRC 		= $(wildcard *.c)
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	=
VALGRIND 	= valgrind --tool=memcheck --leak-check=full
DIFF		= python ./$(OBJDIR)/diff.py

all: pa05

pa05:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pa05

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<

test: clean pa05 test1 test2 test3 test4 test5 testmem

test1:  pa05
	./$(BINDIR)/pa05 SORT_BY NAME > temp.txt
	$(DIFF) temp.txt Test-Cases/Expected/expected1.txt 1

test2:  pa05
	./$(BINDIR)/pa05 SORT_BY ID > temp.txt
	$(DIFF) temp.txt Test-Cases/Expected/expected2.txt 0

test3:  pa05
	./$(BINDIR)/pa05 SORT_BY YEAR > temp.txt
	$(DIFF) temp.txt Test-Cases/Expected/expected3.txt 2

test4:  pa05
	./$(BINDIR)/pa05 SORT_BY ID WHERE NAME ">" D > temp.txt
	$(DIFF) temp.txt Test-Cases/Expected/expected4.txt 0

test5:  pa05
	./$(BINDIR)/pa05 SORT_BY ID WHERE NAME "<" B > temp.txt
	$(DIFF) temp.txt Test-Cases/Expected/expected5.txt 0

testmem:pa05
	$(VALGRIND) ./$(BINDIR)/pa05 SORT_BY ID WHERE NAME "<" B > temp.txt


.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f *~
	rm -f temp.txt
