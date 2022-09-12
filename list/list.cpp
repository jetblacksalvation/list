// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {};
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node* next) : val(x), next(next) {};


};
//create trees here vvvv
Node tree1 = {5};// 2-3-4-5
Node tree2 = {1,new Node(2,new Node(4, new Node(5)))};//3-6
//expected 2-3-3-4-5-6

Node* merge(Node* list1, Node* list2) {
    //create a Node pointer that will hold the merge, put it on the heap, or else solution wont work 
    Node* ret = (Node*)malloc(sizeof(Node));//some operations will get wacky when doing this 
    if (list1 == NULL and list2 == NULL) {
        return ret = new Node();//as a null ptr
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
    //ret = list1; - this is retarded, changes will apply to list1, copy all of list1's values to ret
    Node* temp = list1;
    ret = new Node(temp->val);
    Node* root = ret;
    while (temp->next != NULL) {
        //go through all the values of list1 as temp, and push them to ret, once loop is done, do comparisions aka above comment^^^^^
        ret->next = new Node(temp->next->val);
        ret = ret->next;
        temp = temp->next;
        //std::cout << temp->val << std::endl; uncomment this to check if it's inside if 
    }
    temp = NULL; //clear temp so that it can hold current 
    ret = root;
    
    while (1) {
           
        if (list2 == NULL and ret !=NULL) {
            ret = root;
            return ret;

        }
        else if (list2 != NULL and ret ==NULL)
        {
            ret = list2;
            ret = root;
            return ret;

        }
        else if (list2 == NULL and ret == NULL) {
            ret = root;
            return ret;
        }

        if (ret->val <= list2->val and (ret->next ==nullptr or ret->next->val >= list2->val) ){
            //copy current as temp, push value between current and next, 
            
            temp = ret->next;
            
            
            ret->next = new Node(list2->val, temp);//insertion, now move down tree for both
            
            list2 = list2->next;
            ret = ret->next;
        }
        else if (list2->val < ret->val and list2->next != NULL) {//swap if list2 value is > current 
            ret->next = new Node(ret->val);
            ret->val = list2->val;
            
            list2 = list2->next;

        }
        
        ret = ret->next;
        
        //std::cout << ret->val;

    }
   
    ret = root;//root is the root of temp set root to it, set as return because if not only returns last poinete 
    //clear temp so that you can use it later 



    return ret;

};






int main()
{
    Node* ret = merge(&tree1, &tree2);

    while (ret != NULL) {
        std::cout << ret->val << std::endl;
        ret = ret->next;

    }
   
    std::cout << "Hello World!\n";
}

