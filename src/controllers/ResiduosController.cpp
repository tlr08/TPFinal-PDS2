#include "ResiduosController.hpp"


void ResiduosController::run(){
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

int ResiduosController::get_view(){
    int returnValue = -1;
    while(returnValue < 0 || returnValue > 5){
        clearScreen();
        cout << "Gerenciamento de Resíduos" << endl;
        cout << "1 - Cadastrar Resíduo" << endl;
        cout << "2 - Alterar Resíduo" << endl;
        cout << "3 - Listar Resíduos" << endl;
        cout << "4 - Remover Resíduos" << endl;
        cout << "5 - Detalhar Resíduos" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void ResiduosController::create(){
    Residuo* residuo = new Residuo();
    residuo->set_id(this->get_next_id());
    try {
        cin >> *residuo;
        this->data_set->push_back(residuo);
    }catch(exception e) {
        cout << e.what() << endl;
    }
    residuo =  nullptr;
}

void ResiduosController::update(){
    return;
}

void ResiduosController::show(){
    int id = -1;
    cout << "Informe o Id do Residuo: ";
    cin >> id;
    for(Residuo* x : *this->data_set){
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

void ResiduosController::remove() {

}

void ResiduosController::list_all(){
    clearScreen();
    for(Residuo* residuo : *this->data_set){
        cout << *residuo;
    }
    waitKey(); 
}

int ResiduosController::get_next_id(){
    int returnValue = 0;
    list<Residuo*>* data = this->data_set;
    if(!data->empty()){
        returnValue =  (*(--data->end()))->get_id();
    }

    return ++returnValue;    
}