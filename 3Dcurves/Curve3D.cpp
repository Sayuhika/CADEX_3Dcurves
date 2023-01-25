#include "pch.h"
#include "Curve3D.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>
#include <sstream>

using namespace std;

Point3D::Point3D() { X = 0; Y = 0; Z = 0; };
Point3D::Point3D(double _X, double _Y, double _Z) { X = _X; Y = _Y; Z = _Z; }
string Point3D::ToString()
{
	std::stringstream s;
	s << "(" << X << "; " << Y << "; " << Z << ")";

	return s.str();
};
Point3D::~Point3D() {};

inline std::string EnumCurveTypeToString(CurveType CT)
{
	switch (CT)
	{
	case CIRCLE:	return "CIRCLE";
	case ELLIPSE:	return "ELLIPSE";
	case HELIX:		return "HELIX";
	default:
		return "[Unknown curve type]";
	}
}

/// <summary>
/// Generates curve with random type and parameters
/// </summary>
/// <returns>Curve with random type and parameters</returns>
shared_ptr<Curve3D> GetRandCurve()
{
	int type = rand() % 3;
	double R1 = (double) rand() / RAND_MAX;
	double R2 = (double) rand() / RAND_MAX;

	switch (type)
	{
	case 0:
		return shared_ptr<Curve3D>(new Circle3D(R1));
	case 1:
		return shared_ptr<Curve3D>(new Ellipse3D(R1, R2));
	case 2:
		return shared_ptr<Curve3D>(new Helix3D(R1, R2));
	}
}

vector<shared_ptr<Curve3D>> GetRandCurves(size_t count)
{
	srand(time(NULL));
	
	vector<shared_ptr<Curve3D>> result(count);

	for (size_t i = 0; i < count; i++) result[i] = GetRandCurve();

	return result;
}