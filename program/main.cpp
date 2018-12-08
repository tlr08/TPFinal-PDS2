#include <iostream>
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "MainController.hpp"
#include "Usuario.hpp"
using namespace std;
#define RESET_CMD "RESET"

int main(int argc, const char *argv[]){
	DbHelper *db; 	
	MainController* controller;
	
	db = new DbHelper(DEFAULT_DBNAME);
	db->startConnection();
	
	if(argc > 1){
		std::string command = argv[1];
		if(command.compare(RESET_CMD)==0)
			db->down();
	}

	db->up();
	controller = new MainController(db);
	controller->run();
	

	db->closeConnection();
	
	delete db;
	return 0;
}
