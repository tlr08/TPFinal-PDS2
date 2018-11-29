#ifndef RESIDUO_HPP
#define RESIDUO_HPP
#include <string>
#include "IBaseModel.hpp"



class Residuo  {
    private:
        int id;
        std::string nome_residuo;
    
    public:
        std::ostream& operator<<(std::ostream& out, Residuo const& obj);
        std::istream& operator>>(std::istream& in,Residuo const& obj);
        std::bool& equals(Residuo const& obj);
        std::string to_string();

};

#endif