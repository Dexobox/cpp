/*#########################################################################
Author: Dexobox
###########################################################################*/

#include <iostream>
#include <string>
#include <cstdbool>
#include <algorithm>

bool check_alphabets(std::string& );
void seprate_case(std::string , std::string& , std::string& );
void combine_to_well_order(std::string& , std::string& , std::string& );

int main(){
    
    std::string input;
    
    //getting string input from the user
    std::cout << "Please enter an input string (without spaces) for ordering" << std::endl;
    
    std::cin >> input;
    
    std::cout << input << std::endl;
    
    //check if the string contins only alphabets , parsing for 
    if(!check_alphabets(input)){
        std::cout << "Invalid! string contatins characters that are not alphabets" << std::endl;
        return 0;
    }

    //howt to do the ordering 
        std::string small, caps, result;
        
        // seprate out the capitals and small chars
        seprate_case(input, small, caps);
        
        std::cout << small << std::endl;
        std::cout << caps << std::endl;
        // sort them individually
        sort(small.begin(), small.end());
        sort(caps.begin(), caps.end());
        std::cout << "Sorted :" << std::endl;
        std::cout << small << std::endl;
        std::cout << caps << std::endl;
        
        // combine them back to into a single string. with a  loop itteration
        combine_to_well_order(small, caps, result);
        std::cout << result << std::endl;
}



bool check_alphabets(std::string& x){
    int len = x.length();
    for(int i = 0; i < len; i++){
        std::cout << x[i] <<std::endl;
        if( (x[i] <= 'z' && x[i] >='a') || (x[i]<='Z' && x[i] >= 'A') ){
            continue;
        }else{
            return 0;
        }
    }
    return 1;
}

void seprate_case(std::string u, std::string& small, std::string& caps ){
    int len  = u.length();
    
    for(int i =0; i< len; i++){
        if( u[i] <= 'z' && u[i] >='a' ){
            small = small.append(1, u[i]);
        }else{
            caps.append( 1, u[i]);
        }
    }
}

void combine_to_well_order(std::string& small, std::string& caps, std::string& result){
    char i, j;
    bool loop1 =1;
    bool loop2 =1;
    std::size_t flag1, flag2;
    for( i = 'a', j = 'A'; i<='z', j<='Z'; i++, j++){
        //std::cout << i << j << std::endl;  
        flag1 = small.find(i);
        while(flag1 != std::string::npos){
            //std::cout<< i<<" == " << flag1 << std::endl; 
            result.append(1,i);
            small.erase(flag1,1);
            flag1 = small.find(i);
        }
        flag2 = caps.find(j);
        while(flag2 != std::string::npos){
            //std::cout<< i<<" == " << flag1 << std::endl; 
            result.append(1,j);
            caps.erase(flag2,1);
            flag2 = caps.find(j);
        }
    }
}