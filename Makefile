
PROG = main.exe 
SRC = main.c saveinput.c menu.c 
CFLAGS=-Wall -Werror -g
LIBS = 
all: $(PROG)
$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 
clean:
	rm -f $(PROG)
.PHONY: all clean