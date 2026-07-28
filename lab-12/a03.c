#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char str[100];
    struct node *lptr;
    struct node *rptr;
};

struct node *First = NULL, *Last = NULL, *save = NULL;

void addSong()
{
    struct node *new;

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter Song Name: ");
    getchar();
    gets(new->str);

    new->lptr = NULL;
    new->rptr = NULL;

    if (First == NULL)
    {
        First = Last = new;
    }
    else
    {
        Last->rptr = new;
        new->lptr = Last;
        Last = new;
    }

    if (save == NULL)
        save = First;
}

void display()
{
    struct node *temp = First;

    if (First == NULL)
    {
        printf("Playlist is Empty.");
        return;
    }

    printf("Playlist:\n");
    while (temp != NULL)
    {
        printf("%s\n", temp->str);
        temp = temp->rptr;
    }
}

void playCurrent()
{
    if (save == NULL)
        printf("No Song Available.");
    else
        printf("Now Playing : %s", save->str);
}

void nextSong()
{
    if (save == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    if (save->rptr != NULL)
    {
        save = save->rptr;
        printf("Now Playing : %s", save->str);
    }
    else
        printf("Last Song Reached.");
}

void previousSong()
{
    if (save == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    if (save->lptr != NULL)
    {
        save = save->lptr;
        printf("Now Playing : %s", save->str);
    }
    else
        printf("This is First Song.");
}

void deleteSong()
{
    char name[100];
    struct node *temp;

    if (First == NULL)
    {
        printf("Playlist Empty.");
        return;
    }

    printf("Enter Song Name to Delete: ");
    getchar();
    gets(name);

    temp = First;

    while (temp != NULL)
    {
        if (strcmp(temp->str, name) == 0)
        {
            if (temp == First)
            {
                First = First->rptr;
                if (First != NULL)
                    First->lptr = NULL;
            }
            else
                temp->lptr->rptr = temp->rptr;

            if (temp == Last)
            {
                Last = temp->lptr;
                if (Last != NULL)
                    Last->rptr = NULL;
            }
            else if (temp->rptr != NULL)
                temp->rptr->lptr = temp->lptr;

            if (save == temp)
                save = First;

            free(temp);
            printf("Song Deleted Successfully.");
            return;
        }
        temp = temp->rptr;
    }

    printf("Song Not Found.");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Add Song");
        printf("\n2. Display Playlist");
        printf("\n3. Play Current Song");
        printf("\n4. Next Song");
        printf("\n5. Previous Song");
        printf("\n6. Delete Song");
        printf("\n7. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong();
            break;

        case 2:
            display();
            break;

        case 3:
            playCurrent();
            break;

        case 4:
            nextSong();
            break;

        case 5:
            previousSong();
            break;

        case 6:
            deleteSong();
            break;

        case 7:
            printf("Thank You!");
            break;

        default:
            printf("Invalid Choice.");
        }
    } while (choice != 7);

    return 0;
}