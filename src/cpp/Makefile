IN_EXT ?= .cpp
OUT_EXT ?= .out

INS := $(wildcard *$(IN_EXT))
OUTS_NOEXT := $(basename $(INS))
OUTS := $(addsuffix $(OUT_EXT), $(OUTS_NOEXT))

.PHONY: all clean

all: $(OUTS)

%$(OUT_EXT): %$(IN_EXT)
	g++ -g -o '$@' -std=c++11 '$<'

clean:
	rm *$(OUT_EXT)
