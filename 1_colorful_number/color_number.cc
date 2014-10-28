/*#########################################################################
Author: Dexobox
###########################################################################*/

#include <iostream>
#include <string>
#include <vector>

unsigned int count_digits( int , std::vector<int>& );
void print_vector(std::vector<int>& );
void generate_combinations(std::vector<int> , std::vector<int>& , unsigned int);
void check_duplicates(std::vector<int>&);

int main() {
    //Getting as string from the user
    std::cout << "Please input a number(can be 10 decimal places long)" << std::endl;
    
    unsigned int input;
    std::cin >> input;
    
    
    /* std::cout << input << std::endl; */
    
    if(input == 0){
        std::cout << "Invalid Input :characters not allowed (add non zero number)" << std::endl;
        exit(1);
    }
    std::vector<int> digits, combinations;
    unsigned int num_digits;
    /* std::cout << sizeof(input) << std::endl; */
    //std::cout << "Counting Digits start " << std::endl;
    num_digits = count_digits(input, digits);
    //std::cout << "Counting Digits stop " << std::endl;   
    
    
    
    print_vector(digits);
    
    
    combinations.clear();
    //std::cout << "Generatring combinations of 2 start " << std::endl;
    generate_combinations(digits, combinations, num_digits);   
    //std::cout << "Genrating combinations stop " << std::endl;
    
    /* std::cout << num_digits <<std::endl; */
    print_vector(combinations);
    
    check_duplicates(combinations);
}

unsigned int count_digits(int x, std::vector<int> &y){
    int result = 0;
    
    do{
        //corner case if the numbers contain a 0 or 1 they will create similar numbers in the combination
        //making them non coloured.
        if(x%10 == 0 || x % 10 == 1)
            {
                std::cout << "The number is not colorful" << std::endl;
                exit(1);    
            }
            
        y.push_back (x%10);
        //std::cout << x%10 << std::endl;
        //std::cout << x/10 << std::endl;
        ++result;
        x/=10;
    }while(x);
    std::cout << result << std::endl;
    return result;
    
}

void print_vector(std::vector<int>& path){
    for( std::vector<int>::const_iterator i = path.begin(); i != path.end(); ++i)
        std::cout << *i << ' ';   
    std::cout << std::endl;
}

void generate_combinations(std::vector<int> z, std::vector<int>& result, unsigned int len){
    //std::cout << len << std::endl;
    //std::cout << z[0] << std::endl;
    
    
    for(int k  = 0 ; k < len-1 ; k++)
    {
        result.push_back(z[k]);
    }
    for(int k  = 0 ; k < len-1 ; k++)
    {
        result.push_back(z[k]*z[k+1]);
    }
    for(int k  = 0 ; k < len-2 ; k+=1)
    {
        result.push_back(z[k]*z[k+1]*z[k+2]);
    }
}

void check_duplicates(std::vector<int>& w ){
    int vector_size = w.size();
    for(int l = 0; l < vector_size; l++)
    {
        for(int m = 0; m < vector_size; m++)
        {
            if(m != l && w[l] == w[m])
            {
                std::cout << "The number is not colorful" <<std::endl;
                exit(0);
            }  
        }
    }
    std::cout << "The number is colorful" <<std::endl;
}
