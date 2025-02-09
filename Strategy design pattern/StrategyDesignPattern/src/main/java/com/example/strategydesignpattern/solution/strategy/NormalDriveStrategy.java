package com.example.strategydesignpattern.solution.strategy;

public class NormalDriveStrategy implements DriveStrategy{
    @Override
    public void drive() {
        System.out.println(this.getClass().getSimpleName() + " has Normal Drive Capability");
    }
}
