#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

struct node {
	int data;
	struct node*next;
};


extern struct node* createnode(int data);
extern void displaylist(struct node*head);
extern int getlistlength(struct node*head);
extern int getlistsize(struct node*head);
extern void deletefirstnode(struct node**head);
extern void insert(struct node**head,struct node**prev_node,int data);
#endif
