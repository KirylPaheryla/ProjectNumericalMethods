#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

long double f(long double x)
{
    //rownanie 3
    return x*exp(x)-x*x;
}

long double pohodna_f(long double x)
{
    return exp(x)*(x + 1)-2*x;
}

long double u_f(long double x)
{
    return f(x)/pohodna_f(x);
}

long double g(long double x)
{
    return 4*x*x*x - 2*x*x - 2*x + 1;
}

long double pohodna_g(long double x)
{
    return 12*x*x - 4*x - 2;
}

long double u_g(long double x)
{
    return g(x)/pohodna_g(x);
}

long double blad(long double x1, long double x2)
{
    if(x2 == 0)
    {
        cout << "bezwzgledny = ";
        return fabs(x1-x2);
    }
    else
    {
        cout << "wzgledny = ";
        return fabs(x1-x2)/fabs(x2);
    }
}

int main()
{
    cout << "x*exp(x)-x*x" << endl;
    cout << endl;

    ofstream out("test_metoda_Wielopunktowa.txt", ios_base::app);
    out << "x*exp(x)-x*x" << endl;
    out << endl;

    for(int i = -50; i <= 50; i+=10)
    {
        for(int ii = 3; ii <= 16; ii++)
        {
            long double x1 = i, h1;
            long double e1 = pow(10,-ii);
            int K1 = 0;

            cout << "Dla x0 = " << x1 << endl;
            cout << "Dla e = " << e1 << endl;
            out << "Dla x0 = " << x1 << endl;
            out << "Dla e = " << e1 << endl;

            do
            {
                h1 = (4*f(x1))/(pohodna_f(x1)+3*pohodna_f(x1-(2*u_f(x1))/3));
                x1 = x1 - h1;
                K1++;
            }while(fabs(h1) >= e1);

            cout << "K = " << K1 << endl;
            cout << "x = " << setprecision(15) << x1 << endl;
            cout << "Blad " << setprecision(15) << blad(0,x1) << endl;
            cout << endl;

            out << "K = " << K1 << endl;
            out << "x = " << setprecision(15) << x1 << endl;
            out << "Blad " << setprecision(15) << blad(0,x1) << endl;
            out << endl;
        }
    }

    cout << endl;
    cout << "Rownanie 4*x*x*x - 2*x*x - 2*x + 1" << endl;
    cout << endl;

    out << endl;
    out << "Rownanie 4*x*x*x - 2*x*x - 2*x + 1" << endl;
    out << endl;

    for(int j = -50; j <= 50; j+=10)
    {
        for(int jj = 3; jj <= 16; jj++)
        {
            long double x2 = j, h2;
            long double e2 = pow(10,-jj);
            int K2 = 0;

            cout << "Dla x0 = " << x2 << endl;
            cout << "Dla e = " << e2 << endl;
            out << "Dla x0 = " << x2 << endl;
            out << "Dla e = " << e2 << endl;

            do
            {
                h2 = (4*g(x2))/(pohodna_g(x2)+3*pohodna_g(x2-2*u_g(x2)/3));
                x2 = x2 - h2;
                K2++;
            }while(fabs(h2) >= e2);

            cout << "K = " << K2 << endl;
            cout << "x = " << setprecision(15) << x2 << endl;
            cout << "Blad " << setprecision(15) << blad(0.707106781186547,x2) << endl;
            cout << endl;

            out << "K = " << K2 << endl;
            out << "x = " << setprecision(15) << x2 << endl;
            out << "Blad " << setprecision(15) << blad(0.707106781186547,x2) << endl;
            out << endl;
        }
    }
    out.close();
    return 0;
}
