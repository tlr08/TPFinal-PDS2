#include "PontoColetaController.hpp"

PontoColetaController::PontoColetaController(DbHelper *helper)
{
    this->dao = new PontoColetaDAO(helper);
    this->usuarioDAO = new UsuarioDAO(helper);
}

PontoColetaController::~PontoColetaController()
{
    delete this->dao;
    delete this->usuarioDAO;
    this->dao = nullptr;
    this->usuarioDAO = nullptr;
}

void PontoColetaController::run()
{
    bool continueRunning = true;
    do
    {
        switch (get_view())
        {
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

    } while (continueRunning);
}

int PontoColetaController::get_view()
{
    int returnValue = -1;
    while (returnValue < 0 || returnValue > 5)
    {
        clearScreen();
        cout << "Gerenciamento de Pontos de Coleta" << endl;
        cout << "1 - Cadastrar Local" << endl;
        cout << "2 - Alterar Local" << endl;
        cout << "3 - Listar Locais" << endl;
        cout << "4 - Remover Locais" << endl;
        cout << "5 - Detalhar Locais" << endl;
        cout << "0 - Sair" << endl;
        cout << endl
             << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void PontoColetaController::create()
{
    PontoColeta *local = new PontoColeta();
    Usuario *user = nullptr;
    int updateUser = 0;
    
    clearScreen();
    
    cout << "\tCadastro de Ponto de Coleta" << endl
         << endl;
    
    cin >> *local;
    
    cout << "Deseja vincular o ponto de coleta com um usuário?" << endl
         << "0 - NAO" << endl
         << "1 - SIM" << endl;

    cin >> updateUser;
    if (updateUser == 1)
    {
        cout << "Informe o Id do Usuário: ";
        cin >> updateUser;
        user = usuarioDAO->find(updateUser);
        if (user != nullptr)
        {
            local->set_Usuario(user);
        }
        else
        {
            cout << "Id não encontrado, o usuário não será vinculado." << endl;
        }
    }
    if(dao->create(local)){
        cout << "Ponto de Coleta cadastrado com sucesso!" << endl;
    }else{
        cout << "Falha ao cadastrar o ponto de coleta." << endl;
    }
    waitKey();
    
    delete local;
    local = nullptr;

    if(user!=nullptr)
        delete user;
    
    user = nullptr;
}

void PontoColetaController::update()
{
    PontoColeta *update = nullptr;
    int id = 0;
    int updateUser = 0;
    Usuario *user = nullptr;
    cout << "Informe o ID do Local a ser alterado: ";
    cin >> id;

    update = dao->find(id);
    if (update != nullptr)
    {
        cout << "\tDados do Local" << endl
             << *update << endl
             << "\tAtualização" << endl;
        cin >> *update;
        cout << "Deseja alterar o vínculo do ponto de coleta com usuário?" << endl
             << "0 - NAO" << endl
             << "1 - SIM" << endl;

        cin >> updateUser;
        if (updateUser == 1)
        {
            cout << "Informe o Id do Usuário: ";
            cin >> updateUser;
            user = usuarioDAO->find(updateUser);
            if (user != nullptr)
            {
                update->set_Usuario(user);
            }
            else
            {
                cout << "Id não encontrado, o usuário não será alterado." << endl;
            }
        }
        if (dao->update(update))
        {
            cout << "Local alterado com sucesso." << endl;
        }
        else
        {
            cout << "Falha ao alterar Local." << endl;
        }
    }
    else
    {
        cout << "Local não encontrado." << endl;
    }
    waitKey();
}

void PontoColetaController::show()
{
    int id = -1;
    clearScreen();
    cout << "Informe o Id do Local: ";
    cin >> id;
    PontoColeta *ponto = dao->find(id);
    if (ponto != nullptr)
    {
        cout << "\tDados do Ponto de Coleta" << endl;
        cout << *ponto << endl;
    }
    else
    {
        cout << "Ponto de Coleta não encontrado." << endl;
    }
    waitKey();
}

void PontoColetaController::remove()
{
    int id = 0;
    cout << "Informe o Id do Ponto de coleta: ";
    cin >> id;
    PontoColeta *ponto = dao->find(id);
    if (ponto != nullptr)
    {
        dao->remove(id);
        cout << "Ponto de coleta removido com sucesso." << endl;
        
    }
    else
    {
        cout << "Não foi possível remover o Ponto de Coleta selecionado." << endl;
    }


    waitKey();
}

void PontoColetaController::list_all()
{
    clearScreen();
    cout << "\tPontos de Coletas" << endl
         << endl;
    for (PontoColeta *local : *dao->list_all())
    {
        cout << *local;
    }
    waitKey();
}

