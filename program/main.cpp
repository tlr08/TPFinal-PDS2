#include <iostream>
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "MainController.hpp"
using namespace std;


int main(){
	DbHelper *db; 	
	MainController* controller;
	
	db = new DbHelper(DEFAULT_DBNAME);
	controller = new MainController(db->getDatabase());
	
	db->startConnection();
	controller->run();
	db->closeConnection();
	
	delete db;
	delete controller;
	
	return 0;
}
