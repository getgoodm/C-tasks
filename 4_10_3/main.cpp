#include <QCoreApplication>
#include <math.h>
#include <iostream>;
#define eps 0.0001
using namespace std;

double calculate_delta(double x1,double c)
{
    double fx1,fxc;
    fx1=0.1*pow(x1,2)-exp(x1);
    fxc=0.1*pow(c,2)-exp(c);
    return fx1*(x1-c)/(fx1-fxc);
}
double f(double x)
{
    return(0.1*x*x-exp(x));
}

double fi (double x3, double L)
{
    return(x3+L*f(x3));
}

int Iteration(double *x, double L)
{
    double x0;
    int k=0;
      do
    {
        x0=*x;
        *x=fi(x0,L);
        k++;
    }
    while (fabs(x0-*x)>=eps);
    return k;
}

int main(int argc, char *argv[])
{
    double c=-1;
    double x1=-2;
    double X=-1.5;
    double L1=2;
    int K=0;
    x1=x1-calculate_delta(x1,c);
    while (fabs(calculate_delta(x1,c))>eps)
    {
        x1=x1-calculate_delta(x1,c);
        K++;
    };

    cout<<"Chord solution: x= "<<x1;
    cout<<", iteration amount k="<<K<<endl;
    K=Iteration(&X,L1);
    cout<<"Iteration solution: x= "<<X;
    cout<<", iteration amount k="<<K<<endl;


    QCoreApplication a(argc, argv);

    return a.exec();
}
