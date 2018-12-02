#include "UsuarioController.hpp"

void UsuarioController::run(){
    bool continueRunning = true;
    do {
        switch(get_view()){
            case 0:
                continueRunning = false;
                break;
            case 1:
                this->create();
                break;
            case 2:
                this->update();
                break;
            case 3:
                this->list_all();
                break;
            case 4:
                this->remove();
                break;
            case 5:
                this->show();
                break;
        }

    } while(continueRunning);

}

int UsuarioController::get_view(){
    int returnValue = -1;
    while(returnValue < 0 || returnValue > 5){
        clearScreen();
        cout << "Gerenciamento de Usuário" << endl;
        cout << "1 - Cadastrar Usuário" << endl;
        cout << "2 - Alterar Usuário" << endl;
        cout << "3 - Listar Usuário" << endl;
        cout << "4 - Remover Usuário" << endl;
        cout << "5 - Detalhar Usuário" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void UsuarioController::create(){
    Usuario* usuario = nullptr;
    int opcao = 0;
    cout << "Qual tipo de pessoa deseja cadastrar?" << endl;
    cout << " 1 - Pessoa Física" << endl;
    cout << " 2 - Pessoa Jurídica" << endl;
    cin >> opcao;
    if(opcao == 1){
        usuario = new PessoaFisica();
    }else if (opcao == 2){
        usuario = new PessoaJuridica();
    }
    usuario->set_id(this->get_next_id());
    try {
        if(PessoaFisica* pessoaFisica = dynamic_cast<PessoaFisica*>(usuario)){
            cin >> *pessoaFisica;
        }else if(PessoaJuridica* pessoaJuridica = dynamic_cast<PessoaJuridica*>(usuario)){
            cin >> *pessoaJuridica;
        }
        this->data_set->push_back(usuario);
    }catch(exception e) {
        cout << e.what() << endl;
    }
    usuario =  nullptr;
}

void UsuarioController::update(){
    Usuario* update = nullptr;
    int id = 0;
    cout << "Informe o Id do Usuário a ser alterado.";
    cin >> id;
    for(Usuario* usuario: *this->data_set){
        if(usuario->get_id()==id){
            update = usuario;
        }
    }
    if(update!=nullptr){
        if(PessoaFisica* pessoaFisica = dynamic_cast<PessoaFisica*>(update)){
            cin >> *pessoaFisica;
        }else if(PessoaJuridica* pessoaJuridica = dynamic_cast<PessoaJuridica*>(update)){
            cin >> *pessoaJuridica;
        }
        cout << "Usuário alterado com sucesso.";

    } else{
        cout << "Falha ao alterar o usuário.";
    }
    waitKey();
    
}

void UsuarioController::show(){
    int id = -1;
    cout << "Informe o Id do Usuário: ";
    cin >> id;
    for(Usuario* usuario : *this->data_set){
        if(usuario->get_id() == id){
            clearScreen();
            if(PessoaFisica* pessoaFisica = dynamic_cast<PessoaFisica*>(usuario)){
                cout << *pessoaFisica;
            }else if(PessoaJuridica* pessoaJuridica = dynamic_cast<PessoaJuridica*>(usuario)){
                cout << *pessoaJuridica;
            }
            waitKey();
            return;
        }
    }
    cout << "Usuário não encontrado." << endl;
    waitKey();
}

void UsuarioController::remove() {
    int id = 0;
    bool removed = false;
    cin >> id;


    for(Usuario* usuario: *this->data_set){
        if(usuario->get_id() == id){
            this->data_set->remove(usuario);
            removed = true;
            break;
        }
    }
    if(!removed)
        cout << "Não foi possível remover o usuário selecionado." << endl;
    else   
        cout << "Usuário removido com sucesso." << endl;
    
    waitKey();
}

void UsuarioController::list_all(){
    clearScreen();
    for(Usuario* usuario : *this->data_set){
        if(PessoaFisica* pessoaFisica = dynamic_cast<PessoaFisica*>(usuario)){
            cout << *pessoaFisica;
        }else if(PessoaJuridica* pessoaJuridica = dynamic_cast<PessoaJuridica*>(usuario)){
            cout << *pessoaJuridica;
        }
    }
    waitKey(); 
}

int UsuarioController::get_next_id(){
    int returnValue = 0;
    list<Usuario*>* data = this->data_set;
    if(!data->empty()){
        returnValue =  (*(--data->end()))->get_id();
    }

    return ++returnValue;    
}