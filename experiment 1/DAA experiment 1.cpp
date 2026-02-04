
#include <bits/stdc++.h>
using namespace std;
int c = 0;
int d = 0;
void complexRec(int n, int depth) {
    d = max(d, depth);
    c++;  
    if (n <= 2) {
        return;
    }
    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            c++;
        }
        p >>= 1;
    }
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        c++;
    }
      if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    int n = 4;
    complexRec(n, 1);

    cout << "operation count is: " << c << endl;
    cout << "depth is: " << d<< endl;

    return 0;
}

//recc relation T(n)=3T(n/2)+nlogn;
//Time complexity= O(n^log23)
//Case 1st;
