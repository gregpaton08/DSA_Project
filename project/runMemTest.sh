#!bin/bash

for ((i = 1024; i < 600000; i = i * 2));
do
	echo $i >> trieMem.txt
	./a.out -trie words.txt $i 0 >> trieMem.txt
	echo $i >> bwtMem.txt
	./a.out -bwt words.txt $i 0 >> bwtMem.txt
done
