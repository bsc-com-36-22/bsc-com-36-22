#include <iostream>
#include <cstdlib> 
#include <ctime>  

int main() {
 
    srand(time(nullptr));

   
    int daysUntilExpiration = rand() % 12;

    std::cout << "Days until expiration: " << daysUntilExpiration << std::endl;

    if (daysUntilExpiration <= 0) {
        std::cout << "Your subscription has already expired." << std::endl;
    } else if (daysUntilExpiration == 1) {
        std::cout << "Your subscription expires tomorrow! Renew now and save 20%!" << std::endl;
    } else if (daysUntilExpiration <= 5) {
        std::cout << "Your subscription expires in " << daysUntilExpiration << " days. Renew now and save 10%!" << std::endl;
    } else if (daysUntilExpiration <= 10) {
        std::cout << "Your subscription will expire in less than 10 days. Renew now!" << std::endl;
    } else {
        std::cout << "You have an active subscription. Enjoy!" << std::endl;
    }

    return 0;
}
