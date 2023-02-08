#include "Base.hpp"

Base *generate(void)
{
    int n = rand()%3 + 1;
    switch (n)
    {
        case 0 :
            return (new A());
        case 1 :
            return (new B());
        default :
            return (new C());
    }
}

void identify_pointer(Base* p)
{
    if (dynamic_cast<A*>(p))
        std :: cout << "class A" << std :: endl;
    else if (dynamic_cast<B*>(p))
        std :: cout << "class B" << std :: endl;
    else if (dynamic_cast<C*>(p)) 
        std :: cout << "class C" << std :: endl;
    else 
        std :: cout << "je reconnais pas la classe" << std :: endl;
}

void identify_reference(Base& p)
{
    identify_pointer(&p);
}
int main()
{
    Base *p;

	p = generate();
    identify_pointer(p);
    identify_reference(*p);
    return (0);
}