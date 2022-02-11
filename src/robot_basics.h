#ifndef ROBOT_BASICS_H
#define ROBOT_BASICS_H

#define Meter(X) (X)
#define Centimeter(X) (0.01*(X))
#define CM(X) Centimeter(X)
#define Inch(X) (Centimeter(2.54*X))

global f64 Gearset36MaxVelocity = 100; // Red
global f64 Gearset18MaxVelocity = 200; // Green
global f64 Gearset6MaxVelocity  = 600; // Blue

#endif //ROBOT_BASICS_H
