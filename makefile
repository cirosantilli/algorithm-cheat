CC=pandoc
FLAGS=

OUTDIR=_out

INEXT=.md
OUTEXT=.html
SRCS = $(wildcard *$(INEXT))
OUT = $(patsubst %$(INEXT),$(OUTDIR)/%$(OUTEXT),$(SRCS))

firefox: all
	firefox $(OUT)

all: $(OUT)

$(OUTDIR)/%.html: %.md
	@mkdir -p $(OUTDIR)
	$(CC) $(FLAGS) -o $@ $<

clean:
	@rm -r $(OUTDIR)
