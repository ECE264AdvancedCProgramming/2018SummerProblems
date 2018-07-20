TARGET 		= pa07
GCC 		= gcc
CFLAGS		= -c
LDFLAGS		= -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
BINDIR		= bin
OBJDIR		= obj 
CC 		= $(GCC) $(LDFLAGS)
SRCS 		= pa07.c frequency.c list_node.c tree.c
OBJS 		= $(SRCS:%.c=$(BINDIR)/%.o)
VALGRIND 	= valgrind --tool=memcheck --verbose --log-file

all: $(TARGET)

test: test1 test2 test3 test4 test5 test6 test7 valtest

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o ./$(BINDIR)/$(TARGET)

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

test1: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/simple1.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedSimple1.txt

test2: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/simple2.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedSimple2.txt

test3: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/test1.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedTest1.txt

test4: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/test2.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedTest2.txt

test5: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/wiki1.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedWiki1.txt

test6: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/wiki2.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedWiki2.txt

test7: $(TARGET)
	./$(BINDIR)/$(TARGET) Test-Cases/Test/wiki3.txt > temp.txt
	diff temp.txt Test-Cases/Expected/expectedWiki3.txt

valtest: $(TARGET)
	$(VALGRIND)=expected/valgrind.log ./$(BINDIR)/$(TARGET) Test-Cases/Test/wiki1.txt > /dev/null

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *~
	rm -f -r $(BINDIR)
