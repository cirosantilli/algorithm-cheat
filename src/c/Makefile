IN_EXT ?= .c
OUT_EXT ?= .out

INS := $(wildcard *$(IN_EXT))
OUTS_NOEXT := $(basename $(INS))
OUTS := $(addsuffix $(OUT_EXT), $(OUTS_NOEXT))

.PHONY: all clean

all: $(OUTS)

%$(OUT_EXT): %$(IN_EXT)
	gcc -o '$@' -std=c89 '$<'

clean:
	rm *$(OUT_EXT)
