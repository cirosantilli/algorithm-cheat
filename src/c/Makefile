.POSIX:

IN_EXT ?= .c
OUT_EXT ?= .out

INS := $(wildcard *$(IN_EXT))
OUTS_NOEXT := $(basename $(INS))
OUTS := $(addsuffix $(OUT_EXT), $(OUTS_NOEXT))

.PHONY: all clean run

all: $(OUTS)

%$(OUT_EXT): %$(IN_EXT)
	gcc -O0 -Wall -ggdb3 -pedantic-errors -o '$@' -std=c99 '$<'

clean:
	rm *$(OUT_EXT)

clean:
	rm *$(OUT_EXT)

run: all
	./"$(RUN)$(OUT_EXT)"
