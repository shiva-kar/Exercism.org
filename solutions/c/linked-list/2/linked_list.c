#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node *prev, *next;
  ll_data_t data;
} list_node_t;

typedef struct list {
  list_node_t *first, *last;
  size_t length;
} list_t;

static list_node_t *create_node(ll_data_t data);
static void initialize_empty_list(list_t *list, list_node_t *node);
static void remove_node(list_t *list, list_node_t *node);

list_t *list_create(void) {
  list_t *list = malloc(sizeof(list_t));
  if (!list) {
    return NULL;
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

size_t list_count(const list_t *list) { return list->length; }

void list_push(list_t *list, ll_data_t item_data) {
  if (!list) {
    return;
  }
  list_node_t *new_node = create_node(item_data);
  if (!new_node) {
    return;
  }
  if (!list->length) {
    initialize_empty_list(list, new_node);
  } else {
    new_node->prev = list->last;
    list->last->next = new_node;
    list->last = new_node;
  }
  list->length++;
}

ll_data_t list_pop(list_t *list) {
  if (!list) {
    return 0;
  }
  if (!list->length) {
    return 0;
  }
  ll_data_t value = list->last->data;
  remove_node(list, list->last);
  return value;
}

void list_unshift(list_t *list, ll_data_t item_data) {
  if (!list) {
    return;
  }
  list_node_t *new_node = create_node(item_data);
  if (!new_node) {
    return;
  }
  if (!list->length) {
    initialize_empty_list(list, new_node);
  } else {
    new_node->next = list->first;
    list->first->prev = new_node;
    list->first = new_node;
  }
  list->length++;
}

ll_data_t list_shift(list_t *list) {
  if (!list) {
    return 0;
  }
  if (!list->length) {
    return 0;
  }
  ll_data_t value = list->first->data;
  remove_node(list, list->first);
  return value;
}

void list_delete(list_t *list, ll_data_t data) {
  if (!list) {
    return;
  }
  if (!list->length) {
    return;
  }
  if (list->first->data == data) {
    remove_node(list, list->first);
    return;
    } else {
    list_node_t *ptr = list->first;
    while (ptr != NULL && ptr->data != data) {
      ptr = ptr->next;
    }
    if (ptr) {
      remove_node(list, ptr);
    }
  }
}

void list_destroy(list_t *list) {
  if (!list) {
    return;
  }
  while (list->length) {
    list_pop(list);
  }
  free(list);
  return;
}

static list_node_t *create_node(ll_data_t data) {
  list_node_t *new_node = malloc(sizeof(list_node_t));
  if (!new_node) {
    fprintf(stderr, "Error: memory allocation failure.\n");
    return NULL;
  }
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

static void initialize_empty_list(list_t *list, list_node_t *node) {
  list->first = node;
  list->last = node;
}

static void remove_node(list_t *list, list_node_t *node){
  assert(list);
  assert(node);
  assert(list->length);
  if (node->prev) {
    node->prev->next = node->next;
  } else {
    list->first = node->next;
  }
if (node->next) {
  node->next->prev = node->prev;
  } else {
    list->last = node->prev;
  }
  list->length--;
  free(node);
}
