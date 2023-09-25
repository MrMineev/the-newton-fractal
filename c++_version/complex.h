#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "math_functions.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef bool bit;

class complex {
    private:
        functions func;
    public:
        ld real = 0;
        ld imag = 0;

        bit operator==(const complex& value);
        bit operator!=(const complex& value);

        complex& operator=(const complex& value);
        complex& operator=(const ld& value);

        complex operator+(const complex adder);
        complex operator+(const ll adder);

        complex operator-(const complex subtractor);
        complex operator-(const ll subtractor);

        complex operator*(const ld multi);
        complex operator*(const complex multi);

        complex operator/(const ld div);
        complex operator/(const complex dividor);

        ld magnitude() {
            ld answer = sqrt(func.power(real, 2) + func.power(real, 2));
            return answer;
        }

        void print() {
            cout << real << " + " << imag << "i" << endl;
        }
};

bit complex::operator==(const complex& value) {
    if (real == value.real && imag == value.imag) {
        return true;
    } else {
        return false;
    }
}

bit complex::operator!=(const complex&value) {
    return  (!(*this == value));
}

complex& complex::operator=(const ld& value) {
    real = value;
}

complex& complex::operator=(const complex& value) {
    if (this != &value) {
        real = value.real; 
        imag = value.imag;
    }
}

complex complex::operator+(const ll adder) {
    complex answer;
    answer.real = real + adder;
    answer.imag = imag;

    return answer;
}

complex complex::operator+(const complex adder) {
    complex answer;
    answer.real = real + adder.real;
    answer.imag = imag + adder.imag;

    return answer;
}

complex complex::operator-(const complex subtractor) {
    complex answer;
    answer.real = real - subtractor.real;
    answer.imag = imag - subtractor.imag;

    return answer;
}

complex complex::operator-(const ll subtractor) {
    complex answer;
    answer.real = real - subtractor;
    answer.imag = imag;

    return answer;
}

complex complex::operator*(const ld multi) {
    complex answer;
    answer.real = real * multi;
    answer.imag = imag * multi;

    return answer;
}

complex complex::operator*(const complex multi) {
    complex multid;
    multid.real = 0, multid.imag = imag * multi.imag;

    complex sum;
    sum.real = 0, sum.imag = real * multi.imag + imag * multi.real;

    complex number;
    number.real = real * multi.real, number.imag = 0;

    complex answer = (number - multid) + sum;

    return answer;
}

complex complex::operator/(const ld div) {
    complex answer;
    answer.real = real / div;
    answer.imag = imag / div;

    return answer;
}

complex complex::operator/(const complex dividor) {
    complex answer;
    answer.real = real * dividor.real + imag * dividor.imag;
    answer.imag = imag * dividor.real - real * dividor.imag;

    complex result = answer / (func.power(dividor.real, 2) + func.power(dividor.imag, 2));

    return result;
}


