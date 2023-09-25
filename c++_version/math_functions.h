#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
typedef long double ld;

class functions {
    public:
        ll power(ld number, ll power) {
            ll answer = 1;
            for (ll i = 0; i < power; i++) {
                answer *= number;
            }
            return answer;
        }
};


