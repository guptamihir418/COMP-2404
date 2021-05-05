// Mihir Gupta
// 101172281
#ifndef LIST_H
#define LIST_H

#include "Match.h"

class MatchList
{

    public:
        MatchList();
        ~MatchList();
        void print();
        void cleanup();

    protected:

        class Node
            {
            public:
                Match*   data;
                Node*    next;
            };

            protected:
                Node* head;

};

#endif

