#include <iostream>
using namespace std;

string name, email, city, type;

string products[8] = {"T-Shirt", "Jeans", "Shoes", "Watch", "Handbag", "Headphones", "Mobile Cover", "Perfume"};
double prices[8] = {1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

double total = 0;

void registerUser()
{
    cin.ignore();

    cout << "Name: ";
    getline(cin, name);

    cout << "Email: ";
    getline(cin, email);

    cout << "City: ";
    getline(cin, city);

    cout << "Type (New/Returning): ";
    getline(cin, type);
}

void showProducts()
{
    for (int i = 0; i < 8; i++)
        cout << i + 1 << ". " << products[i] << " - " << prices[i] << endl;
}

void addProduct()
{
    int item, qty;

    cout << "Product No: ";
    cin >> item;

    cout << "Quantity: ";
    cin >> qty;

    total += prices[item - 1] * qty;
}

void checkout()
{
    double gst = total * 0.17;

    double delivery;

    if (city == "Lahore" || city == "Karachi" || city == "Islamabad")
        delivery = 250;
    else
        delivery = 500;

    double customerDiscount;

    if (type == "Returning")
        customerDiscount = total * 0.10;
    else
        customerDiscount = total * 0.05;

    double orderDiscount = 0;

    if (total >= 5000 && total <= 10000)
        orderDiscount = total * 0.05;
    else if (total > 10000)
        orderDiscount = total * 0.12;

    double finalBill = total + gst + delivery - customerDiscount - orderDiscount;

    int payment;

    cout << "1.COD  2.Card : ";
    cin >> payment;

    if (payment == 2)
        finalBill += finalBill * 0.025;

    cout << "Final Bill: " << finalBill << endl;
}

int main()
{
    registerUser();

    int choice;

    do
    {
        cout << "\n1.View Products\n2.Add Product\n3.Checkout\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showProducts();
            break;

        case 2:
            addProduct();
            break;

        case 3:
            checkout();
            break;
        }

    } while (choice != 4);

    return 0;
}
