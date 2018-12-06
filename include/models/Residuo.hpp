#ifndef RESIDUO_HPP
#define RESIDUO_HPP
#include <stdafx.hpp>

using namespace std;

enum TipoResiduo {
    LIQUIDO = 0,
    SOLIDO = 1,
    ORGANICO = 2
};

string tipo_to_string(TipoResiduo tipo);
TipoResiduo int_to_tipo(int value);
class Residuo  {
    private:
        int id;
        string nome_residuo;
        string forma_armazenamento;
        TipoResiduo tipo_residuo;
        double Quantidade;
        string Unidade;
    public:
        Residuo();
        Residuo(int id, string nome_residuo, string forma_armazenamento, TipoResiduo tipo_residuo,double Quantidade,string Unidade);
        ~Residuo();
        string to_string();
        int get_id() const;
        string get_nome_residuo() const;
        string get_forma_armazenamento() const;
        string get_Unidade() const;
        double get_Quantidade() const;
        TipoResiduo get_tipo_residuo() const;
        bool set_id(int id);
        bool set_nome_residuo(string nome_residuo);
        bool set_forma_armazenamento(string forma_armazenamento);
        bool set_Unidade(string Unidade);
        bool set_Quantidade(double Quantidade);
        void set_tipo_residuo(TipoResiduo tipo_residuo);
        friend ostream& operator<<(ostream& out,const Residuo& obj);
        friend istream& operator>>(istream& in,Residuo& obj);

};
#endif
