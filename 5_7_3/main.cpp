#include <QCoreApplication>
#include <math.h>
#include <iostream>;
using namespace std;


bool prostoe(int N)
{
    int i; bool pr;
    for (pr=true,i=2;i<=N/2;i++)
        if (N%i==0) {pr=false; break;}
    return (pr);
}


bool vozr(int n)
{
    bool fl=true;
  while ((n>=10) && (fl==true))
  {
      if ((n%10)>(n/10%10))
          n=n/10;
      else
          fl=false;
  }
  return fl;
}

bool check(int n)
{
    if (prostoe(n) && vozr(n))
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    int *X, n, i, j, group1_index1, group1_k, group2_index1, group2_k;
    bool group1_start=false;
    bool group2_start=false;
    bool group1_end=false;
    bool group2_end=false;
    group1_k=1;
    group2_k=1;
    cout<<"Input size of X array ";
    cin>>n;
    X=new int [n];
    cout<<"Input X array"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<"X["<<i<<"]=";
        cin>>X[i];
    }
    for (i=(n-1); i>0; i--)
    {
        if (group1_start==false && group1_end==false && check(X[i]) && check(X[i-1]))
        {
            group1_index1=i;
            group1_start=true;
        }
        else if (group2_start==false && group2_end==false && group1_start==true && group1_end==true && check(X[i]) && check(X[i-1]))
        {
            group2_index1=i;
            group2_start=true;
        }

        if (check(X[i-1])) {
            if (group1_start==true && group1_end==false)
                group1_k++;
            else if (group2_start==true && group1_end==true && group2_end==false)
                group2_k++;
        }
        else
            if (group1_start==true && group2_start==false)
              group1_end=true;
            else
                if (group1_end==true && group2_start==true && group2_end==false)
                    group2_end=true;
        if (group1_end==true && group2_end==true)
            break;


    }
   // cout<<"group1_index1="<<group1_index1<<"\tgroup1_k="<<group1_k<<"\tgroup2_index1="<<group2_index1<<"\tgroup2_k="<<group2_k<<endl;
    if (group1_end==true && group2_end==true) {
    cout<<"Last group:"<<endl;
    for (i=group1_index1-group1_k+1, j=0; j<group1_k; j++,i++)
        cout<<X[i]<<"\t";

    cout<<"\nPenultimate group:"<<endl;
    for (i=group2_index1-group2_k+1,j=0; j<group2_k; j++, i++)
        cout<<X[i]<<"\t";
    }
    else cout<<"\nLess than 2 groups found";


    QCoreApplication a(argc, argv);

    return a.exec();
}
