#ifndef CHAPTER7LAB_ITEMTOPURCHASE_H
#define CHAPTER7LAB_ITEMTOPURCHASE_H
#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string userName, string userDescription, double userPrice, int userQuantity);
    void SetName(string userName);
    string GetName() const;
    void SetPrice(double userPrice);
    double GetPrice() const;
    void SetQuantity(int userQuantity);
    int GetQuantity() const;
    void SetDescription(string userDescription);
    string GetDescription() const;
    void PrintCost() const;
    void PrintDescription() const;

private:
    string itemName;
    double itemPrice;
    int itemQuantity;
    string itemDescription;
};


#endif
