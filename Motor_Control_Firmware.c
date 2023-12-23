```c
#include <stdio.h>
#include <stdlib.h>

// Assuming we're using a microcontroller with built-in PWM functionality
#include "pwm.h"

// Define the pin connected to the motor
#define MOTOR_PIN 3

// Define the range of the motor's rotation
#define MIN_ANGLE 0
#define MAX_ANGLE 180

// Function to initialize the motor
void motor_init() {
    // Initialize the PWM on the motor pin
    pwm_init(MOTOR_PIN);
}

// Function to move the motor to a specific angle
void motor_move_to_angle(int angle) {
    // Check if the angle is within the valid range
    if (angle < MIN_ANGLE || angle > MAX_ANGLE) {
        printf("Error: Invalid angle. Must be between %d and %d.\n", MIN_ANGLE, MAX_ANGLE);
        return;
    }

    // Convert the angle to a PWM duty cycle (assuming a linear relationship)
    int duty_cycle = (angle - MIN_ANGLE) * (PWM_MAX - PWM_MIN) / (MAX_ANGLE - MIN_ANGLE) + PWM_MIN;

    // Set the PWM duty cycle
    pwm_set_duty_cycle(MOTOR_PIN, duty_cycle);
}

int main() {
    // Initialize the motor
    motor_init();

    // Move the motor to a test angle
    motor_move_to_angle(90);

    return 0;
}
```
