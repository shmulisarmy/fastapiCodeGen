#include <fstream>
#include <iostream>
#include <vector>
#include <map>

#include "generalData.cpp"
#include "utils.cpp"
#include "appSpecificData.cpp"
#include "generateReactCode.cpp"
#include "generateFastapiCode.cpp"
#include "generateSqliteCode.cpp"
using namespace std;












int main(){
    ofstream pythonFile("output/main.py");
    genFastApiInit(&pythonFile);
    usersGet(&pythonFile);
    usersPost(&pythonFile);
    usersPut(&pythonFile);
    usersDelete(&pythonFile);

    
    ofstream reactFile("output/main.tsx");
    ReactHead(&reactFile);
    gernateTypeScript(&reactFile);
    reactComponent(&reactFile);
    ReactTail(&reactFile);

    ofstream sqliteFile("output/dataBase.py");
    sqlite::genSqliteInit(&sqliteFile);
    sqlite::usersPost(&sqliteFile);
    sqlite::usersGet(&sqliteFile);
    sqlite::usersDelete(&sqliteFile);
    sqlite::usersPut(&sqliteFile);
    return 0;
}