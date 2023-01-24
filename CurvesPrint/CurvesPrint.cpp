#include <iostream>
#include "Curve3D.h"
#include <string>
#include <iomanip>

using namespace std;

constexpr auto M_PI_D4 = 3.141592653589793238462643383279502884197169399375105820974944 * 0.25;

int main(int argc, char *argv[])
{
    int count = 1024;
    if (argc > 1) count = stoi(argv[1]);
    auto curves = GetRandCurves(count);
    vector<shared_ptr<Curve3D>> circles;
    
    // Table column names of curves array
    cout << endl << "Curves array:" << endl;
    cout 
        << setw(7) << left << setfill(' ') << "Number"
        << setw(10) << left << setfill(' ') << "Type"
        << setw(40) << left << setfill(' ') << "Coords"
        << setw(40) << left << setfill(' ') << "Derivative" << endl;

    // Data-rows of the table
    for (size_t i = 0; i < curves.size(); i++)
    {
        cout 
            << setw(7) << left << setfill(' ') << i 
            << setw(10) << left << setfill(' ') << EnumCurveTypeToString(curves[i]->GetType()) 
            << setw(40) << left << setfill(' ') << curves[i]->GetPos(M_PI_D4).ToString() 
            << setw(40) << left << setfill(' ') << curves[i]->GetDer(M_PI_D4).ToString() << endl;

        // Filling the array only with curves of the CIRCLE type
        if ((curves[i]->GetType() == CIRCLE))
        {
            size_t j = 0;
            for (j = 0; j < circles.size(); j++)
            {
                if (circles[j]->GetRx() > curves[i]->GetRx())
                {
                    break;
                }
            }

            circles.insert(circles.begin() + j, curves[i]);
        }
    }
    
    // Show CIRCLE array
    cout << endl << "Circles sort:" << endl;
    cout << setprecision(5) << "Number\tType\tR" << endl;
    for (size_t i = 0; i < circles.size(); i++)
    {
        cout
            << i << "\t"
            << EnumCurveTypeToString(circles[i]->GetType()) << "\t"
            << circles[i]->GetRx() << endl;
    }

    // Gets the sum of R with using parallel calculation
    double sum = 0;
    #pragma omp for reduction(+:sum)
    for (size_t i = 0; i < circles.size(); i++)
    {
        sum += circles[i]->GetRx();
    }
    cout << endl << "R sum: " << sum << endl;

    return 0;
}