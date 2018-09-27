#include <iostream>

struct ListNode {
    int value;
    ListNode* pNext;
};

void PrintList(ListNode* first) {
    bool firstEl = true;
    while(first != NULL) {
        if(!firstEl) {
            std::cout << ' ';
        }

        firstEl = false;
        std::cout << first->value;
        first = first->pNext;
    }
}

ListNode* Add(ListNode* first, int number) {
    ListNode* temp = new ListNode;

    temp->value = number;
    temp->pNext = first;

    return temp;
}

void DeleteDuplicates(ListNode* pSortedList) {
    ListNode* head = pSortedList;

    while(pSortedList != NULL) {
        if(head->pNext == NULL) {
            std::cout << head->value;
            break;
        }

        if(head->value != head->pNext->value) {
            std::cout << head->value << ' ';
        }

        head = head->pNext;
    }
}

int main() {
    ListNode* head = NULL;

        head = Add(head, 4);
        head = Add(head, 3);
        head = Add(head, 2);
        head = Add(head, 2);
        head = Add(head, 1);
        head = Add(head, 1);


    PrintList(head);
    std::cout << std::endl;

    DeleteDuplicates(head);
    std::cout << std::endl;

    return 0;
}

/*#include <iostream>

struct ListNode {
    int value;
    ListNode* pNext;
};

class List {
    ListNode* Head;
public:
    List(){ Head = NULL;}
    ~List();

    void Add(const int& x);
    void Show();
};

List::~List() {
    while(Head != NULL) {
        ListNode* temp = Head->pNext;
        delete Head;
        Head = temp;
    }
}

void List::Add(const int& x) {
    ListNode* temp = new ListNode;
    temp->value = x;
    temp->pNext = Head;
    Head = temp;
}

void List::Show() {
    ListNode* temp = Head;
    bool first = true;

    while(temp != NULL) {
        if(!first) {
            std::cout << ' ';
        }

        first = false;
        std::cout << temp->value;
        temp = temp->pNext;
    }
}

void RemoveDuplicates(ListNode * pSortedList) {
    ListNode* bufI = 0;
    bool firstWasChanged = false;
    for(ListNode* i = pSortedList; i; i = i->pNext) {
        if(firstWasChanged) {
            i = pSortedList;
            firstWasChanged = false;
        }

        bool isDuplicate = false;
        ListNode* bufJ = pSortedList;

        for(ListNode* j = pSortedList; j; j->pNext) {
            if(i->value == j->value && i != j) {
                bufJ->pNext = j->pNext;
                delete j;
                j = bufJ;
                isDuplicate = true;
            }

        if(isDuplicate) {
            if(i == pSortedList) {
                bufI = i->pNext;
                delete i;
                i = bufI;
                pSortedList = i;
                if(!i) std::cout << "return 0" << std::endl;
                firstWasChanged = true;
            } else {
                bufI->pNext = i->pNext;
                delete i;
                i = bufI;
            }
        }
        bufI = i;
        }
        std::cout << pSortedList << ' ';
    }
}

int main() {
    List myList;

    for(int i = 5; i >= 0; --i) {
        myList.Add(i);
    }

    myList.Show();
    std::cout << std::endl;

    RemoveDuplicates(head);

    return 0;
}*/
