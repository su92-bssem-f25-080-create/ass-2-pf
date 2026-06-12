#include <iostream>
#include <string>
using namespace std;

string customerName;
string contactNumber;
int orderType;
int persons;
//prototype define here
string items[8] =    // array 
{
    "Chicken Burgur",
    "Zinger Burgur",
    "Pizza Small",
    "Pizza Large",
	//functions
//arrays 1d
//arrays 2d
    "Chicken Biriyani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

double prices[8] = // array 2
{
    450,
    550,
    900,
    1800,
    350,
    1200,
    250,
    120
};

double foodBill = 0;

void registerCustomer()
{
    cin.ignore();

    cout << "Enter Customar Name: ";
    getline(cin, customerName);

    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);

    cout << "1. Dine In\n";
    cout << "2. Takeaway\n";
    cout << "Select Order Type: ";
    cin >> orderType;

    cout << "Enter Number Of Persons: ";
    cin >> persons;
}

void displayMenu()
{
    cout << "\n1. View Food Menue\n";
    cout << "2. Place Order\n";
    cout << "3. Calculate Bill\n";
    cout << "4. View Customer Details\n";
    cout << "5. Exit\n";
}

void displayFoodMenu()
{
    for(int i=0;i<8;i++)
    {
        cout << i + 1 << ". "
             << items[i]
             << " Rs." << prices[i]
             << endl;
    }
}

void placeOrder()
{
    int itemNo;
    int quantity;

    char choice;

    do
    {
        displayFoodMenu();

        cout << "Enter Item Number: ";
        cin >> itemNo;

        cout << "Enter Quantity: ";
        cin >> quantity;

        foodBill =
        foodBill +
        (prices[itemNo - 1] * quantity);

        cout << "Add More Items? : ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');
}

double calculateServiceCharges()
{
    if(orderType == 1)
        return foodBill * 0.10;

    return foodBill * 0.05;
}

double calculateGST()
{
    return foodBill * 0.16;
}

double calculateDiscount()
{
    if(foodBill >= 3000 && foodBill <= 5000)
        return foodBill * 0.05;

    if(foodBill > 5000 && foodBill <= 10000)
        return foodBill * 0.10;

    if(foodBill > 10000)
        return foodBill * 0.15;

    return 0;
}
double calculateTotalBill()
{
    double serviceCharges = calculateServiceCharges();
    double gst = calculateGST();
    double discount = calculateDiscount();

    double total = foodBill + serviceCharges + gst - discount;

    return total;
}

void viewCustomerDetails()
{
    cout << "Customar Name: " << customerName << endl;
    cout << "Contactt Number: " << contactNumber << endl;

    if(orderType == 1)
        cout << "Order Type: Dine In" << endl;
    else
        cout << "Order Type: Takeaway" << endl;

    cout << "Number of Persons: " << persons << endl;
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            displayFoodMenu();
        }
        else if(choice == 2)
        {
            placeOrder();
        }
        else if(choice == 3)
        {
            cout << "Food Bill: " << foodBill << endl;
            cout << "Service Charges: " << calculateServiceCharges() << endl;
            cout << "GST: " << calculateGST() << endl;
            cout << "Discount: " << calculateDiscount() << endl;
            cout << "Total Bill: " << calculateTotalBill() << endl;
        }
        else if(choice == 4)
        {
            viewCustomerDetails();
        }
        else if(choice == 5)
        {
            cout << "Exiting Program" << endl;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }

    } while(choice != 5);

    return 0;
}
