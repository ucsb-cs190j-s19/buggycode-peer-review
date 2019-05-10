
#include<vector>
#include<string>
#include <iostream>
#include "table.h"
#include "entry.h"

using namespace std;



Table::Table(unsigned int max_entries) {
    this->max_entries = max_entries;
    if(max_entries <= 10) {
        arr_size = max_entries;
    }
    else {
        arr_size = max_entries/10;
    }
    table = new vector<Entry>[arr_size];
    count = 0;
}
Table::Table(unsigned int entries, istream& input) {
    max_entries = entries;

    if(max_entries <= 10) {
        arr_size = max_entries;
    }
    else {
        arr_size = max_entries/10;
    }



    table = new vector<Entry>[arr_size];
    count = 0;

    if(input) {
        while(input && count < entries) {
            Entry *e = new Entry();
            input >> *e;
            this->put(*e);
        }
    }

}
void Table::put(unsigned int key, std::string data) {

    this->remove(key);
    int index = key % arr_size;
    Entry e( key, data );
    table[index].push_back(e);
    count++;

}

void Table::put(Entry e) {

    this->remove(e.get_key());
    int index = e.get_key() % arr_size;
    table[index].push_back(e);
    count++;

}
std::string Table::get(unsigned int key) const {
    int index = key % arr_size;
    for(int i = 0; i < table[index].size(); i++) {

        if(table[index][i].get_key() == key) {
            return table[index][i].get_data();
        }
    }

    return "";
}


bool Table::remove(unsigned int key) {

    int index = key % arr_size;
    for(int i = 0; i < table[index].size(); i++) {

        if(table[index][i].get_key() == key) {
            table[index].erase(table[index].begin()+(i));
            count--;
            return true;
        }
    }

    return false;

}

void merge(Entry arr[], size_t left_arr, size_t right_arr) {

    Entry* temp;
    size_t copied = 0;
    size_t left_c = 0;
    size_t right_c = 0;

    temp = new Entry[left_arr + right_arr];

    while((left_c < left_arr) && (right_c < right_arr)) {
        if(arr[left_c] < (arr + left_arr)[right_c]) {
            temp[copied++] = arr[left_c++];
        }
        else {
            temp[copied++] = (arr + left_arr)[right_c++];
        }
    }

    while(left_c < left_arr) {
        temp[copied++] = arr[left_c++];
    }

    while(right_c < right_arr) {
        temp[copied++] = (arr + left_arr)[right_c++];
    }

    for (int i = 0; i < left_arr + right_arr; i++) {
        arr[i] = temp[i];
    }

    delete [] temp;


}

void mergesort(Entry arr[], size_t size) {

    size_t left_arr;
    size_t right_arr;

    if(size > 1) {
        left_arr = size/2;
        right_arr = size - left_arr;

        mergesort(arr, left_arr);
        mergesort((arr + left_arr), right_arr);

        merge(arr, left_arr, right_arr);
    }
}

ostream& operator<< (ostream& out, const Table& t) {

    Entry *temp_arr = new Entry[t.count];
    size_t index = 0;
    for(int i = 0; i < t.arr_size; i++) {
        for(int j = 0; j < t.table[i].size(); j++) {
            temp_arr[index] = t.table[i][j];
            index++;
        }
    }

    mergesort(temp_arr, (t.count));

    for(int i = 0; i < t.count; i++) {
        out << temp_arr[i] << endl;
    }

    delete[] temp_arr;



    return out;
}

Table::Table(const Table &orig) {

    this->table = new vector<Entry> [orig.arr_size];
    this->max_entries = orig.max_entries;
    this->arr_size = orig.arr_size;
    this->count = 0;

    for(int i = 0; i < orig.arr_size; i++) {

        for(int j = 0; j < orig.table[i].size(); j++) {
            this->put(orig.table[i][j]);
        }
    }

}
Table & Table::operator=(const Table &right) {

    if(&right == this) {
        return (*this);
    }
    else {

        delete[] this->table;

        this->table = new vector<Entry> [right.arr_size];

        for(int i = 0; i < right.arr_size; i++) {
            for(int j = 0; j < right.table[i].size(); j++) {
                this->put(right.table[i][j]);
            }


        }
    }

    return(*this);
}

Table:: ~Table() {


    delete[] this->table;

}




