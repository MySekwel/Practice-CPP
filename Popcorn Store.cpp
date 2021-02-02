// Popcorn Program

#include <iostream>
#include <vector>
int
    orders;

std::vector<int> order_size;
std::vector<int> order_flavor;

int main(){
    while (true)
    {
        std::cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O\n";
        std::cout<<"|\t\tPOP-CORN STORE\t\t|\n";
        std::cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O\n";

        std::cout<<"Size:\t\t\tPrice\n";
        std::cout<<"1 - Small\t\t50.00\n";
        std::cout<<"2 - Medium\t\t70.00\n";
        std::cout<<"3 - Large\t\t100.00\n";
        std::cout<<"4 - Extra Large\t\t120.00\n";

        std::cout<<"Flavor:\n";
        std::cout<<"1 - Cheese\t\t10.00\n";
        std::cout<<"2 - Barbecue\t\t10.00\n";
        std::cout<<"3 - Sour and Cream\t10.00\n";
        std::cout<<"4 - NONE\t\t0.00\n";

        std::cout<<"HOW MANY ORDERS? "; std::cin>>orders;
        order_size.push_back(orders);
        order_flavor.push_back(orders);

        for(int i=0; i < orders; i++){
            std::cout<<"Order#"<<i+1<<":\n";
            std::cout<<"\t\tSize: "; std::cin>>order_size[i];
            std::cout<<"\t\tFlavor: "; std::cin>>order_flavor[i];
            std::cout<<order_size[i]<<std::endl;
            std::cout<<order_flavor[i]<<std::endl; 
        }

        break;
    }

    system("pause");
    return 0;
}
