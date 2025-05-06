
DIFFTOOL=meld
DIFF=diff

all: cvPlot.pdf

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

#question 4
explore: unitTest
	 ./unitTest > out.ref
	valgrind --tool=verrou --rounding-mode=random ./unitTest > out.random_1
	valgrind --tool=verrou --rounding-mode=random ./unitTest > out.random_2
	valgrind --tool=verrou --rounding-mode=random ./unitTest > out.random_3
	$(DIFFTOOL) out.ref out.random_1
	$(DIFFTOOL) out.ref out.random_2
	$(DIFFTOOL) out.ref out.random_3


clean:
	xargs rm -rf <to_clean
