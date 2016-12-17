#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{
    int sum=0;
    for (int i=105;i<=995;i=i+10)
        sum=sum+i;
    cout<<"Sum= "<<sum;
    QCoreApplication a(argc, argv);

    return a.exec();
}
