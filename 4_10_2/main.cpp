#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int transfer_to_decimal(int n, int radix)
{
    int res=0;
    int po=0;
    while (n!=0)
    {
        res=res+n%10*pow(radix,po);
        n=n/10;
        po++;
    };
    return res;

}

int transfer_to_r(int n, int r)
{
    int res=0;
    int po=1;
    while (n>0)
    {
        res=res+n%r*po;
        n=n/r;
        po=po*10;

    };
    return res;
}

int main(int argc, char *argv[])
{
    int a1,b1,answer;
    cout<<"Input A, B"<<endl;;
    cin>>a1>>b1;
    a1=transfer_to_decimal(a1,8);
    b1=transfer_to_decimal(b1,5);
    answer=2*pow(a1,2)+3*a1*b1;
    cout<<"Result in decimal: "<<answer<<"\t Result in 7 radix: "<<transfer_to_r(answer,7);

    QCoreApplication a(argc, argv);

    return a.exec();
}
