#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
double a,res;
int main(int argc, char *argv[])
{
    cout<<"Input a: ";
    cin>>a;
    if (a<-sqrt(8))
            res=-2;
    else if (a>=-sqrt(8) && a<sqrt(8))
            res=a*a/2-2;
    else
      res=2;

    cout<<"f(a)= "<<res;


    QCoreApplication a(argc, argv);

    return a.exec();
}
