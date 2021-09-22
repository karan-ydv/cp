/*


int fun(List* curr, List* &head)
{
    if(curr -> next)
    if(fun(curr -> next, head) == 1)
        return 1;
    if(curr -> val % 2 == 0)
    {
        while(head -> val % 2 == 0)
        {
            if(head == curr)    return 1;
            head = head -> next;
        }
        swap(head -> val, curr -> val);
    }
    return 0;
}