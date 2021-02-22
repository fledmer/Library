#ifndef LIB_H
#include <vector>
#include <book.h>
#include <algorithm>
#define LIB_H

using namespace std;

class Lib
{
public:
    Lib();
    ~Lib()
    {
        for(auto x : books_vector)
            delete x;
    }
    void save()
    {
        for(auto x : books_vector)
            x->save();
    }
    vector<Book*> books_vector;
    Book* operator[](int x){return books_vector[x];}
    //void sort(){std::sort(books_vector.begin(),books_vector.end(),Book::comp);}
    Book* add();
    int size(){return books_vector.size();}
};

#endif // LIB_H
