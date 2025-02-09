package com.example.strategydesignpattern.solution;

import com.example.strategydesignpattern.solution.strategy.DriveStrategy;

/*
    Strategy pattern
    When a parent has multiple children and the functionality
    of few children is same but not present in parent class, in
    such a case we need to define an interface that would
    implement the functionality of the child classes.

    It deals with is-a relationship.

    Under strategy package, we have defined an interface called DriveStrategy which
    has drive method that is implemented by NormalDriveStrategy and OffRoadDriveStrategy
    classes which have their own implementation. This makes our code scalable and in
    future if new strategy is developed, it could be implemented as a separate class.
*/
public class Vehicle {

    DriveStrategy driveType;

    Vehicle(DriveStrategy driveTypeObj) {
        this.driveType = driveTypeObj;
    }
    public void drive() {
        driveType.drive();
    }
}
