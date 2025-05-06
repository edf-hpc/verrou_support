
DIFFTOOL=meld
DIFF=diff

all: cvPlot.pdf dd-line

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

#question 7.c
check-dd-script:
	mkdir -p check-ddRun
	./ddRun check-ddRun
	bash -c './ddCmp check-ddRun check-ddRun ; echo $$? "(0 expected)"'
	@cp -r check-ddRun check-ddRunDiff
	@cat check-ddRun/res.dat | tail -1 > check-ddRunDiff/res.dat #en enlève la dernière ligne 
	bash -c './ddCmp check-ddRun check-ddRunDiff ; echo $$? "(1 expected)"' 

#question 17
dd-line: unitTest ddRun ddCmp
	verrou_dd_line --nruns=1 --cache=clean ./ddRun ./ddCmp

#question 7.d
dd-line-pycmp: unitTest ddRun ddCmp.py
	verrou_dd_line --rep=dd.line.pycmp --cache=clean ./ddRun ./ddCmp.py

#question 9.b
post-verrou-dd: dd-line
	post_verrou_dd --trace-bin --nruns=10 ./ddRun ./ddCmp
	cd dd.line; \
	$(DIFFTOOL) NoPerturbation-trace/default/dd.run0/cover FullPerturbation-trace/default/dd.run0/cover ; \
	$(DIFFTOOL) NoPerturbation-trace/default/dd.run0/cover FullPerturbation-trace/default/dd.run1/cover ; \

#	$(DIFFTOOL) NoPerturbation-trace/default/dd.run0/cover ddmin1-trace/default/dd.run0/cover ; \
#	$(DIFFTOOL) NoPerturbation-trace/default/dd.run0/cover ddmin1-trace/default/dd.run1/cover 

LISTE.EX: unitTest
	valgrind --tool=verrou --libm=manual_exclude --gen-exclude=LISTE.EX ./unitTest 1.1
	emacs LISTE.EX #user expertise

plot.stat: unitTest
	verrou_plot_stat --cache=clean --num-threads=6 --nruns=50 ./ddRun ./ddCmp.py
	verrou_plot_stat --nruns=50 ./ddRun ./ddCmp2.py	

dd-sym: unitTest ddRun ddCmp
	verrou_dd_sym --cache=clean ./ddRun ./ddCmp

clean:
	xargs rm -rf <to_clean
