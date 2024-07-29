#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "generalData.cpp"
#include "appSpecificData.cpp"
#include "generalData.cpp"
#include "utils.cpp"
using namespace std;


void ReactHead(ofstream *buffer){
    
    *buffer << "let React, ReactDOM;" << endl;
    *buffer << "const { useState, useRef, useEffect, useMemo, useCallback, useContext, createContext } = React" << endl;

}

void ReactTail(ofstream *buffer){

    *buffer << "function App() {" << endl;
    *buffer << "    return (" << endl;
    *buffer << "        <div className=\"App\">" << endl;
    *buffer << "            <h1>Wellcome to " << appName << "app </h1>" << endl;
    *buffer << "            <h2>Start editing to see some magic happen!</h2>" << endl;
    *buffer << "            <div className=\"" << appName << "-container\">" << endl;
    *buffer << "                {" << appName << ".map((" << appName << ") => < " << appName << "key={" << appName << ".id} " << appName << "={" << appName << "} />)}" << endl;
    *buffer << "            </div>" << endl;
    *buffer << "        </div>" << endl;
    *buffer << "    );" << endl;
    *buffer << "}" << endl;
    
    *buffer << "ReactDOM.render(<" << appName << " " << appName << "={" << appName << "[0]}/>, document.getElementById('root'))" << endl;
}




void reactComponent(ofstream *buffer){

    *buffer << "function " << capFirstLetter((char *)toSingular(appName).c_str()) << "({" << toSingular(appName) << "}: {" << toSingular(appName) << ": " << capFirstLetter((char *)toSingular(appName).c_str()) << "}) {" << endl;
    *buffer << "    const [placeholder, setPlaceholder] = React.useState()" << endl;
    *buffer << "    const rerender = () => setPlaceholder(!placeholder);" << endl;
    *buffer << "    return (" << endl;
    *buffer << "        <div className='" << appName << "'" << ">" << endl;
    
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << "            <p>" << key << ": {" << appName << "." << key << "}" << "</p>" << endl;
    }


    *buffer << "        </div>" << endl;
    *buffer << "    );" << endl;
    *buffer << "}" << endl;
}


void gernateTypeScript(ofstream *buffer){


    *buffer << "type " << capFirstLetter((char *)toSingular(appName).c_str()) << " = {" << endl;

    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;

        *buffer << "    " << key << ": " << typeToTypeScriptType[value] << "," << endl;
    }

    *buffer << "};" << endl;
}