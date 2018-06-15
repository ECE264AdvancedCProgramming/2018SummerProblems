FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		=
BINDIR		= bin
OBJDIR		= obj
SRC 		= pe02.c
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	= $(OBJDIR)/mem_mgmt.o $(OBJDIR)/mean_shift.o
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

all: pe02

pe02:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pe02

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<


test: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11

test1: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test1.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected1.txt

test2: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test2.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected2.txt

test3: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test3.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected3.txt

test4: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test4.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected4.txt

test5: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test5.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected5.txt

test6: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test6.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected6.txt

test7: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test7.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected7.txt

test8: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test8.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected8.txt

test9: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test9.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected9.txt

test10: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test10.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected10.txt

test11: pe02
	$(VALGRIND) ./$(BINDIR)/pe02 Test-Cases/Test/test4.txt temp.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt


