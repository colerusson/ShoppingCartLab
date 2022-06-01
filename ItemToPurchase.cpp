#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string userName, string userDescription, double userPrice, int userQuantity) {
    itemName = userName;
    itemDescription = userDescription;
    itemPrice = userPrice;
    itemQuantity = userQuantity;
}

void ItemToPurchase::SetName(string userName) {
    itemName = userName;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

void ItemToPurchase::SetPrice(double userPrice) {
    itemPrice = userPrice;
}

double ItemToPurchase::GetPrice() const {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int userQuantity) {
    itemQuantity = userQuantity;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string userDescription) {
    itemDescription = userDescription;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

void ItemToPurchase::PrintCost() const {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintDescription() const {
    cout << itemName << ": " << itemDescription << endl;
}
