#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
     int n;
     cin >> n;

    unordered_map<string, int> names; // kad galetume lengvai gauti kiek artu panaudota

    while(n--) {
        string a;
        cin >> a;

        if (!names.count(a)) { // rastas stringas masyve, 
            cout << "OK" << endl;
            names[a] = 0;
        } else { // nerastas stringas masyve
            names[a]++;
            cout << a << to_string(names[a]) << endl;     
        }
     }
}