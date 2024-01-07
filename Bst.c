#include <stdio.h>
#include <stdlib.h>

struct node{
struct node * left;
int data;
struct node *right;

};

struct node *root=NULL;

struct node* newnode(int val){

struct node* temp;
temp=(struct node*)malloc (sizeof(struct node));
temp->data=val;
temp->left='\0';
temp->right='\0';
return temp;

}


struct node* insert(struct node* root,int val){

if(root==NULL){
    root=newnode(val);
}

else if(val<root->data){
    root->left=insert(root->left,val);

}
else if(val>root->data){
    root->right=insert(root->right,val);
}
return root;

}

struct node* deleted(struct node *root,int val){

if(root->data>val){
    root->left=deleted(root->left,val);
}
else if(root->data<val){
    root->right=deleted(root->right,val);
}
else{
    if(root->right==NULL){
        struct node *temp=root->left;
        free(root);
        return temp;
    }
    else if(root->left==NULL){
        struct node *temp=root->right;
        free(root);
        return temp;
    }

        //struct node *temp=minvalue(root->right);
        //struct node *temp = minValueNode(root->right);
        struct node *temp = minValueNode(root->right);
        root->data=temp->data;
        root->right=deleted(root->right,temp->data);

  }
  return root;
}


struct node *minValueNode(struct node *node){
  struct node *current = node;
  while (current && current->left != NULL){
    current = current->left;
  }

  return current;
}

int main(){

int val,opt;
while(1){
    printf("Enter the option:");
    scanf("%d",&opt);
    switch(opt){
case 1:
    printf("enter the value : ");
    scanf("%d",&val);
    root=insert(root,val);
    printf("%d",root->data);
    break;

case 2:
    if(root!=NULL){
        printf("no values");
        break;
    }
    printf("enter the value to delete : ");
    scanf("%d",&val);
    root=deleted(root,val);
    printf("%d",root->data);
    break;
    }
}



}
