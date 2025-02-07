/*
    Liskov Substitution principle - The program should support multiple children
    objects of the parents i.e when you substiture child of parent, the program
    should not break.

    Parent p1 = new Child1()
    It should work even when Child1 is replaced with Child2

    We have made a separate class for non-generic functionality which is hasEngine
    method, it is converted to a class called EngineVehicle and it is extended by vehicles
    that have engine i.e Car and Motorcycle.
*/

#include <bits/stdc++.h>
using namespace std;

class Vehicle
{

public:
    virtual int getNumberofWheels() // Include only generic methods in parent class
    {
        return 2;
    }
};

class EngineVehicle : public Vehicle // Separate class for hasEngine method
{
public:
    bool hasEngine()
    {
        return true;
    }
};

class Car : public EngineVehicle
{
public:
    int getNumberofWheels()
    {
        return 4;
    }
};

class Motorcycle : public EngineVehicle
{
};

class Bicycle : public Vehicle
{
};

int main()
{
    Vehicle *v1 = new Car();
    Vehicle *v2 = new Motorcycle();
    Vehicle *v3 = new Bicycle();

    cout << v1->getNumberofWheels() << "\n";
    cout << v2->getNumberofWheels() << "\n";
    cout << v3->getNumberofWheels() << "\n";

    delete v1, v2, v3;
}