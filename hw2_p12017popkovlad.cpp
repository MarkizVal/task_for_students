#include <iostream>

struct Node
{
    Node* pNext = nullptr;
    int data;
};

 struct List
{
    Node *pHead = nullptr;
    int len = 0;
};

void Add(List &lst, int date)
{
    Node *new_node = new Node;
    new_node->data = date;
    new_node->pNext = lst.pHead;
    lst.pHead = new_node;
    ++lst.len;
}

void Print(const List& lst)
{
    std::cout << "*************************" << std::endl;
    Node *it = lst.pHead;
    while(it)
    {
        std::cout << it->data << '\t';
        it = it->pNext;
    }
    std::cout << "\n*************************" << std::endl;
}



Node *SearchIt(Node *it, int pos)
{
    for(int i = 0; i < pos; ++i)
    {
        it = it->pNext;
    }
    return it;
}

void Swap(List& lst, int pos1, int pos2)
{
    Node* it1 = SearchIt(lst.pHead, pos1);
    Node* pred1 = lst.pHead;
    Node* next1 = lst.pHead;

    Node* it2 = SearchIt(lst.pHead, pos2);
    Node* pred2 = lst.pHead;
    Node* next2 = lst.pHead;

    if(pred1 == it1)
        pred1 = nullptr;
    else
        while(pred1->pNext != it1)
        {
            pred1 = pred1->pNext;
        }

    if(pred2 == it2)
        pred2 = nullptr;
    else
        while(pred2->pNext != it2)
        {
            pred2 = pred2->pNext;
        }

    next1 = it1->pNext;
    next2 = it2->pNext;

    if (it2 == next1)
    {
        it2->pNext = it1;
        it1->pNext = next2;

        if (it1 != lst.pHead)
            pred1->pNext = it2;
    }
    else
        if (it1 == next2)
        {
            it1->pNext = it2;
            it2->pNext = next1;

            if (it2 != lst.pHead)
                pred2->pNext = it2;
        }
        else
        {
            if (it1 != lst.pHead)
                pred1->pNext = it2;
            it2->pNext = next1;
            if(it2 != lst.pHead)
                pred2->pNext = it1;
            it1->pNext = next2;
        }

        if(it1 == lst.pHead)
            lst.pHead = it2;
}

void SortList(List& lst)
{
    Node *it1 = lst.pHead;
    Node *it2 = lst.pHead;

    for(int i = 0; i < lst.len-1; ++i)
    {
        for(int j = i + 1; j < lst.len; ++j)
        {
            it2 = it2->pNext;
            if(it1->data > it2->data)
            {
                Swap(lst, i, j);
                it2 = SearchIt(lst.pHead, j);
                it1 = SearchIt(lst.pHead, i);
            }

        }
        it1 = it1->pNext;
        it2 = it1;
    }


}

int main()
{
    List my_list;
    Add(my_list, 2);
    Add(my_list, 9);
    Add(my_list, 4);
    Add(my_list, 2);
    Add(my_list, 8);
    Add(my_list, 3);
    Add(my_list, 6);

    Print(my_list);

    SortList(my_list);

    Print(my_list);

    return 0;
}
