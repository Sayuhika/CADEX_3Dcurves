#pragma once

#include "Curve3D.h"
#include <cmath>

class Ellipse3D :public Curve3D
{
private:
	double A, B;
public:
	Ellipse3D(double _A, double _B) { A = _A; B = _B; }

	virtual CurveType GetType() override
	{
		return CurveType::ELLIPSE;
	}

	virtual Point3D GetPos(double t) override
	{
		return Point3D(A * cos(t), B * sin(t), 0);
	}

	virtual Point3D GetDer(double t) override
	{
		return Point3D(-A * sin(t), B * cos(t), 0);
	}

	virtual double GetRx() override
	{
		return A;
	}

	virtual double GetRy() override
	{
		return B;
	}
};