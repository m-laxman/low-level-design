package com.example.strategydesignpattern.problem;

public class SportUtilityVehicle extends Vehicle{
    @Override
    public void drive() {
        System.out.println(this.getClass().getSimpleName() + " has OffRoad Drive Capability");
    }
}
