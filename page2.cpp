// 1. Create a program that asks user to input number of rows and columns.
// 2. Input numbers depending on the number of rows and columns.
// 3. Display the size of the matrix based on the number of rows and columns.
// 4. Transpose the matrix and display its size and values.
// 5. FOLLOW THE FORMAT on the sample image.

#include <iostream>

#define MAX_ROWS        100
#define MAX_COLUMNS     100

int values[MAX_ROWS][MAX_COLUMNS];

int main(){
    int rows = 0, columns = 0;
    std::cout<<"How many rows? "; std::cin>>rows;
    std::cout<<"How many columns? "; std::cin>>columns;
    std::cout<<"=====================================================\n";

    std::cout<<"Input "<<rows * columns<<" numbers:\n";
    for(int i = 0; i < rows; i++){
        for(int x=0; x < columns; x++){
            std::cin>>values[i][x];
        }
    }
    std::cout<<"=====================================================\n";
    std::cout<< rows << " X " << columns << " Matrix\n";
    std::cout<<"=====================================================\n";
    for(int i=0; i < rows; i++){
        for(int x=0; x < columns; x++){
            std::cout<<values[i][x] << "\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<"=====================================================\n";
    std::cout<< "TRANSPOSE OF THE MATRIX ABOVE\n";
    std::cout<< columns << " X " << rows << " Matrix\n";
    std::cout<<"=====================================================\n";
    for(int i=0; i < columns; i++){
        for(int x=0; x < rows; x++){
            std::cout<<values[x][i] << "\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}