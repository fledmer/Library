#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <lib.h>
#include <control.h>

class Controller
{
protected:
    int ptr;
public:
    Lib &library;
    Controller *controlcenter;
    virtual int &get_ptr()=0;
    virtual void set_ptr(int x)=0;
    Controller(Lib &lib,Controller *controlCenter):library(lib),ptr(0),controlcenter(controlCenter){}
    virtual void print_interface()=0;
    virtual void request(char command)=0;
};

#endif // CONTROLLER_H
