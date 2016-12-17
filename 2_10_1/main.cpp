#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
float P,S;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //cout<<"Input P"<<endl;
    printf("Input P: ");
    //cin>>P;
    scanf("%f",&P);
    S=sqrt(3)/4*pow(P/3,2);
    //cout<<"S="<<S;
    printf("S=%f", S);


    return a.exec();
}
