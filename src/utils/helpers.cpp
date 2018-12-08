#include "helpers.hpp"

double getDouble(variant* data){
    if(data->variantType == t_double){
        return data->data.double_value;
    } else { 
        return 0;
    }

}

int getInt(variant* data){
    if(data->variantType == t_int){
        return data->data.int_value;
    } else { 
        return -1;
    }
}

std::string getString(variant* data){
    if(data->variantType == t_string){
        std::string toCopy =  data->data.string_value;
        int strSize = toCopy.length();
        std::string returnStr(toCopy, 0,strSize);
        return returnStr;
    } else {
        return "";
    }
}

variant* getVariant(int value){
    variant* data = new variant {
        {.int_value=value},
        t_int
    };
    return data;
}
variant* getVariant(double value){
    variant* data = new variant {
        {.double_value=value},
        t_double
    };
   return data;
}
variant* getVariant(std::string value){
    variant* data = new variant {
        {.string_value=value},
        t_string
    };
    return data;
}



int clearScreen(){
    int returnVal = 0;
    #if defined _WIN32
        returnVal = system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        returnVal = system("clear");
    #elif defined (__APPLE__)
        returnVal = system("clear");
    #endif
    return returnVal;
}
void waitKey(){
    int returnCode = 0; 
    std::cout << "Pressione um botão para continuar \t";
    clearBuffer(std::cin);
    returnCode = std::cin.get();
}

void clearBuffer(std::istream& in){
    in.clear();
    in.ignore(1);
}