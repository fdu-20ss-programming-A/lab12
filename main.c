#include <stdio.h>
#include <stdlib.h>

// 单链表节点
struct Node{
    int value;
    struct Node *next;
};

struct Node *insert(struct Node *head, int value, int index);
struct Node *reverse(struct Node *head);
void printNodeList(struct Node *head);
void freeNodeList(struct Node *head);
struct Node *createNodeList(int *list, int len);
struct Node *getIndexNode(struct Node *head, int index);


int main(){
    int list[] = {23,6,9,15};
    int len = sizeof(list)/sizeof(int);
    struct Node *nodeList = createNodeList(list,len);
    printf("Before insert, the list:\n");
    printNodeList(nodeList);
    printf("Insert a node:\n");
    nodeList = insert(nodeList, 10, 0);
    printNodeList(nodeList);
    printf("Reverse node list:\n");
    nodeList = reverse(nodeList);
    printNodeList(nodeList);
    freeNodeList(nodeList);
    return 0;
}

/*
Question 1:
实现在链表当中插入一个元素
*/
struct Node *insert(struct Node *head, int value, int index){
    // 请在这里实现
    printf("Error: Question 1!!!\n");
    return head;
}

/*
Question 2:
反转一个链表
*/
struct Node *reverse(struct Node *head){
    // 请在这里实现
    printf("Error: Question 2!!!\n");
    return head;
}

// 打印链表
void printNodeList(struct Node *head){
    struct Node *node = head;
    if(node == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d",node->value);
    node = node->next;
    while(node != NULL){
        printf("->%d",node->value);
        node = node->next;
        if(node == head){
            printf("Error: There is a loop in the list!!!");
            exit(0);
        }
    }
    printf("->NULL\n");
}

// 释放链表内存
void freeNodeList(struct Node *head){
    struct Node *node = head;
    struct Node *temp;
    while(node != NULL){ // NULL 代表最后链表最后的空节点
        temp = node;
        node = node->next;
        if(node == head){
            printf("Error: There is a loop in the list!!!");
            exit(0);
        }
        free(temp);
    }
}

// 根据int数组创建链表
struct Node *createNodeList(int *list, int len){
    struct Node *node;
    struct Node *nodeList = NULL;
    for(int i = len-1; i >= 0; i--){
        node = (struct Node *)malloc(sizeof(struct Node));
        node->value = list[i];
        node->next = nodeList;
        nodeList = node;
    }
    return nodeList;
}

// 获取链表第i个元素
struct Node *getIndexNode(struct Node *head, int index){
    int i = 0;
    struct Node *node = head;
    while(node != NULL){ // NULL 代表最后链表最后的空节点
        if(i == index){
            return node;
        }
        i++;
        node = node->next;
    }
    // 超出下标，返回空指针
    return NULL;
}
