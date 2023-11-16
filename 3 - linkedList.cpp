#include <iostream>

using namespace std;

class Node {
    public:
        int val; //data stored in node
        Node* next; //pointer to next node in linked list
        
        Node(int num) {
            val = num; //set value stored by node
            next = nullptr; //points to null since no next node yet
        }
};

class LinkedList {
    public:
        Node* head; //pointer to start element of list
        
        LinkedList() {
            //initialize both pointers to nullptr because the list starts empty
            head = nullptr;
        }
        
        void insertNode(int num) { //insert at beginning
            Node* newNode = new Node(num); //create pointer to new node
            newNode->next = head; //set next pointer of new node to point to node currently at start of list (head)
            
            head = newNode; //update head pointer to the new node that was placed at the start
        }
        
        void deleteNode(int pos) { //delete from specified position, with head node being position "0"
            if(head == nullptr) { //if list is empty, cannot delete any nodes
                cout << "Cannot delete node: Linked List is Empty.\n";
                return;
            }
            
            if(pos == 0) { //if first element needs to be deleted
                head = head->next; //only need to adjust head pointer because no nodes come before element
                //cout<<"pos0\n";
                return;
            }
            
            Node* prev = head;
            //if node to be deleted is not at beginning of list, find next pointer of element before it in list to update and remove link
            for(int i = 0; i < pos-1; i++) { //will run until pos of node being deleted to obtain previous node
                prev = prev->next; //iterate to next node
                if(prev == nullptr || prev->next == nullptr) { //if the requested position is not present in the list
                    cout << "Cannot delete node: Position Out of List Range.\n";
                    return;
                }
            }
           
            cout<< prev->next->val <<" was deleted.\n"; //debug
            prev->next = prev->next->next; //remove the link the node that is being removed, instead make it point to the node after it    
        }
        
        int search(int pos) { //find value stored at position pos, with head node being position "0"
            Node* curr = head;
            
            for(int i = 0; i < pos; i++) { //will run until node at position is reached
                curr = curr->next; //iterate to next nod
                if(curr == nullptr) { //check that node is contained in the list, return error (-99) if not in range
                    cout << "Cannot find node: Position Out of List Range.\n";
                    return -99;
                }
            }
            return curr->val; //return value stored in node at requested location
        }
        
        void display() {
            Node* curr = head; //set current node to head/start node
            
            while(curr!=nullptr) { //while the current node is not null (after the last node)
                cout << curr->val << " -> "; //print out value stored in current node
                curr = curr->next; //update current node to the next node in the list
            }
            cout << "nullptr\n"; //prints nullptr to show end of list
        }
};

int main()
{
    class LinkedList list1 = LinkedList();
    
    list1.insertNode(12);
    list1.insertNode(13);
    list1.insertNode(14);
    list1.insertNode(15);
    list1.insertNode(16);
    list1.insertNode(17);
    list1.insertNode(18);
    list1.insertNode(19);
    list1.insertNode(20);
    list1.insertNode(21);
    list1.insertNode(22);
    list1.insertNode(23);
    
    list1.display();
    
    list1.deleteNode(2);
    list1.display();
    cout<<list1.search(6) <<"\n";
    
    list1.display();
    
    return 0;
}