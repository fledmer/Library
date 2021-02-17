#ifndef LIB_H
#include <iostream>
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include <book.h>
#include <algorithm>
#define LIB_H

using namespace std;
namespace  fs = std::filesystem;

class Lib
{
public:
    Lib();
    vector<Book> books_vector;
    Book& operator[](int x){return books_vector[x];}
    void sort(){std::sort(books_vector.begin(),books_vector.end(),Book::comp);}
    int size(){return books_vector.size();}
};

#endif // LIB_H
