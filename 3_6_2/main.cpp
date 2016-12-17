#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{
    double x,y;
    cout<<"Input x: ";
    cin>>x;
    cout<<"Input y: ";
    cin>>y;
    if (((x>=-3 && x<=-1)|| (x>=1 && x<=3)) && (y>=-3 && y<=3))
        cout<<"the point belongs to the field";
    else if ((x>=-1)&&(x<=1) && ((y>=1 && y<=3) || ((y>=-3) && (y<=-1))))
             cout<<"the point belongs to the field";
             else
             cout<<"the point doesn't belong to the field";
    QCoreApplication a(argc, argv);

    return a.exec();
}
