package com.example.strategydesignpattern.solution;

import com.example.strategydesignpattern.solution.strategy.OffRoadDriveStrategy;

public class SportUtilityVehicle extends Vehicle {
    public SportUtilityVehicle() {
        super(new OffRoadDriveStrategy());
    }
}
