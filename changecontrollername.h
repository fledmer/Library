#ifndef CHANGECONTROLLERNAME_H
#define CHANGECONTROLLERNAME_H
#include <controller.h>

class ChangeControllerName:public Controller
{
    int horizontal_ptr;
public:
    Book *book;
    string new_name;
    void set_horizontal_ptr(int x);
    int &get_horizontal_ptr();
    int &get_ptr() override;
    void set_ptr(int x) override;
    ChangeControllerName(Lib &lib,Controller **ControlCenter,Book *book);
    void pushChar(int x);
    void print_interface() override;
    void request(int command) override;
    void pushChar(const char *_char); // вставка символа в строку
};
#endif // CHANGECONTROLLERNAME_H
