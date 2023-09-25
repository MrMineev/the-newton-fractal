#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

// my classes

#include "assets.h"
#include "complex.h"
#include "math_functions.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef string line;
typedef bool bit;
typedef vector<line> text;

signed main() {
    ofstream File("result.txt");

    assets tools;
    functions func;

    ll width = 800;
    ll height = 800;

    ll center_x = width / 2;
    ll center_y = height / 2;

    ld left_border = -5;
    ld right_border = 5;
    ld top_border = 5;
    ld bottom_border = -5;

    ll rounding = 2;
    ld step = 0.01;

    ll times_calculate = 10;

    ld maximum_distance = 0.5;

    tools.solution[0] = tools.GetComplex(1, 0);
    tools.solution[1] = tools.GetComplex(-1, 0);
    tools.solution[2] = tools.Lamda;

    for (ld RealValue = left_border; RealValue <= right_border; RealValue += step) {
        for (ld ImagValue = bottom_border; ImagValue <= top_border; ImagValue += step) {
            tools.Lamda.real = RealValue, tools.Lamda.imag = ImagValue;

            vector<complex> points(0);

            for (ld i = - center_x; i <= center_x; i += step) {
                for (ld g = - center_y; g <= center_y; g += step) {
                    points.push_back(tools.GetComplex(i, g));
                }
            }

            for (ll i = 0; i < times_calculate; i++) {
                for (ll g = 0; g < points.size(); g++) {
                    points[g] = points[g] - tools.f(points[g]) / tools.complex_derivative_f(points[g]);
                }
            }

            complex AveragePosition = tools.Lamda / 3;
            AveragePosition.real = round(AveragePosition.real * func.power(10, rounding)) / func.power(10, rounding);
            AveragePosition.imag = round(AveragePosition.imag * func.power(10, rounding)) / func.power(10, rounding);

            vector<ld> dist(tools.solution.size());

            for (ll i = 0; i < dist.size(); i++) {
                dist[i] = tools.magnitude(AveragePosition - tools.solution[i]);
            }

            ld min_dist = 1e18;

            ll index = -1;

            for (ll i = 0; i < dist.size(); i++) {
                if (dist[i] <= maximum_distance && dist[i] < min_dist) {
                    min_dist = dist[i];
                    index = i;
                }
            }

            File << index << " ";
        }
        File << endl;
    }

    File.close();
}