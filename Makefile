CFILES := $(shell find src -type f -name '*.c')
OFILES := $(CFILES:.c=.o)

CFLAGS := -Iinclude $(INCLUDES)
LDFLAGS := $(LIBS) -ltermbox -llua

.PHONY: clean

etac: $(OFILES)
	$(CC) $(OFILES) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f etac
	find . -type f -name '*.o' -print -delete
