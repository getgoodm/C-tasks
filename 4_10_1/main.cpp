#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
long int factorial(int n)
{
    if (n<=1)
        return n;
    else
        return n*factorial(n-1);

}

double calculate_c(int a, int b)
{
    return factorial(a)/(factorial(b)*factorial(a-b));
}

int main(int argc, char *argv[])
{
    int N, a1, b1;
    cout<<"Input N: ";
    cin>>N;
    for (int i=1; i<=N; i++)
    {
        cout<<"Input a, b: ";
        cin>>a1>>b1;
        if (a1>b1)
            cout<<"C="<<calculate_c(a1,b1)<<endl;

    }
    QCoreApplication a(argc, argv);
    return a.exec();
}
