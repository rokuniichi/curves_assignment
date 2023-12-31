#include "curves_lib/circle.h"

#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(const double radius) : radius{ Validate(radius) }, center{ Vector3D() } {}
Circle::Circle(const double radius, const Vector3D center) : radius{ Validate(radius) }, center{ center } {}

Vector3D Circle::GetPoint(const double t) const
{ 
	return Vector3D(center.x + radius * cos(t), center.y + radius * sin(t), center.z);
}

Vector3D Circle::GetFirstDerivative(const double t) const
{
	return Vector3D(-radius * sin(t), radius * cos(t), 0);
}

std::ostream& Circle::Print(std::ostream& out)
{
	out << "Circle of radius (" << radius << "), center at " << center;
	return out;
}
