#include <iostream>
using namespace std;

string name, id, type, payment;
string items[8] = {"Rice", "Sugar", "Oil", "Milk", "Tea", "Flour", "Eggs", "Detergent"};
double prices[8] = {350, 180, 580, 220, 450, 950, 320, 600};

double bill = 0;

void registerCustomer()
{
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);

    cout << "ID: ";
    getline(cin, id);

    cout << "Type (Regular/Member): ";
    getline(cin, type);

    cout << "Payment (Cash/Card): ";
    getline(cin, payment);
}

void showItems()
{
    for (int i = 0; i < 8; i++)
        cout << i + 1 << ". " << items[i] << " - " << prices[i] << endl;
}

void addItems()
{
    int item, qty;

    cout << "Item No: ";
    cin >> item;

    cout << "Quantity: ";
    cin >> qty;

    bill += prices[item - 1] * qty;
}

void calculateBill()
{
    double tax = bill * 0.05;

    if (bill > 0 && bill >= prices[7])
        tax += 600 * 0.05;

    double memberDiscount = 0;

    if (type == "Member")
        memberDiscount = bill * 0.07;

    double billDiscount = 0;

    if (bill >= 5000 && bill <= 10000)
        billDiscount = bill * 0.05;
    else if (bill > 10000)
        billDiscount = bill * 0.10;

    double total = bill + tax - memberDiscount - billDiscount;

    if (payment == "Card")
        total += total * 0.02;

    int currentPoints = total / 100;
    int oldPoints;

    cout << "Existing Loyalty Points: ";
    cin >> oldPoints;

    int totalPoints = currentPoints + oldPoints;

    int choice;
    cout << "1 Redeem  2 Continue: ";
    cin >> choice;

    if (choice == 1)
        total -= totalPoints;

    cout << "Total Bill: " << total << endl;
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n1.View Items\n2.Add Item\n3.Calculate Bill\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showItems();
            break;

        case 2:
            addItems();
            break;

        case 3:
            calculateBill();
            break;
        }

    } while (choice != 4);

    return 0;
}
