#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char name[50];
  int choice,n,temp;
  struct node *root=NULL;
  char cont[5];

  /*Structure of the Employee BST*/
  do{
      printf("\n Enter your choice");
      printf("\n Enter 1 to Add name");
      printf("\n Enter 2 to Delete name");
      printf("\n Enter 3 to Search name");
      printf("\n Enter 4 to Display name");
      printf("\n Enter 5 to Exit name");
      scanf("%d", &choice);

      switch(choice){
        case 1 : printf("** Insert the name of the employee to be add**");/* Insertion case*/
        do{
          printf("Enter the name: ");
          scanf("%s",name);
          root=insert(root,name);

          printf("Do you want to add more name [yes/no]: \n");
          scanf("%s", cont);

        }while(*cont == 'y');
        break;


        case 2 : printf("** enter the name of the employee to be delete**\n"); /*Deletion case*/
          printf("Enter a name: ");
          scanf("%s",name);
          root=delete(root,name);
          break;

        case 3: printf("Do you want to search any employee in the list? : \n"); /*Search case*/
            printf("Enter a name: ");
            scanf("%s",name);
            temp=search(root,name);
            if (temp==0) printf("Not Found\n");
            else printf("Found\n");

            break;

        case 4:  /*Display case*/
        do{
          printf("How do you want to display your employee list: \n");

          printf("enter your choice: ");

            /*Here is three cases to display the employee name */
          printf("Enter 1. to display by In order");
          printf("Enter 2. to display by Pre order");
          printf("Enter 3. to display by Post order");


          scanf("%d", &n);

          switch(n){
            case 1: printf("InOrder Display");
            printInorder(root);
            break;
            case 2: printf("Preorder Display");
            printPreorder(root);
            break;
            case 3: printf("post Order Display");
            printPostorder(root);
            break;

            default:
            printInorder(root);
        }
        }while(n !=3);
        break;
      }
  }while(choice !=5);

}
