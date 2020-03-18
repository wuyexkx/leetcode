#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// 任意位数都可以
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* first;
    int flag = 1;
    int add = 0;
    while(l1 || l2 || add){
        struct ListNode* prev;
        struct ListNode* new_l = malloc(sizeof(* l1));   
        new_l->next = NULL;
        // 处理个位
        if(flag){
            flag = 0;
            int temp = l1->val + l2->val; 
            new_l->val = temp>9 ? (add=1, temp%10) : temp;
            first = new_l;
            prev = new_l;
            l1 = l1->next;
            l2 = l2->next;
        } else {
        // 处理其它位
            int temp = 0;
            if(l1){
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2){
                temp += l2->val;
                l2 = l2->next;
            }
            // 处理进位的情况
            if(add){
                temp += add;
            }
            new_l->val = temp>9 ? (add=1, temp%10) : (add=0, temp);

            prev->next = new_l;
            prev = new_l;
        }
    }
    return first;
}

// 我的垃圾代码，没有考虑超过long long范围的情况
// unsigned long long long的最大值：1844 6744 0737 0955 1615
struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2){
    unsigned long long num1=0, num2=0;
    int digits=0;
    unsigned long long rate=1;

    // 得到这两个正整数
    while(l1 != NULL){
        num1 += rate * l1->val;
        rate *= 10;
        l1 = l1->next;
    }
    rate = 1;
    while(l2 != NULL){
        num2 += rate * l2->val;
        rate *= 10;
        l2 = l2->next;
    }

    // 两数之和，并得到各位数字
    printf("%lld %lld\n", num1, num2);
    // 和为0的情况
    unsigned long long res_num = num1 + num2;
    if(res_num == 0){
        struct ListNode* ret_l = malloc(sizeof(struct ListNode));
        ret_l->val = 0;
        ret_l->next = NULL;
        return ret_l;
    }
    // 和不为0的情况
    int d_num[100], index=0;
    while(res_num){
        d_num[index++] = res_num % 10;
        res_num /= 10;
        ++digits;
    } 
    // 将各位存入链表
    struct ListNode* ret_l = malloc(sizeof(struct ListNode) * digits);
    for(int i=0; i<digits; ++i){
        ret_l[i].val = d_num[i];
        if(i < digits-1)
            ret_l[i].next = &ret_l[i+1];
        else // 最后的节点next指针为NULL
            ret_l[i].next = NULL;
    }
    return ret_l;
}

// 测试代码用到的工具，
// 通过输入的数字字符串，将各位转存入struct ListNode
struct ListNode* strs_to_ListNode(char* strs)
{
    char *s = strs;
    int str_length = strlen(strs);
    int start = 0;
    int index = 0;
    while(*s == '0' && index < str_length){
        ++index;
        ++start;
        ++s;
    }
    // 找到最后也是0
    if(index == str_length){
        struct ListNode* ret_l = malloc(sizeof(struct ListNode));
        ret_l->val = 0;
        ret_l->next = NULL;
        return ret_l;
    }
    // 比0大的输入
    int length = str_length - start;
    struct ListNode* ret_l = malloc(sizeof(struct ListNode) * length);
    for(int i=str_length-1, j=0; i>=start; --i, ++j){
        ret_l[j].val = strs[i] - '0';
        if(i > start){
            ret_l[j].next = &ret_l[j+1];
        } else {
            ret_l[j].next = NULL;
        }
        // printf("%c ", strs[i]);
    }
    return ret_l;
}


void print_ListNode(const struct ListNode* l)
{
//  p           q       p           q     p        q        p     q          p  q
//  |           |       |           |     |        |        |     |          |  |
//  v           v       v           v     v        v        v     v          v  v
//  0  1  2  3 [ ] ->   1  2  3 [ ] 0     2  3 [ ] 1  0     3 [ ] 2  1  0   [ ] 3  2  1  0  
//               ^                   ^              ^              ^             ^
//               |                   |              |              |             |
//               pv                  pv             pv             pv            pv

    // struct ListNode* prev;
    // struct ListNode* p1 = l;
    // struct ListNode* p2 = NULL;  
    // while(p1){
    //     prev = p2;
    //     p2 = p1;
    //     p1 = p1->next;
    //     p2->next = prev;
    // }
    // l = p2;

    while(l != NULL){
        printf("%d ", l->val);
        l = l->next;
    }    
    printf("\n");
}


// #include <stdio.h>
// #include <stdlib.h>

// // struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

// int main(int argc, char**argv)
// {
//     if(argc < 3) return;

//     struct ListNode* l1 = strs_to_ListNode(argv[1]);
//     struct ListNode* l2 = strs_to_ListNode(argv[2]);
//     // print_ListNode(l1);
//     // print_ListNode(l2);

//     struct ListNode* ret_l = addTwoNumbers(l1, l2);
//     print_ListNode(ret_l);

//     return 0;
// }
