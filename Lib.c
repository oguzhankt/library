#include <stdio.h>
#include <stdlib.h>

/// The data structure of a book which has name, author, pages.
struct books{
    char name[25];
    char author[25];
    int pages;
};

/// The main method
void main(){
    menu();
}

/// Prints a straight line for separation
void pline(){
    printf("----------------------------------------------\n");
}

/// This is the starting function
void menu(){
    /// Prints a menu for user
    int ans;
    printf("Welcome to the Library...\n");
    printf("1) Search books\n");
    printf("2) List all books\n");
    printf("3) Add books\n");
    printf("4) How to use\n");
    printf("5) Exit\n");
    scanf(" %d", &ans);

    switch(ans)
    {
        case(1):{
        //search();
        break;
        }
        case(2):{
        listAll();
        break;
        }
        case(3):{
        addBooks();
        break;
        }
        case(4):{
        printInstructions();
        break;
        }
        case(5):{
        exit(31);
        break;
        }
        default:{
            /// This helps to achieve some kind of Data Integrity with user input
            printf("You have entered an invalid value please try again...\n");
            returnMenu();
        }
    }
}

/// This returns the user to main menu
void returnMenu(){
    printf("Press enter to return to menu\n");
    getchar(); // These are required to catch the newline before the main
    getchar(); //
    menu();
}

/// Prints some basic instructions then returns to main menu
void printInstructions(){
    printf("Instruction\n");
    returnMenu();
}

/// Adds a book to the library and then asks the user if they want to add another
void addBooks(){
    char ans = "e";
    char name[25];
    char author[25];
    int pages, bookNum, ctr;
    FILE *file;
    file = fopen("Library.txt", "a");
    printf("How many books ?\n");
    scanf(" %d", &bookNum);
    getchar();
    struct books * book[bookNum];
    printf("Press enter to start adding books...\n");
    getchar();
    pline();
    for (ctr = 0; ctr < bookNum; ctr++)
    {
        fprintf(file, "%d\n", ctr+1);
        book[ctr] = (struct books*)malloc(sizeof(struct books));
        printf("What is the name of the book # %d ?\n", ctr+1);
        gets(book[ctr]->name);
        fprintf(file, "%s\n", book[ctr]->name);
        printf("What is the author of the book # %d ?\n", ctr+1);
        gets(book[ctr]->author);
        fprintf(file, "%s\n", book[ctr]->author);
        printf("How many pages is the book # %d ?\n", ctr+1);
        scanf(" %d", &book[ctr]->pages);
        fprintf(file, "%d\n", book[ctr]->pages);
        getchar();
        pline();
        fprintf(file, "-\n");
    }

    fclose(file);
    returnMenu();
}

/// Lists all book in the file "Library.txt"
void listAll(){
    FILE *file;
    file = fopen("Library.txt", "r");
    char books[99];
    printf("%s", books);
}
