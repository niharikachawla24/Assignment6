#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

Node* construct(int mat[3][3], int n, int m) {
    Node* head = NULL;
    Node* rowHead = NULL;
    Node* prevRow = NULL;

    for (int i = 0; i < n; i++) {
        Node* prev = NULL;
        for (int j = 0; j < m; j++) {
            Node* newNode = new Node;
            newNode->data = mat[i][j];
            newNode->next = newNode->prev = newNode->up = newNode->down = NULL;

            if (j == 0) {
                if (i == 0) head = newNode;
                rowHead = newNode;
            } else {
                prev->next = newNode;
                newNode->prev = prev;
            }

            if (prevRow != NULL) {
                Node* upper = prevRow;
                for (int k = 0; k < j; k++)
                    upper = upper->next;
                upper->down = newNode;
                newNode->up = upper;
            }

            prev = newNode;
        }
        prevRow = rowHead;
    }
    return head;
}

void display(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* temp = row;
        for (int j = 0; j < m; j++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    Node* head = construct(mat, 3, 3);

    cout << "Doubly Linked List form:\n";
    display(head, 3, 3);
}
