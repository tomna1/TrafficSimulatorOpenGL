#ifndef CAR___H
#define CAR___H

#include <stdbool.h>;

typedef struct Car {
	// 8 xy positions for the 4 corners of a car. A car is represented as a 
	// rectangle.
	float position[8];
	// The length of a car
	float length;
	// The width of the car
	float width;
	// The maximum speed that the car can go.
	int maxSpeed;
	// The current speed that the car is going
	float currentSpeed;
	// the acceleration force of the car
	float acceleration;
	// The braking force of the car
	float brakingForce;
	// if the car is braking or not
	bool isBraking;
	// The colour of the car
	char colour[15];

} Car;


void BrakeCar();

void StopBraking();

// Accelerates to the speed defined. Will not go faster than the top speed
// of the car
void GoToSpeed(int speed);

#endif
