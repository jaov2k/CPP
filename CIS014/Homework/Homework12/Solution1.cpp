#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class CIS14
{
public:
    Node* addLists(Node*, Node*);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// ------------------------------------------------------------

// Optional: you may add any global function, variables here

/**
 * PURPOSE: Adds two integers, returning the sum. Integers are in the form of linked lists
 *          and single digits are a node in the linked list. The sum is also a linked list
 *          which is returned.
 * PARAMETERS: Node* l1, Node* l2
 * RETURN VALUE: Node*
 * FUNCTION SIGNATURE: Node* addLists(Node* l1, Node* l2)
*/
Node* CIS14::addLists(Node* l1, Node* l2) {
    int sizeL1 = 0, sizeL2 = 0;
    vector<int> list1, list2;

    while (l1 != nullptr){
        list1.push_back((*l1).val);
        l1 = l1->next;
    }
    while (l2 != nullptr){
        list2.push_back((*l2).val);
        l2 = l2->next;
    }

    for (int i = 0; i < list1.size(); i++)
        (i != list1.size()-1) ? cout << list1[i] << ", " : cout << list1[i] << endl;
    for (int i = 0; i < list2.size(); i++)
        (i != list2.size()-1) ? cout << list2[i] << ", " : cout << list2[i] << endl;
};

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    // The example uses declared node instances. You may dynamically
    // allocate your nodes as well for the same effect. If so, 
    // just remember to deallocate them after use to avoid memory
    // leaks.

    // First input list: 2->3->4->8
    Node first1(2), first2(3), first3(4), first4(8);
    first1.next = &first2;
    first2.next = &first3;
    first3.next = &first4;

    // Second input list: 9->9
    Node second1(9), second2(9);
    second1.next = &second2;

    // Adding:
    //    2->3->4->8
    //          9->9
    // -------------
    //    2->4->4->7
    Node* ans = cis14.addLists(&first1, &second1);

    // You may use the following code to print your list
    Node* tmp = ans;
    while (tmp != nullptr)
    {
        (tmp->next != nullptr) ? 
            cout << tmp->val << "->" : 
            cout << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;

    // If your add(...) method allocated heap memory, you
    // should deallocate them here to avoid memory leaks. 

    return 0;
}