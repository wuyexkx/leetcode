#include <stdio.h>
#include <stdlib.h>

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(int argc, char**argv)
{
    if(argc < 3) return;

    struct ListNode* l1 = strs_to_ListNode(argv[1]);
    struct ListNode* l2 = strs_to_ListNode(argv[2]);
    // print_ListNode(l1);
    // print_ListNode(l2);

    struct ListNode* ret_l = addTwoNumbers(l1, l2);
    print_ListNode(ret_l);

    return 0;
}
