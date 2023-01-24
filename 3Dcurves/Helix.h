#pragma once

constexpr auto M_2_PI = 2 * 3.141592653589793238462643383279502884197169399375105820974944;

#include "Curve3D.h"
#include <cmath>

class Helix3D :public Curve3D
{
private:
	double R, L;
public:
	Helix3D(double _R, double _L) { R = _R; L = _L; }

	virtual CurveType GetType() override
	{
		return CurveType::HELIX;
	}

	virtual Point3D GetPos(double t) override
	{
		return Point3D(R * cos(t), R * sin(t), t * L / M_2_PI);
	}

	virtual Point3D GetDer(double t) override
	{
		return Point3D(-R * sin(t), R * cos(t), L / M_2_PI);
	}

	virtual double GetRx() override
	{
		return R;
	}

	virtual double GetRy() override
	{
		return R;
	}
};