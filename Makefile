LATEX=pdflatex
BIBTEX=biber
titel=masterarbeit_boes_hermann
PAGES=end-end

all:
	$(LATEX) $(titel)
	makeindex $(titel).nlo -s nomencl.ist -o $(titel).nls
	makeindex $(titel).idx -o $(titel).ind
	$(BIBTEX) $(titel)

silent:
	$(LATEX) -interaction=nonstopmode $(titel) 2>&1 > /dev/null
	makeindex -q $(titel).nlo -s nomencl.ist -o $(titel).nls
	makeindex -q $(titel).idx -o $(titel).ind
	$(BIBTEX) $(titel) > /dev/null
	$(LATEX) -interaction=nonstopmode $(titel) 2>&1 > /dev/null
	makeindex -q $(titel).nlo -s nomencl.ist -o $(titel).nls
	makeindex -q $(titel).idx -o $(titel).ind
	$(BIBTEX) $(titel) > /dev/null
	$(LATEX) -interaction=nonstopmode $(titel) 2>&1 > /dev/null
	makeindex -q $(titel).nlo -s nomencl.ist -o $(titel).nls
	makeindex -q $(titel).idx -o $(titel).ind
	$(BIBTEX) $(titel) > /dev/null

.PHONY: pictures david

pictures:
	find pictures -name \*.tex -exec bash -c 'echo {}; pdflatex -output-directory=pictures {} 2>&1 > /dev/null' \;
	find pictures -name \*.svg -exec bash -c 'echo {}; filename={}; inkscape -D -z --file=$$filename --export-pdf=$${filename%.svg}.pdf --export-latex' \;

david:
	pdftk $(titel).pdf cat $(PAGES) output $(titel)-david.pdf

clean:
	rm -f $(titel).idx $(titel).ilg $(titel).ind $(titel).nlo $(titel).nls $(titel).toc $(titel).bbl $(titel).blg $(titel).aux $(titel).log $(titel).out $(titel).pdf $(titel).bcf $(titel).run.xml
