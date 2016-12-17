#include <QCoreApplication>

#include <math.h>
#include <iostream>;
using namespace std;
int udal (int *x, int k, int n)
{
    int i;
    if (k>n-1) return n;
    else
    {
        for (i=k; i<n-1;i++)
            x[i]=x[i+1];
        n--;
        return n;
    }
}

int main(int argc, char *argv[])
{
    int *P, n, m, qn, *R, *Q, i,S,number, positiven, max, nchet;
    bool nu;
    nu=false;
    bool firstelement=false;
    S=0;
    positiven=0;
    cout<<"Input size of the array P ";
    cin>>n;
    P=new int [n];
    cout<<"Input array P"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<"P["<<i<<"]=";
        cin>>P[i];
        S+=abs(P[i]);
        if ((nu==false)&&(P[i]==0))
        {
            number=i;
            nu=true;
        }
        if (P[i]>0)
            positiven++;

    }
    cout<<"S="<<S<<endl;
    if (nu==true)
      cout<<"number="<<number<<endl;
    else
        cout<<"No zero elements were found"<<endl;
    cout<<"Input size of the array R ";
    cin>>m;
    R=new int [m];
    cout<<"Input array R"<<endl;
    for (i=0;i<m;i++)
    {
        cout<<"R["<<i<<"]=";
        cin>>R[i];
        if (R[i]>0)
            positiven++;
    }
    Q=new int [positiven];
    for (qn=0,i=0; i<n; i++)
        if (P[i]>0)
        {
            Q[qn]=P[i];
            qn++;
        }
    for (i=0;i<m;i++)
        if (R[i]>0)
        {
            Q[qn]=R[i];
            qn++;
        }
    for (i=0;i<qn;i++)
        if ((firstelement==false) && (Q[i]%2==0))
        {
                max=Q[i];
                firstelement=true;
        }
        else if ((Q[i]%2==0) && (Q[i]>max))
        {
            max=Q[i];
            nchet=i;
        }
cout<<"\n nchet="<<nchet<<endl;

    udal(Q,nchet,qn);


    for (i=0;i<qn-1;i++) cout <<"\t X["<<i<<"]="<<Q[i];






    delete [] P;
    delete [] R;
    delete [] Q;
    QCoreApplication a(argc, argv);

    return a.exec();
}
