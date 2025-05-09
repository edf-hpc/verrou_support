MAIN = main.tex
DOC  = $(MAIN:.tex=.pdf)

.PHONY: $(DOC)
$(DOC):
	latexmk -pdf $(MAIN)

continuous:
	latexmk -pdf -pvc $(MAIN)

clean:
	latexmk -c $(MAIN)

distclean: clean
	latexmk -C $(MAIN)

install: $(DOC)
	cp $(DOC) ../tp-verrou/tp-verrou.pdf
