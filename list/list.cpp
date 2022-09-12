// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};


};
//create trees here vvvv
ListNode tree1 = {-2,new ListNode(5)};// 2-3-4-5
ListNode tree2 = {-9,new ListNode(-6,new ListNode(-3, new ListNode(-1, new ListNode(1, new ListNode(6)))))};//3-6
//expected 2-3-3-4-5-6

ListNode* merge(ListNode* list1, ListNode* list2) {
    //create a ListNode pointer that will hold the merge, put it on the heap, or else solution wont work 
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));//some operations will get wacky when doing this 
    if (list1 == NULL and list2 == NULL) {
        return ret = nullptr;//as a null ptr
    }
    else if (list1 == NULL and list2 != NULL) {
        ret = list2;
        return ret;
    }
    else if (list1 != NULL and list2 == NULL) {
        ret = list1;
        return ret;
    }
    //actual coding part 
    //go through both untill next is NULL, store current as ret, if current.val < compared.val and current.next.val > compared.val : do insert compared, 
    //ret = list1; - this is , changes will apply to list1, copy all of list1's values to ret
    /*
    output = new list
    while list1.next != nullptr && list2.next != nullptr
        if list1.val < list2.val
            output.append(list1.val)
            if list1.next != nullptr
                list1 = list1.next
        else
            output.append(list2.val)
            if list2.next != nullptr
                list2 = list2.next

    return output
    */


};






int main()
{

    
    ListNode* ret = merge(&tree1, &tree2);

    while (ret != NULL) {
        std::cout << ret->val << std::endl;
        ret = ret->next;

    }
   
    std::cout << "Hello World!\n";
}

