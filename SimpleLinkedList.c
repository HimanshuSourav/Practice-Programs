#include <stdio.h>
#include <stdlib.h>

#define Error -1

struct Node{
	int element;
	struct Node *next;
//	struct Node *previous;
};
typedef struct Node node;

int DisplayMenu();
int create(int element, node* start);
int delete();
int insert();
int search();
int DisplayNodes(node);


int main(){
	node *start;int choice;
	while(Error != (choice = DisplayMenu())){
		switch(choice){
			case -1:
				return 0;//exit option
				break;
			case  0:
				//struct Node *start;
				start = (node*) malloc(sizeof(node));
				create(5,start);
				DisplayNodes(*start);
				break;
			case  1:
				insert(start);
				break;
			case  2:
				break;
			case  3:
				DisplayNodes(*start);
				break;
			default:
				break;
		}
	}

	return 0;
}

int DisplayMenu(){
	int ch;
	printf("Simple Linked List Program\n\nPlease Enter your choice:\n\n\t");
	printf("a. Exit   -1\n \t"
	       "b. Create  0\n \t"
		"c. Insert  1\n \t"
		"d. Delete  2\n \t"
		"e. Display 3\n \t"
		"\n\tchoice:");
	scanf("%d",&ch);
	return ch;
}

int create(int element, node *start){
	 start->element  = 11;
	 //start->previous = NULL;
	 start->next     = NULL;
	 return 0;
}

int DisplayNodes(node n){
	printf("element:%d\n",n.element);
	if(n.next != NULL){
		n = *(n.next);
		DisplayNodes(n);
	}
	else
		return 0;
}

int insert(node *n){
	//count number of nodes and ask user where does she want to insert the node
	int position,i;
	node *temp = (node*)malloc(sizeof(node));
	*temp = *n;
	//for(i=0;n->next != NULL; i++)
	//	n = n->next;
	printf("currently %d number of nodes are present,\n"
		"please enter the position, where you wish to insert the element:",i);
	scanf("%d",&position);
	int NewElement;
	printf("Enter the element to be inserted:");
	scanf("%d",&NewElement);
	*n = *temp;
	for(i=0;i<position;i++)
		n = n->next;
	*temp = *n;
	n->next       = temp;
	n->element    = NewElement;

	return 0;
}

int delete(node *n){

}
