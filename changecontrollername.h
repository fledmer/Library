#ifndef CHANGECONTROLLERNAME_H
#define CHANGECONTROLLERNAME_H
#include <controller.h>

class ChangeControllerName:public Controller
{
public:
    Book *book;
    string new_name;
    int &get_ptr() override;
    void set_ptr(int x) override;
    ChangeControllerName(Lib &lib,Controller **ControlCenter,Book *book);
    void print_interface() override;
    void request(char command) override;
};
#endif // CHANGECONTROLLERNAME_H
