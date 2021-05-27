#include "HashTable.h"

bool compare(HashNode * N1, HashNode* N2)
{
    return N1->get_count()>N2->get_count();
}

HashTable::HashTable(int N):size(N),curr_size(0)
{
    table = new HashNode *[N]();

    for(int i=0;i<N;i++) table[i]=NULL;

    Power_P[0] = 1; 
    for (int i = 1; i < 30 ; i++)
    {
        Power_P[i] = (Power_P[i-1] * P) % M;
    }
}

int HashTable::hash(string S) const{

    long long int hash_value = 0;
    for (int i=0 ;i< S.size();i++) {
        hash_value = (hash_value + (S[i] * Power_P[i])) % M;
    }
    return hash_value % size;
}

void HashTable::insertNode(string S) 
{ 
    int index = hash(S);
    int i=1;

    while(1)
    {
        if(table[index]==NULL){
            table[index] = new HashNode(S);
            curr_size++;
            break;
        }

        else if(table[index]->get_key()==S)
        {
            table[index]->incr_count();
            break;
        }
        index = (index + (i*i) ) % size;
        i++;
    }
}

int HashTable::search(string S) const
{
    int index = hash(S); 
    int i=1;

    while(1)
    {
        if(table[index]==NULL) return -1;

        else if(table[index]->get_key()==S) return index;

        index = (index + (i*i) ) % size;
        i++;
    }
    return -1;
}

int HashTable::encode(string S) const
{
    int I = search(S);
    if(I==-1) return -1;
    return table[I]->get_code();
}
string HashTable::decode(int x) const
{
    return(Sorted_Node[x-1]->get_key());
}

void HashTable::table_sort()
{
    for(int i=0;i<size;i++)
    {
        if(table[i]!=NULL)Sorted_Node.push_back(table[i]);
    }
    sort(Sorted_Node.begin(),Sorted_Node.end(),compare);

    for(int i=0;i<Sorted_Node.size();i++)
    {
        Sorted_Node[i]->set_code(i+1);
    }
} 