FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla  -lm -Werror
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

all: pa04

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<

test: clean test_comb test_sum test_per

test_comb: clean test2 test4 test6 test10 test11

test_sum: clean test3 test5 test8 test12 test13

test_per: clean test1 test7 test9 test14 test15

test1: pa04
	./$(BINDIR)/pa04 -p Test-Cases/Test/test1.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected1.txt

test2: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test2.txt 4 > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected2.txt

test3: pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test3.txt  > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected3.txt

test4: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test1.txt 3 > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected4.txt

test5: pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test5.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected5.txt

test6: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -c Test-Cases/Test/test1.txt 3 > temp.txt

test7: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -p Test-Cases/Test/test1.txt > temp.txt

test8: pa04
	$(VALGRIND) ./$(BINDIR)/pa04 -sp Test-Cases/Test/test5.txt > temp.txt

test9: pa04
	./$(BINDIR)/pa04 -p Test-Cases/Test/test6.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected6.txt

test10: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test6.txt 3 > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected7.txt

test11: pa04
	./$(BINDIR)/pa04 -c Test-Cases/Test/test1.txt 4 > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected8.txt

test12:pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test7.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected9.txt

test13:pa04
	./$(BINDIR)/pa04 -sp Test-Cases/Test/test8.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected10.txt

test14:pa04
	./$(BINDIR)/pa04 -p Test-Cases/Test/test8.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected11.txt

test15:pa04
	./$(BINDIR)/pa04 -p Test-Cases/Test/test3.txt > temp.txt
	python ./$(OBJDIR)/diff.py temp.txt Test-Cases/Expected/expected12.txt


.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt


