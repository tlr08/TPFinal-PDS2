#include <iostream>
#include "stdafx.hpp"
#include "DbHelper.hpp"
using namespace std;


int main(){
	DbHelper *db; 	
	db = new DbHelper(DEFAULT_DBNAME);
	db->startConnection();
	cout << "Running db: " << db->getDbName() << endl;
	db->closeConnection();
	return 0;
}
