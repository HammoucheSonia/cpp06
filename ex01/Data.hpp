#ifndef DATA_HPP
#define DATA_HPP
#include <ostream>
#include <string>
#include <iostream>
#include <stdint.h>

typedef struct t_data
{
    std :: string data;
} Data; 

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif 