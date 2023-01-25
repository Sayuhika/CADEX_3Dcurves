#include "pch.h"
#include "Circle.h"
#include <cmath>

Circle3D::Circle3D(double _R) { R = _R; }

CurveType Circle3D::GetType() 
{
	return CurveType::CIRCLE;
}

Point3D Circle3D::GetPos(double t)
{
	return Point3D(R * cos(t), R * sin(t), 0);
}

Point3D Circle3D::GetDer(double t)
{
	return Point3D(-R * sin(t), R * cos(t), 0);
}

double Circle3D::GetRx()
{
	return R;
}
 double Circle3D::GetRy()
{
	return R;
}

 Circle3D::~Circle3D() {};
