#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Structure of the node*/
struct node
{
  char name[100];
  struct node *left;
  struct node *right;

};

/*Structure of the Insertion*/
struct node *insert(struct node *root, char name[]){
 if ( root == NULL ){

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

/*Search Structure*/
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


/*part of the delete method using the successor*/

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
/*Delete Structure*/

struct node *delete(struct node *root, char key[]){
    if (root==NULL) return NULL;

    if (strcmp(key, root ->name)>0){
      root->right=delete(root->right,key);
    }
    else if (strcmp(key, root ->name)<0){
      root->left=delete(root->left,key);
    }
    else {

        if (root->left==NULL && root->right==NULL){
          return NULL;
        }
        else if (root->left==NULL || root->right==NULL){//
            if (root->left==NULL) return root->right;
            else return root->left;
        }
        else {/*if both childs are present;*/
            del_using_successor(root);

        }
    }

    return root;
}



/*Display Structure of the Employee BST*/
  void printInorder(struct node *root)
  {
    if(root == NULL)
    return;
    else{
    printInorder(root -> left);
    printf("%s",root -> name);
    printf("\n");
    printInorder(root -> right);
    }
  }

  void printPreorder(struct node *root)
  {
    if(root == NULL)
    return;

    else{
    printf("%s",root -> name);
    printf("\n");
    printPreorder(root -> left);
    printPreorder(root -> right);
    }
  }

  void printPostorder(struct node *root)
  {
    if(root == NULL)
    return;

    else{

    printPostorder(root -> left);
    printPostorder(root -> right);
    printf("%s",root -> name);
    printf("\n");
  }

}
