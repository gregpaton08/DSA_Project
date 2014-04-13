#!bin/bash

for ((i = 1024; i < 600000; i = i * 2));
do
	echo $i >> triePop.txt
	./autocomplete.out -trie rand_text.txt $i 0 >> triePop.txt
	echo $i >> bwtPop.txt
	./autocomplete.out -bwt rand_text.txt $i 0 >> bwtPop.txt
done
