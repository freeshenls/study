#include<stdlib.h>
#include<stdio.h>

struct ListNode
{
        int val;
        struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode *head){
        struct ListNode *prev = NULL;
        struct ListNode *cur = head;
        struct ListNode *next = NULL;
        while(cur){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
        };
        return prev;
}

int main(int argc, char const *argv[])
{
        struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
        head->val=1;

        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=2;
        temp->next=NULL;

        head->next=temp;

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=3;
        temp->next=NULL;

        head->next->next=temp;

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=4;
        temp->next=NULL;

        head->next->next->next=temp;

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=5;
        temp->next=NULL;

        head->next->next->next->next=temp;

        head = reverseList(head);

        printf("%d\n", head->val);
        printf("%d\n", head->next->val);
        printf("%d\n", head->next->next->val);
        printf("%d\n", head->next->next->next->val);
        printf("%d\n", head->next->next->next->next->val);
        free(head->next->next->next->next);
        free(head->next->next->next);
        free(head->next->next);
        free(head->next);
        free(head);
        return 0;
}
