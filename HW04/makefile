FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		= 
BINDIR		= bin
OBJDIR		= obj
SRC 		= pa04.c
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	= $(OBJDIR)/parse.o
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

pa04:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pa04

all: pa04 test

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<

test: test1 test2 test3 test4 test5 test6 test7 test8

test1: pa04
	./$(BINDIR)/pa04 -p Test-Cases/Test/test1.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expected1.txt

test2: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test2.txt 4 > temp.txt
	diff temp.txt Test-Cases/Expected/expected2.txt

test3: pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test3.txt  > temp.txt
	diff temp.txt Test-Cases/Expected/expected3.txt

test4: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test1.txt 3 > temp.txt
	diff temp.txt Test-Cases/Expected/expected4.txt

test5: pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test5.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expected5.txt

test6: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -c Test-Cases/Test/test1.txt 3 > temp.txt

test7: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -p Test-Cases/Test/test1.txt > temp.txt

test8: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -sp Test-Cases/Test/test5.txt > temp.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt


