#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    cout<<"Number\t"<<"Cube-root"<<endl;
    for (int i=1;i<=10;i++)

        cout<<i<<"\t"<<pow(i,1./3)<<endl;;


    return a.exec();
}
