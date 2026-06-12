#include <iostream>
using namespace std;

string clientName, businessName, businessType;
int days;

string platforms[3] = {"Instagram", "Facebook", "LinkedIn"};
double charges[3] = {15000, 12000, 20000};

int selected = 0;

void registerClient()
{
    cin.ignore();

    cout << "Client Name: ";
    getline(cin, clientName);

    cout << "Business Name: ";
    getline(cin, businessName);

    cout << "Business Type (Small/Medium/Corporate): ";
    getline(cin, businessType);

    cout << "Campaign Days: ";
    cin >> days;
}

void showPlatforms()
{
    for (int i = 0; i < 3; i++)
        cout << i + 1 << ". " << platforms[i] << " - " << charges[i] << endl;
}

void selectPlatform()
{
    cout << "Select Platform: ";
    cin >> selected;

    selected--;
}

void calculateCost()
{
    int staticPosts, reels, carousel;

    cout << "Static Posts: ";
    cin >> staticPosts;

    cout << "Reel Posts: ";
    cin >> reels;

    cout << "Carousel Posts: ";
    cin >> carousel;

    double designCost = staticPosts * 1000 +
                        reels * 2500 +
                        carousel * 1800;

    double adBudget;

    cout << "Ad Budget: ";
    cin >> adBudget;

    double handlingFee;

    if (adBudget < 50000)
        handlingFee = adBudget * 0.05;
    else if (adBudget <= 100000)
        handlingFee = adBudget * 0.08;
    else
        handlingFee = adBudget * 0.10;

    double extra = 0;

    if (days > 30)
        extra = (days - 30) * 500;

    double total = charges[selected] + designCost + adBudget + handlingFee + extra;

    double gst = total * 0.16;

    double discount = 0;

    if (businessType == "Small")
        discount = total * 0.05;
    else if (businessType == "Medium")
        discount = total * 0.08;
    else
        discount = total * 0.10;

    double finalCost = total + gst - discount;

    cout << "Final Campaign Cost: " << finalCost << endl;
}

int main()
{
    registerClient();

    int choice;

    do
    {
        cout << "\n1.View Platforms\n2.Select Platform\n3.Calculate Cost\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showPlatforms();
            break;

        case 2:
            selectPlatform();
            break;

        case 3:
            calculateCost();
            break;
        }

    } while (choice != 4);

    return 0;
}
