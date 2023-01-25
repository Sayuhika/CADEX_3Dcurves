#pragma once

#include "Curve3D.h"

class Ellipse3D :public Curve3D
{
private:
	double A, B;
public:
	Ellipse3D(double _A, double _B);
	virtual CurveType GetType() override;
	virtual Point3D GetPos(double t) override;
	virtual Point3D GetDer(double t) override;
	virtual double GetRx() override;
	virtual double GetRy() override;
	~Ellipse3D();
};