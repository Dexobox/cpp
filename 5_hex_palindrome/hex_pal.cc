#include <iostream>
#include <string>
#include <sstream>

int convert_to_octal( int);
void reverse_str(std::string, std::string&);

int main(){
    /* Accept input from user */
    std::cout << "Enter a decimal number to which palindromes in octal are to be calculated " << std::endl;
    int max = 0;
    std::cin >> max;
    int result;
    
    #ifdef DEBUG
    std::cout << max << std::endl;
    #endif
    
    int num_oct, result1, result2, palindrome_count = 0;
    std::string dec, oct, rev_oct, rev_dec;   
    std::ostringstream Convert;
    
    /* iterating through numbers from 0 to max */
    for( int i = 0 ; i <= max; i++){
        
        #ifdef DEBUG
        std::cout << i << std::endl;
        #endif
        
        num_oct = convert_to_octal(i);
        
        #ifdef DEBUG
        std::cout << num_oct << std::endl;
        #endif
        
        Convert << i;
        dec = Convert.str();
        
        Convert.str("");
        
        Convert << num_oct;
        oct = Convert.str();
        
        #ifdef DEBUG
        std::cout << dec << std::endl;
        std::cout <<"Octal :" << oct << std::endl;
        #endif
        
        
        
        reverse_str(oct, rev_oct);
        reverse_str(dec, rev_dec);
        
        //std::cout << "oct: " << oct << "rev_oct: " << rev_oct <<std::endl;
        result1 = oct.compare(rev_oct);
        //std::cout << result1 << " "<<sizeof(oct)<<" "<<sizeof(rev_oct) <<std::endl;
        //std::cout << "dec: " << dec << "rev_dec: " << rev_dec <<std::endl;
        result2 = dec.compare(rev_dec);
        //std::cout << result2 << " "<<sizeof(dec)<<" "<<sizeof(rev_dec) <<std::endl;
        
        #ifdef DEBUG
        std::cout << "Reversed Octal: " << rev_oct << std::endl;
        #endif
        
        //result1 = oct.compare(rev_oct);
        // /result2 = dec.compare(rev_dec);
        if(result1 == 0 && result2 ==0)
        {
            std::cout << dec << " is a palindrome in decimal (" << dec <<")D and octal (" <<oct<< ")OCT" <<std::endl;
            palindrome_count++;
        }
        dec.clear();
        oct.clear();
        rev_oct.clear();
        rev_dec.clear();
        Convert.str("");
        
    
    }
    if(palindrome_count == 0)
    {
        std::cout << "There are no palindromes between 1 and "<< max << std::endl;
    }
}


int convert_to_octal( int x ){
    int r, octal = 0,i = 1;
    while( x != 0 ){
    r =  x % 8;
    x /= 8;
    octal+= r*i;
    i*=10;
    }
    return octal;
}


void reverse_str(std::string str, std::string& rev){
    for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
    {
        //std::cout << *rit ;
        rev.append(1,  *rit );
    }
    //rev.append(1,'\0');
}