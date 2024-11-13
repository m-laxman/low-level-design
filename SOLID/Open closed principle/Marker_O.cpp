/*
    Open Closed principle - A class should be open for extension but closed for modifition
    
    Based on open closed principle implement an interface called InvoiceDao that would
    have methods DatabaseInvoiceDao & FileInvoiceDao.
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
    Marker() {}

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
    Invoice() {}

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

    virtual void save(Invoice& invoice) = 0; // Pure virtual function
    // virtual ~InvoiceDao() = default;

    /*
    InvoiceDao(Invoice invoice) : invoice(invoice) {}

    void saveToDatabase()
    {
        // save to database logic
    }

    /* cannot have the method saveToFile since class is already tested & live, 
    instead create InvoiceDao interface & add new classes FileInvoiceDao & 
    DatabaseInvoiceDao
    void saveToFile() 
    {
        // save to database logic
    }
    */
};

class DatabaseInvoiceDao : public InvoiceDao {
public:
    void save(Invoice& invoice) override {
        // Logic to save the invoice to the database
        cout << "Saving invoice to database." << endl;
    }
};

class FileInvoiceDao : public InvoiceDao {
public:
    void save(Invoice& invoice) override {
        // Logic to save the invoice to a file
        cout << "Saving invoice to file." << endl;
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

    InvoiceDao *databaseDao = new DatabaseInvoiceDao();
    databaseDao->save(invoice);  // Output: Saving invoice to database.

    InvoiceDao *fileDao = new FileInvoiceDao();
    fileDao->save(invoice);  // Output: Saving invoice to file.

    return 0;
}