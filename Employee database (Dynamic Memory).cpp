#include <iostream>
#include <string>
using namespace std;

class Emp {
public:
    int id, salary;
    string name;  
    
    void quickSort(Emp *p[], int l, int r);
    int partition(Emp *p[], int l, int r);
    
    void mergeSort(Emp *p[], int l, int r);
    void merge(Emp *p[], int l, int m, int r);

    void print(Emp *p[], int i) {
        for (int j = 0; j < i; j++) {
            cout << "Employee [" << j + 1 << "] id: " << p[j]->id << endl;
            cout << "Employee [" << j + 1 << "] name: " << p[j]->name << endl;
            cout << "Employee [" << j + 1 << "] salary: " << p[j]->salary << endl;
        }
    }

    void swap(Emp *p[], int i, int j) {
        Emp* temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
};

int Emp::partition(Emp *p[], int l, int r) {
    int pivot = p[r]->id;
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (p[j]->id < pivot) {
            i++;
            swap(p, i, j);
        }
    }
    swap(p, i + 1, r);
    return i + 1;
}

void Emp::quickSort(Emp *p[], int l, int r) {
    if (l < r) {
        int pi = partition(p, l, r);
        quickSort(p, l, pi - 1);
        quickSort(p, pi + 1, r);
    }
}

void Emp::merge(Emp *p[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    Emp *L[n1], *R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = p[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i]->name <= R[j]->name) {
            p[k] = L[i];
            i++;
        } else {
            p[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        p[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        p[k] = R[j];
        j++;
        k++;
    }
}

void Emp::mergeSort(Emp *p[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(p, l, m);
        mergeSort(p, m + 1, r);
        merge(p, l, m, r);
    }
}

int main() {
    Emp *p[100];
    int i = 0;
    int k;
    Emp x;
    
    do {
        cout << "Enter the choice:::" << endl;
        cout << "1. Enter record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Ascending order by ID using quick sort" << endl;
        cout << "4. Ascending order by name using merge sort" << endl;
        cout << "5. Exit" << endl;
        cin >> k;
        
        switch (k) {
            case 1: {
                int n;
                do {
                    p[i] = new Emp;
                    cout << "Enter the Employee [" << i + 1 << "] id: " << endl;
                    cin >> p[i]->id;
                    cout << "Enter the Employee [" << i + 1 << "] name: " << endl;
                    cin >> p[i]->name;
                    cout << "Enter the Employee [" << i + 1 << "] salary: " << endl;
                    cin >> p[i]->salary;
                    i++;
                    cout << "Do you want to continue: (press [1] for [yes]....[0] for [No])";
                    cin >> n;
                } while (n == 1);
                break;
            }
            
            case 2:
                x.print(p, i);
                break;
            
            case 3:
                x.quickSort(p, 0, i - 1);
                x.print(p, i);
                break;
                
            case 4:
                x.mergeSort(p, 0, i - 1);
                x.print(p, i);
                break;
                
            case 5:
                cout << "You are exiting now" << endl;
                break;
            
            default:
                cout << "Your choice is invalid" << endl;
                break;
        }
    } while (k != 5);

    // Clean up memory
    for (int j = 0; j < i; j++) {
        delete p[j];
    }

    return 0;
}
