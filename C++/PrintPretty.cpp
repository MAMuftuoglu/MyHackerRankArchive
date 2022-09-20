#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        stringstream ss;
        ss << "0x" << hex << (long long)(A) << endl;
        cout << setw(ss.str().length()) << ss.str();

        ss.str("");
        ss.clear();
        if (B > 0)
            ss << "+" << fixed << setprecision(2) << B;
        else
            ss << "-" << setprecision(2) << B;
        cout << setfill('_') << setw(15) << ss.str() << endl;

        cout << scientific << setprecision(9) << C << endl;
    }
    return 0;
}