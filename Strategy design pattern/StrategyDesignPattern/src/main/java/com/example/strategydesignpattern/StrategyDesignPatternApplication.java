package com.example.strategydesignpattern;

//import com.example.strategydesignpattern.problem.SedanVehicle;
//import com.example.strategydesignpattern.problem.Vehicle;
import com.example.strategydesignpattern.solution.SedanVehicle;
import com.example.strategydesignpattern.solution.Vehicle;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class StrategyDesignPatternApplication {

	public static void main(String[] args) {

		SpringApplication.run(StrategyDesignPatternApplication.class, args);
		Vehicle v = new SedanVehicle();
		v.drive();
	}

}
