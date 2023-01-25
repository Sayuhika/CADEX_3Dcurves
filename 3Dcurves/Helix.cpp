#include "pch.h"
#include "Helix.h"
#include <cmath>

constexpr auto M_2_PI = 2 * 3.141592653589793238462643383279502884197169399375105820974944;

Helix3D::Helix3D(double _R, double _L) { R = _R; L = _L; }

CurveType Helix3D::GetType() 
{
	return CurveType::HELIX;
}

Point3D Helix3D::GetPos(double t) 
{
	return Point3D(R * cos(t), R * sin(t), t * L / M_2_PI);
}

Point3D Helix3D::GetDer(double t) 
{
	return Point3D(-R * sin(t), R * cos(t), L / M_2_PI);
}

double Helix3D::GetRx() 
{
	return R;
}

double Helix3D::GetRy() 
{
	return R;
}

Helix3D::~Helix3D() {};
