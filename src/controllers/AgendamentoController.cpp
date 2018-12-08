#include "AgendamentoController.hpp"


void AgendamentoController::run(){
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

int AgendamentoController::get_view(){
    int returnValue = -1;
    while(returnValue < 0 || returnValue > 5){
        clearScreen();
        cout << "Gerenciamento dos Agendamentos" << endl;
        cout << "1 - Agendar" << endl;
        cout << "2 - Alterar Agendamento" << endl;
        cout << "3 - Listar Agendamentos" << endl;
        cout << "4 - Cancelar Agendamento" << endl;
        cout << "5 - Detalhar Agendamentos" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void AgendamentoController::create(){
    Agendamento* agendamento = new Agendamento();
    agendamento->set_id(this->get_next_id());
    try {
        cin >> *agendamento;
        this->data_set->push_back(agendamento);
    }catch(exception e) {
        cout << e.what() << endl;
    }
    agendamento =  nullptr;
}

void AgendamentoController::update(){
    Agendamento *update = nullptr;
    int id = 0;
    cout << "Informe o ID do Agendamento a ser alterado: ";
    cin >> id;

    for(Agendamento* agendamento: *this->data_set){
        if(agendamento->get_id() == id)
            update = agendamento;
    }
    if(update != nullptr){
         Agendamento* novo_Agendamento = dynamic_cast<Agendamento*>(update);
         cin >> *novo_Agendamento;
         cout << "Agendamento alterado com sucesso.";
    }
    else {
        cout << "Falha ao alterar Agendamento.";
    }

    waitKey();

}

void AgendamentoController::show(){
    int id = -1;
    cout << "Informe o Id do Agendamento: ";
    cin >> id;
    for(Agendamento* x : *this->data_set){
        if(x->get_id() == id){
            clearScreen();
            cout << *x;
            waitKey();
            return;
        }
    }
    cout << "Agendamento não encontrado." << endl;
    waitKey();
}

void AgendamentoController::remove() {
      

}

void AgendamentoController::list_all(){
    clearScreen();
    for(Agendamento* agendamento : *this->data_set){
        cout << *agendamento;
    }
    waitKey(); 
}

int AgendamentoController::get_next_id(){
    int returnValue = 0;
    list<Agendamento*>* data = this->data_set;
    if(!data->empty()){
        returnValue =  (*(--data->end()))->get_id();
    }

    return ++returnValue;    
}