#include <iostream>
#include <iomanip>
using namespace std;
  
int n, k;
  
int main() {
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= k; i++){
        double x = 1, y = 1;
        for (int j = 1; j <= n; j++){
            x *= (double)i/k;
            y *= (double)(i-1)/k;
        }
        ans += (double)i*(x-y);
    }
    cout << fixed << setprecision(6) << ans << "\n";
}