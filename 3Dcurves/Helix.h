#pragma once

#include "Curve3D.h"

class Helix3D :public Curve3D
{
private:
	double R, L;
public:
	Helix3D(double _R, double _L);
	virtual CurveType GetType() override;
	virtual Point3D GetPos(double t) override;
	virtual Point3D GetDer(double t) override;
	virtual double GetRx() override;
	virtual double GetRy() override;
	~Helix3D();
};