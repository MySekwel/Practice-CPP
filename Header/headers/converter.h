#include <iostream>
#include <string>

std::string vowels = "AEIOU";

void EncryptMessage(){
    if(accountid == 1){
        for(int i = 0; i < input_message.size(); i++){
            if(toupper(input_message[i]) == vowels[0]){
                input_message.replace(i, 1, "@");
            }
            if(toupper(input_message[i]) == vowels[1]){
                input_message.replace(i, 1, "3");
            }
            if(toupper(input_message[i]) == vowels[2]){
                input_message.replace(i, 1, "===");
            }
            if(toupper(input_message[i]) == vowels[3]){
                input_message.replace(i, 1, "<>");
            }
            if(toupper(input_message[i]) == vowels[4]){
                input_message.replace(i, 1, "8");
            }
        }
    }
}

void DecryptMessage(){
    if(accountid == 1){
        for(int i = 0; i < input_message.size(); i++){
            if(input_message.find("@") != std::string::npos){
                input_message.replace(input_message.find("@"), 1, "a");
            }
            if(input_message.find("3") != std::string::npos){
                input_message.replace(input_message.find("3"), 1, "e");
            }
            if(input_message.find("===") != std::string::npos){
                input_message.replace(input_message.find("==="), 3, "i");
            }
            if(input_message.find("<>") != std::string::npos){
                input_message.replace(input_message.find("<>"), 2, "o");
            }
            if(input_message.find("8") != std::string::npos){
                input_message.replace(input_message.find("8"), 1, "u");
            }
        }
    }
}