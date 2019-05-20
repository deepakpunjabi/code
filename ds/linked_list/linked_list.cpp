#include <iostream>

using namespace std;

class node {
   public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    node* insertFront(node* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        node* tmp = new node(data);
        tmp->next = head->next;
        head = tmp;

        return tmp;
    }

    node* insertBack(node* head, int val) {
        node *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        node *new_node = new node(val);
        tmp->next = new_node;

        return new_node;
    }

    // NULL indicates error in inserting
    node* insertAt(int val, int at) {
        return NULL;
    }

    node* insert(int data) { return NULL; }

    node* search(int data) { return NULL; }

    node* remove(int data) { return NULL; }

    node* update(int prev, int next) { return NULL; }
};

int main() {}