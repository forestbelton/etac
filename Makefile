CC := gcc-7

CFILES := $(shell find src -type f -name '*.c')
OFILES := $(CFILES:.c=.o)

CFLAGS := -Iinclude -I/Users/case/homebrew/Cellar/termbox/1.1.2/include -I/Users/case/homebrew/Cellar/lua/5.3.4_2/include
LDFLAGS := -L/Users/case/homebrew/Cellar/termbox/1.1.2/lib -ltermbox -L/Users/case/homebrew/Cellar/lua/5.3.4_2/lib -llua

.PHONY: clean

etac: $(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm etac
	find . -type f -name '*.o' -print -delete
