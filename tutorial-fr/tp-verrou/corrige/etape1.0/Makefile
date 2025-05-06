
DIFFTOOL=meld
DIFF=diff

all: cvPlot.pdf check

unitTest: unitTest.cxx integrate.hxx
	g++ -Wall -g -O3 -o $@ $<

cvPlot.pdf: unitTest cvPlot.gp
	./cvPlot

#question 2
check: unitTest
	./unitTest                                                > out.ref
	valgrind --tool=none ./unitTest                           > out.vg-none
	valgrind ./unitTest                                       > out.vg-mem
	valgrind --tool=verrou --rounding-mode=nearest ./unitTest > out.vg-verrou
	$(DIFF) out.ref out.vg-none
	$(DIFF) out.ref out.vg-mem
	$(DIFF) out.ref out.vg-verrou

clean:
	xargs rm -rf <to_clean
