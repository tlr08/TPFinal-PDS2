#include "Row.hpp"

Row::Row(){
    this->fields =new std::map<std::string, variant*>();
}
Row::~Row(){
    if(this->fields!=nullptr){
        //fields->erase();
        delete this->fields;
    }
}

void Row::insert(std::pair<std::string, variant*> field){
    this->fields->insert(field);
}

variant* Row::getValue(std::string key){
    auto it = fields->find(key);
    if(it!=fields->end())
        return it->second;
    else
        return nullptr;
}