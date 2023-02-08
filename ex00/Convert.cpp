#include "Convert.hpp"
#include <iostream>   
#include <string>

Convert :: Convert(std :: string args) : args(args), type("non")
{
    if (serch_int(args)== true)
        this->type = "int";
    else if (serch_double(args) == true)
        this->type = "double";
    else if (serch_float(args) == true)
        this->type = "float";
    else
        this->type = "string";
    convert_all(args, this->type);
}

Convert :: ~Convert(){}


Convert :: Convert(const Convert &src)
{
    (void)src;
    //*this->src;
}

Convert &Convert :: operator=(const Convert &src)
{
    this->type = src.type;
    this->args = src.args;
    return (*this);
}

bool Convert :: serch_int(std :: string args)
{
    int i = 0;
    if (args[0] == '-')
        i = 1;
    while (args[i])
    {
        if (! isdigit(args[i]))
            return (false);
        i++; 
    }
    return (true);
}

static int nb_point(std :: string args)
{
    int i = 0;
    int nb = 0;
    while (args[i])
    {
        if (args[i] == '.')
            nb++;
        i++;
    }
    return (nb);
}

bool Convert :: serch_double(std :: string args)
{
    int i = 0;
    if (args[0] == '-')
        i = 1;
    while (args[i])
    {
        if (!isdigit(args[i]) && args[i]!='.')
            return (false);
        i++; 
    }
    if (nb_point(args) != 1)
        return (false);
    return (true);
}

bool Convert :: serch_float(std :: string args)
{
    if ((args[args.size() - 1] == 'f') && (serch_double(args.erase(args.size()-1)) == true))
        return (true);
    return (false);
}

void Convert :: convert_all(std:: string args, std :: string type)
{
    if (type == "string")
        convert_string(args);
    else if (type == "int")
        convert_int(args);
    else if (type == "float")
        convert_float(args);
    else if (type == "double")
        convert_double(args);
}

void Convert :: convert_double(std :: string args)
{
    long n = atoi(args.c_str());
    if (n > INT_MAX || n < INT_MIN)
    {
        convert_string(args);
        return ;
    }
    std :: cout << "char: " << "Non displayable" << std :: endl;
    std :: cout << "int: "<< static_cast<int>(n) << std :: endl;
    std :: cout << "float: "<< args + "f" << std :: endl;
    std :: cout << "double: "<< args << std :: endl;
}
void Convert :: convert_float(std :: string args)
{
    long n = atoi(args.c_str());
    if (n > INT_MAX || n < INT_MIN)
    {
        convert_string(args);
        return ;
    }
    std :: cout << "char: " << static_cast<char>(n) << std :: endl;
    std :: cout << "int: "<< static_cast<int>(n) << std :: endl;
    std :: cout << "float: "<< args << std :: endl;
    std :: cout << "double: "<< args.erase(args.size()-1) << std :: endl;
}

void Convert :: convert_int(std :: string args)
{
    long n = atoi(args.c_str());
    if (n > INT_MAX || n < INT_MIN)\
    {
        convert_string(args);
        return ;
    }
    std :: cout << "char: " << "Non displayable" << std :: endl;
    std :: cout << "int: "<< args << std :: endl;
    std :: cout << "float: "<< args + ".0f" << std :: endl;
    std :: cout << "double: "<<  args + ".0" << std :: endl;
}

void Convert :: convert_string(std :: string args)
{
    (void)args;
    std :: cout << "char: " << "impossible" << std :: endl;
    std :: cout << "int: "<< "impossible" << std :: endl;
    std :: cout << "float: "<< "nanf" << std :: endl;
    std :: cout << "double: "<< "nan" << std :: endl;
} 


std :: string Convert :: get_type()
{
    return (this->type);
}

std :: string Convert :: get_args()
{
    return (this->args);
}