#include "lib.h"
#include <algorithm>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;

namespace fs  = filesystem;

Lib::Lib()
{
    if(!fs::exists("Lib"))  // Проверка существования пути
    {
        fs::create_directory("Lib");
    }
    for (auto &p : fs::directory_iterator("Lib")) // Итерируемся по всем книгам в дирректории
    {
        string buff;
        string text;
        string name;
        ifstream reader(p.path());         // Открываем книгу из txt
        getline(reader,name);
        while(getline(reader,buff))              //считываем
        {
            text += buff;
            buff = "";
        }
        reader.close();
        Book *book = new Book(name,text);
        book->path = p.path().string();
        books_vector.push_back(book);    // Создаем экземпляры книги из txt файла
    }
    //this->sort();
}


Book* Lib::add()
{
    Book *book = new Book();
    book->name = "new_Book";
    book->text = "";
    books_vector.push_back(book);
    book->path = "Lib\\"+std::to_string(time(NULL));
    return book;
}
