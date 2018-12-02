#include "helpers.hpp"

double Field::getDouble(){
    if(this->getType() == t_double){
        return this->fieldData->data.double_value;
    } else { 
        return 0;
    }

}

int Field::getInt(){
    if(this->getType() == t_int){
        return this->fieldData->data.int_value;
    } else { 
        return 0;
    }
}

std::string Field::getString(){
    if(this->getType() == t_string){
        std::string toCopy =  this->fieldData->data.string_value;
        int strSize = toCopy.length();
        std::string returnStr(toCopy, 0,strSize);
        
        return returnStr;
    } else {
        return "";
    }
}

Field::~Field(){
}

Field::Field(std::string fieldName, t_variant *data){
    this->fieldData = data;
    
}

dataTypes Field::getType(){
    return this->fieldData->variantType;
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