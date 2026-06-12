#include <iostream>
#include <string>
using namespace std;

string customerName;
int customerID;
int customerType;
int meterType;

double slabRates[8] =
{
    12.21, 14.53, 31.51, 38.41,
    41.62, 43.04, 44.18, 49.10
};

void registerCustomer()
{
    cout << "\n---------CUSTOMER REGISTRATION----\n";

    cin.ignore();

    cout << "Enter Customar Name: ";
    getline(cin, customerName);

    cout << "Enter Customar ID: ";
    cin >> customerID;

    cout << "1. Household\n";
    cout << "2. Commercial\n";
    cout << "Select Customar Type: ";
    cin >> customerType;

    cout << "1. First Metre\n";
    cout << "2. Second Meter\n";
    cout << "Select Meter Type: ";
    cin >> meterType;
}

void displayMenu()
{
    cout << "\n------LESCO SYSTEM------\n";
    cout << "1. Calculate Monthly Electrcity Bill\n";
    cout << "2. Apply For New Connection\n";
    cout << "3. View Customer Details\n";
    cout << "4. Exit\n";
    cout << "Enter Choice: ";
}

double calculateConsumptionCharges(int units)
{
    if (units <= 100)
        return units * slabRates[0];

    else if (units <= 200)
        return units * slabRates[1];

    else if (units <= 300)
        return units * slabRates[2];

    else if (units <= 400)
        return units * slabRates[3];

    else if (units <= 500)
        return units * slabRates[4];

    else if (units <= 600)
        return units * slabRates[5];

    else if (units <= 700)
        return units * slabRates[6];

    else
        return units * slabRates[7];
}

double calculateGST(double amount)
{
    return amount * 0.18;
}

double calculateIncomeTax(double amount)
{
    if (customerType == 1)
        return amount * 0.10;
    else
        return amount * 0.15;
}

double calculateElectricityDuty(double consumption)
{
    return consumption * 0.015;
}

double calculateFixedCharges(int units)
{
    if (units >= 301 && units <= 400)
        return 200;

    else if (units >= 401 && units <= 500)
        return 400;

    else if (units >= 501 && units <= 600)
        return 600;

    else if (units >= 601 && units <= 700)
        return 800;

    else if (units > 700)
        return 1000;

    return 0;
}
double calculateNewConnectionCharges()
{
    double meterCost = 15000;
    double cableCost = 10000;
    double securityCost = 5000;
    double additionalCharges;

    if(customerType == 1)
    {
        if(meterType == 1)
            additionalCharges = 2500;
        else
            additionalCharges = 5000;
    }
    else
    {
        if(meterType == 1)
            additionalCharges = 35000;
        else
            additionalCharges = 70000;
    }

    return meterCost + cableCost + securityCost +
           additionalCharges + 250000;
}

void displayFinalBill()
{
    int units;

    cout << "Enter Units Consomed: ";
    cin >> units;

    double consumptionCharges =
        calculateConsumptionCharges(units);

    double duty =
        calculateElectricityDuty(consumptionCharges);

    double fixedCharges =
        calculateFixedCharges(units);

    double meterRent = 250;

    double tvFee = 35;

    double subTotal =
        consumptionCharges +
        duty +
        fixedCharges +
        meterRent +
        tvFee;

    double gst = calculateGST(subTotal);

    double incomeTax =
        calculateIncomeTax(subTotal);

    double totalBill =
        subTotal +
        gst +
        incomeTax;

    cout << "\n------LESCO ELECTRICITY BILL-------\n";

    cout << "Customar Name: "
         << customerName << endl;

    cout << "Customer ID: "
         << customerID << endl;

    if(customerType == 1)
        cout << "Customer Type: Household\n";
    else
        cout << "Customer Type: Comercial\n";

    cout << "Units Consumed: "
         << units << endl;

    cout << "Electricity Consumption Charges: Rs. "
         << consumptionCharges << endl;

    cout << "Electricity Duty: Rs. "
         << duty << endl;

    cout << "Fixed Charges: Rs. "
         << fixedCharges << endl;

    cout << "Meter Rent: Rs. "
         << meterRent << endl;

    cout << "TV Fees: Rs. "
         << tvFee << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Incomee Tax: Rs. "
         << incomeTax << endl;

    cout << "Total Payable Bill: Rs. "
         << totalBill << endl;

    
}

void displayCustomerDetails()
{
    cout << "\n------CUSTOMER DETAILS-------\n";

    cout << "Customer Name: "
         << customerName << endl;

    cout << "Customer ID: "
         << customerID << endl;

    if(customerType == 1)
        cout << "Customer Type: Household\n";
    else
        cout << "Customer Type: Commercial\n";

    if(meterType == 1)
        cout << "Meter Type: First Meter\n";
    else
        cout << "Meter Type: Second Meter\n";
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch(choice)
        {
        case 1:
            displayFinalBill();
            break;

        case 2:
            cout << "\nNew Connection Charges: Rs. "
                 << calculateNewConnectionCharges()
                 << endl;
            break;

        case 3:
            displayCustomerDetails();
            break;

        case 4:
            cout << "Program Closed\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    return 0;
}
