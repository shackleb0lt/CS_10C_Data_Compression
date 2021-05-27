# CS_10C_Data_Compression

Simple data compression by encoding most frequently occuring words with shorter "words" to reduce file size. The transformstion matrix is calculated by keeping track of how many times a word occurs. Read the pdf to find further details.

To make an executable 
```bash
make all
```
To run the program on sample file use 
```bash
./encoder <filename>
```
You can compare the size of original and encoded files, also a transformation matrix is stored in encoding.txt.