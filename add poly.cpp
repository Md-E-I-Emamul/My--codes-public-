#include <iostream>
using namespace std;

// Class to represent a single node in the polynomial
class node {
public:
    int coeff;
    int pow;
    node* next;
    
    // Constructor
    node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Class to represent the polynomial
class Polynomial {
private:
    node* head;

public:
    // Constructor
    Polynomial() : head(nullptr) {}

    // Function to insert a term into the polynomial
    void insertTerm(int coeff, int pow) {
        node* nn = new node(coeff, pow);
        if (!head || head->pow < pow) {
            nn->next = head;
            head = nn;
        } else {
            node* temp = head;
            while (temp->next && temp->next->pow > pow)
                temp = temp->next;

            if (temp->pow == pow) {
                temp->coeff += coeff;
            } else {
                nn->next = temp->next;
                temp->next = nn;
            }
        }
    }

    // Function to add two polynomials
    Polynomial addPolynomials(Polynomial& poly2) {
        Polynomial result;
        node* poly1node = this->head;
        node* poly2node = poly2.head;

        while (poly1node && poly2node) {
            if (poly1node->pow == poly2node->pow) {
                result.insertTerm(poly1node->coeff + poly2node->coeff, poly1node->pow);
                poly1node = poly1node->next;
                poly2node = poly2node->next;
            } else if (poly1node->pow > poly2node->pow) {
                result.insertTerm(poly1node->coeff, poly1node->pow);
                poly1node = poly1node->next;
            } else {
                result.insertTerm(poly2node->coeff, poly2node->pow);
                poly2node = poly2node->next;
            }
        }

        // If poly1 has remaining terms
        while (poly1node) {
            result.insertTerm(poly1node->coeff, poly1node->pow);
            poly1node = poly1node->next;
        }

        // If poly2 has remaining terms
        while (poly2node) {
            result.insertTerm(poly2node->coeff, poly2node->pow);
            poly2node = poly2node->next;
        }

        return result;
    }

    // Function to print the polynomial
    void printPolynomial() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->coeff << "x^" << temp->pow;
            temp = temp->next;
            if (temp != nullptr && temp->coeff >= 0)
                cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    // Creating first polynomial: 3x^3 + 4x^2 + 5x^1
    poly1.insertTerm(3, 3);
    poly1.insertTerm(4, 2);
    poly1.insertTerm(5, 1);

    // Creating second polynomial: 5x^2 + 6x^1 + 7x^0
    poly2.insertTerm(5, 2);
    poly2.insertTerm(6, 1);
    poly2.insertTerm(7, 0);

    cout << "First Polynomial: ";
    poly1.printPolynomial();

    cout << "Second Polynomial: ";
    poly2.printPolynomial();

    // Add the two polynomials
    Polynomial sum = poly1.addPolynomials(poly2);

    cout << "Sum of Polynomials: ";
    sum.printPolynomial();

    return 0;
}
