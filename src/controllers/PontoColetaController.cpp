#include "PontoColetaController.hpp"


void PontoColetaController::run(){
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

int PontoColetaController::get_view(){
    int returnValue = -1;
    while(returnValue < 0 || returnValue > 5){
        clearScreen();
        cout << "Gerenciamento de Pontos de Coleta" << endl;
        cout << "1 - Cadastrar Local" << endl;
        cout << "2 - Alterar Local" << endl;
        cout << "3 - Listar Locais" << endl;
        cout << "4 - Remover Locais" << endl;
        cout << "5 - Detalhar Locais" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void PontoColetaController::create(){
    PontoColeta* local = new PontoColeta();
    local->set_id(this->get_next_id());
    try {
        cin >> *local;
        this->data_set->push_back(local);
    }catch(exception e) {
        cout << e.what() << endl;
    }
    local =  nullptr;
}

void PontoColetaController::update(){
    PontoColeta *update = nullptr;
    int id = 0;
    cout << "Informe o ID do Local a ser alterado: ";
    cin >> id;

    for(PontoColeta* local: *this->data_set){
        if(local->get_id() == id)
            update = local;
    }
    if(update != nullptr){
         PontoColeta* novo_Local = dynamic_cast<PontoColeta*>(update);
         cin >> *novo_Local;
         cout << "Local alterado com sucesso.";
    }
    else {
        cout << "Falha ao alterar Local.";
    }

    waitKey();

}

void PontoColetaController::show(){
    int id = -1;
    cout << "Informe o Id do Local: ";
    cin >> id;
    for(PontoColeta* x : *this->data_set){
        if(x->get_id() == id){
            clearScreen();
            cout << *x;
            waitKey();
            return;
        }
    }
    cout << "Resíduo não encontrado." << endl;
    waitKey();
}

void PontoColetaController::remove() {
      /*  int id = 0;
        bool removed = false;
        cin >> id;

        for(PontoColeta* local: *this->data_set){
            if(local->get_id() == id)
            this->data_set->remove(local);
            removed = true;
            break;
        }

        if(!removed)
            cout << "Não foi possível remover o Local selecionado." << endl;
        else
            cout << "Local removido com sucesso." << endl;
        
        waitKey();*/

}

void PontoColetaController::list_all(){
    clearScreen();
    for(PontoColeta* local : *this->data_set){
        cout << *local;
    }
    waitKey(); 
}

int PontoColetaController::get_next_id(){
    int returnValue = 0;
    list<PontoColeta*>* data = this->data_set;
    if(!data->empty()){
        returnValue =  (*(--data->end()))->get_id();
    }

    return ++returnValue;    
}