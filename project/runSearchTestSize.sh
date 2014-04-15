#!bin/bash

for ((i = 1024; i < 600000; i = i * 2));
do
	echo $i >> triePop.txt
	./autocomplete -trie rand_text.txt $i 3 >> trieSearchSize.txt
	echo $i >> bwtPop.txt
	./autocomplete -bwt rand_text.txt $i 3 >> bwtSearchSize.txt
done
