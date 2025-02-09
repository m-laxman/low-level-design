package com.example.strategydesignpattern.problem;

/*
    Strategy pattern
    When a parent has multiple children and the functionality
    of few children is same but not present in parent class, in
    such a case we need to define an interface that would
    implement the functionality of the child classes.

    It deals with is-a relationship.

    Vehicle is the parent class that has child classes like SportUtilityVehicle
    that has OffRoadDrive capability, another child class SedanVehicle that has
    NormalDrive capability. We cannot include the drive capability in parent
    class because it will not allow us to scale properly for different types of
    vehicles. Also, we cannot hardcode functionality in the child classes, as it
    would cause code duplicacy when a new child class wants to use the same drive
    capability.

    Please check solution package for the implementation of the strategy design pattern
 */
public class Vehicle {
    public void drive() {
        System.out.println("Normal Capability Driving");
    }
}
