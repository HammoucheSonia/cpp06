#include <ostream>
#include <iostream>
#include "Convert.hpp"
int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std :: cout << "ce programme a besion d'un seul argument" << std :: endl;
        return(0);
    }
    Convert convert(argv[1]);
    return (0);
} 