package com.example.strategydesignpattern.solution.strategy;

public class OffRoadDriveStrategy implements DriveStrategy{

    @Override
    public void drive() {
            System.out.println(this.getClass().getSimpleName() + " has OffRoad Drive Capability");
    }
}
