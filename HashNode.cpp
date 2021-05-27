#include "HashNode.h"

HashNode::HashNode(string S):key(S),count(1),code(-1){}

string HashNode::get_key() const{ return key;}

int HashNode::get_count() const {return count;}

int HashNode::get_code() const {return code;}

void HashNode::incr_count() { count++;}

void HashNode::set_code(int x){ code = x; }

ostream& operator<<(ostream& os, const HashNode & node)
{
    os << std::left << std::setfill(' ') << std::setw(10) << node.get_code()
        << std::left << std::setfill(' ') << std::setw(15) << node.get_key() << endl;
    return os;
}