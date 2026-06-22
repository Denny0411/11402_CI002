#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int c; // the number of chambers in the centrifuge 離心機
    int s; // the number of specimens 樣本
    int count = 0;

    while (cin >> c >> s)
    {
        count++;
        double AM = 0; // Average Mass of the chambers
        vector<int> specimen(s);
        for (int i = 0; i < s; i++)
        {
            cin >> specimen.at(i);
            AM += specimen.at(i);
        }
        AM /= c;

        // 補零技巧 (Dummy Specimens)
        while (specimen.size() < 2 * c)
            specimen.push_back(0);

        sort(specimen.begin(), specimen.end());

        // 配對與計算 IMBALANCE
        double CM = 0; // Chamber Mass of chamber i
        double imbalance = 0;

        cout << "Set #" << count << endl;
        for (int i = 0; i < c; i++)
        {
            int s1 = specimen.at(i);
            int s2 = specimen.at(specimen.size() - 1 - i);
            CM = s1 + s2;
            imbalance += fabs(CM - AM); // abs for float
            // cout << " " << i << ":";
            // if (s1 == 0 && s2 != 0)
            //     cout << " " << s2 << endl;
            // else if (s2 == 0 && s1 != 0)
            //     cout << " " << s1 << endl;
            // else if (s1 == 0 && s2 == 0)
            //     cout << endl;
            // else
            //     cout << " " << s1 << " " << s2 << endl;
            cout << " " << i << ":";
            if (s1 != 0) cout << " " << s1;
            if (s2 != 0) cout << " " << s2;
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << endl << endl;
    }
}