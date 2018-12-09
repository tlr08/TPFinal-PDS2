#ifndef ROW_H
#define ROW_H
#include "stdafx.hpp"

//Estrutura para simplificar o entedimento de resultados do banco.
//Representa uma linha no banco.
class Row {
    private:
        std::map<std::string, variant*> *fields;
    public:
        Row();
        ~Row();
        int field_count();
        void insert(std::pair<std::string, variant*> data);
        variant* getValue(std::string key);
};

#endif