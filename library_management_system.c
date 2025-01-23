#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char name[20];
    char author[20];
    int p_year;
};

int main() {
    int c, i = 0, j;
    char name[20];
    struct book array[1000];
    int book_count = 0; 
    do {
        printf("\nPlz select the task you want to perform -\n");
        printf("1. Add a book to the library\n");
        printf("2. Search for a book\n");
        printf("3. Remove a book from the library\n");
        printf("4. View existing books in the library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        getchar(); 

        switch (c) {
            case 1: {
                printf("Enter the name of the book: ");
                fgets(array[book_count].name, 20, stdin);
                array[book_count].name[strcspn(array[book_count].name, "\n")] = '\0'; 

                printf("Enter the author's name: ");
                fgets(array[book_count].author, 20, stdin);
                array[book_count].author[strcspn(array[book_count].author, "\n")] = '\0';

                printf("Enter the year of publication: ");
                scanf("%d", &array[book_count].p_year);
                getchar();  

                book_count++;
                printf("Book added successfully!\n");
                break;
            }
            case 2: {
                printf("Enter the book's name to search: ");
                fgets(name, 20, stdin);
                name[strcspn(name, "\n")] = '\0';  
                
                int found = 0;
                for (i = 0; i < book_count; i++) {
                    if (strcmp(array[i].name, name) == 0) {
                        printf("Book found!\n");
                        printf("Title: %s\n", array[i].name);
                        printf("Author's Name: %s\n", array[i].author);
                        printf("Year of Publication: %d\n", array[i].p_year);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found in the library.\n");
                }
                break;
            }
            case 3: {
                printf("Enter the book's name to remove: ");
                fgets(name, 20, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                int found = 0;
                for (i = 0; i < book_count; i++) {
                    if (strcmp(array[i].name, name) == 0) {
                        found = 1;
                        // Shift all subsequent books up
                        for (j = i; j < book_count - 1; j++) {
                            array[j] = array[j + 1];
                        }
                        book_count--;
                        printf("Book removed successfully!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found in the library.\n");
                }
                break;
            }
            case 4: {
                if (book_count == 0) {
                    printf("The library is empty.\n");
                } else {
                    printf("Books in the library:\n");
                    for (i = 0; i < book_count; i++) {
                        printf("Title: %s, Author: %s, Year: %d\n",
                               array[i].name, array[i].author, array[i].p_year);
                    }
                }
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
