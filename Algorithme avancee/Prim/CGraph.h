#ifndef __CGRAPH_H__
#define __CGRAPH_H__

#include <vector>
#include <string>

#include "CNode.h"

class CGraph {
private :
    std::vector<CNode*> tabNodes;
    std::vector<std::vector<int> > tabLink;
    Link getMinLink(CNode* node) const;
public :
    CGraph prim() const;
    std::string toString() const;
    void add(int node);
    void add(int node, int key, int weight);
    void link(int node, int key, int weight);
}; // CGraph

#endif /* __CGRAPH_H__ */
