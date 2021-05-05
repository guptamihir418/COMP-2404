// Mihir Gupta
// 101172281
#ifndef MATCHLISTBYCLIENT_H
#define  MATCHLISTBYCLIENT_H

#include "MatchList.h"
#include "Match.h"

class MatchListByClient : public MatchList

{

    public:
        MatchListByClient();
        void add(Match*);

};

#endif