G ?= gdb3
IN_EXT ?= .cpp
O ?= 0
OUT_EXT ?= .out

INS := $(wildcard *$(IN_EXT))
OUTS_NOEXT := $(basename $(INS))
OUTS := $(addsuffix $(OUT_EXT), $(OUTS_NOEXT))

.PHONY: all clean

all: $(OUTS)

%$(OUT_EXT): %$(IN_EXT)
	g++ -g'$(G)' -O'$(O)' -pg -pthread -std=c++11 -Wextra -o '$@' '$<'

clean:
	rm -f *$(OUT_EXT)
