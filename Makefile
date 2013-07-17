CFLAGS=-W -Wall -Wextra -std=c89 -pedantic -ansi -O2
EXEC=dtags

.PHONY: clean

all: $(EXEC)

$(EXEC): dtags.c
	$(CC) -lcjson $(CFLAGS) -o $(EXEC) dtags.c

clean:
	rm dtags
