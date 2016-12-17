#include <QCoreApplication>
#include <iostream>;
using namespace std;
int L;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Input L"<<endl;
    cin>>L;
    cout<<L/1000<<" km "<<L%1000<<" m";
    return a.exec();
}
