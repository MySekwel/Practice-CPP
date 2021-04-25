// 1. Create a program that will ask user to input number or rows and columns. 
// 2. Then the user will input values needed for every rows and columns. 
// 3. Display and arrange the numbers on how they should appear in rows and columns.
// 4. Get the sum for every rows. Get the sum for every columns. 
// 5. FOLLOW THE FORMAT on the sample image.

#include <iostream>

#define MAX_COLUMNS     100
#define MAX_ROWS        100

int values[MAX_COLUMNS][MAX_ROWS];
int sum[2];

void separator(int columns){
    for(int i = 0; i < columns; i++){
        std::cout<<"========";
    }
    std::cout<<std::endl;
}

int main(){
    int rows = 0, columns = 0;
    std::cout<<"How many rows? "; std::cin>>rows;
    std::cout<<"How many columns? "; std::cin>>columns;
    std::cout<<"=======================\n";

    for(int i = 0; i < rows; i++){
        for(int x = 0; x < columns; x++){
            std::cin>>values[i][x];
        }
        std::cout<<std::endl;
    }

    for(int i = 0; i < rows; i++){
        for(int x = 0; x < columns; x++){
            std::cout<<values[i][x]<<"\t";
            sum[0] += values[i][x];
        }
        std::cout<<"|| "<<sum[0]<<std::endl;
        sum[0] = 0;
    }
    separator(columns);
    for(int i = 0; i < columns; i++){
        for(int x = 0; x < rows; x++){
            sum[1] += values[x][i];
        }
        std::cout<<sum[1]<<"\t";
        sum[1] = 0;
    }
    std::cout<<std::endl;
    return 0;
}