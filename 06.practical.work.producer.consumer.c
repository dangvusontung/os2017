#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10


typedef struct
{
	char type; //fried chicken : 0, french fries : 1
	int amount; //piece, weight
	char unit; //piece : 0, gram : 1
}item;

item buffer[BUFFER_SIZE];
int first =0;
int last=0;

void produce(item *i){

	while((first+1) % BUFFER_SIZE == last)
	{	
	// do nothing -- no free buffer item
	}

	memcpy(&buffer[first],i, sizeof(item));
	first = (first+1) % BUFFER_SIZE;
}

item *consume()	
{
	item *i = (item *)malloc(sizeof(item));
	while(first == last)
	{	
	// do nothing -- no free buffer item
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last+1) % BUFFER_SIZE;
	return i;
}

int main(){
	item i1;
	item i2;


	i1.type = '1';
	i1.amount = 0;
	i1.unit = '1';

	i2.type= '0';
	i2.amount =1;
	i2.unit = '0';


	printf("Producing item 1 : type=%c, amount= %d, unit = %c", i1.type, i1.amount, i1.);
	produce(&i1);
	printf("First = %d  Last = %d\n",first,last);




	printf("Producing item 2 : type=%c, amount= %d, unit = %c", i2.type, i2.amount, i2.);
	produce(&i2);
	printf("First = %d  Last = %d\n",first,last);


	printf("Consume :");
	consume();

	printf("First = %d  Last = %d\n",first,last);

}
