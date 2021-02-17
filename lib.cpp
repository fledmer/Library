#include "lib.h"

Lib:: Lib()
{
    if(!fs::exists("Lib"))  // Проверка существования пути
    {
        fs::create_directory("Lib");
    }
    for (auto & p : fs::directory_iterator("Lib")) // Итерируемся по всем книгам в дирректории
    {
        string buff;
        ifstream reader(p.path());          // Открываем книгу из txt
        while(reader >> buff);              //считываем
        books_vector.push_back(Book(string(p.path().string()),buff));    // Создаем экземпляры книги из txt файла
    }
    this->sort();
}
