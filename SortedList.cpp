#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedList::SortedList()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedList::~SortedList()
{
    Node::reset();
}

/**
 * @return the size of the data list.
 */
int SortedList::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/**
 * Insert a new node at the beginning of the data list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
    data.push_front(Node(value));
}

/**
 * Append a new node at the end of the data list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
    data.push_back(Node(value));
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
    list<Node>::iterator it = data.begin();
    list<Node>::reverse_iterator r_it=data.rbegin();
    if (index<=data.size()/2)
    {  
       int i=index;
       while(i!=0){
           it++;
           i--;
       }
       it = data.erase(it);
    }
    else
    {
        int i=data.size()-index-1;
        while(i!=0){
           r_it++;
           i--;
       }
        list<Node>::iterator it1 = r_it.base();
        --it1;
        it1=data.erase(it1);
    } 
}

/**
 * Insert a new node into the data list at the
 * appropriate position to keep the list sorted.
 */
void SortedList::insert(const long value)
{
    if(!data.empty()){
        list<Node>::iterator it = data.begin();
        while(value>*it){
            it++;
        }
        it=data.insert(it,Node(value));
    }
    else
        data.push_back(Node(value));
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node SortedList::at(const int index)
{
    list<Node>::iterator it = data.begin();
    int i=index;
      while(i!=0){
          it++;
          i--;
      }
    return *it;
}

list<Node>& SortedList::get_list(){
    return data;
}