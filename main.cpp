#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

string GetUserString(const string& prompt);
double GetUserDouble(const string& prompt);
int GetUserInt(const string& prompt);


int main() {
    string customerName = GetUserString("Enter Customer's Name: ");
    string todayDate = GetUserString("Enter Today's Date: ");

    ShoppingCart userShoppingCart(customerName, todayDate);

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            string itemName = GetUserString("Enter the item name: ");
            string itemDescription = GetUserString("Enter the item description: ");
            double itemPrice = GetUserDouble("Enter the item price: ");
            int itemQuantity = GetUserInt("Enter the item quantity: ");
            ItemToPurchase userItem(itemName, itemDescription, itemPrice, itemQuantity);
            userShoppingCart.AddItem(userItem);
        }
        else if (userMenuChoice == "remove") {
            string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
            userShoppingCart.RemoveItem(nameOfItemToRemove);
        }
        else if (userMenuChoice == "change") {
            string nameOfItemToChange = GetUserString("Enter the item name: ");
            int newItemQuantity = GetUserInt("Enter the new quantity: ");
            userShoppingCart.UpdateQuantity(nameOfItemToChange, newItemQuantity);
        }
        else if (userMenuChoice == "descriptions") {
            if (userShoppingCart.ReturnQuantity() != 0) {
                cout << userShoppingCart.GetName() << "'s Shopping Cart - " << userShoppingCart.GetDate() << endl
                << "Item Descriptions" << endl;
                userShoppingCart.PrintDescription();
            }
            else {
                cout << userShoppingCart.GetName() << "'s Shopping Cart - " << userShoppingCart.GetDate() << endl;
                cout << "Shopping cart is empty." << endl;
            }
        }
        else if (userMenuChoice == "cart") {
            if (userShoppingCart.ReturnQuantity() != 0) {
                cout << userShoppingCart.GetName() << "'s Shopping Cart - " << userShoppingCart.GetDate() << endl
                << "Number of Items: " << userShoppingCart.ReturnQuantity() << endl;
                cout << fixed << setprecision(2);
                userShoppingCart.PrintTotalCost();
            }
            else {
                cout << userShoppingCart.GetName() << "'s Shopping Cart - " << userShoppingCart.GetDate() << endl;
                cout << "Shopping cart is empty." << endl;
            }
        }
        else if (userMenuChoice == "options") {
            cout << "MENU" << endl
                      << "add - Add item to cart" << endl
                      << "remove - Remove item from cart" << endl
                      << "change - Change item quantity" << endl
                      << "descriptions - Print the items' descriptions" << endl
                      << "cart - Print the shopping cart" << endl
                      << "options - Print the options menu" << endl
                      << "quit - Quit" << endl << endl;
        }
        else if (userMenuChoice == "quit") {
            cout << "Goodbye." << endl;
            continueMenuLoop = false;
        }
        else {
            cout << "MENU" << endl
                      << "add - Add item to cart" << endl
                      << "remove - Remove item from cart" << endl
                      << "change - Change item quantity" << endl
                      << "descriptions - Print the items' descriptions" << endl
                      << "cart - Print the shopping cart" << endl
                      << "options - Print the options menu" << endl
                      << "quit - Quit" << endl << endl;
        }
    }

    return 0;
}

string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(std::cin, userAnswer);
    cout << endl;
    return userAnswer;
}
double GetUserDouble(const string& prompt) {
    double userAnswer = 0.0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
int GetUserInt(const string& prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
