#pragma once

// importing built-in libraries

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// importing my classes

#include "complex.h"
#include "math_functions.h"

using namespace std;

typedef long long ll;
typedef long double ld;

class assets {
    public:
        ld delta_x = 0.001;
        ll number_coof = 3;
        complex Lamda;
        vector<complex> solution;

        assets() {
            solution.resize(number_coof);
        }

        complex f(complex x) {
            return (x - 1) * (x + 1) * (x - Lamda);
        }

        complex complex_derivative_f(complex x) {
            complex z;
            z.real = x.real + delta_x;
            z.imag = x.imag + delta_x;

            complex answer = (f(z) - f(x)) / (z - x);
        }

        complex GetComplex(ld x, ld y) {
            complex answer;
            answer.real = x;
            answer.imag = y;

            return answer;
        }

        ld magnitude(complex x) {
            return sqrt(x.real * x.real + x.imag * x.imag);
        }
};