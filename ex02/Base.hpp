#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base 
{
    public :
        virtual ~Base();
};

class A : public Base
{

};

class B : public Base
{

};
class C : public Base
{

};

Base * generate(void);
void identify_pointer(Base* p);
void identify_reference(Base& p);

#endif 