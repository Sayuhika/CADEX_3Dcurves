#pragma once

#include <vector>
#include <memory>
#include <string>

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
	Point3D();
	Point3D(double _X, double _Y, double _Z);
	std::string ToString();
	~Point3D();
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
inline std::string CURVES3D_API EnumCurveTypeToString(CurveType CT);

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
	virtual ~Curve3D() {};
};

/// <summary>
/// Generates curves with random type and parameters
/// </summary>
/// <param name="count">Count of curves</param>
/// <returns>Curves with random type and parameters</returns>
std::vector<std::shared_ptr<Curve3D>> CURVES3D_API GetRandCurves(size_t count);