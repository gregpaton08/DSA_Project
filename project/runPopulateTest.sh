#!bin/bash

for ((i = 1024; i < 600000; i = i * 2));
do
	echo $i >> triePop.txt
	./a.out -trie rand_text.txt $i 0 >> triePop.txt
	echo $i >> bwtPop.txt
	./a.out -bwt rand_text.txt $i 0 >> bwtPop.txt
done
