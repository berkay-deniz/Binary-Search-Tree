//Berkay Deniz
#include <stdio.h>
#include <stdlib.h>
int size=0;
int counter=0;
typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int key;
}node;
node *tree=NULL;
node * insert(node *parent,node *tree,int key){
    if(tree==NULL){
        node *root=(node *)malloc(sizeof(node));
        root->key=key;
        root->left=NULL;
        root->right=NULL;
        root->parent=parent;
        return root;
    }
    if(key>tree->key){
        parent=tree;
        tree->right=insert(parent,tree->right,key);
        return tree;
    }
    if(key<tree->key){
        parent=tree;
        tree->left=insert(parent,tree->left,key);
        return tree;
    }
}
int control_parent(node *ptr,int *arr,int n){
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==ptr->parent->key)
            return 1;
    return 0;
}
int control_sequence(int key,int *arr,int n){
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==key)
            return 1;
    return 0;
}
void print_array(int *arr){
    int  i=0;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void traverse(node *tree,int *arr,int n);

int rec_func(node *ptr,int *arr,int n){
    arr[n]=ptr->key;
    if(n+1==size){
         print_array(arr); //this is for printing all sequences
        counter++;
        return 0;
    }
    traverse(tree,arr,n+1);
    return 0;
}
void traverse(node *tree,int *arr,int n){
    node *temp=tree;
    if(temp!=NULL)
        if(control_sequence(temp->key,arr,n)==0){
            if(control_parent(temp,arr,n)==1){
                rec_func(temp,arr,n);
            }
        }
    if(temp->left!=NULL)
        traverse(temp->left,arr,n);
    if(temp->right!=NULL)
        traverse(temp->right,arr,n);
}
void in_order(node *tree){
    if(tree->left!=NULL)
        in_order(tree->left);
    if(tree!=NULL)
        printf("%d ",tree->key);
    if(tree->right!=NULL)
        in_order(tree->right);
}
int main(){
    int *arr=(int *)malloc(sizeof(int)*size);
    int numbers[50];
    char c;
    node *parent=NULL;
    printf("Please enter the keys : ");
    do {
        scanf("%d%c", &numbers[size], &c);
        tree=insert(parent,tree,numbers[size]);
        size++;
    } while(c != '\n');
    printf("\n");
    printf("in order traversal of tree : ");
    in_order(tree);
    printf("\n\n");
    arr[0]=tree->key;
    traverse(tree,arr,1);
    printf("%d sequences",counter);
    return 0;
}
