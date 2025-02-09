package com.example.strategydesignpattern.problem;

public class SedanVehicle extends Vehicle{
    @Override
    public void drive() {
        System.out.println(this.getClass().getSimpleName() + " has Normal Drive Capability");
    }
}
