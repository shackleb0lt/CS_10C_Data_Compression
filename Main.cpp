#include<iostream>
#include<fstream>
#include "HashTable.h"
using namespace std;

//Function to get the file size.
int get_file_size(std::string filename) // path to file
{
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    int size = ftell(p_file);
    fclose(p_file);
    return size;
}


int main(int argc, char *argv[])
{
    string filename;
    if(argc<2) 
    {
        cout<<"Enter Filename ";
        cin>>filename;
    }
    else filename=argv[1];

    int N = get_file_size(filename)/5 ; // Estimating number of words assuming average length of word is 5

    HashTable Huff(200000);
    long long int c=0;

    ifstream file;
    file.open(filename);
    string line,token;

    while(getline(file,line,'\n')) //taking each line as input
    {
        stringstream S(line);
        while(getline(S,token,' ')){ //tokenizing each line spearated by space.
            Huff.insertNode(token);  // Inserting into hashtable
            c++;
        }

        // Huff.insertNode("\n");
        // c++;
    }
    
    file.close();

    ofstream file_en;
    file_en.open("Encoding.txt"); 
    Huff.table_sort();
    file_en<<"Code\t"<<"Token\n";
    for(int i=0;i<Huff.Sorted_Node.size();i++) // Creating and writing the encoding table
    {
        // if(Huff.Sorted_Node[i]->get_key()=="\n")
        // {
        //     file_en<<"\\n "<<Huff.Sorted_Node[i]->get_count()<<" "<<Huff.Sorted_Node[i]->get_code()<<"\n";
        //     continue;
        // }
        file_en<<(*Huff.Sorted_Node[i]); //overloaded << operator
    }
    file_en.close();

    ifstream file_in;
    file_in.open(filename);

    ofstream file_op;
    file_op.open(filename.substr(0,filename.size()-4)+"_encoded.txt");

    while(getline(file_in,line,'\n')) // encoding the input file
    {
        stringstream S(line);
        while(getline(S,token,' ')){
            file_op<< Huff.encode(token)<<" ";
        }
        file_op<<"\n";
    }
    file_op.close();
    file_in.close();

}
