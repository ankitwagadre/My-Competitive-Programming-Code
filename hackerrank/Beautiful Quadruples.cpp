#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main(){
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    vector <int> a; //= {A, B, C, D};
    a.push_back(A);
    a.push_back(B);
    a.push_back(C);
    a.push_back(D);
    sort(a.begin(), a.end());
    A = a[0];
    B = a[1];
    C = a[2];
    D = a[3];

    long long q = 0;
    q = q + A*(B-1)*(C-2)*(D-3);
    q = q + A*((C-1)*(C-2)/2 + (C-1)*(D-C)) + (B-A)*(A*(A-1)/2 + A*(D-A-1)) + (C-B)*A*(A-1)/2 + (C-B)*A*(B-A);
    q = q + A*(D-1) + A*(B-A);
    cout << q;

    return 0;
}
