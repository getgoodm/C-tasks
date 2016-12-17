#include <QCoreApplication>
#include <math.h>
#include <iostream>;
#include <iomanip>
using namespace std;
int SLAU(double **matrix_a, int n, double *massiv_b, double *x)
{
    int i,j,k,r;
    double c, M, max, s;
    double **a, *b;
    a=new double *[n];
    for (i=0;i<n;i++)
        a[i]=new double [n];
    b=new double [n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            a[i][j]=matrix_a[i][j];
    for (i=0;i<n;i++)
         b[i]=massiv_b[i];
    for (k=0;k<n;k++)
    {
        max=fabs(a[k][k]);
        r=k;
        for (i=k+1;i<n;i++)
            if (fabs(a[i][k])>max)
            {
                max=fabs(a[i][k]);
                r=i;
            }
        for (j=0;j<n;j++)
        {
            c=a[k][j];
                    a[k][j]=a[r][j];
                    a[r][j]=c;
        }
        c=b[k];
        b[k]=b[r];
        b[r]=c;
        for (i=k+1;i<n;i++)
    {
            for (M=a[i][k]/a[k][k],j=k;j<n;j++)
                a[i][j]-=M*a[k][j];
            b[i]-=M*b[k];
     }
    }
    if (a[n-1][n-1]==0)
        if (b[n-1]==0)
            return -1;
    else return -2;
    else
    {
        for (i=n-1;i>=0;i--)
        {
            for (s=0, j=i+1; j<n;j++)
                s+=a[i][j]*x[j];
            x[i]=(b[i]-s)/a[i][i];
        }
        return 0;
    }
    for (i=0; i<n; i++)
        delete [] a[i];
        delete[] a;
    delete [] b;
}

int inverse(double **a, int n, double **y)
{
    int i,j,res;
    double *b, *x;
    b=new double [n];
    x=new double [n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            if (j==i)
                b[j]=1;
        else b[j]=0;
        res=SLAU(a,n,b,x);
        if (res!=0)
            break;
        else
            for (j=0;j<n;j++)
                y[j][i]=x[j];
    }
    if (res!=0)
        return -1;
    else
        return 0;
}
double **product_m(double **A, double **B, int N, int M, int L)
{
    int i,j,k;
    double **temp;
    temp=new double *[N];
    for (i=0;i<N;i++)
        temp[i]=new double [L];
    for (i=0;i<N;i++)
        for (j=0;j<L;j++)
            for (temp[i][j]=k=0;k<M;k++)
                temp[i][j]+=A[i][k]*B[k][j];
    return temp;
}

int main(int argc, char *argv[])
{
    int i,j, result;
    bool equal=true;
    double **A2,**b, **proizv;
    b=new double *[4];
    for (i=0;i<4;i++)
        b[i]=new double[4];
    double A1[4][4]={{1, 0.42, 0.54, 0.66}, {0.42, 1, 0.32, 0.44}, {0.54, 0.32, 1, 0.22}, {0.66, 0.44, 0.22, 1}};
    A2=new double *[4];
    for (i=0;i<4;i++)
        A2[i]=new double [4];
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            A2[i][j]=A1[i][j];
    double A_t[4][4];
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
        {
            A_t[i][j]=A1[j][i];
        }
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            if (A_t[i][j]!=A1[j][i]){
                equal=false;
                break;
            }

    if (equal) cout<<"A_t = A"<<endl;
    result=inverse(A2,4,b);
    if (result==0)
    {
        cout<<"Inverse matrix:"<<endl;
        for (i=0;i<4;cout<<endl,i++)
            for (j=0;j<4;j++)
                cout<<b[i][j]<<"\t";
    }
cout<<endl;

proizv=product_m(A2,b,4,4,4);
cout<<"Matrix multiplication:"<<endl;
for (i=0;i<4;cout<<endl, i++)
    for (j=0;j<4;j++)
        cout<<fixed<<setprecision(0)<<fabs(proizv[i][j])<<"\t";


    QCoreApplication a(argc, argv);

    return a.exec();
}
