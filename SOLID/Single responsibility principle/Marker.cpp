/*
    Single responsibility - A class should have only 1 reason to change.

    This Marker class does not follow the Single Responsibility Principle because
    if a new member called tax/discount is included then calculateTotal logic would need to
    be changed, also if printInvoice method could require change if tax needs to be included
    in the invoice and similarly saveToDatabase would require a change if the invoice
    requires to be saved to a file rather than a database.

    So, there are 3 reasons to change a class instead of 1, which violates the single responsibility
    principle.

    Please check Marker_S.cpp for the Single Responsibility Principle.
*/
#include <iostream>
using namespace std;

class Marker
{

private:
    string brand;
    string color;
    int price;
    int year;

public:
    // Marker() {}

    Marker(string brand, string color, int price, int year)
    {
        this->brand = brand;
        this->color = color;
        this->price = price;
        this->year = year;
    }

    // Getter methods for private members
    string getColor()
    {
        return color;
    }

    string getBrand()
    {
        return brand;
    }

    int getPrice()
    {
        return price;
    }

    int getYear()
    {
        return year;
    }
};

class Invoice
{
private:
    Marker marker; //Invoice has a Marker
    int quantity;

public:
    // Invoice(Marker marker, int quantity)
    // {
    //     this->marker = marker;
    //     this->quantity = quantity;
    // }

    Invoice(Marker marker, int quantity) : marker(marker), quantity(quantity) {}
    /* This Member Initialization (using the initializer list):
        Directly constructs the member with the provided argument.
        Efficient and avoids creating a temporary default object.*/

    int calculateTotal()
    {
        int price = marker.getPrice() * quantity;
        return price;
    }

    void printInvoice()
    {
        // print logic
    }

    void saveToDatabase()
    {
        // save to database logic
    }
};

int main()
{
    Marker m1("Camlin", "Red", 10, 2024);

    cout << "Marker Details: " << endl;
    cout << "Color: " << m1.getColor() << endl;
    cout << "Brand: " << m1.getBrand() << endl;
    cout << "Price: " << m1.getPrice() << endl;
    cout << "Year: " << m1.getYear() << endl;

    Invoice invoice(m1, 5);
    cout << "Total Price: " << invoice.calculateTotal() << endl;

    return 0;
}
