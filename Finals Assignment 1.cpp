#include <iostream>
// - Global Variable Declaration
int
    customer = 1,
    newCustomer,
    repeat;
float
    bookCost[3],
    bookCharge[3],
    bookCharged[3],
    total;
// - Long Line function
void longLine(int lines){
    for(int i = 0; i < lines; i++){
        std::cout<< ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    }
}
// Main Function
int main(){
    MENU: // - goto reference
    longLine(2);
    std::cout<< "\t\t\t\t\tPHOTOBOOK STORE:\n"; // Title
    longLine(2);

    bookCost[0]   = 600.00; bookCost[1]   = 2000.00; bookCost[2]   = 3000.00;                                   // - Price of Bundle
    bookCharge[0] = bookCost[0] / 100; bookCharge[1] = bookCost[1] / 250; bookCharge[2] = bookCost[2] / 250;    // - Additional Charge Price

    std::cout<< "\nWelcome to Photobook Store Customer#:" << customer << std::endl << std::endl; // Welcome customer message
    std::cout<< "SELECT BOOK SIZE\n";
    std::cout<< "1 - 6\" x 6\"\t" <<   bookCost[0] <<" (21 Photos plus " << bookCharge[0] << " for every additional photos)\n"; // - Bundle price for photo size 6 x 6
    std::cout<< "2 - 8\" x 8\"\t" <<   bookCost[1] <<" (21 Photos plus " << bookCharge[1] << " for every additional photos)\n"; // - Bundle price for photo size 8 x 8
    std::cout<< "3 - 12\" x 12\"\t" << bookCost[2] <<" (21 Photos plus " << bookCharge[2] << " for every additional photos)\n"; // - Bundle price for photo size 12 x 12
    longLine(1);
    int // - Variable reset after goto
        photosAmount = 0,
        bookSize = 0,
        additionalPhotos = 0;
    // - Input Processing
    std::cout<< "BOOK SIZE(Press 1, 2, or 3): "; std::cin>> bookSize;

    if(bookSize >= 1 && bookSize <= 3){
        std::cout<< "HOW MANY PHOTOS? "; std::cin>> photosAmount;
        if(photosAmount >= 21){
            additionalPhotos = photosAmount - 21;
            std::cout<< "Customer # " << customer << std::endl;
            std::cout<< "----------------------------------------------\n";
            for(int i = 0, ii = 1; i < 3; i++, ii++){
                if(bookSize == ii){
                    if(bookSize == 1) std::cout<< "6\" x 6\" Photobook\n";
                    if(bookSize == 2) std::cout<< "8\" x 8\" Photobook\n";
                    if(bookSize == 3) std::cout<< "12\" x 12\" Photobook\n";
                    float amountDue;
                    bookCharged[i] = additionalPhotos * bookCharge[i];
                    amountDue += bookCharged[i];
                    
                    std::cout<< photosAmount << " with " << additionalPhotos << " additional Photos\n";
                    std::cout<< "Additional Charge is: " << bookCharged[i] << std::endl << std::endl;
                    std::cout<< "AMOUNT DUE: " << bookCost[i] + amountDue << std::endl;

                    total += amountDue + bookCost[i];
                    amountDue = 0;
                }
            }
            std::cout<< "----------------------------------------------\n";
            std::cout<< "NEW CUSTOMER(1 - YES): "; std::cin>> newCustomer;
            if(newCustomer == 1){
                do{
                    system("cls");
                    goto MENU;
                    newCustomer++;
                } while(newCustomer < 1);
            } else{
                std::cout<< "  =======================================================\n";
                std::cout<< "||\tTOTAL NUMBER OF CUSTOMERS TODAY: "<< customer << "\t\t||\n";
                std::cout<< "||\tTOTAL AMOUNT SALES: "             << total    << "\t\t\t||\n";
                std::cout<< "  =======================================================\n";
            }
        } else{
            std::cout<< "Unable to process order with less than 21 Photos\n";
            std::cout<< "Do you want to continue processing order of Customer #1?\n";
            std::cout<< "Press 1 for YES: "; std::cin>> repeat;
            if(repeat == 1){
                do{
                    system("cls");
                    goto MENU;
                    repeat++;
                } while(repeat < 1);
            } else{
                system("cls");
                customer++;
                goto MENU;
            }
        }
    } else{
        system("cls");
        goto MENU;
        return 1;
    }
    system("pause");
}
