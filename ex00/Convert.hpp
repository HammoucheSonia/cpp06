#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <ostream>
#include <iostream>
#include <string>    
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483647

class Convert
{
    private:
        std :: string args;
        std :: string type;
    public:
        Convert(std :: string args);
        ~Convert();
        Convert(const Convert &src);
        Convert &operator=(const Convert &src);
        std :: string get_type();
        std :: string get_args();
        bool serch_int(std :: string args);
        bool serch_double(std :: string args);
        bool serch_float(std :: string args);
        void convert_all(std:: string args, std :: string type);
        void convert_float(std :: string args);
        void convert_int(std :: string args);
        void convert_double(std :: string args);
        void convert_string(std :: string args);

};

#endif