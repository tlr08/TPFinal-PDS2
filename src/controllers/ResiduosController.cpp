#include "ResiduosController.hpp"

void ResiduosController::run()
{
    bool continueRunning = true;
    dao = new ResiduosDAO(helper);
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
    delete dao;
    dao = nullptr;
}

int ResiduosController::get_view()
{
    int returnValue = -1;
    while (returnValue < 0 || returnValue > 5)
    {
        clearScreen();
        cout << "Gerenciamento de Resíduos" << endl;
        cout << "1 - Cadastrar Resíduo" << endl;
        cout << "2 - Alterar Resíduo" << endl;
        cout << "3 - Listar Resíduos" << endl;
        cout << "4 - Remover Resíduos" << endl;
        cout << "5 - Detalhar Resíduos" << endl;
        cout << "0 - Sair" << endl;
        cout << endl
             << "Selecione uma opção: ";
        cin >> returnValue;
    }
    return returnValue;
}

void ResiduosController::create()
{
    Residuo *residuo = new Residuo();
    cin >> *residuo;
    if (dao->create(residuo))
    {
        cout << "Resíduo cadastrado com sucesso!" << endl;
    }
    else
    {
        cerr << "Erro ao cadastrar o resíduo" << endl;
    }
    waitKey();
    residuo = nullptr;
}

void ResiduosController::update()
{
    Residuo *update = nullptr;
    int id = 0;
    cout << "Informe o Id do Resíduo a ser alterado: ";
    cin >> id;
    update = dao->find(id);
    
    if (update != nullptr)
    {
        cout << "\tDados do Resíduo" << endl << *update << endl
             << "\tAtualização" << endl;
        cin >> *update;
        if(dao->update(update)){
            cout << "Resíduo alterado com sucesso." << endl;
        }else{
            cout << "Erro ao atualizar o resíduo." << endl;
        }
    }
    else
    {
        cout << "Resíduo não encontrado." << endl;
    }
    waitKey();
}

void ResiduosController::show()
{
    int id = -1;
    cout << "Informe o Id do Residuo: ";
    cin >> id;
    Residuo *res = dao->find(id);
    if (res != NULL)
    {
       cout << *res;
    }
    else
    {
        cout << "Resíduo não encontrado." << endl;
    }
    waitKey();
}

void ResiduosController::remove()
{
    int id = -1;
    cout << "Informe o Id do Residuo: ";
    cin >> id;
    if (dao->remove(id))
    {
       cout << "Resíduo removido com sucesso!" << endl;
    }
    else
    {
        cout << "Resíduo não encontrado." << endl;
    }
    waitKey();
}

void ResiduosController::list_all()
{
    clearScreen();
    for (Residuo *residuo : *dao->list_all())
    {
        cout << *residuo;
    }
    waitKey();
}

int ResiduosController::get_next_id()
{
   return 0;
}