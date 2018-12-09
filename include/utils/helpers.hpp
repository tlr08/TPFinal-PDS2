#ifndef HELPERS_H
#define HELPERS_H
#include <string>
#include <cstdlib>
#include <iostream>

enum dataTypes {
    t_string,
    t_int,
    t_double   
};

typedef struct struct_variant {
    union union_data {
        int int_value;
        double double_value;
        std::string string_value;
    } data;
    dataTypes variantType;
} variant;



int clearScreen();
void waitKey();
void clearBuffer(std::istream& in);

double getDouble(variant* data);
int getInt(variant* data);
std::string getString(variant* data);

variant* getVariant(int value);
variant* getVariant(double value);
variant* getVariant(std::string value);

#endif
