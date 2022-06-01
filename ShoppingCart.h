#ifndef CHAPTER7PROJECT_SHOPPINGCART_H
#define CHAPTER7PROJECT_SHOPPINGCART_H
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;


class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string userCustomerName, string userDateCreated);
    string GetName() const;
    string GetDate() const;
    void AddItem(ItemToPurchase newUserItem);
    void RemoveItem(string itemName);
    void UpdateQuantity(string itemName, int newQuantity);
    int ReturnQuantity() const;
    double ReturnCost() const;
    void PrintDescription() const;
    void PrintTotalCost() const;

private:
    string customerName;
    string dateCreated;
    vector<ItemToPurchase> itemList;
};


#endif
