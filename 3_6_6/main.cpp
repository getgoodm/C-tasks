#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;

int main(int argc, char *argv[])
{
    int number, count1, count2, N;
    count1=0;
    count2=0;
    cout<<"Input N: ";
    cin>>N;
    int i=1;
    while (i<=N) {
        cout<<"Input your number: ";
        cin>>number;
        cout<<endl;
        if (number % 2 == 0)
                count2++;
        else count1++;
        i++;

    }
    cout<<"Quantity of even numbers: "<<count2<<"\tQuantity of odd numbers: "<<count1;
    QCoreApplication a(argc, argv);

    return a.exec();
}
