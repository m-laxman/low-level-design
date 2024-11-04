/*
    Single responsibility - A class should have only 1 reason to change.

    printInvoice and saveToDatabase are made as different classes.
    Now, if any change happens, it needs to happen in their respective classes
    which are InvoiceDao and InvoicePrinter.
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
    Marker marker;
    int quantity;

public:
    // Invoice(Marker marker, int quantity)
    // {
    //     this->marker = marker;
    //     this->quantity = quantity;
    // }

    Invoice(const Marker &marker, int quantity) : marker(marker), quantity(quantity) {}
    /* This Member Initialization (using the initializer list):
        Directly constructs the member with the provided argument.
        Efficient and avoids creating a temporary default object.*/

    int calculateTotal()
    {
        int price = marker.getPrice() * quantity;
        return price;
    }

    // void printInvoice()
    // {
    //     // print logic
    // }

    // void saveToDatabase()
    // {
    //     // save to database logic
    // }
};

class InvoiceDao
{

private:
    Invoice invoice;

public:
    InvoiceDao(Invoice invoice) : invoice(invoice) {}

    void saveToDatabase()
    {
        // save to database logic
    }
};

class InvoicePrinter
{
private:
    Invoice invoice;

public:
    InvoicePrinter(Invoice invoice) : invoice(invoice) {}

    void printInvoice()
    {
        // print invoice logic
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