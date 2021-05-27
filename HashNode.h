#ifndef HASHNODE_H
#define HASHNODE_H

#include<iostream>
#include<iomanip>
using namespace std;

class HashNode
{
    private:
    string key;         //stores a word
    int count;          //stores the number of occurences of word
    int code;            // stores the encoding of word.

    public:
    HashNode(string S);
    string get_key() const;
    int get_count() const;
    int get_code() const;
    void set_code(int x);
    void incr_count();
    friend ostream& operator<<(ostream& os, const HashNode& node);
};

#endif
