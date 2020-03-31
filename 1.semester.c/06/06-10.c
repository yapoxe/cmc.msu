// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>
int n=0, a=0, b=0, m=0, count=0;
struct list *root=NULL, **c=NULL;
struct list{
	int value;
	struct list *next;
	struct list *prev;
};

struct list *create_list( struct list *root, int n){
	struct list *head=NULL, *tmp=NULL;
	root=malloc(sizeof (struct list));
	root->value=1;
	root->prev=NULL;
	root->next=NULL;
	head=root;
	for(int i=0; i<n-1; i++){
		tmp=malloc(sizeof(struct list));
		tmp->next=NULL;
		tmp->prev=head;
		tmp->value=i+2;
		head->next=tmp;
		head=head->next;
	}
	return root;
}

struct list **create_arr(struct list **c, struct list *root, int n){
	c=(struct list **)malloc(n*sizeof(struct list*));
	static int count = 0;
	while(count<n){
		c[count]=root;
		root=root->next;
		count++;
	}
	return c;
}

struct list *swap(struct list *root, struct list **c, int i, int j){
	struct list *l=NULL, *r=NULL;
	i--;
	l=c[i];
	if(root==l){
		return root;
	}
	j--;
	r=c[j];
	if(r->next){
		l->prev->next=r->next,r->next->prev=l->prev;
		r->next=root;
		root->prev=r;
		l->prev=NULL;
		root=l;
		return root;
	}
	else if (!r->next){
		l->prev->next=NULL, r->next=root;
		root->prev=r;
		l->prev=NULL;
		root=l;
		return root;
	}
	return root;
}

int change(FILE *file){
	while(count<m){
		count++;
		fscanf(file,"%d %d", &a, &b);
		root=swap(root, c, a, b);
		if(count==m){
			break;
		}
	}
	return 0;
}

int printl(struct list *type, FILE *file){
	while(type){
		fprintf(file, "%d ", type->value);
		type=type->next;
	}
	fclose(file);
	return 0;
}

int deletel(void){
	struct list *n=NULL;
	while(root!=NULL){
		n=root;
		root=root->next;
		free(n);
	}
	free(root);
	return 0;
}

int main(void){
	FILE *input=fopen("input.txt", "r");
	FILE *output=fopen("output.txt", "w");
	fscanf(input,"%d %d", &n, &m);
	root=create_list(root, n);
	c=create_arr(c, root, n);
	change(input);
	fclose(input);
	printl(root, output);
	deletel();
	return 0;
}
