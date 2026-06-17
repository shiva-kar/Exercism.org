#include "linked_list.h"
#include <stdlib.h>

struct list_node {
  struct list_node *prev, *next;
  ll_data_t data;
};

struct list {
  struct list_node *first, *last;
};

struct list *list_create(void) {
  struct list *list = malloc(sizeof(struct list));
  if (list == NULL) {
    return NULL;
  }
  list->first = NULL;
  list->last = NULL;
  return list;
}

size_t list_count(const struct list *list) {
  size_t count = 0;
  struct list_node *ptr = list->first;
  while (ptr != NULL) {
    ptr = ptr->next;
    count++;
  }
  return count;
}

void list_push(struct list *list, ll_data_t item_data) {
  if (list == NULL) {
    return;
  }
  struct list_node *node = malloc(sizeof(struct list_node));
  if (node == NULL) {
    return;
  }
  node->data = item_data;
  if (list->first == NULL) {
    node->prev = NULL;
    node->next = NULL;
    list->first = node;
    list->last = node;
  } else {
    node->prev = list->last;
    node->next = NULL;
    list->last->next = node;
    list->last = node;
  }
  return;
}

ll_data_t list_pop(struct list *list) {
  if (list == NULL) {
    return 0;
  }
  if (list->first == NULL) {
    return 0;
  }
  ll_data_t value = list->last->data;
  if (list->first == list->last) {
    free(list->first);
    list->first = NULL;
    list->last = NULL;
    return value;
  } else {
    struct list_node *ptr = list->last;
    list->last = list->last->prev;
    list->last->next = NULL;
    free(ptr);
    return value;
  }
}

void list_unshift(struct list *list, ll_data_t item_data) {
  if (list == NULL) {
    return;
  }
  struct list_node *node = malloc(sizeof(struct list_node));
  if (node == NULL) {
    return;
  }
  node->data = item_data;
  if (list->first == NULL) {
    node->prev = NULL;
    node->next = NULL;
    list->first = node;
    list->last = node;
  } else {
    node->prev = NULL;
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }
  return;
}

ll_data_t list_shift(struct list *list) {
  if (list == NULL) {
    return 0;
  }
  if (list->first == NULL) {
    return 0;
  }
  ll_data_t value = list->first->data;
  if (list->first == list->last) {
    free(list->first);
    list->first = NULL;
    list->last = NULL;
    return value;
  } else {
    struct list_node *ptr = list->first;
    list->first = list->first->next;
    list->first->prev = NULL;
    free(ptr);
    return value;
  }
}

void list_delete(struct list *list, ll_data_t data) {
  if (list == NULL) {
    return;
  }
  if (list->first == NULL) {
    return;
  }
  if (list->first == list->last) {
    if (list->first->data == data) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
      return;
    }
  } else {
    struct list_node *ptr = list->first;
    while (ptr != NULL && ptr->data != data) {
      ptr = ptr->next;
    }
    if (ptr == NULL) {
      return;
    } else if (ptr == list->first) {
      list->first = list->first->next;
      list->first->prev = NULL;
      free(ptr);
      return;
    } else if (ptr == list->last) {
      list->last = list->last->prev;
      list->last->next = NULL;
      free(ptr);
      return;
    } else {
      ptr->next->prev = ptr->prev;
      ptr->prev->next = ptr->next;
      free(ptr);
      return;
    }
  }
}

void list_destroy(struct list *list) {
  if (list == NULL) {
    return;
  }
  while (list->first != NULL) {
      list_pop(list);
  }
  free(list);
  return;
}
