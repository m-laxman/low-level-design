/*
    Liskov Substitution principle - The program should support multiple children
    objects of the parents i.e when you substiture child of parent, the program
    should not break.

    Parent p1 = new Child1()
    It should work even when Child1 is replaced with Child2

    Vehicle class here is extended by Car, motorcycle and bicycle.
    The Bicycle class breaks the Liskov principle primarily because it does not
    have an engine.

    Please check Marker_S.cpp for the Single Responsibility Principle.
*/

#include <bits/stdc++.h>
using namespace std;

class Vehicle
{

public:
    virtual int getNumberofWheels()
    {
        return 2;
    }

    virtual bool hasEngine()
    {
        return true;
    }
};

class Car : public Vehicle
{
public:
    int getNumberofWheels()
    {
        return 4;
    }
};

class Motorcycle : public Vehicle
{
};

class Bicycle : public Vehicle
{
public:
    bool hasEngine()
    {
        return false;
    }
};

int main()
{
    Vehicle *v1 = new Car();
    Vehicle *v2 = new Motorcycle();
    Vehicle *v3 = new Bicycle(); // Violates Liskov because Bicycle does NOT have an engine

    cout << v1->hasEngine() << "\n";
    cout << v2->hasEngine() << "\n";
    cout << v3->hasEngine() << "\n";
}