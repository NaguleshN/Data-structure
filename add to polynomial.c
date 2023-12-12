#include <stdio.h>

struct poly
{
 int coefficient;
 int exponential;
 struct poly* link;
};

struct poly *head1,*head2,*curr,*temp;


void create_poly1(int coefficient,int exponential){
    if (head1==NULL){
        head1=(struct poly*)malloc(sizeof(struct poly));
        scanf("%d",&head1->coefficient);
        scanf("%d",&head1->exponential);
        head1->link=NULL;
    }
    else{
        head1=(struct poly*)malloc(sizeof(struct poly));
        curr=head1;
        while (curr->link!=NULL){
            curr=curr->link;
        }
        scanf("%d",&curr->coefficient);
        scanf("%d",&curr->exponential);
        curr->link=NULL;
    }
}

void create_poly2(int coefficient,int exponential){
    if (head2==NULL){
        head2=(struct poly*)malloc(sizeof(struct poly));
        scanf("%d",&head2->coefficient);
        scanf("%d",&head2->exponential);
        head2->link=NULL;
    }
    else{
        head2=(struct poly*)malloc(sizeof(struct poly));
        curr=head2;
        while (curr->link!=NULL){
            curr=curr->link;
        }
        scanf("%d",&curr->coefficient);
        scanf("%d",&curr->exponential);
        curr->link=NULL;
    }
}

void disp1(){
    curr=head1;
    while (curr!=NULL){
        printf("%d",curr->coefficient);
        printf("%d",curr->exponential);
    }
}

int main(){
    // poly1=(struct poly*)malloc(sizeof(struct poly));
    // poly2=(struct poly*)malloc(sizeof(struct poly));
    int option;
    while(1){
        printf("enter the operation");
        printf("1.poly one create ");
        printf("2.poly 2 create ");
        // printf("3.")
        scanf("%d",&option);
        switch(option){
            case 1:
                create_poly1(1,2);
                disp1();
                break;
            case 2:
                create_poly2(2,3);
                break;
            // case 3:

        }
    

    }

}