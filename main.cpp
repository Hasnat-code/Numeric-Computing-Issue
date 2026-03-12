#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function for derivative
double f(double x)
{
    return sin(x);
}

float f_float(float x)
{
    return sin(x);
}

int main()
{
    double x = 1.0;
    double true_derivative = cos(x);

    cout << fixed << setprecision(15);
    cout << "True derivative cos(1) = " << true_derivative << "\n\n";
    cout << "h\t\tDouble Derivative\tError(double)\tFloat Derivative\tError(float)\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    // Loop over h decreasing
    for(double h = 1e-1; h >= 1e-20; h /= 10)
        {

        // double calculation
        double derivative_double = (f(x + h) - f(x)) / h;
        double error_double = fabs(derivative_double - true_derivative);

        // float calculation
        float h_float = static_cast<float>(h);
        float x_float = static_cast<float>(x);
        float derivative_float = (f_float(x_float + h_float) - f_float(x_float)) / h_float;
        float error_float = fabs(derivative_float - static_cast<float>(true_derivative));

        cout << scientific << h << "\t"
             << fixed << derivative_double << "\t" << error_double << "\t"
             << derivative_float << "\t" << error_float << "\n";

        // Stop when float error is clearly noticeable (>0.01)
        if(error_float > 0.01)
            {
            cout << "\n*** Noticeable error in float starts at h = " << scientific << h << " ***\n";
            break;
        }
    }

    return 0;
}