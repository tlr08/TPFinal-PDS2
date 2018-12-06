#include "PontoColeta.hpp"
#include <iostream>
        PontoColeta::PontoColeta()
        {
            _nome = "";
            _endereco = "";
            //Usuario *_User;
        }
        PontoColeta::PontoColeta(string nome,string endereco /*Usuario *User*/)
        {
            _nome = nome;
            _endereco = endereco;
          //  _User = User;
        }
        string PontoColeta::get_nome() const
        {
            return this->_nome;
        }
        string PontoColeta::get_endereco() const
        {
            return this->_endereco;
        }
      /*  Usuario* PontoColeta::get_usuario()
        {
           return *_User;
        }*/
        bool PontoColeta::set_nome(string nome)
        {
            if(!nome.empty()){
                _nome = nome;
                return true;
            }
            return false;
        }
        bool PontoColeta::set_endereco(string endereco)
        {
            if(!endereco.empty()){
                _endereco = endereco;
                return true;
            }
            return false;
        }
       /* bool PontoColeta::set_Usuario(Usuario User);
        {

        }*/

        PontoColeta::~PontoColeta()
        {
            _nome.clear();
            _endereco.clear();
        }

         ostream& operator<<(ostream& out,const PontoColeta& obj)
        {
            out << "Nome: " << obj.get_nome() << endl;
           // out << "Usu�rio: " << (obj.get_usuario())->get_nome_usuario << endl;
            out << "Endereco: " << obj.get_endereco() << endl;
            out << endl;
            return out;
        }
         istream& operator>>(istream& in,PontoColeta& obj)
        {
            string nome = "";
            string endereco = "";


            clearBuffer(in);


            cout << "Informe o nome do Local: ";
            getline(in,nome,'\n');

         /*   cout << "Informe o usuario: ";
            getline(in,nome,'\n');*/

            cout << "Informe o endere�o: ";
            getline(in,endereco,'\n');


            obj.set_nome(nome);
           // obj.set_usuario(nome_usuario);
            obj.set_endereco(endereco);

            return in;
        }
