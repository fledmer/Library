#ifndef CHANGECONTROLLERTEXT_H
#define CHANGECONTROLLERTEXT_H
#include <controller.h>

class ChangeControllerText:public Controller
{
public:
    vector<string> new_text;
    Book *book;
    int &get_ptr() override;
    void set_ptr(int x) override;
    ChangeControllerText(Lib &lib,Controller **ControlCenter,Book *book);
    void print_interface() override;
    void request(char command) override;
};
#endif
