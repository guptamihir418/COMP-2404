// Mihir Gupta
// 101172281
#ifndef MATCHLISTBYSCORE_H
#define  MATCHLISTBYSCORE_H

#include "MatchList.h"
#include "Match.h"

class MatchListByScore : public MatchList

{

    public:
        MatchListByScore();
        void add(Match*);
};

#endif