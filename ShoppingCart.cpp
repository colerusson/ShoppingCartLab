#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart() {
    customerName = "none";
    dateCreated = "January 1, 1970";
}

ShoppingCart::ShoppingCart(string userCustomerName, string userDateCreated) {
    customerName = userCustomerName;
    dateCreated = userDateCreated;
}

string ShoppingCart::GetName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return dateCreated;
}

void ShoppingCart::AddItem(ItemToPurchase newUserItem) {
    bool containsName = false;
    for (int i = 0; i < itemList.size(); ++i) {
        if (newUserItem.GetName() == itemList.at(i).GetName()) {
            containsName = true;
        }
    }
    if (containsName == true) {
        cout << "Item is already found in the cart. It will not be added." << endl;
    }
    else {
        itemList.push_back(newUserItem);
    }
}

void ShoppingCart::RemoveItem(string itemName) {
    bool itemInCart = false;
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemName == itemList.at(i).GetName()) {
            itemInCart = true;
        }
    }
    if (itemInCart == true) {
        for (int i = 0; i < itemList.size(); ++i) {
            if (itemName == itemList.at(i).GetName()) {
                itemList.erase(itemList.begin() + i);
            }
        }
    }
    else {
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}

void ShoppingCart::UpdateQuantity(string itemName, int newQuantity) {
    bool itemInCart = false;
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemName == itemList.at(i).GetName()) {
            itemInCart = true;
        }
    }
    if (itemInCart == true) {
        for (int i = 0; i < itemList.size(); ++i) {
            if (itemName == itemList.at(i).GetName()) {
                itemList.at(i).SetQuantity(newQuantity);
            }
        }
    }
    else {
        cout << "Item not found in cart. It will not be modified." << endl;
    }
}

int ShoppingCart::ReturnQuantity() const {
    int totalQuantity = 0;
    for (int i = 0; i < itemList.size(); ++i) {
        totalQuantity += itemList.at(i).GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::ReturnCost() const {
    double totalCost = 0.0;
    for (int i = 0; i < itemList.size(); ++i) {
        totalCost += (itemList.at(i).GetPrice() * itemList.at(i).GetQuantity());
    }
    return totalCost;
}

void ShoppingCart::PrintDescription() const {
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.empty()) {
            cout << "Shopping cart is empty." << endl;
        }
        else {
            itemList.at(i).PrintDescription();
        }
    }
}

void ShoppingCart::PrintTotalCost() const {
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.empty()) {
            cout << "Shopping cart is empty." << endl;
        }
        else {
            itemList.at(i).PrintCost();
        }
    }
    cout << "Total: $" << ReturnCost() << endl;
}
