#ifndef __LINK_H__
#define __LINK_H__

#include "CNode.h"

class CNode;

struct Link {
public:
    int weight;
    bool run;
    CNode* to;
};

#endif /* __LINK_H__ */
