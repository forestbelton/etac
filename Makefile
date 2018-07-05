CFILES := src/main.c src/video.c src/map/map_default.c
OFILES := $(CFILES:.c=.o)

CFLAGS := -Iinclude -I/Users/case/homebrew/Cellar/termbox/1.1.2/include
LDFLAGS := -L/Users/case/homebrew/Cellar/termbox/1.1.2/lib -ltermbox

.PHONY: clean

etac: $(OFILES)
	gcc $(LDFLAGS) $(OFILES) -o $@

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm etac
	find . -type f -name '*.o' -print -delete
