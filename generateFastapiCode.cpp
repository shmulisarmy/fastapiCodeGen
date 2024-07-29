#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "generalData.cpp"
#include "utils.cpp"
#include "appSpecificData.cpp"
using namespace std;




void genFastApiInit(ofstream *buffer){
    *buffer << "from fastapi import FastAPI" << endl;
    *buffer << "app = FastAPI()" << endl;
    *buffer << "\n\n\n\n\n\n" << endl;
}



void usersGet(ofstream *buffer){
    *buffer << "@app.get(\"/" << appName;
    *buffer << "/{id}\")" << endl;
    *buffer << "async def get(id : int)" << ": dict" << endl;
    *buffer << "\tdb" << "Get" << capFirstLetter(appName) << "(id: int) -> dict" << endl;
}

void usersPost(ofstream *buffer){
    *buffer << "@app.post(\"" << appName;
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << "/{" << key << "}";
    }
    *buffer << "\")" << endl;
    *buffer << "async def post(username: str, password: str) -> dict:" << endl;
    
    *buffer << "\t" << pythonMultiLineComment << "posts " << capFirstLetter(appName) << " with the following fields: username, password" << endl;
    *buffer << "\t";
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << key << ", ";
    }
    *buffer << pythonMultiLineComment << endl;
    
    *buffer << "\treturn {" << endl;
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << "\t\t\"" << key << "\": " << key << ", " << endl;
    }
    *buffer << "\t}" << endl;
}

void usersPut(ofstream *buffer){

    *buffer << "@app.put(\"/" << appName << "\")" << endl;
    *buffer << "async def put(id : int, ";
    *buffer <<  ")";
    displayFields(userDetails, &*buffer);
    *buffer << ": dict" << endl;

    *buffer << "\tdb" << "Put" << capFirstLetter(appName) << "(";
    displayVars(userDetails, &*buffer);
    *buffer << ")" << endl;
}

void usersDelete(ofstream *buffer){

    *buffer << "@app.delete(\"/" << appName << "\")" << endl;
    *buffer << "async def delete(id : int)" << ": dict" << endl;
    *buffer << "\tdb" << "Delete" << capFirstLetter((char *)appName) << "(id: int)" << endl;
}



void generateUserClass(ofstream *buffer){
    *buffer << "class User(BaseModel):" << endl;
    for (auto pair : userDetails) {
        *buffer << "\t" << pair.first << ": " << typeToPythonType[pair.second] << endl;
    }
}

