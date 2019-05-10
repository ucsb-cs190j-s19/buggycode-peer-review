//Lyuda Panina
//  table.h
//  S19 - Lab04
//
#ifndef table_h
#define table_h

#include<string>
#include<iosfwd>
#include "entry.h"
#include<vector>

// Note: Your hash table must be implemented using an array of
// std::vector<Entry> as stated in the instructions.

class Table {

public:
    Table(unsigned int max_entries = 100);
    Table(unsigned int entries, std::istream& input);
    void put(unsigned int key, std::string data);
    void put(Entry e);
    std::string get(unsigned int key) const;
    bool remove(unsigned int key);
    friend std::ostream& operator<< (std::ostream& out, const Table& t);

    Table(const Table &orig);
    Table & operator=(const Table &right);
    ~Table();
    

private:
    std::vector<Entry> *table;
    unsigned int max_entries; 
    unsigned int arr_size;
    int count;
};
    void merge(Entry arr[], size_t left, size_t right);
    void mergesort(Entry arr[], size_t size);


#endif /* table_h */
