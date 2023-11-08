#ifndef QUEUE_H
#define QUEUE_H


template <typename type>
class Queue {
    class QueueNode
{
    public:
        type item;
        QueueNode* next;
};

        int siz;
        QueueNode* Front;
        QueueNode* rear;
    public:
        Queue()
        {
            this->siz = 0;
            this->Front = nullptr;
            this->rear = nullptr;
        }  

       void push(type e)
        {
            QueueNode* temp = new QueueNode;
            
            if (temp)
            {
                temp->item = e;
                temp->next = nullptr;
            if (!this->rear)
            {
               this->Front = temp;
            }
            this->rear = temp;
            this->siz++;
            }
        }

        type pop()
        {       
                QueueNode* temp = this->Front;
                type e = this->Front->item;

                this->Front = this->Front->next;
                delete temp;
                temp = nullptr;
                this->siz--;
                return (e);
        }

        type front()
        {
            type e  = this->Front->item;
            return (e);
        }

        type back()
        {
            type e = this->rear->item;
        }

        int size()
        {
            return (this->siz);
        }

        bool empty()
        {
            return (!this->Front);
        }

        void clear()
        {
          while(this->Front != nullptr)
          {
            this->rear = this->Front->next;
            delete this->Front;
            this->Front = this->rear;
            
          }
            this->siz = 0;
        }

};

#endif