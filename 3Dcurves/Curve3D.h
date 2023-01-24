#pragma once

#include <vector>
#include <memory>
#include <string>
#include <sstream>

#ifdef CURVES3D_EXPORTS
#define CURVES3D_API __declspec(dllexport)
#else
#define CURVES3D_API __declspec(dllimport)
#endif

/// <summary>
/// 3D point struct
/// </summary>
struct CURVES3D_API Point3D
{
	double X, Y, Z;
	Point3D() { X = 0; Y = 0; Z = 0; };
	Point3D(double _X, double _Y, double _Z) {X = _X; Y = _Y; Z = _Z;}
	std::string ToString()
	{
		std::stringstream s;
		s << "(" << X << "; " << Y << "; " << Z << ")";
		
		return s.str();
	};
};

/// <summary>
/// Possible types of curve
/// </summary>
enum CURVES3D_API CurveType
{
	CIRCLE, ELLIPSE, HELIX
};

/// <summary>
/// Transforms enum "CurveType" to string
/// </summary>
/// <param name="CT">Type of curve from enum "CurveType"</param>
/// <returns>String</returns>
inline std::string CURVES3D_API EnumCurveTypeToString(CurveType CT)
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
/// Base class of curve
/// </summary>
class CURVES3D_API Curve3D 
{
private:
	Point3D center;
public:
	virtual CurveType GetType() = 0;
	virtual Point3D GetPos(double t) = 0;
	virtual Point3D GetDer(double t) = 0;
	virtual double GetRx() = 0;
	virtual double GetRy() = 0;
};

std::vector<std::shared_ptr<Curve3D>> CURVES3D_API GetRandCurves(size_t count);