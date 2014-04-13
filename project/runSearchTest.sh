#!bin/bash

for i in {1..5}
do
	echo $i >> trieSearch.txt
	./autocomplete.out -trie rand_text.txt 100000 $i >> trieSearch.txt
	echo $i >> bwtSearch.txt
	./autocomplete.out -bwt rand_text.txt 100000 $i >> bwtSearch.txt
done
