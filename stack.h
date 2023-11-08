#ifndef STACK_LIST
#define STACK_LIST

#define STACK_PEEK(name) (name)->head
#define STACK_EMPTY(name) (name)->head == NULL
#define STACK_SIZE(name) (name)->size

#define STACK_NEXT(type)\
    struct{\
        struct type *next;\
    }                               

#define STACK(name, type)\
    typedef struct{\
        struct type *head;\
        size_t size;\
    }name

#define STACK_INIT(name) do{\
    (name)->head = NULL;\
    (name)->size = 0;\
}while(0)

#define STACK_PUSH(name, node, next)do{\
    if((name)->head == NULL) (name)->head = (node);\
    else{\
        (node)->next.next = (name)->head;\
        (name)->head = (node);\
    }\
    (name)->size++;\
}while(0)

#define STACK_POP(name, node, next)do{\
    if((name)->head == NULL);\
    else{\
        (node) = (name)->head;\
        (name)->head = (name)->head->next.next;\
    }\
    (name)->size--;\
}while(0)

#define STACK_ITERATE(node, name, next)\
    for((node) = ((name)->head);\
            (node);\
            (node) = ((node)->next.next)) 

#endif
