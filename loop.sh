#!/bin/sh
for i in {1..5}
do
	if test -r signal.txt -a -e signal.txt; then
		rm signal.txt*
	fi
	
	if test -r bkg.txt -a -e bkg.txt; then
		rm bkg.txt*
	fi

	root -b -q run.cpp++

	if test $i -eq 1; then
		python3 llqq_mva.py "first"
		#python3 llqq_mva.py "later"
	else
		python3 llqq_mva.py "later"
	fi
	
	cp model1_architecture_c.json model1_architecture.json
	cp model1_weights_c.h5 model1_weights.h5
	rm model1_architecture_c.json
	rm model1_weights_c.h5

done
