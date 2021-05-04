#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node() : next(NULL) {}
    Node(int v) : value(v), next(NULL) {}
};
class CIS14 {
public:
    Node* getClosestCommonWaypoint(Node* A, Node* B);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with a method called getClosestCommonWaypoint(...)
//  you will implement.
// ------------------------------------------------------------
 
/**
 * PURPOSE: Returns the closest common waypoint from any given two path input, Node* A and Node* B
 * PARAMETERS: Node* A, Node* B
 * RETURN VALUES: Node*
 * FUNCTION SIGNATURE: Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B)
 */
Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B) {
    Node* B1 = B;
    while (A != nullptr){
        while(B != nullptr){
            if (A == B)
                return A;
            B = B->next;
        }            
        A = A->next;
        B = B1;
    }        
}

int main()
{
    // EXAMPLE: there are two lists, a1 and b1. Both lists
    // intersect at c1.
    //
    //         a1->a2 
    //               \
    //                c1 -> c2 -> nullptr
    //               /
    // b1->b2->b3->b4
    Node a1(1), a2(2), b1(11), b2(12), b3(13), b4(14), c1(21), c2(22);
    a1.next=&a2; a2.next=&c1; 
    c1.next=&c2; c2.next=nullptr;
    b1.next=&b2; b2.next=&b3; b3.next=&b4; b4.next=&c1;
    
    CIS14 cis14;
    Node* intersection = cis14.getClosestCommonWaypoint(&a1, &b1);
    
    // you may compare the memory location of the intersection node from
    // your answer to the actual node's memory location to verify that 
    // your solution is correct. Note this is just an arbitrary test case. 
    // Your method will be tested with other random test cases.
    cout << (intersection == &c1) << endl; // this should return 1 or true

    return 0;
}