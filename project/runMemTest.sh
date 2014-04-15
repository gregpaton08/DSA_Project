#!bin/bash

for ((i = 1024; i < 600000; i = i * 2));
do
	echo $i >> trieMem.txt
	./autocomplete -trie words.txt $i 0 >> trieMem.txt
	echo $i >> bwtMem.txt
	./autocomplete -bwt words.txt $i 0 >> bwtMem.txt
done
