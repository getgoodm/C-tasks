#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;
int main(int argc, char *argv[])
{
    int *X, *Y, *Z, n, k, i, *nmax, kvo, nmax_temp, j, l;
    bool pr;
    int p1=0;
    nmax=new int[5];
    int p=0;
    cout<<"Input size of X array ";
    cin>>n;
    X=new int [n];
    cout<<"Input X array"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<"X["<<i<<"]=";
        cin>>X[i];
        if (X[i]>0)
            p++;
    }

    cout<<"Input size of Y array ";
    cin>>k;
    Y=new int [k];
    cout<<"Input Y array"<<endl;
    for (i=0;i<k;i++)
    {
        cout<<"Y["<<i<<"]=";
        cin>>Y[i];
    }

    for (j=0;j<5;j++)
    {
        kvo=0;
        for (i=0;i<n;i++)
        {
            pr=false;
            for (l=0;l<j;l++)
                if (i==nmax[l]) pr=true;
            if (!pr)
            {
                kvo++;
                if (kvo==1) nmax_temp=i;
                else
                    if (Y[i]>Y[nmax_temp]) nmax_temp=i;
            }
        }
        nmax[j]=nmax_temp;
    }
   Z=new int [p+5];
   for (i=0;i<n;i++)
       if (X[i]>0)
       {
           Z[p1]=X[i];
           p1++;
       }
   for (i=0;i<5;i++)
   {
       Z[p1]=Y[nmax[i]];
       p1++;
   }

   int sum=0;
   for (i=0;i<(p+4);i++)
   {
       cout <<"\t Z["<<i<<"]="<<Z[i];
       if ((abs(Z[i])>999) && abs((Z[i])<9999))
           sum+=Z[i];
   }
   cout<<"\n Sum="<<sum;




   delete [] X;
   delete [] Y;
   delete [] Z;

    QCoreApplication a(argc, argv);

    return a.exec();
}
