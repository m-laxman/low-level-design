package com.example.strategydesignpattern.solution;

import com.example.strategydesignpattern.solution.strategy.NormalDriveStrategy;

public class SedanVehicle extends Vehicle {

    public SedanVehicle() {
        super(new NormalDriveStrategy());
    }

}
