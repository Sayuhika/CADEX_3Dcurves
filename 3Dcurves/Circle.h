#pragma once

#include "Curve3D.h"
#include <cmath>

class Circle3D:public Curve3D
{
private:
	double R;
public:
	Circle3D(double _R) {R = _R; }

	virtual CurveType GetType() override 
	{
		return CurveType::CIRCLE;
	}

	virtual Point3D GetPos(double t) override
	{
		return Point3D(R * cos(t), R * sin(t), 0);
	}

	virtual Point3D GetDer(double t) override
	{
		return Point3D(- R * sin(t),R * cos(t), 0);
	}

	virtual double GetRx() override
	{
		return R;
	}

	virtual double GetRy() override
	{
		return R;
	}

	~Circle3D() {};
};

