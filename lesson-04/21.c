#include<stdlib.h>
#include<stdio.h>

struct ListNode
{
        int val;
        struct ListNode *next;
};

struct ListNode* appendList(struct ListNode* node, struct ListNode* list){
        struct ListNode *temp = list;
        struct ListNode *next = NULL;
        node->next = NULL;

        while(list){
                next = list->next;

                if (node->val<=list->val)
                {
                        node->next = list;
                        temp = node;
                        break;
                }

                if (node->val>list->val)
                {
                        if (next && node->val<=next->val)
                        {
                                list->next = node;
                                node->next = next;
                                break;
                        }
                }
                list = next;
        }
        list = temp;
        return list;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
        if (list1==NULL)
        {
                return list2;
        }

        if (list2==NULL)
        {
                return list1;
        }

        struct ListNode *next = NULL;

        while(list1){
                next = list1->next;
                appendList(list1, list2);
                list1 = next;
        }

        return list2;
}

int main(int argc, char const *argv[])
{
        struct ListNode node1, node2, node3;
        node1.val = 1;
        node2.val = 2;
        node3.val = 4;
        node1.next = &node2;
        node2.next = &node3;
        node3.next = NULL;

        struct ListNode node4, node5, node6;
        node4.val = 1;
        node5.val = 3;
        node6.val = 4;
        node4.next = &node5;
        node5.next = &node6;
        node6.next = NULL;

        struct ListNode *result = mergeTwoLists(&node1, &node4);
        printf("%s\n", "==============result==============");
        while(result){
                printf("%d\n", result->val);
                result = result->next;
        }
        return 0;
}
