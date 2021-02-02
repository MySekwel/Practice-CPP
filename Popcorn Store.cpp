// Popcorn Program

#include <iostream>
#include <vector>
int
    customer,
    orders;

char newCustomer;

std::vector<int> order_size;
std::vector<int> order_flavor;
std::vector<int> customer_total;

#define PRICE_SMALL         50.0
#define PRICE_MEDIUM        75.0
#define PRICE_LARGE         100.0
#define PRICE_EXTRALARGE    120.0

#define PRICE_CHEESE        10.0
#define PRICE_BBQ           10.0
#define PRICE_SOURCREAM     10.0
#define PRICE_NONE          0.0

int main(){

    while (true){
        customer++;
        customer_total.push_back(customer);
        customer_total[customer] = 0;

        std::cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O\n";
        std::cout<<"|\t\tPOP-CORN STORE\t\t|\n";
        std::cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O\n";

        std::cout<<"Size:\t\t\tPrice\n";
        std::cout<<"1 - Small\t\t"          <<PRICE_SMALL      <<std::endl;
        std::cout<<"2 - Medium\t\t"         <<PRICE_MEDIUM     <<std::endl;
        std::cout<<"3 - Large\t\t"          <<PRICE_LARGE      <<std::endl;
        std::cout<<"4 - Extra Large\t\t"    <<PRICE_EXTRALARGE <<std::endl;

        std::cout<<"Flavor:\n";
        std::cout<<"1 - Cheese\t\t"         <<PRICE_CHEESE     <<std::endl;
        std::cout<<"2 - Barbecue\t\t"       <<PRICE_BBQ        <<std::endl;
        std::cout<<"3 - Sour and Cream\t" <<PRICE_SOURCREAM  <<std::endl;
        std::cout<<"4 - None\t\t"           <<PRICE_NONE       <<std::endl;

        std::cout<<"HOW MANY ORDERS? "; std::cin>>orders;
        order_size.push_back(orders);
        order_flavor.push_back(orders);

        for(int i=0; i < orders; i++){
            std::cout<<"Order#"<<i+1<<":\n";
            std::cout<<"\t\tSize: "; std::cin>>order_size[i];
            std::cout<<"\t\tFlavor: "; std::cin>>order_flavor[i];
            if(order_size[i] == 1){
                customer_total[customer] += PRICE_SMALL+10;
            }
            else if(order_size[i] == 2){
                customer_total[customer] += PRICE_MEDIUM+10;
            }
            else if(order_size[i] == 3){
                customer_total[customer] += PRICE_LARGE+10;
            }
            else if(order_size[i] == 4){
                customer_total[customer] += PRICE_EXTRALARGE+10;
            }
        }
        std::cout<<"TOTAL AMOUNT FOR CUSTOMER#"<<customer<<": "<<customer_total[customer]<<std::endl;
        std::cout<<"----------------------------\n";
        std::cout<<"NEW CUSTOMER? "; std::cin>>newCustomer;
        system("cls");
        if(newCustomer == 'Y' || newCustomer == 'y'){
            continue;
        }
        else{
            break;
        }
    }

    system("pause");
    return 0;
}
