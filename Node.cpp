#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

Node::Node(const long the_value)
{
    value=the_value;
    constructor_count++;
}

Node::Node(const Node& other)
{
    this->value = other.value;
   // cout<<"copy constructor called assigned value : "<<other.value<<endl;
    copy_count++;
}

Node::~Node()
{
   // delete value;
    destructor_count++;
}

long Node::get_constructor_count()
{
    return constructor_count;
}

long Node::get_copy_count()
{
    return copy_count;
}

long Node::get_destructor_count()
{
    return destructor_count;
}

void Node::reset()
{
   constructor_count=0;
   copy_count=0;
   destructor_count=0;
}

long Node::get_value() const
{
    return value;
}

bool operator >(const Node& n1, const Node& n2){
    if((n1.get_value()>n2.get_value())||(n1.get_value()==n2.get_value()))
        return true;
    else
        return false;
}
bool operator >(const long& n1, const Node& n2){
    return (n1>n2.get_value());
}