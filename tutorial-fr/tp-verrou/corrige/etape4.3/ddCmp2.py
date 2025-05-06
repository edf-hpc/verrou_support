#!/usr/bin/python3
import sys
import os
def extractValue(rep):
    lines=(open(os.path.join(rep, "res.dat"))).readlines()
    lastLine=lines[-2] #dernière ligne
    return float(lastLine.split()[1]) # deuxième colonne

if __name__=="__main__":
    if len(sys.argv)==2:
        #this case is to be compatible with the extract script
        # of verrou_plot_stat and to simplify debug
        print(extractValue(sys.argv[1]))
    if len(sys.argv)==3:
        valueRef=extractValue(sys.argv[1])
        value=extractValue(sys.argv[2])
        relDiff=abs((value-valueRef)/valueRef)
        if relDiff < 1.0e-6:
            sys.exit(0) #OK
        else:
            sys.exit(1) #KO
