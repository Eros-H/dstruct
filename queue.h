#ifndef QUEUE_LIST
#define QUEUE_LIST

#define QUEUE_NEXT(type)\
    struct{\
        struct type *next;\
    }

#define QUEUE(name, type)\
    typedef struct{\
        struct type *head; \
        struct type *tail; \
        size_t size;\
    }name

#define QUEUE_INIT(name) do{\
    (name)->head = NULL;\
    (name)->size = 0;\
}while(0)
#define QUEUE_FIRST(name) (name)->head
#define QUEUE_LAST(name) (name)->tail
#define QUEUE_EMPTY(name) (name)->head == NULL
#define QUEUE_SIZE(name) (name)->size
#define QUEUE_ENQUEUE(name, node, next)do{\
    if((name)->head == NULL){\
        (name)->head = (node);\
        (name)->tail = (name)->head;\
    }else if((name)->head == (name)->tail){\
        (name)->tail = (node);\
        (name)->head->next.next = (name)->tail;\
    }else{\
        (name)->tail->next.next = (node);\
        (name)->tail = (name)->tail->next.next;\
    }\
    (name)->size++;\
}while(0)
#define QUEUE_DEQUEUE(name, node, next)do{\
    if((name)->head == NULL){\
    }else if((name)->head == (name)->tail){\
        (node) = (name)->head;\
        (name)->head = NULL;\
    }else{\
        (node) = (name)->head;\
        (name)->head = (name)->head->next.next;\
    }\
    (name)->size--;\
}while(0)
#define QUEUE_ITERATE(node, name, next)\
    for((node) = (name)->head;\
        (node);\
        (node) = (node)->next.next)
#endif
