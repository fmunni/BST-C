#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
  char name[100];
  struct node *left;
  struct node *right;

};


struct node *insert(struct node *root, char name[]){
 if ( root == NULL ){
  //struct node *new_node = malloc(sizeof(struct node));

    root=malloc(sizeof(struct node));
    root->left=NULL;
    root->right=NULL;
    strcpy(root->name,name);
  }
  else if(strcmp(name, root ->name)>0){
    root->right=insert(root->right,name);
  }
  else {
    root->left=insert(root->left,name);
  }
  return root;
}

//search
int search(struct node *root, char key[]){
 if ( root == NULL ){
    return 0;
  }
  else if (strcmp(key, root ->name)==0)
    return 1;
  else if(strcmp(key, root ->name)>0){
    return search(root->right,key);
  }
  else {
    return search(root->left,key);
  }

}


//deletion
//root=delete(root,key);

void del_using_successor(struct node *root){
    struct node *p=root;
    struct node *cur=root->right;

    if (cur->left==NULL && cur->right==NULL){
      strcpy(root->name,cur->name);
      root->right=NULL;
      return;
    }


    while(cur->left!=NULL){
      p=cur;
      cur=cur->left;
    }
    strcpy(root->name,cur->name);
    if (cur->right==NULL)
        p->left=NULL;
    else {
      p->left=cur->right;
    }

}


struct node *delete(struct node *root, char key[]){
    if (root==NULL) return NULL;

    if (strcmp(key, root ->name)>0){
      root->right=delete(root->right,key);
    }
    else if (strcmp(key, root ->name)<0){
      root->left=delete(root->left,key);
    }
    else {
        //
        if (root->left==NULL && root->right==NULL){
          return NULL;
        }
        else if (root->left==NULL || root->right==NULL){//
            if (root->left==NULL) return root->right;
            else return root->left;
        }
        else {//both childs are present;
            del_using_successor(root);

        }
    }

    return root;
}



//Display of the Employee BST
  void printInorder(struct node *root){
    if(root == NULL)
    return;
    else{
    printInorder(root -> left);
    printf("%s",root -> name);
    printf("\n");
    printInorder(root -> right);
    }
  }

  void printPreorder(struct node *root){
    if(root == NULL)
    return;

    else{
    printf("%s",root -> name);
    printf("\n");
    printPreorder(root -> left);
    printPreorder(root -> right);
    }
  }

  void printPostorder(struct node *root){
    if(root == NULL)
    return;

    else{

    printPostorder(root -> left);
    printPostorder(root -> right);
    printf("%s",root -> name);
    printf("\n");
  }

}


int main(){
  char name[50];
  int choice,n,temp;
  struct node *root=NULL;

  //
  char cont[5];

  //Structure of the Employee BST
  do{
      printf("\n Enter your choice");
      printf("\n Enter 1 to Add name");
      printf("\n Enter 2 to Delete name");
      printf("\n Enter 3 to Search name");
      printf("\n Enter 4 to Display name");
      printf("\n Enter 5 to Exit name");
      scanf("%d", &choice);

      switch(choice){
        case 1 : printf("** Insert the name of the employee to be add**");
        do{
          printf("Enter the name: ");
          scanf("%s",name);
          root=insert(root,name);

          printf("Do you want to add more name [yes/no]: \n");
          scanf("%s", cont);

        }while(*cont == 'y');
        break;


        case 2 : printf("** enter the name of the employee to be delete**\n");
          printf("Enter a name: ");
          scanf("%s",name);
          root=delete(root,name);
          break;

        case 3: printf("Do you want to search any employee in the list? : \n");
            printf("Enter a name: ");
            scanf("%s",name);
            temp=search(root,name);
            if (temp==0) printf("Not Found\n");
            else printf("Found\n");

            break;

        case 4:
        do{
          printf("How do you want to display your employee list: \n");

          printf("enter your choice: ");

          //
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
