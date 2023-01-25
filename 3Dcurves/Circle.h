#pragma once

#include "Curve3D.h"

class Circle3D:public Curve3D
{
private:
	double R;
public:
	Circle3D(double _R);
	virtual CurveType GetType() override;
	virtual Point3D GetPos(double t) override;
	virtual Point3D GetDer(double t) override;
	virtual double GetRx() override;
	virtual double GetRy() override;
	~Circle3D();
};

