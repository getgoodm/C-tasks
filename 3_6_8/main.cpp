#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{
    int K,count,i,number;
    count=0;
    double sum=0;
    cout<<"Input K: ";
    cin>>K;
    i=1;

    while (i<=K){
       cout<<"Input your set of numbers: ";
       cin>>number;
       while (number!=0)
         {
          sum=sum+number;
          count++;
          cin>>number;
         }
       i++;
     }
    cout<<"Arithmetical mean = "<<sum/count;

    QCoreApplication a(argc, argv);

    return a.exec();
}
