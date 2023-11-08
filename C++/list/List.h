#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 *  List - Class to contain our data structure
 *  list node - class contain our node struture
 *
 *  @siz: siz of list
 *  @head: pointer to first element in list
 *  @tail: pointer to tail of the list
 */
template <typename type>
class List
{
private:
    /**
     * list node - class contain our node struture
     *
     * @item: element stored in node
     * @next: pointer to next node
     *
     */
    class listnode
    {
    public:
        type item;
        listnode *next;
    };
    int siz;
    listnode *head;
    listnode *tail;

public:
    List() /*empty constructor to intialize class items*/
    {
        this->siz = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int size() /*return size of list*/
    {
        return (siz);
    }

    bool empty() /*check if list is empty or not*/
    {
        return (!siz);
    }

    int insert(int pos, type e) /*insert in speccific position in list */
    {
        listnode *p, *q;
        int i;
        if (p = new listnode)
        {
            p->item = e;
            p->next = nullptr;

            if (pos == 1)
            {
                p->next = head;
                head = p;
                if (!siz)
                    tail = head;
            }
            else
            {
                for (q = head, i = 1; i < pos - 1; i++)
                    q = q->next;
                p->next = q->next;
                q->next = p;
                if (pos == siz + 1)
                    tail = p;
            }
            siz++;
            return (1);
        }
        return (0);
    }

    int push_front(type e) /*push element in front of list */
    {
        //  listnode *p;
        //  if (p = new listnode)
        // {
        //     p->item = e;
        //     p->next = head;
        //     head = p;
        //     siz++;
        //     return (1);
        // }
        if (insert(1, e))
            return (1);
        return (0);
    }

    int push_back(type e) /*push element in back of list */
    {
        // listnode *p, *q;
        // int i;
        // p->item = e;
        // p->next = nullptr;
        // for (q = head ,i = 1; i < siz ; i++)
        //     q = q->next;
        // p->next = q->next;
        // q->next = p;
        // siz++;
        // return (1);
        if (insert(siz + 1, e))
            return (1);
        return (0);
    }

    type deletelist(int pos)
    {
        if (siz)
        {
            listnode *q, *pt;
            type temp;
            int i;
            if (pos == 1)
            {
                q = head;
                temp = q->item;
                head = head->next;
                delete q;
            }
            else
            {
                for (q = head, i = 1; i < pos - 1 ; i++)
                    q = q->next;
                pt = q->next;
                temp = pt->item;
                q->next = pt->next;
                delete pt;
                if (pos == siz)
                    tail = q;
            }
            siz--;
            return (temp);
        }
        return (0);
    }

    type pop_front() /*pop first element from list*/
    {
        // if (siz)
        // {

        //     listnode *q = head;
        //     type temp = q->item;
        //     head = head->next;
        //     delete q;
        //     siz--;
        //     return (temp);
        // }
        if (siz)
            return (deletelist(1));
        return (0);
    }

    type pop_back() /*pop last element in list*/
    {
        // if (siz)
        // {
        //     listnode *q;
        //     int i;
        //     for (q = head, i = 1; i < siz; i++)
        //         q = q->next;
        //     type temp = q->item;
        //     delete q;
        // }
        if (siz)
            return (deletelist(siz));
        return (0);
    }

    type front() /*return copy of first element in list*/
    {
        return (head->item);
    }

    type back() /*return copy of last element in list*/
    {
        return (tail->item);
    }
};

#endif /*LINKED_LIST_H*/