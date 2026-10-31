#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "===========================" << endl;
    cout << "  C++ Workspace Ready!     " << endl;
    cout << "===========================" << endl;

    int n;
    cout << "Enter number of elements: ";
    if (cin >> n) {
        vector<int> numbers(n);
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        cout << "Processed Elements: ";
        for (int val : numbers) {
            cout << val * val << " ";
        }
        cout << endl;
    }

    return 0;
}