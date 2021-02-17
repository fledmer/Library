#ifndef BOOK_H
#include<string>
#define BOOK_H


class Book
{
public:
    std::string name;
    std::string text;
    Book(std::string _name,std::string _text):name(_name),text(_text){}
    static bool comp(Book a, Book b)
    {
        return a.name <= b.name;
    }
};

#endif // BOOK_H
