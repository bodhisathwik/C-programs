
snode*insertNodeBegining(snode*head){
    int val;
    snode *k,*p;
    printf("Enter the node value");
    scanf(" %d", &val);
    p=getNode(val);
    if(!head)
     head=0;
     else{
        k=head;
        head=p;
        p->next=k;
     }
     return head;
}