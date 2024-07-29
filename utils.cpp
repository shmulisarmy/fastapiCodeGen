#pragma once
#include <iostream>
#include <cctype>
#include <vector>
#include <map>
#include <cstdarg>  // For variadic functions
#include <fstream>

// #include "/Users/Shmuli/coding-projects/library/utils.cpp"
#include "generalData.cpp"




using namespace std;







string capFirstLetter(string str){
    str[0] = toupper(str[0]);
    return string(str);
}

string toSingular(string word) {



    string singularWord = word;

    // Handle plural forms based on specific rules
    if (word.size() > 0) {
        if (word.back() == 's') {
            singularWord.pop_back(); // Remove 's' at the end
            
            // Handle specific cases for plurals
            if (singularWord.back() == 'x') {
                singularWord.pop_back(); // Remove 'x'
            } else if (singularWord.back() == 'y') {
                singularWord.pop_back(); // Remove 'y'
                singularWord += 'i';     // Add 'i'
            } else if (singularWord.substr(singularWord.size() - 3) == "oes") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "o"; // Change "oes" to "o"
            } else if (singularWord.substr(singularWord.size() - 2) == "sses") {
                singularWord = singularWord.substr(0, singularWord.size() - 2) + "ss"; // Change "sses" to "ss"
            } else if (singularWord.substr(singularWord.size() - 3) == "ies") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "y"; // Change "ies" to "y"
            } else if (singularWord.back() == 's') {
                // If still ends with 's', it's likely a plural without specific rule, keep 's'
            } else {
                // Default case, append 's' (though this might need more specific handling)
                singularWord += 's';
            }
        } else if (word.size() >= 2 && word.substr(word.size() - 2) == "en") {
            // Handle endings like "men" -> "man", "oxen" -> "ox"
            if (word.substr(word.size() - 3) == "omen") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "an"; // Change "omen" to "an"
            } else if (word.substr(word.size() - 3) == "oxen") {
                singularWord = singularWord.substr(0, singularWord.size() - 1); // Remove "n" from "oxen"
            }
        } else if (word.size() >= 2 && word.substr(word.size() - 2) == "ves") {
            // Handle endings like "lives" -> "life", "leaves" -> "leaf"
            if (word.size() >= 4 && word.substr(word.size() - 4) == "aves") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "f"; // Change "aves" to "f"
            } else if (word.size() >= 5 && word.substr(word.size() - 5) == "elves") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "f"; // Change "elves" to "f"
            } else {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "fe"; // Change "ves" to "fe"
            }
        } else if (word.size() >= 3 && word.substr(word.size() - 3) == "men") {
            // Handle ending like "women" -> "woman", "children" -> "child"
            if (word.size() >= 6 && word.substr(word.size() - 6) == "women") {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "an"; // Change "women" to "woman"
            } else {
                singularWord = singularWord.substr(0, singularWord.size() - 3) + "d"; // Change "children" to "child"
            }
        }
    }

    return singularWord;
}





inline void displayFields(map<string, string> userDetails, ofstream *buffer){
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << ", " << key << ": " << typeToPythonType[value];
    }
}

inline void displayVars(map<string, string> userDetails, ofstream *buffer){
    for (auto pair : userDetails) {
        string key = pair.first;
        string value = pair.second;
        *buffer << ", " << key << " ";
    }
}





// int main() {

//     fstringWriter("hello.txt", {"hello", ""});

//     cout << cyan(toSingular("children")) << endl;
//     cout << magenta("hello") << endl;
//     cout << red("hello") << endl;
//     cout << green("hello") << endl;

//     return 0;
// }