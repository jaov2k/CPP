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

    // For debug purposes DELETE ME
    for (int i = 0; i < int1.size(); i++)
        (i != int1.size()-1) ? cout << int1[i] << ", " : cout << int1[i] << endl;
    for (int i = 0; i < int2.size(); i++)
        (i != int2.size()-1) ? cout << int2[i] << ", " : cout << int2[i] << endl;
    for (int i = 0; i < sum.size(); i++)
        (i != sum.size()-1) ? cout << sum[i] << ", " : cout << sum[i] << endl;

    return 0;
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
    Node first1(1);
    
    // , first2(0), first3(9), first4(1);
    // first1.next = &first2;
    // first2.next = &first3;
    // first3.next = &first4;

    // Second input list: 9->9
    Node second1(9), second2(9),second3(9),second4(9),second5(9);
    second1.next = &second2;
    second2.next = &second3;
    second3.next = &second4;
    second4.next = &second5;

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