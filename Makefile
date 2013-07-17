.PHONY: clean

dtags: dtags.c
	gcc -lcjson -o dtags dtags.c

clean:
	rm dtags
