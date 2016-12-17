#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
bool check (int x)
{
    int sum=0;
    if (x!=0){

    while (x>0){
        sum+=x%10;
        x/=10;
    }
    if (x==0 && sum%3==0)
        return true;
    else return false; }
    else return false;

}

int main(int argc, char *argv[])
{
    int i,j,m,n,pr,max, max_i;
    int **A;
    int *B;
    pr=1;
    bool firstmax=false;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    B=new int[m];
    A=new int *[n];
    for (i=0;i<n;i++)
        A[i]=new int [m];
    cout<<"Input matrix elements"<<endl;;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cin>>A[i][j];
            pr*=A[i][j];
        }
        if (firstmax==false)
        {
            max=pr;
            max_i=i;
            firstmax=true;
        }
        else if (pr>max)
        {
            max=pr;
            max_i=i;
        }
        pr=1;
    }

    int k=0;
    for (j=0;j<m;j++)
    {
        for (i=0;i<n;i++)
            if (check(A[i][j]))
                k++;
        B[j]=k;
        k=0;
    }
    cout<<"\n B array:"<<endl;
    for (j=0;j<m;j++)
        cout<<B[j]<<" ";
    cout<<"\n The string with max multiplication value:"<<endl;
    for (j=0;j<m;j++)
        cout<<A[max_i][j]<<" ";


    QCoreApplication a(argc, argv);

    return a.exec();
}
