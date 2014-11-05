#include <iostream>
#include <string>

int main(){
    unsigned int num_digits;
    unsigned int dis1, dis2, dis3;
    std::cout<<"Please enter the number of digits in the phone number: " << std::endl;
    std::cin >> num_digits;
    
    //std::cout << num_digits <<std::endl;
    
    std::cout << "Pleas enter the three numbers to be disallowed(seprated by spaces):" <<std::endl;
    std::cin >> dis1 >> dis2 >> dis3;
    //std::cout << dis1<<dis2<<dis3 <<std::endl;
    
    std::string max = std::string(num_digits, '9') ;
    std::cout << max << std::endl;
    
    
    
}