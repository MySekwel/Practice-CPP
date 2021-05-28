#include <iostream>
#include <string>

void GetMessage(int account);
void GetAccount();

int accountid;
std::string user_name[2], user_pass[2];
int attempts = 2;

bool IsAccountValid(int accountid){
    if(accountid == 0){
        if(user_name[accountid] == "Anna" && user_pass[accountid] == "Hannah1234"){
            return true;
        }
    }
    if(accountid == 1){
        if(user_name[accountid] == "Tom" && user_pass[accountid] == "Cat234"){
            return true;
        }
    }
    return false;
}

void ProcessInvalidAuth(){
    std::cout<<"\n==============================\n";
    std::cout<<"Invalid username or password (" << attempts << ")\n";

    if(!attempts){
        std::cout<<"\nThe program will end now.\n";
        system("pause");
        std::exit(0);
    }
    attempts--;

    system("pause");
    system("cls");

    GetAccount();
    return;
}

void GetAccount(){
    for(int i = 0; i < MAX_ACCOUNTS; i++){
        if(accountid == i){
            std::cout<<"USERNAME: ";
            std::getline(std::cin, user_name[i]);
            std::cout<<"PASSWORD: ";
            std::getline(std::cin, user_pass[i]);

            if(!IsAccountValid(i)){
                ProcessInvalidAuth();
            }
        }
    }

    GetMessage(accountid);
}