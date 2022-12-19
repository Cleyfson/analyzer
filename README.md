# analyzer

 project developed in C++, for the discipline of data structures at UFMG.

The proposed problem was to implement a system that would take care of the analysis of the
number of occurrences of certain words in a text, organizing them according to a
new lexicographical order. In this system, for a set of words, which
appeared in a text, it would be necessary to treat them, removing unwanted signs
and specify the number of times that word appears in the text.
In addition, it would be necessary to organize such words according to the lexicographical order
specified.

# Implementation

The program was developed in the C++ language, compiled by the GNU GCC compiler
Compiler Collection, on the Linux operating system.

# Data structure

The implementation of the program was based on the data structure of a
doubly linked list, in which the cell-like entities (which contained the type
palavra) were entered. This preference was given due to the fact that we did not have
a specific value for the number of words in the text. In addition, the
use of a doubly linked list ends up facilitating the use of the algorithm
quicksort compared to a single-linked list. This structure of
data was assembled in a class called LinkedList. following default standards.

# Classes

To modularize the implementation, 3 classes were used, the first of them
being the TipoPalavra, containing as attributes key and quantity, being the
key class for creating the list of words present in the text read, also and
in this class we have functions that handle words, such as the
removal of symbols and transformation to the lowercase form of words.

We have the TipoCelula class, which was used more as a helper class to
assembly of the doubly linked list, the cell stores a TipoCelula and
pointers to the next cell and the previous cell.

Finally, we have the ListaEncadeada class that has the cell type first and
last, pointing to the first and last TipoCelula of our word list. This class have the necessary functions for inserting the
TipoPalavra in the list and also for realizations of some specified requirements
at work, such as the quicksort function, the selection function, the registration of words and their
quantities in a text file output, etc.

# Lexicographic order

for sorting to be performed correctly in a lexicographical order
different, some functions were implemented in the TipoPalavra class, being them
letraValor(), menorTam() and palavraMaior() and an external variable was also used
of type vector of characters called dictionary that was defined in main. two string
are compared,each character, where the value of the character is given by its position in the
dictionary vector, which is defined in main using the order presented by the base
input file. In this way it is possible to know the positional level of each
word, given different lexicographical order.

# Instructions for compiling and running

1. get the analyze folder. enter the folder and run the makefile using the "make" command (in the folder, there are already
   entrada.txt with a few test runs)
2. the "make" command will generate the \*.o file, and also executable in the bin folder.
3. For the "make run" command to work, the input folder must be in the root next to the makefile,
4. the command “make run” will generate the folder output in the root folder of the
   makefile with results
