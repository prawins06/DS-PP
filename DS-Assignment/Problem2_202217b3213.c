#include <stdio.h>

// Structure to represent a single term of a polynomial
struct poly {
    int coeff;  // Coefficient of the term
    int expo;   // Exponent of the term
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[10], p2[10], p3[10];
    int t1, t2, t3;

    // Read and display first polynomial (p1)
    printf("Enter the first polynomial:\n");
    t1 = readPoly(p1);
    printf("First polynomial: ");
    displayPoly(p1, t1);

    // Read and display second polynomial (p2)
    printf("\nEnter the second polynomial:\n");
    t2 = readPoly(p2);
    printf("Second polynomial: ");
    displayPoly(p2, t2);

    // Add two polynomials (p1 and p2) and display result (p3)
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

// Function to read polynomial terms into an array of structures
int readPoly(struct poly p[10]) {
    int terms, i;

    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &terms);

    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER:\n");
    for (i = 0; i < terms; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the Exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }

    return terms;  // Return number of terms read
}

// Function to add two polynomials and store the result in another polynomial
int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // Copy remaining terms of polynomial 1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms of polynomial 2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k;  // Return number of terms in resultant polynomial p3
}

// Function to display polynomial terms stored in an array of structures
void displayPoly(struct poly p[10], int terms) {
    int i;

    for (i = 0; i < terms - 1; i++) {
        printf("%d(x^%d) + ", p[i].coeff, p[i].expo);
    }
    printf("%d(x^%d)\n", p[terms - 1].coeff, p[terms - 1].expo);
}
