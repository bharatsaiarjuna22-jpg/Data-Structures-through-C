#include <stdio.h>
#include <stdlib.h>
// Define the structure for a polynomial term
struct Term {
    int coeff;
    int exp;
    struct Term *next;
};
// Create a new term node
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*) malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}
// Append a term to the end of the polynomial
void appendTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*head == NULL) {
        *head = newTerm;
    } else {
        struct Term* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
// Add two polynomials and return the result
struct Term* addPolynomials(struct Term* p1, struct Term* p2) {
    struct Term* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            appendTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            appendTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                appendTerm(&result, sum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    // Append remaining terms
    while (p1 != NULL) {
        appendTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        appendTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
// Display the polynomial
void display(struct Term* head) {
    struct Term* term = head;
    while (term != NULL) {
        printf("%dx^%d", term->coeff, term->exp);
        if (term->next != NULL) printf(" + ");
        term = term->next;
    }
    printf("\n");
}
// Main function to demonstrate polynomial addition
int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *sum = NULL;
    //Polynomial 1:
    appendTerm(&poly1, 8, 7);
    appendTerm(&poly1, 2, 3);
    //Polynomial 2:
    appendTerm(&poly2, 6, 7);
    appendTerm(&poly2, 5, 3);
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);
    return 0;
}

