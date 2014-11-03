==================================
wordcount dictfile [inputfile ...]
==================================

wordcount parses a dictionary file as follows:

* a line with a single word defines a word to be counted in the input stream
* empty lines and line starting with # are ignored


wordcount then filters its input stream, the concatenation of all input files specified on
the command line or standard input if none is given.


wordcount must count the number of occurrence of any word in the dictfile that appears
in the input streams, and also count the total number of words. Matching is performed
on a full word basis. Words are delimited by white space.


A suggested output format is: nnn TAB word CR, which would yield something like:

10 foo

20 bar

104 frotz

19274 total words


Implementation should be simple and efficient, dictionary size should be limited only
by memory. An arbitrary limit on line length is OK for the dictionary, but should be
unnecessary on input stream.


You should not spend more than 3 or 4 hours on this exercise. We do not insist on
a complete solution, however, we ask for a small document describing the work
accomplished: program limitations, possible areas for improvement...


Your submission will be evaluated on the following aspects:

* Presentation, readability, conciseness.
* Choice of algorithms, implementation, correctness, sturdiness.
* Compilation without errors, portability, efficiency.
* Documentation, tests, possible extensions.