#ifndef IMODEL_DAO_H 
#define IMODEL_DAO_H
#include <iostream>
#include <list>

//Interface Template IModelDAO
//Utilizar em todos os DAO's dos Modelos.
//Garantimos assim a implementação dos métodos:
// create -> Salva um objeto no banco de dados.
// update -> Atualiza um objeto no banco de dados.
// ListAll -> Lista todos os objetos no banco de dados.
// Find -> Busca um objeto no banco de dados.
// Remove -> Remove um objeto do banco de dados.

template <class T>
class IModelDAO{
    public:
        virtual bool create(T* obj) = 0;
        virtual bool update(T* obj) = 0;
        virtual std::list<T*>* list_all() = 0;
        virtual T* find(int id) = 0;
        virtual bool remove(int id) = 0;
        virtual bool remove(T* obj) = 0;
        ~IModelDAO() {}

};



#endif 
