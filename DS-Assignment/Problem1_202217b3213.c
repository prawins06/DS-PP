#include <stdio.h>
#include <conio.h> // Assuming conio.h is needed for getch()

#define MAX 20 // Increased to 20 as your array size

// Function prototypes
void create();
void deletion();
void search();
void insert();
void display();

int b[MAX], n, pos, e, i;

int main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display \n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf(" \n Enter the correct choice: ");
        }

        printf("\n Do you want to continue (y/n): ");
        scanf(" %c", &g);
    } while(g == 'y' || g == 'Y');
    
    getch(); // Waits for a character input before exiting
    return 0;
}

void create() {
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("\n Enter the elements:\n");
    for(i = 0; i < n; i++) {
        printf(" Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    if(pos >= n) {
        printf("\n Invalid Location!");
    } else {
        for(i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    
    printf("\n The Elements after deletion: ");
    display();
}

void search() {
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);
    
    int f = 0; // Flag to track if element is found
    
    for(i = 0; i < n; i++) {
        if(b[i] == e) {
            printf(" Value is at position %d.\n", i);
            f = 1;
            break;
        }
    }
    
    if(f == 0) {
        printf(" Value %d is not in the list.\n", e);
    }
}

void insert() {
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    
    if(pos > n) {
        printf("\n Invalid Location!");
    } else {
        printf("\n Enter the element to insert: ");
        scanf("%d", &b[pos - 1]);
        n++;
    }
    
    printf("\n The list after insertion:\n");
    display();
}

void display() {
    printf("\n The Elements of The list ADT are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
