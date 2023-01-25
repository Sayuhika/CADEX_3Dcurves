#include "pch.h"
#include "Ellipse.h"
#include <cmath>

Ellipse3D::Ellipse3D(double _A, double _B) { A = _A; B = _B; }

CurveType Ellipse3D::GetType()
{
	return CurveType::ELLIPSE;
}

Point3D Ellipse3D::GetPos(double t) 
{
	return Point3D(A * cos(t), B * sin(t), 0);
}

Point3D Ellipse3D::GetDer(double t) 
{
	return Point3D(-A * sin(t), B * cos(t), 0);
}

double Ellipse3D::GetRx() 
{
	return A;
}

double Ellipse3D::GetRy() 
{
	return B;
}

Ellipse3D::~Ellipse3D() {};
