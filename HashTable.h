#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<vector>
#include<algorithm>
#include "HashNode.h"

#define P 53
#define M 1000000009
using namespace std;



class HashTable
{
    public:
    int size;                          //size of table
    int curr_size;                  //Total unique words;
    long long int Power_P[30];      //Helper array for hashing
    HashNode ** table;              //Array of HashNode pointers
    vector<HashNode *> Sorted_Node; //vector to store sorted nodes of HashTable


    HashTable(int N);               //constructor
    int hash(string S)const ;       //hashing function
    void insertNode(string S);      //inserting a string into S
    int search(string S) const;     //searching the hastable 

    int encode(string S) const;     //encoding a string according to Sorted_Node vector 
    string decode(int x) const;     //decoding a string according to sorted_Node vector 

    void table_sort();              // sortinfg the unique words according to the count 
};

#endif