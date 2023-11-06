#ifndef STACK_LIST
#define STACK_LIST

#define STACK_PEEK(name) (name)->head
#define STACK_EMPTY(name) (name)->head == NULL

#define STACK_NEXT(type)\
    struct{\
        struct type *next;\
    }                               

#define STACK(name, type)\
    typedef struct{\
        struct type *head;\
    }name

#define STACK_INIT(name) do{\
    (name)->head = NULL;\
}while(0)

#define STACK_PUSH(name, node, next)do{\
    if((name)->head == NULL) (name)->head = (node);\
    else{\
        (node)->next.next = (name)->head;\
        (name)->head = (node);\
    }\
}while(0)

#define STACK_POP(name, next)do{\
    if((name)->head == NULL);\
    else{\
        (name)->head = (name)->head->next.next;\
    }\
}while(0)

#define STACK_PRINT(node, name, next)\
    for((node) = ((name)->head);\
            (node);\
            (node) = ((node)->next.next)) 

#endif
