#include <iostream>
using namespace std;
class st
{
    int roll, marks;
    string name;
    public:
    void read(st a[],int n);
    void dis(st a[],int n);
    void in_sort(st a[],int n);
    void shellsort(st arr[],int n);

};
void st:: read(st a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the roll of the student:"<<(i+1)<<":";
        cin>>a[i].roll;
        cout<<"Enter the name of the student:"<<(i+1)<<":";
        cin>>a[i].name;
        cout<<"Enter the marks of the student:"<<(i+1)<<":";
        cin>>a[i].marks;

    }
}
void st:: dis(st a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i].roll<<" ";
        cout<<a[i].name<<" ";
        cout<<a[i].marks<<" ";
        cout<<endl;

    }
}

void st:: in_sort(st a[],int n)
{
    for(int i=1;i<n;i++)
    {
       int j=i-1;
        st val;
        val=a[i];
        while(j>=0 && a[j].roll>val.roll)
        {
            a[j+1]=a[j];//shift
            j--;
        }
        a[j+1]=val; 
    }
    for (int i=0;i<n;i++)
    {
        cout<<a[i].roll<<" ";
        cout<<a[i].name<<" ";
        cout<<a[i].marks<<" ";
        cout<<endl;

    }
   
}
void st:: shellsort(st arr[],int n)
{
   int gap=n/2;

   while(gap>=1)
   {
    for(int j=gap;j<n;j++)
    {
        for(int i=j-gap;i>=0;i=i-gap)
        {
            if(arr[i].name>arr[i+gap].name)
            {
                //swaping//
                st temp;
                temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
            }
            else
            {
                break;
            }
        }
    }
    gap=gap/2;
   }
   for (int i=0;i<n;i++)
    {
        cout<<arr[i].roll<<" ";
        cout<<arr[i].name<<" ";
        cout<<arr[i].marks<<" ";
        cout<<endl;

    }
}

int main()
{
    int n;
    cout<<"Enter the number of students:";
    cin>>n;

    st s[n], x;
    int k;
do
{
    cout<<"Enter the choice:::"<<endl;
    cout<<"1.Enter record"<<endl ;
    cout<< "2.Display Record:"<<endl;
    cout<<"3.Assending order using insertion sort: "<<endl;
    cout<<"4.Assending order using shell sort: "<<endl;
    cout<<"5. Exit."<<endl;
    cin>>k;
    switch (k)
    {
    case 1:
        x.read(s,n);
        break;
    case 2:
       x.dis(s,n);
        break;
    case 3:
        x.in_sort(s,n);
        break;
    case 4:
        x.shellsort(s,n);
        break;   
    
    default:
        cout<<"----!!!!You don't enter the right option!!!!!---";
        break;
    }  
} while (k<=4);

    
    return 0;
}
