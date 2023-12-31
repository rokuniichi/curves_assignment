#include "curves_lib/ellipse.h"

#define _USE_MATH_DEFINES
#include <math.h>

Ellipse::Ellipse(const double radiusX, const double radiusY) : radiusX{ Validate(radiusX) }, radiusY{ Validate(radiusY) }, center { Vector3D() } {}
Ellipse::Ellipse(const double radiusX, const double radiusY, const Vector3D center) : radiusX{ Validate(radiusX) }, radiusY{ Validate(radiusY) }, center{ center } {}

Vector3D Ellipse::GetPoint(const double t) const
{ 
	return Vector3D(center.x + radiusX * cos(t), center.y + radiusY * sin(t), center.z);
}

Vector3D Ellipse::GetFirstDerivative(const double t) const
{
	return Vector3D(-radiusX * sin(t), radiusY * cos(t), 0);
}

std::ostream& Ellipse::Print(std::ostream& out)
{
	out << "Ellipse of x-radius (" << radiusX << "), y-radius (" << radiusY << "), center at " << center;
	return out;
}
