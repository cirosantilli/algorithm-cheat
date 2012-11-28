CC=pandoc
FLAGS=

OUTDIR=_out

INEXT=.md
OUTEXT=.html
SRCS = $(wildcard *$(INEXT))
OUT = $(patsubst %$(INEXT),$(OUTDIR)/%$(OUTEXT),$(SRCS))

.PHONY: firefox all clean

all: $(OUT)

firefox: all
	firefox $(OUT)

$(OUTDIR)/%.html: %.md
	@mkdir -p $(OUTDIR)
	$(CC) $(FLAGS) -o $@ $<

clean:
	@rm -r $(OUTDIR)
