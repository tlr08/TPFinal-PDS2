#include "PontoColeta.hpp"
#include <iostream>
        PontoColeta::PontoColeta()
        {
            _nome = "";
            _endereco = "";
            _id = 0;
            _id_usuario = 0;
        }
        PontoColeta::PontoColeta(int id, string nome,string endereco, int idUsuario)
        {   _id = id;
            _nome = nome;
            _endereco = endereco;
            _id_usuario = idUsuario;

        }
        string PontoColeta::get_nome() const
        {
            return this->_nome;
        }
        string PontoColeta::get_endereco() const
        {
            return this->_endereco;
        }
        int PontoColeta::get_id() const{
            return this->_id;
        }
        int PontoColeta::get_id_usuario() const
        {
            return this->_id_usuario;
        }
        bool PontoColeta::set_id_Usuario(int idUsuario)
        {
            if(!(idUsuario == 0)){
            this->_id_usuario = idUsuario;
            return true;
            }  
            return false;
        }
      
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
        bool PontoColeta::set_id(int id)
        {
            if(id>0)
            {
                this->_id = id;
                return true;
            }
            return false;
        }

        PontoColeta::~PontoColeta()
        {
            _nome.clear();
            _endereco.clear();
        }

         ostream& operator<<(ostream& out,const PontoColeta& obj)
        {
            out << "ID: " << obj.get_id() << endl;
            out << "Nome: " << obj.get_nome() << endl;
            out << "Endereco: " << obj.get_endereco() << endl;
            out << endl;
            return out;
        }
         istream& operator>>(istream& in,PontoColeta& obj)
        {
            string nome = "";
            string endereco = "";
            int idUser = 0;


            clearBuffer(in);


            cout << "Informe o nome do Local: ";
            getline(in,nome,'\n');

            cout << "Informe o endereço: ";
            getline(in,endereco,'\n');
            
            cout << "Informe o ID do usuario dono do Local: ";
            in >> idUser;


            obj.set_nome(nome);
            obj.set_id_Usuario(idUser);
            obj.set_endereco(endereco);
            cout << endl;
            return in;
        }
