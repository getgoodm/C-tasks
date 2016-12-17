#include <QCoreApplication>
#include <math.h>
using namespace std;
#define PI 3.14159
float x,res, sq1;
int main(int argc, char *argv[])
{
    printf("Input x: ");
    scanf("%f",&x);
    sq1=PI-sqrt(fabs(pow(x,3)))+pow(sin(x/(pow(x,2)+1)),2);
    if (sq1<0)
            res=pow(x,4)+pow(-sq1,1./5);

    else
            res=pow(x,4)-pow(sq1,1./5);
    printf("f(x)= %f",res);

    QCoreApplication a(argc, argv);

    return a.exec();
}
