#include "AgendamentoController.hpp"

AgendamentoController::AgendamentoController(DbHelper* helper){
    this->dao = new AgendamentoDAO(helper);
    this->usuarioDAO = new UsuarioDAO(helper);
    this->localDAO = new PontoColetaDAO(helper);
    this->residuosDAO = new ResiduosDAO(helper);
}
AgendamentoController::~AgendamentoController()
{
    delete this->dao;
    delete this->usuarioDAO;
    delete this->localDAO;
    delete this->residuosDAO;
    this->dao = nullptr;
    this->usuarioDAO = nullptr;
    this->localDAO = nullptr;
    this->residuosDAO = nullptr;

}
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
    Usuario *doador = nullptr;
    int idDoador = 0;
    Usuario *receptor = nullptr;
    int idReceptor = 0;
    PontoColeta* local = nullptr;
    int idLocal = 0;
    clearScreen();
    cout << "\t Cadastro do Agendamento da Coleta" << endl
        << endl;

    cin >> *agendamento;
    cout << "Informe o ID do Doador: " << endl;
    cin >> idDoador;
    doador = usuarioDAO->find(idDoador);
    if (doador != nullptr)
    {
        agendamento->set_doador(doador);
    } 
    else
    {
        cout << "ID não encontrado, doador não será vinculado." << endl;
    }

    cout << "Informe o ID do Receptor: " << endl;
    cin >> idReceptor;
    receptor = usuarioDAO->find(idReceptor);
    if (receptor != nullptr)
    {
        agendamento->set_recepetor(receptor);
    } 
    else
    {
        cout << "ID não encontrado, receptor não será vinculado." << endl;
    }

    cout << "Informe o ID do Ponto de Coleta: " << endl;
    cin >> idLocal;
    local = localDAO->find(idLocal);
    if (local != nullptr)
    {
        agendamento->set_local(local);
    } 
    else
    {
        cout << "ID não encontrado, local não será vinculado." << endl;
    }

    if(dao->create(agendamento))
    {
        cout << "Agendamento cadastrado com sucesso!" << endl;
    } else {
        cout << "Falha ao cadastrar agendamento.";
    }
    if( doador != nullptr)
        delete doador;
    if( receptor != nullptr)
        delete receptor;
    if( local != nullptr)
        delete local;
    delete agendamento;
    agendamento =  nullptr;
}

void AgendamentoController::update(){
    Agendamento *update = nullptr;
    int id = 0;
    Usuario *doador = nullptr;
    int idDoador = 0;
    Usuario *receptor = nullptr;
    int idReceptor = 0;
    PontoColeta* local = nullptr;
    int idLocal = 0;

    update = dao->find(id);
    if (update != nullptr){
        cout << "\t Dados do Local" << endl
             << *update << endl
             << "\t Atualização" << endl;
        cin >> *update;
        cout << "Informe o ID do Doador: " << endl;
        cin >> idDoador;
        doador = usuarioDAO->find(idDoador);
        if (doador != nullptr)
        {
            update->set_doador(doador);
        } 
        else
        {
            cout << "ID não encontrado, doador não será vinculado." << endl;
        }

        cout << "Informe o ID do Receptor: " << endl;
        cin >> idReceptor;
        receptor = usuarioDAO->find(idReceptor);
        if (receptor != nullptr)
        {
            update->set_recepetor(receptor);
        } 
        else
        {
            cout << "ID não encontrado, receptor não será vinculado." << endl;
        }

        cout << "Informe o ID do Ponto de Coleta: " << endl;
        cin >> idLocal;
        local = localDAO->find(idLocal);
        if (local != nullptr)
        {
            update->set_local(local);
        } 
        else
        {
            cout << "ID não encontrado, local não será vinculado." << endl;
        }

        if(dao->update(update))
        {
            cout << "Agendamento alterado com sucesso!" << endl;
        } else {
            cout << "Falha ao alterar agendamento.";
        }

    }
    else{
        cout << "Agendamento não encontrado." << endl;
    }
    waitKey();
}

void AgendamentoController::remove() {
      int id = 0;
      cout << "Informe o ID do AGendamento: ";
      cin >> id;
      Agendamento *agendamento = dao->find(id);
      if (agendamento != nullptr)
      {
          dao->remove(id);
          cout << "Agendamento removido com sucesso!" << endl;
      }
      else{
          cout <<  "Não foi possível remover o Agendamento selecionado." << endl;
      }

}

void AgendamentoController::list_all(){
    clearScreen();
    cout << "\t Agendamentos" << endl;
    for(Agendamento* agendamento : *dao->list_all()){
        cout << *agendamento;
    }
    waitKey(); 
}
/*
void AgendamentoController::residuos(){
    int id = 0;
    int adicionador = 0;
    cout << "Informe o ID do Agendamento a ser alterado: ";
    cin >> id;

    for(Agendamento* x : *this->data_set){
        if(x->get_id() == id){
            cout << "1 - Adicionar Resíduo | 0 - Remover Resíduos : ";
            cin >> adicionador;
            if(adicionador == 0)
            {
                int idRemove = 0;
                cout << "Qual o ID do Resíduo a ser removido: ";
                cin >> idRemove;
                x->remove_residuos(idRemove);
            }
            else{
                int idAdd = 0;
                cout << "Qual o ID do Resíduo a ser adicionado: ";
                cin >> idAdd;
                x->add_residuos(idAdd);
            }
        }
        else
            cout << "Agendamento não encontrado! ";
   

    waitKey();

    }
}*/

int AgendamentoController::get_next_id(){
   return 0;   
}