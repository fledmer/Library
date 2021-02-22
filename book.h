#ifndef BOOK_H
#include<string>
#include<fstream>
#include<stdio.h>
#define BOOK_H


class Book
{
public:

    std::string path;
    std::ofstream ofs;
    std::string name;
    std::string text;
    Book(std::string _name,std::string _text):name(_name),text(_text){}
    Book(){}
    ~Book(){
        ofs.open(path);
        ofs<<name<<std::endl;
        ofs<<text;
        ofs.close();
    }
    void save()
    {
        ofs.open(path);
        ofs<<name<<std::endl;
        ofs<<text;
        ofs.close();
    }
    void _delete()
    {
        remove(path.c_str());
    }
    static bool comp(Book a, Book b)
    {
        return a.name <= b.name;
    }
    bool operator==(Book book)
    {
        return name == book.name;
    }
    void operator=(const Book &book)
    {
        path = book.path;
        name = book.name;
        text = book.text;
    }
};

#endif // BOOK_H
