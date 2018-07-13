FLAGS 			= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 			= gcc $(FLAGS)
CFLAGS			= -c
LDFLAGS			= 
BINDIR			= bin
OBJDIR			= obj
SRC 			= pa03.c $(OBJDIR)/solution_interface.c
OBJS 			= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES		= $(OBJDIR)/euclid_distance.o $(OBJDIR)/get_weight.o $(OBJDIR)/tester.o
VALGRIND 		= valgrind --tool=memcheck --leak-check=full
DEFINE_MEANSHIFT	= -DTEST_ALLOC -DTEST_FREE -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_ALLOC		= -DTEST_MEANSHIFT -DTEST_FREE -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_FREE		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_NEIGH		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_FREE -DTEST_MEAN
DEFINE_MEAN		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_FREE -DTEST_NEIGHBOURS
DUMMY			= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_FREE -DTEST_NEIGHBOURS -DTEST_MEAN

all: pa03

pa03:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pa03

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<


test: clean pa03 testall

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 testmem

test1:
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt

test2:
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt

test3:
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt

test4:
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test5:
	./$(BINDIR)/pa03 Test-Cases/Test/test5.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected5.txt

test6:
	./$(BINDIR)/pa03 Test-Cases/Test/test6.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected6.txt

test7:
	./$(BINDIR)/pa03 Test-Cases/Test/test7.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected7.txt

test8:
	./$(BINDIR)/pa03 Test-Cases/Test/test8.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected8.txt

test9:
	./$(BINDIR)/pa03 Test-Cases/Test/test9.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected9.txt

test10:
	./$(BINDIR)/pa03 Test-Cases/Test/test10.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected10.txt

testmem:
	$(VALGRIND) ./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt

test_alloc: clean 
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_ALLOC) -o $(BINDIR)/pa03
	make testall

test_dealloc: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_FREE) -o $(BINDIR)/pa03
	make testall

test_mean: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_MEAN) -o $(BINDIR)/pa03
	make testall

test_neigh: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_NEIGH) -o $(BINDIR)/pa03
	make testall


test_meanshift: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_MEANSHIFT) -o $(BINDIR)/pa03
	make testall

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt
