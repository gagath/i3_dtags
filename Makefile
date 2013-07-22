CFLAGS=-W -Wall -Wextra -std=c89 -pedantic -ansi -O2
EXEC=i3-dtags
SCRIPT=i3-dtags.sh

.PHONY: clean, install

all: $(EXEC)

$(EXEC): i3-dtags.c
	$(CC) -lcjson $(CFLAGS) -o $(EXEC) i3-dtags.c

install: $(EXEC)
	cp $(EXEC) /usr/local/bin/
	cp $(SCRIPT) /usr/local/bin/

clean:
	rm i3-dtags
