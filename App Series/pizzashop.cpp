/*****************************************
 * THIS FILE CONTAINS A SIMPLE CONSOLE BASED APPLICATION IN C++
 * pizzashop
 *****************************************/
#include <iostream>
#include <iomanip>  // make doubles 2 decimal places
#include <vector> 
#include <string>

int main(){
    std::cout << std::endl;
    // App variables
    double cardBalance {0.00};
    int inputChoice;
    bool exitloop {false};
    double totalamt {0};
    std::vector<std::string> orderVector;
    std::vector<double> orderPriceVector;

    for(;;){
        // MAIN MENU
        std::cout << "**************************************************" << std::endl;
        std::cout << "WELCOME TO THE CPP PIZZASHOP APP!" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "1. Order Pizza" << std::endl;
        std::cout << "2. Order Pasta" << std::endl;
        std::cout << "3. Check Orders" << std::endl;
        std::cout << "4. Top up card" << std::endl;
        std::cout << "5. Check card balance" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter no: ";
        std::cin >> inputChoice;

        // SELECTOR BRANCHES
        switch (inputChoice){   // switch for main menu
            case 1:
                while(exitloop==false){
                    std::cout << "**************************************************" << std::endl;
                    std::cout << "YOUR CARD BALANCE IS: " << std::endl;
                    std::cout << '$' << std::fixed << std::setprecision(2) << cardBalance << std::endl;
                    std::cout << "What Pizza do you wanna buy?" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "1. $10 - Hawaiian Pizza" << std::endl;
                    std::cout << "2. $15 - BBQ Chicken Pizza" << std::endl;
                    std::cout << "3. $18 - Cheesy Pepperoni Pizza" << std::endl;
                    std::cout << "4. $20 - Hazelnut Pizza" << std::endl;
                    std::cout << "5. $50 - Best Pizza Ever" << std::endl;
                    std::cout << "6. Back" << std::endl;
                    std::cout << "7. Quit" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "Enter no: ";
                    std::cin >> inputChoice;
                    switch (inputChoice){   // switch for top up card
                        case 1:
                            if(cardBalance>=10){
                                cardBalance -= 10;
                                std::cout << "Hawaiian Pizza bought successfully" << std::endl;
                                orderVector.push_back("Hawaiian Pizza");
                                orderPriceVector.push_back(10);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 2:
                            if(cardBalance>=15){
                                cardBalance -= 15;
                                std::cout << "BBQ Chicken Pizza bought successfully" << std::endl;
                                orderVector.push_back("BBQ Chicken Pizza");
                                orderPriceVector.push_back(15);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 3:
                            if(cardBalance>=18){
                                cardBalance -= 18;
                                std::cout << "Cheesy Pepperoni Pizza bought successfully" << std::endl;
                                orderVector.push_back("Cheesy Pepperoni Pizza");
                                orderPriceVector.push_back(18);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 4:
                            if(cardBalance>=20){
                                cardBalance -= 20;
                                std::cout << "Hazelnut Pizza bought successfully" << std::endl;
                                orderVector.push_back("Hazelnut Pizza");
                                orderPriceVector.push_back(20);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            break;
                        case 5:
                            if(cardBalance>=50){
                                cardBalance -= 50;
                                std::cout << "Best Pizza Ever bought successfully" << std::endl;
                                orderVector.push_back("Best Pizza Ever");
                                orderPriceVector.push_back(50);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            break;
                        case 6:
                            exitloop = true;
                            break;
                        case 7:
                            std::cout << "Pizzashop exited" << std::endl;
                            return 0;
                        default:
                            std::cout << "Error: Invalid inputs detected" << std::endl;
                            return 0;
                        }
                }
                exitloop = false;
                break;
            case 2:
                while(exitloop==false){
                    std::cout << "**************************************************" << std::endl;
                    std::cout << "YOUR CARD BALANCE IS: " << std::endl;
                    std::cout << '$' << std::fixed << std::setprecision(2) << cardBalance << std::endl;
                    std::cout << "What Pasta do you wanna buy?" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "1. $5 - Bolognese Spagetti" << std::endl;
                    std::cout << "2. $8 - Creamy Chicken Penne" << std::endl;
                    std::cout << "3. $10 - Alfredo Linguini" << std::endl;
                    std::cout << "4. $15 - Basil Prawn Fuccini" << std::endl;
                    std::cout << "5. $25 - Duck blood Maccaroni" << std::endl;
                    std::cout << "6. Back" << std::endl;
                    std::cout << "7. Quit" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "Enter no: ";
                    std::cin >> inputChoice;
                    switch (inputChoice){   // switch for top up card
                        case 1:
                            if(cardBalance>=5){
                                cardBalance -= 5;
                                std::cout << "Bolognese Spagetti bought successfully" << std::endl;
                                orderVector.push_back("Bolognese Spagetti");
                                orderPriceVector.push_back(5);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 2:
                            if(cardBalance>=8){
                                cardBalance -= 8;
                                std::cout << "Creamy Chicken Penne bought successfully" << std::endl;
                                orderVector.push_back("Creamy Chicken Penne");
                                orderPriceVector.push_back(8);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 3:
                            if(cardBalance>=10){
                                cardBalance -= 10;
                                std::cout << "Alfredo Linguini bought successfully" << std::endl;
                                orderVector.push_back("Alfredo Linguini");
                                orderPriceVector.push_back(10);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            
                            break;
                        case 4:
                            if(cardBalance>=15){
                                cardBalance -= 15;
                                std::cout << "Basil Prawn Fuccini bought successfully" << std::endl;
                                orderVector.push_back("Basil Prawn Fuccini");
                                orderPriceVector.push_back(15);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            break;
                        case 5:
                            if(cardBalance>=25){
                                cardBalance -= 25;
                                std::cout << "Duck Blood Maccaroni bought successfully" << std::endl;
                                orderVector.push_back("Duck Blood Maccaroni");
                                orderPriceVector.push_back(25);
                            }else{
                                std::cout << "Not enough mulah" << std::endl;
                            }
                            break;
                        case 6:
                            exitloop = true;
                            break;
                        case 7:
                            std::cout << "Pizzashop exited" << std::endl;
                            return 0;
                        default:
                            std::cout << "Error: Invalid inputs detected" << std::endl;
                            return 0;
                        }
                }
                exitloop = false;
                break;
            case 3:
                std::cout << "**************************************************" << std::endl;
                std::cout << "YOUR ORDERS ARE: " << std::endl;
                for(int i = 0; i < orderVector.size(); ++i){
                    std::cout << orderVector[i] << " " << orderPriceVector[i] << std::endl;
                }
                std::cout << "Total spent: " << std::endl;
                for(auto op: orderPriceVector){
                    totalamt += op;
                }
                std::cout << std::fixed << std::setprecision(2) << totalamt << std::endl;
                std::cout << "What would you like to do?" << std::endl;
                std::cout << "--------------------------------------------------" << std::endl;
                std::cout << "1. Back" << std::endl;
                std::cout << "2. Quit" << std::endl;
                std::cout << "--------------------------------------------------" << std::endl;
                std::cout << "Enter no: ";
                std::cin >> inputChoice;
                switch (inputChoice){   // switch for check card balance
                    case 1:
                        break;
                    case 2:
                        std::cout << "Pizzashop exited" << std::endl;
                        return 0;
                    default:
                        std::cout << "Error: Invalid inputs detected" << std::endl;
                        return 0;
                    }
                break;
            case 4:
                while(exitloop==false){
                    std::cout << "**************************************************" << std::endl;
                    std::cout << "YOUR CARD BALANCE IS: " << std::endl;
                    std::cout << '$' << std::fixed << std::setprecision(2) << cardBalance << std::endl;
                    std::cout << "How much to top up?" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "1. $1" << std::endl;
                    std::cout << "2. $2" << std::endl;
                    std::cout << "3. $5" << std::endl;
                    std::cout << "4. $10" << std::endl;
                    std::cout << "5. $50" << std::endl;
                    std::cout << "6. Back" << std::endl;
                    std::cout << "7. Quit" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    std::cout << "Enter no: ";
                    std::cin >> inputChoice;
                    switch (inputChoice){   // switch for top up card
                        case 1:
                            cardBalance += 1;
                            std::cout << "Card Topped Up" << std::endl;
                            break;
                        case 2:
                            cardBalance += 2;
                            std::cout << "Card Topped Up" << std::endl;
                            break;
                        case 3:
                            cardBalance += 5;
                            std::cout << "Card Topped Up" << std::endl;
                            break;
                        case 4:
                            cardBalance += 10;
                            std::cout << "Card Topped Up" << std::endl;
                            break;
                        case 5:
                            cardBalance += 50;
                            std::cout << "Card Topped Up" << std::endl;
                            break;
                        case 6:
                            exitloop = true;
                            break;
                        case 7:
                            std::cout << "Pizzashop exited" << std::endl;
                            return 0;
                        default:
                            std::cout << "Error: Invalid inputs detected" << std::endl;
                            return 0;
                        }
                }
                exitloop = false;
                break;
            case 5:
                std::cout << "**************************************************" << std::endl;
                std::cout << "YOUR CARD BALANCE IS: " << std::endl;
                std::cout << '$' << std::fixed << std::setprecision(2) << cardBalance << std::endl;
                std::cout << "What would you like to do?" << std::endl;
                std::cout << "--------------------------------------------------" << std::endl;
                std::cout << "1. Back" << std::endl;
                std::cout << "2. Quit" << std::endl;
                std::cout << "--------------------------------------------------" << std::endl;
                std::cout << "Enter no: ";
                std::cin >> inputChoice;
                switch (inputChoice){   // switch for check card balance
                    case 1:
                        break;
                    case 2:
                        std::cout << "Pizzashop exited" << std::endl;
                        return 0;
                    default:
                        std::cout << "Error: Invalid inputs detected" << std::endl;
                        return 0;
                    }
                break;
            case 6:
                std::cout << "Pizza Shop exited" << std::endl;
                return 0;
            default:
                std::cout << "Error: Invalid inputs detected" << std::endl;
                return 0;
        }
    };
    
    std::cout << "Pizzashop exited" << std::endl;
    return 0;
}