#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
    char book_name[100];
    char author_name[100];
    char book_issued_date[20];
};

void displayBook(struct library *b)
{
    printf("\n************************************");
    printf(" \nBook Name : %s ", b->book_name);
    printf(" \nAuthor Name : %s ", b->author_name);
    printf(" \nIssued date : %s ", b->book_issued_date);
}

int main()
{
    struct library book[100];
    char author_search[100];
    int i, j, s, count;
    i = 0;
    j = 0;
    s = 0;
    count = 0;

    FILE *file;

    
    file = fopen("library.rec", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%99[^\n]%*c%99[^\n]%*c%19[^\n]%*c", book[i].book_name, book[i].author_name, book[i].book_issued_date) == 3)
        {
            i++;
            count++;
        }
        fclose(file);
    }

    while (j != 6)
    {
    	printf("\n___________________________________________________________");
        printf("\n*******Welcome to the library Management System********\n");
        printf(" \n\n  1. Add Records of the book\n ");
        printf(" 2. Display the Records of the books \n ");
        printf(" 3. Search for the books \n ");
        printf(" 4. Update the Records of the books \n ");
        printf(" 5. Exit\n\n");
        printf("\n______________________________________________________________");
        printf("\n Enter the number: ");
        scanf("%d", &j);
       

        switch (j)
        {
        case 1:
            printf(" \nYou can add the Records of the book ");
            printf(" \nEnter the book name: ");
            getchar(); 
            fgets(book[i].book_name, sizeof(book[i].book_name), stdin);
            book[i].book_name[strcspn(book[i].book_name, "\n")] = '\0'; 
            printf(" \nEnter the author name: ");
            scanf(" %[^\n]s", book[i].author_name);
            printf(" \nEnter the issued date: ");
            scanf(" %s", book[i].book_issued_date);
            printf("Records Added Successfully!!!");
            printf("\n------------------------------------------");
            count = count + 1;
            i = i + 1;
            break;

        case 2:
            if (count == 0)
            {
                printf(" \nThere are no books stored!!\n\n ");
            }
            else
            {
                printf(" \nYou can view the list of books ");
                printf(" \nThe list of books are: ");
                for (i = 0; i < count; i++)
                {
                    displayBook(&book[i]);
                }
            }
            break;

        case 3:
            printf("\nEnter the name of the author of the book:");
            scanf(" %[^\n]s", author_search);
            for (s = 0; s < count; s++)
            {
                if (!(strcmp(author_search, book[s].author_name)))
                {
                    printf("\nBook found successfully!!!!");
                    displayBook(&book[s]);
                    break;
                }
            }
            if (s == count)
            {
                printf("\nSorry, There is no book having author name:  %s  .", author_search);
                printf("\nPlease check the spelling else add the book.");
                printf("\n----------------------------------------------------");
            }
            break;

        case 4:
            printf("\nEnter the name of the author of the book which you want to update:");
            scanf(" %[^\n]s", author_search);
            for (s = 0; s < count; s++)
            {
                if (!(strcmp(author_search, book[s].author_name)))
                {
                    printf("\nBook found successfully!!!!");
                    printf("\nEnter the updated name of the %s whose author is %s:", book[s].book_name, author_search);
                    getchar(); 
                    fgets(book[s].book_name, sizeof(book[s].book_name), stdin);
                    book[s].book_name[strcspn(book[s].book_name, "\n")] = '\0'; 
                    printf("\nUpdated Successfully!!!");
                    printf("\n---------------------------------------------------");
                    break;
                }
            }
            if (s == count)
            {
                printf("\nSorry, There is no book having author name:  %s  .", author_search);
                printf("\nPlease check the spelling else add the book.");
                printf("\n--------------------------------------------------------");
            }
            break;

        case 5:
            
            file = fopen("library.rec", "w");
            if (file != NULL)
            {
                for (s = 0; s < count; s++)
                {
                    fprintf(file, "%s\n%s\n%s\n", book[s].book_name, book[s].author_name, book[s].book_issued_date);
                }
                fclose(file);
            }
            printf("\n Thank you for using this program. Have a good day.");
            exit(0);

        default:
            printf(" \nInvalid number entered\n\n ");
        }
    }

    return 0;
}



