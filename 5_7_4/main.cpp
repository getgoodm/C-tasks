#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int kvo_razryad (int M)
{
    long int k;
    for (k=1;M>9;M/=10,k++);
    return k;
}

bool palindrom (int n)
{
    int k=kvo_razryad(n), s, p=n;
    for (s=0;p!=0; p/=10, k--)
        s+=(p%10)*pow(10,k-1);
    if (s==n) return true; else return false;
}

int main(int argc, char *argv[])
{
    int *X, i, j, n, maxpal, minpal, max_index, min_index, first_index, last_index, b;
    bool first=false;
    bool pr=true;
    cout<<"Input size of X array ";
    cin>>n;
    X=new int [n];
    cout<<"Input X array"<<endl;
    for (i=0;i<n;i++)
    {

        cout<<"X["<<i<<"]=";
        cin>>X[i];
        if (palindrom(X[i]))
            if (first==false)
            {
                maxpal=X[i];
                max_index=i;
                minpal=X[i];
                min_index=i;
                first=true;
            }
        else
                if (X[i]>maxpal)
                {
                    maxpal=X[i];
                    max_index=i;
                }

        else
                    if (X[i]<minpal)
                    {
                        minpal=X[i];
                        min_index=i;
                    }

    }
    cout<<"minpal="<<minpal<<" maxpal="<<maxpal<<" mind="<<min_index<<" maxind="<<max_index<<endl;
    if (max_index<min_index)
    {
        first_index=max_index+1;
        last_index=min_index;
    }
    else
    {
        first_index=min_index+1;
        last_index=max_index;
    };

   // cout<<"first index="<<first_index<<" last index="<<last_index<<endl;

for (j=1;pr;j++)
{
    for (pr=false, i=0;i<last_index-first_index-j;i++) {
        if (abs((X[i+first_index])<abs(X[i+first_index+1])))
        {
            b=X[i+first_index];
            X[i+first_index]=X[i+first_index+1];
            X[i+first_index+1]=b;
            pr=true;
        }
     }
}

    cout<<"Sorted array X\n";
    for (i=0;i<n;i++)
        cout<<X[i]<<" ";

delete X;
    QCoreApplication a(argc, argv);

    return a.exec();
}
