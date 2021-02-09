#include <iostream>
int
    amount_size,
    amount_lowest,
    amount_highest,
    amount_value[100];
int main(){
    int
        x = 0,
        y = 0;
    std::cout<< "How many numbers you want to enter? "; std::cin>> amount_size;
    std::cout<< "Input " << amount_size << " numbers.\n";
    std::cout<< "========================================\n";
    for(int i = 0; i < amount_size; i++){
        std::cout<< i + 1 << ": "; std::cin>> amount_value[i];
        if(amount_value[i] % 2 == 0){
            x++;
        }
        else{
            y++;
        }
        if(amount_highest < amount_value[i]){
            amount_highest = amount_value[i];
        }
    }
    amount_lowest = amount_value[0];
    for(int i = 0; i < amount_size; i++){
        if(amount_lowest > amount_value[i]){
            amount_lowest = amount_value[i];
        }
    }
    std::cout<< "You have entered " << x << " EVEN numbers.\n";
    int count[2] = {1, 1};
    for(int i = 0; i < amount_size; i++){
        if(amount_value[i] % 2 == 0){
            std::cout<< count[0]++ << ": " << amount_value[i] << std::endl;
        }
    }
    std::cout<< std::endl;
    std::cout<< "You have entered " << y << " ODD numbers.\n";
    for(int i = 0; i < amount_size; i++){
        if(amount_value[i] % 2 != 0){
            std::cout<< count[1]++ <<  ": " << amount_value[i] << std::endl;
        }
    }
    std::cout<< std::endl;
    std::cout<< "The LARGEST number you entered is: " << amount_highest << std::endl;
    std::cout<< "The SMALLEST number you entered is: : " << amount_lowest << std::endl;
    system("pause");
}
