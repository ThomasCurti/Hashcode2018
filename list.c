#include "list.h"

void list_print(struct list * list)
{
	list = list->next;

	while(list != NULL)
	{
		printRide(list->data);

		list = list->next;
	}
}


void list_init(struct list *list)
{
	list->next = NULL;
}
 
int list_is_empty(struct list *list)
{
	return list->next == NULL;
}
 
size_t list_len(struct list *list)
{
	int lenght = 0;

	while(list->next != NULL)
	{
		list = list->next;
		lenght += 1;
	}

	return lenght;
}
 
void list_push_front(struct list *list, struct list *elm)
{
	elm ->next = list->next;

	list->next = elm;
}
 
struct list* list_pop_front(struct list *list)
{
	struct list * result = list->next;

	if(result != NULL)
		list->next = result->next;

	return result;
}
 
struct list* list_find(struct list *list, Ride * value)
{
	list = list->next;

	while(list != NULL)
	{
		if(list->data == value)
			return list;

		list = list->next;
	}

	return NULL;
}
 
struct list* list_lower_bound(struct list *list, Ride * value)
{

	while(list->next != NULL && list->next->data->earlierStart < value->earlierStart)
	{
		list = list->next;
	}

	return list;
}
 
int list_is_sorted(struct list *list)
{	
	if(list->next == NULL)
		return 1;

	list = list->next;

	while(list->next != NULL)
	{
		if(list->data->earlierStart > list->next->data->earlierStart)
			return 0;

		list = list->next;
	}

	return 1;
}
 
void list_insert(struct list *list, struct list *elm)
{
	list = list_lower_bound(list,elm->data);

	list_push_front(list,elm);
}
 
static struct list * list_pop_back(struct list * list)
{
	if(list == NULL)
		return NULL;

	struct list * parent = list;
	list = list->next;

	if(list == NULL)
		return NULL;

	while(list->next != NULL)
	{
		parent = list;
		list = list->next;
	}

	if(parent != NULL)
		parent->next = NULL;

	return list;
}

void list_rev(struct list *list)
{	
	struct list * last;

	do
	{
		last = list_pop_back(list);

		if(last != NULL)
		{
			list_push_front(list,last);
			list = last;			
		}

	}while(last != NULL);
}

void list_clear(struct list * list)
{
	list = list->next;

	while(list != NULL)
	{
		free(list->data);

		struct list * old = list;

		list = list->next;

		free(old);
	}
}