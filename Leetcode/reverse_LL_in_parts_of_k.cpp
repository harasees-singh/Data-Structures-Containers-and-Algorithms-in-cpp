#include"linked_list_basics.cpp"
const int k=3;
node* reverse_k_at_a_time(node* curr_head)
{
    if(!curr_head) return NULL;
    int i=0;
    node* previous = NULL;
    node* copy_head = curr_head;
    while(i<k && curr_head)
    {    
        node* temp = curr_head->next;
        curr_head->next = previous;
        previous= curr_head;
        curr_head = temp;
        i++;
    }
    
    copy_head->next = reverse_k_at_a_time(curr_head);
    return previous;
}
int main()
{
    node head(1);
    for(int i=0; i<10; i++)
    {
        InsertAtTail(&head, i+2);
    }
    cout << "working fine" << endl;
    node*new_head = reverse_k_at_a_time(&head);
    cout << "fine" << endl;
    Display(new_head);

}