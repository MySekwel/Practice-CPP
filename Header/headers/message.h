#include <iostream>
#include <string>

std::string input_message, response[4];

void EncryptMessage();
void DecryptMessage();

void GetMessage(int account){
    if(account == 0){
        std::cout<<"\n==============================\n";
        std::cout<<"Hello, " << user_name[accountid] << "! Please type your message now.\n\n";

        std::getline(std::cin, input_message);
        std::cout<<"\nDo you want to send the message \"" << input_message << "\"? Type SEND if you agree. (Note: It will only be sent if you typed SEND): ";
        std::getline(std::cin, response[0]);

        if(response[0] == "SEND"){
            std::cout<<"\nMessage has been sent successfuly. Clearing the screen now will clear this screen and log you out, " << user_name[accountid] << ".\n";
            accountid++;
            attempts = 2;
        }
        system("pause");
        system("cls");

        GetAccount();
    }
    if(account == 1){
        std::cout<<"\n==============================\n";
        std::cout<<"Hello, " << user_name[accountid] << ". You got 1 message from " << user_name[accountid-1] << ".\n";
        std::cout<<"Display message now? Type YES or NO: ";
        std::getline(std::cin, response[1]);

        if(response[1] == "YES"){
            EncryptMessage();
            std::cout<<"\nMESSAGE FROM ANNA:\n";
            std::cout<<input_message;
        }
        else if(response[1] == "NO"){
            std::cout<<"Okay " << user_name[accountid] << ". Do you want to delete the message from " << user_name[accountid-1] << "? TYPE YES: ";
            std::getline(std::cin, response[2]);
            if(response[2] == "YES"){
                std::cout<<"\n\nMessage has been deleted. Pressing any key will end this program.\n";
                system("pause");
                std::exit(0);
            }
            return;
        }
        
        std::cout<<"\n\nDo you want to decrypt the message? Type YES: ";
        std::getline(std::cin, response[3]);
        if(response[3] == "YES"){
            DecryptMessage();
            std::cout<<"\nMESSAGE FROM ANNA:\n";
            std::cout<<input_message << std::endl;
            system("pause");
            std::exit(0);
        }
    }
}