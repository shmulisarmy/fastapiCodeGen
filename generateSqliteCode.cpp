#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "generalData.cpp"
#include "utils.cpp"
#include "appSpecificData.cpp"


namespace sqlite {
    

void genSqliteInit(ofstream *buffer){
    *buffer << "import sqlite3" << endl;
    *buffer << "\n\n\n\n\n\n" << endl;
}


void usersGet(ofstream *buffer){
    *buffer << "def get(id: int) -> list[tuple]|None:" << endl;
    *buffer << "\t" << pythonMultiLineComment << "gets " << capFirstLetter(appName) << " by id with the following fields" << endl;
    *buffer << "\t";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ", ";
    }

    *buffer << "id" << pythonMultiLineComment << endl;

    *buffer << "\tconn = sqlite3.connect('users.db')" << endl;
    *buffer << "\tquery = 'SELECT ";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ", ";
    }
    *buffer << "id FROM " << appName << " WHERE id = ?'" << endl;
    *buffer << "\twith conn:" << endl;
    *buffer << "\t\tcur = conn.cursor()" << endl;
    *buffer << "\t\tcur.execute(query, (id,))" << endl;
    *buffer << "\t\treturn cur.fetchone()" << endl;
}



void usersPost(ofstream *buffer){

    *buffer << "def post(";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ": " << value << ", ";
    }
    *buffer << "):" << endl;
    *buffer << "\t" << pythonMultiLineComment << "posts " << capFirstLetter(appName) << " with the following fields" << endl;
    *buffer << "\t";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ", ";
    }
    *buffer << pythonMultiLineComment << endl;
    *buffer << "\tconn = sqlite3.connect('users.db')" << endl;
    *buffer << "\tquery = 'INSERT INTO " << appName << "(";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = typeToPythonType[pair.second];
        *buffer << key << ", ";
    }
    *buffer << ") VALUES(";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = typeToPythonType[pair.second];
        *buffer << key << ", ";
    }
    *buffer << ")'" << endl;
    *buffer << "\twith conn:" << endl;
    *buffer << "\t\tcur = conn.cursor()" << endl;
    *buffer << "\t\tcur.execute(query, (";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = typeToPythonType[pair.second];

        *buffer << key << ", ";
    }
    *buffer << "))" << endl;
    *buffer << "\t\tconn.commit()" << endl;
}

void usersPut(ofstream *buffer){
    *buffer << "def put(";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ": " << value << ", ";
    }
    *buffer << "):" << endl;
    *buffer << "\t" << pythonMultiLineComment << "puts " << capFirstLetter(appName) << " with the following fields" << endl;
    *buffer << "\t";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ", ";
    }
    *buffer << pythonMultiLineComment << endl;
    *buffer << "\tconn = sqlite3.connect('users.db')" << endl;
    *buffer << "\tquery = 'UPDATE " << appName << " SET ";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = typeToPythonType[pair.second];
        *buffer << key << " = ?, ";
    }
    *buffer << " WHERE id = ?'" << endl;
    *buffer << "\twith conn:" << endl;
    *buffer << "\t\tcur = conn.cursor()" << endl;
    *buffer << "\t\tcur.execute(query, (";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = typeToPythonType[pair.second];
        *buffer << key << ", ";
    }
    *buffer << "))" << endl;
    *buffer << "\t\tconn.commit()" << endl;
}

void usersDelete(ofstream *buffer){
    *buffer << "def delete(id):" << endl;
    *buffer << "\tconn = sqlite3.connect('users.db')" << endl;
    *buffer << "\tquery = 'DELETE FROM " << appName << " WHERE id = ?'" << endl;
    *buffer << "\twith conn:" << endl;
    *buffer << "\t\tcur = conn.cursor()" << endl;
    *buffer << "\t\tcur.execute(query, (id,))" << endl;
    *buffer << "\t\tconn.commit()" << endl;
}


};