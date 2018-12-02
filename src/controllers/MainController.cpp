#include "MainController.hpp"

using namespace std;


MainController::MainController(sqlite3* db){
    this->db = db;
    this->residuos = new ResiduosController(db);
}

void MainController::run(){
    bool continueRunning = true;
    do {
        switch(showView()){
            case 0:
                continueRunning = false;
                break;
            case 1:
                this->residuos->run();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }

    } while(continueRunning);

}

int MainController::showView(){
    int returnValue = -1;

    while (returnValue < 0  || returnValue > 4){
        returnValue = clearScreen();
        cout << APP_NAME << endl;
        cout << "1 - Gerenciamento de Resíduos" << endl;
        cout << "2 - Gerenciamento de Usuários" << endl;
        cout << "3 - Gerenciamento de Pontos de Coletas" << endl;
        cout << "4 - Agendamento de Coletas" << endl;
        cout << "0 - Sair" << endl;
        cout << "Selecione uma opção: ";
        cin >> returnValue;
    }

    return returnValue;
}

