#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int (*callback)(void *cookie, int cookie_len);
typedef int event_type;

#define MAX_EVENTS 10
int init_done = 0;

enum event_types {
	type1,
	type2,
	type3,
	type4,
	type5,
	type6,
	type7,
	type8,
	type9,
	type10
};

/*
 * Structure for containing listener callback and cookie
 */
typedef struct callback_node {
	struct callback_node *next;
	callback callback_func;
	void *cookie;
	int cookie_len;
} callback_node_t; 

/*
 * Structure for maintaining list of head pointers for different
 * type of events.
 */
struct event_list {
	callback_node_t *head;
};

struct event_list events[MAX_EVENTS];

callback_node_t* create_node(void) {
	callback_node_t *node = (callback_node_t *)malloc(sizeof(callback_node_t));
	node->next = NULL;
	node->callback_func = NULL;
	return node;
}

int my_callback1(void *cookie, int cookie_size) {
	//Can do what it wants with cookie
	printf("%s called.\n", __FUNCTION__);
}

int my_callback2(void *cookie, int cookie_size) {
	//Can do what it wants with cookie
	printf("%s called.\n", __FUNCTION__);
}

int  my_callback3(void *cookie, int cookie_size) {
	//Can do what it wants with cookie
	printf("%s called.\n", __FUNCTION__);
}

void register_init(void) {
	int i = 0;
	for(i = 0; i < MAX_EVENTS; i++) {
		events[i].head = NULL;
	}
}

void register_for_event(event_type et,
			callback ptr_reg_callback,
			void *cookie,
			int cookie_len) {
	
	printf("%s called for event type %d\n", __FUNCTION__, et);

	if(!init_done) {
		register_init();
		init_done = 1;
	}

	callback_node_t *ptr = events[et].head;

	callback_node_t *temp = create_node();
	temp->callback_func = ptr_reg_callback;
	temp->cookie = cookie;
	temp->cookie_len = cookie_len;

	if(!ptr) {
		events[et].head = temp;
		return;
	}

	while(ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = temp;

	return;
}

void notify_for_event(event_type et) {
	callback_node_t *ptr = events[et].head;

	while(ptr->next != NULL) {
		(*ptr->callback_func)(ptr->cookie, ptr->cookie_len);
		ptr = ptr->next;
	}

	(*ptr->callback_func)(ptr->cookie, ptr->cookie_len);
	return;
}

void unit_test_register_all_callbacks_once(void) {
	printf("======================================\n");
	printf("Entering %s, should print total 3 lines from the three callbacks, 1 from each.\n", __FUNCTION__);

	init_done = 0;
	callback ptr_my_callback;
	int value = 10; //some test value
	int *cookie = &value;
	int cookie_len = 1;

	enum event_types event;
	event = type1;

	ptr_my_callback = my_callback1;
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	ptr_my_callback = my_callback2;
	event = type2;
	
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	ptr_my_callback = my_callback3;
	event = type3;
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	event = type1;
	notify_for_event(event);

	event = type2;
	notify_for_event(event);

	event = type3;
	notify_for_event(event);

	printf("Exiting %s, should have printed total 3 lines from the three callbacks, 1 from each.\n", __FUNCTION__);
}

void unit_test_register_all_callbacks_twice(void) {
	printf("======================================\n");
	printf("Entering %s, should print total 6 lines from the three callbacks, 2 from each.\n", __FUNCTION__);

	init_done = 0;
	callback ptr_my_callback;
	int value = 10; //some test value
	int *cookie = &value;
	int cookie_len = 1;

	enum event_types event;
	event = type1;

	ptr_my_callback = my_callback1;
	register_for_event(event, ptr_my_callback, cookie, cookie_len);
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	ptr_my_callback = my_callback2;
	event = type2;
	
	register_for_event(event, ptr_my_callback, cookie, cookie_len);
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	ptr_my_callback = my_callback3;
	event = type3;
	register_for_event(event, ptr_my_callback, cookie, cookie_len);
	register_for_event(event, ptr_my_callback, cookie, cookie_len);

	event = type1;
	notify_for_event(event);

	event = type2;
	notify_for_event(event);

	event = type3;
	notify_for_event(event);

	printf("Exiting %s, should have printed total 6 lines from the three callbacks, 2 from each.\n", __FUNCTION__);
}

int main(int argc, char **argv) {
	unit_test_register_all_callbacks_once();
	unit_test_register_all_callbacks_twice();
	return (0);
}
