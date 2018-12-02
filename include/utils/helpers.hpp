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
} t_variant;

class Field {
    public:
        int getInt();
        double getDouble();
        std::string getString();
        std::string getFieldName();
        Field(std::string name,t_variant *data);
        ~Field();
    private:
        std::string fieldName;
        t_variant *fieldData;
        dataTypes getType();
};

int clearScreen();
void waitKey();
void clearBuffer(std::istream& in);
#endif
