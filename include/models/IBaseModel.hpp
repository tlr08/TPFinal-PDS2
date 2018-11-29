#ifndef IBASE_MODEL_H
#define IBASE_MODEL_H
#include <iostream>

//Interface Template IBaseModel
//Utilizar em todos os Modelos.
//Garantimos assim a implementação dos métodos:
// cout << objeto -> Exibição do Objeto pela stdout
// cin >> objeto -> Leitura do Objeto pela stdin
// equals -> Compara objetos
// to_string -> Retorna nome do Objeto em Questão.

template<class T>
class IBaseModel {
    public:
        //Overload do operador de Saída.
        virtual std::ostream& operator<<(std::ostream& out, T const& obj) = 0;
        //Overload do operador de Entrada.
        virtual std::istream& operator>>(std::istream& in, T const& obj) = 0;
        //Verifica se dois objetos são iguais
        virtual std::bool& equals(T const& obj) = 0;
        //Retorna nome do Objeto
        virtual std::string to_string() = 0;
};
#endif