/*******************************************************************************
-Ws4
-Itai Marienberg
-Dec 1 2019    
*******************************************************************************/

#include <stdio.h> /* printf */

#include "linkedlist.h"

#define GREEN "\033[;032m"
#define RED   "\033[;031m"
#define RESET "\033[0m"
#define RUN_TEST(test)\
{\
  if(test)\
  {\
    printf(GREEN);\
    printf("SUCCESS\n");\
    printf(RESET);\
  }\
  else\
  {\
    printf(RED);\
    printf("FAIL \n");\
    printf(RESET);\
  }\
}

static void TestLinkedList()
{
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
    node_t *head = NULL, *node1 = NULL, *node2 = NULL, *node3 = NULL, *node4 =NULL;
    
    printf("Linked List 1:\n");
    node1 = SLLCreateNode(NULL, &x1);
    node2 = SLLCreateNode(NULL, &x2);
    node3 = SLLCreateNode(NULL, &x3);
    node4 = SLLCreateNode(NULL, &x4);
    head = node1;
    
    RUN_TEST(0 == SLLInsertAfter(node2, node1));
    RUN_TEST(0 == SLLInsertAfter(node3, node2));
    RUN_TEST(0 == SLLInsertAfter(node4, node3));
    
    RUN_TEST(4 == SLLSize(node1));
    head = SLLFlip(head);
    RUN_TEST(node4 == head);
    SLLDestroy(node4);
    
    printf("\nLinked List 2:\n");
    node1 = SLLCreateNode(NULL, &x1);
    node2 = SLLCreateNode(NULL, &x2);
    node3 = SLLCreateNode(NULL, &x3);
    node4 = SLLCreateNode(NULL, &x4);
    
    RUN_TEST(0 == SLLInsertAfter(node2, node1));
    RUN_TEST(0 == SLLInsertAfter(node3, node2));
    RUN_TEST(0 == SLLInsertAfter(node4, node3));
    
    RUN_TEST(4 == SLLSize(node1));
    SLLFlip(node2);
    RUN_TEST(3 == SLLSize(node4));
    RUN_TEST(2 == SLLSize(node1));
    RUN_TEST(node3 == node4->next);
    RUN_TEST(node2 == SLLFindIntersection(node1, node4));
    SLLFlip(node4);
    SLLDestroy(node1);
    
    printf("\nLinked List 3:\n");
    node1 = SLLCreateNode(NULL, &x1);
    node2 = SLLCreateNode(NULL, &x2);
    node3 = SLLCreateNode(NULL, &x3);
    node4 = SLLCreateNode(NULL, &x4);
    
    RUN_TEST(0 == SLLInsertAfter(node2, node1));
    RUN_TEST(0 == SLLInsertAfter(node3, node2));
    RUN_TEST(0 == SLLInsertAfter(node4, node3));
    
    RUN_TEST(4 == SLLSize(node1));
    SLLFlip(node2);
    RUN_TEST(3 == SLLSize(node4));
    RUN_TEST(2 == SLLSize(node1));
    RUN_TEST(node3 == node4->next);
    RUN_TEST(node2 == SLLFindIntersection(node1, node4));
    SLLFlip(node4);
    SLLDestroy(node1);
    
     
}


int main()
{
        TestLinkedList();
        /*node_t *n1 = NULL;
        node_t *n2 = NULL;
        node_t *n3 = NULL;
        node_t *n4 = NULL;
        node_t *head1 = NULL;
        node_t *intersection = NULL;

        int a = 10;        
        int b = 20;
        int c = 30;
        int d = 40;
        int e = 50;
        int result = 3;
        
        n4 = SLLCreateNode(NULL,&d);
        n3 = SLLCreateNode(n4, &c);
        n2 = SLLCreateNode(n3, &b);
        n1 = SLLCreateNode(n2, &a);
        n4->next = n2;

        head1 = n1;
        printf("size: %lu \n", SLLSize(head));

        result =  SLLHasLoop(head1);
        printf("has loop: %d \n", result);*/
    return 0;
}

