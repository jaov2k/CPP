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
 * PURPOSE: Returns a vector. Creates vector from linked lists,
 *          allowing access to vector methods.
 * PARAMETERS: Node* linkedList
 * RETURN VALUE: vector<int>
 * FUNCTION SIGNATURE: vector<int> linkedListToVector(Node* linkedList)
*/
vector<int> linkedListToVector(Node* linkedList) {
    vector<int> vec;
    while (linkedList != nullptr) {
        vec.push_back((*linkedList).val);
        linkedList = linkedList->next;
    }
    return vec;
}

/**
 * PURPOSE: Returns void. Vectors are passed by reference.
 *          Pads the vector with leading zeros to facilitate looping 
 *          and avoid boundary checking. 
 * PARAMETERS: vector<int>* v1, vector<int>* v2
 * RETURN VALUE: void
 * FUNCTION SIGNATURE: void leadingZeros(vector<int>* v1, vector<int>* v2)
*/
void leadingZeros(vector<int>* v1, vector<int>* v2) {
    while (v1->size() < v2->size())
            v1->insert(v1->begin(), 0);
    while (v2->size() < v1->size())        
            v2->insert(v2->begin(), 0);
}

/**
 * PURPOSE: Returns void. Creates a new Node.
 * PARAMETERS: Node** root, int item
 * RETURN VALUE: void
 * FUNCTION SIGNATURE: void newNode(Node** root, int item)
*/
void newNode(Node** root, int num)
{
    Node* temp = new Node(num);
    Node* ptr;
  
    if (*root == nullptr)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

/**
 * PURPOSE: Returns the starting Node address of a linked list.
 *          Takes a vector, creating a Node from each element
 * PARAMETERS: vector<int>* vec
 * RETURN VALUE: Node*
 * FUNCTION SIGNATURE: Node* vectorToLinkedList(vector<int>* vec)
*/
Node* vectorToLinkedList(vector<int>* vec){
    Node* root = nullptr;
    for (int i = 0; i < vec->size(); i++)
        newNode(&root, (*vec)[i]);
    return root;
}

/**
 * PURPOSE: Adds two integers, returning the sum. Integers are in the form of linked lists
 *          and single digits are a node in the linked list. The sum is also a linked list
 *          which is returned.
 * PARAMETERS: Node* l1, Node* l2
 * RETURN VALUE: Node*
 * FUNCTION SIGNATURE: Node* addLists(Node* l1, Node* l2)
*/
Node* CIS14::addLists(Node* l1, Node* l2) {
    vector<int> int1, int2;
    int carryOne = 0;

    // Convert linked list to vectors
    int1 = linkedListToVector(l1);
    int2 = linkedListToVector(l2);

    // Balance the two vectors if not the same number of positions
    if (int1.size() != int2.size())
        leadingZeros(&int1, &int2);

    // Add the two integers and store it in new vector
    vector<int> sum(int1.size(),0);
    for (int i = int1.size() - 1; i >= 0; i--){
        sum[i] = (int1[i] + int2[i] + carryOne) % 10;
        carryOne = (int1[i] + int2[i] + carryOne) / 10;
    }

    // If a carried 1 remains then add it to the front
    if (carryOne != 0){
        sum.insert(sum.begin(),carryOne);
    }
    
    return vectorToLinkedList(&sum);
};

// You may use the following code to print your list
void printList (Node* ans){
    Node* tmp = ans;
    while (tmp != nullptr)
    {
        (tmp->next != nullptr) ? 
            cout << tmp->val << "->" : 
            cout << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;   
}

// Function to delete an entire linked list
void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = nullptr;
 
    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = nullptr;
}

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
    printList(ans);

    // third input list: 1
    Node third1(1);

    // fourth input list: 9->9
    Node fourth1(9), fourth2(9);
    fourth1.next = &fourth2;

    // Adding:
    //             1
    //          9->9
    // -------------
    //       1->0->0
    Node* ans2 = cis14.addLists(&third1, &fourth1);
    printList(ans2); 

    // If your add(...) method allocated heap memory, you
    // should deallocate them here to avoid memory leaks. 

    deleteList(&ans);
    deleteList(&ans2);

    return 0;
}