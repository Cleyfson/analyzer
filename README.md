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

# Input example

#TEXTO<br />
Sofisticado, o Tenis Adidas Top Ten Low Sleek W e o tipo de calcado que faz uma baita diferenca no look da mulher moderna. Confeccionada em Couro predominante, sua parte superior promove um calce suave por longas horas. Alem disso, tem solado em Borracha para excelente tracao em superficies escorregadias. Mude os rumos de sua casualidade, va de Originals e faca efeito em diversas ocasioes.
#ORDEM<br />
Q A Z W S X E D C R F V T G B Y H N M U J I K O L P<br />

# Example Output (referring to example input)

que 1<br />
adidas 1<br />
alem 1<br />
w 1<br />
sua 2<br />
suave 1<br />
superficies 1<br />
superior 1<br />
sofisticado 1<br />
solado 1<br />
sleek 1<br />
e 2<br />
escorregadias 1<br />
excelente 1<br />
efeito 1<br />
em 4<br />
da 1<br />
de 3<br />
disso 1<br />
diferenca 1<br />
diversas 1<br />
casualidade 1<br />
calcado 1<br />
calce 1<br />
confeccionada 1<br />
couro 1<br />
rumos 1<br />
faz 1<br />
faca 1<br />
va 1<br />
ten 1<br />
tenis 1<br />
tem 1<br />
tracao 1<br />
tipo 1<br />
top 1<br />
baita 1<br />
borracha 1<br />
horas 1<br />
no 1<br />
mude 1<br />
mulher 1<br />
moderna 1<br />
um 1<br />
uma 1<br />
o 2<br />
os 1<br />
ocasioes 1<br />
originals 1<br />
low 1<br />
longas 1<br />
look 1<br />
para 1<br />
parte 1<br />
predominante 1<br />
promove 1<br />
por 1<br />
#FIM<br />


