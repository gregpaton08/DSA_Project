Run on Mac OSX 10.9.2.

Call make to compile.
Binary is named 'autocomplete'.

To run user mode call either
	./autocomplete -bwt
or
	./autocomplete -trie
then enter words to populate the dictionary. Type 'QUIT' when you are done
populating the dictionary. Then type the first few letters of a word to get
the top three results.

To run in test mode specify a file for input
	./autocomplete -bwt rand_text.txt

To run using a limited number of words from that file run
	./autocomplete -bwt rand_text.txt 10000

To run specifying the length of the search string run
	./autocomplete -bwt rand_text.txt 10000 2
default value is 3.




https://github.com/gregpaton08/DSA_Project