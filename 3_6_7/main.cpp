#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{
    int x,sum;
    sum=0;
    cout<<"Input x: ";
    cin>>x;

    for (int i=2;i<=x/2;i++)
        if (x % i==0)
            sum=sum+i;
    cout<<"Sum: "<<sum;

    QCoreApplication a(argc, argv);

    return a.exec();
}
