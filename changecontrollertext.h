#ifndef CHANGECONTROLLERTEXT_H
#define CHANGECONTROLLERTEXT_H
#include <controller.h>

class ChangeControllerText:public Controller
{
    int horizontal_ptr;
public:
    vector<string> new_text;
    Book *book;
    void set_horizontal_ptr(int x);
    int &get_horizontal_ptr();
    int &get_ptr() override;
    void set_ptr(int x) override;
    ChangeControllerText(Lib &lib,Controller **ControlCenter,Book *book);
    //void back(Controller *controlCenter);
    void print_interface() override;
    void request(int command) override;
    void pushChar(int x); // вставка символа в строку
};
#endif
