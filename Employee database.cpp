#include <iostream>
using namespace std;
class Emp
{
    int id ,salary;
    string name;
    public:
    
    void collect(Emp a[],int n);
    void show(Emp a[],int n);
    void order(Emp a[],int n);

};

void Emp :: collect (Emp a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the employee ["<<i+1<<"] id:";
        cin>>a[i].id;
        cout<<"Enter the employee ["<<i+1<<"] name:";
        cin>>a[i].name;
        cout<<"Enter the employee ["<<i+1<<"] salary:";
        cin>>a[i].salary;
        
    }
}
void Emp :: show (Emp a[],int n)
{
    for(int i=0;i<n;i++)
    {
        
        cout<<a[i].id
        
    }
}
void Emp :: order (Emp a[],int n)
{
    
}


int main()
{
    int n;
    cout<<"Enter the number of the Employee: ";
    cin>>n;

    Emp a[n], x;

    int k;
    do
    {
    cout<<"Enter the choice:::"<<endl;
    cout<<"1.Enter record"<<endl ;
    cout<< "2.Display Record:"<<endl;
    cout<<"3.Assending order using quick sort: "<<endl;
    cout<<"4. Exit."<<endl;
    cin>>k;
        switch (k)
        {
            case 1:
                x.collect(a,n);
                break;
            case 2:
                x.show(a,n);
                break;
            case 3:
                x.order(a,n);
                break;
        
    
        default:
         break;
        }
    } while (/* condition */);
    
}
