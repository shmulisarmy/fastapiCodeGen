#pragma once

#include <iostream>
#include <vector>
#include <map>
using namespace std;


#define pythonMultiLineComment "'''"





map<string, string>typeToPythonType = {
    {"string", "str"},
    {"int", "int"},
    {"float", "float"},
    {"bool", "bool"},
    {"list", "list"},
    {"dict", "dict"},
    {"tuple", "tuple"},
    {"set", "set"},
};


map<string, string>typeToTypeScriptType = {
    {"string", "string"},
    {"int", "number"},
    {"float", "number"},
    {"bool", "boolean"},
    {"list", "any[]"},
    {"dict", "any"},
    {"tuple", "any[]"},
    {"set", "any[]"},
};



map<string, string>dummyData = {
    {"string", "hello"},
    {"int", "10"},
    {"float", "10.5"},
    {"bool", "True"},
    {"list", "[]"},
    {"dict", "{'key': 'value'}"},
    {"tuple", "()"},
    {"set", "set()"},
};

