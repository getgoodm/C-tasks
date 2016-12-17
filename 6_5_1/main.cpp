#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
bool same_digits(int x)
{
    int digit=x%10;
    while (x>0){
        if (x%10==digit)
        x/=10;
        else break;
    }
    if (x==0)
        return true;
    else return false;

}

int main(int argc, char *argv[])
{
    int i,j,m,n,pr,min;
    int **B;
    int sum=0;
    bool firstmin=false;
    pr=1;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    B=new int *[n];
    for (i=0;i<n;i++)
        B[i]=new int [m];
    cout<<"Input matrix elements"<<endl;;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++) {
            cin>>B[i][j];
            if (same_digits(B[i][j]))
                if (firstmin==false) {
                    min=B[i][j];
                    firstmin=true;
                }
            else if (B[i][j]<min)
                    min=B[i][j];

            pr*=B[i][j];
        }
    for (i=1;i<n-1;i++)
        for (j=1;j<m-1;j++)
            sum+=B[i][j];
    cout<<"pr="<<pr<<" sum="<<sum<<" same digit minimum="<<min;



    QCoreApplication a(argc, argv);

    return a.exec();
}
