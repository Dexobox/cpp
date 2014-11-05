#include <iostream>
#include <string>


using namespace std;

int main(int argc, char **argv ){
    
    std::string input= "";
    
    size_t length;
    //cout <<argc <<endl;
    if (argc > 2){
        cout << "Too Many Arguments! Usage ./uniquestr <string>" <<endl;
        exit(-1);
    }
    
    if(argc == 1){
        cout << "Please enter a string: " <<endl;
        cin >> input;
    }
    else {
        std::string tmp(argv[1]);
        input = tmp;
    }
    //cout << input << endl;
    bool symbols[256];
    int int_of_ascii;
    for(int i=0 ; i< input.length();i++){
        int_of_ascii = (int) input[i];
        /*convert from ascii to int*/
        if(symbols[int_of_ascii] == 0){
            symbols[int_of_ascii]=1;
        }
        else{
            cout << "The String is not contain unique characters" <<endl;
            return 0;
        }
        
    }
    cout << "The String is unique" << endl;
    return 0;
}