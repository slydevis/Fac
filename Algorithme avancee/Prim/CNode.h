#ifndef __CNODE_H__
#define __CNODE_H__

#include <vector>
#include "Link.h"

class CNode {
private:
    int IKey;
    std::vector<Link> tabLink;
    CNode* parent;
public :
    CNode(int key);
    int getKey() const;
    std::vector<Link> getLink() const;
    void setKey(int key);
    void setParent(CNode* node);
    CNode* getParent() const;
    void link(CNode* node, int weight);
    std::string toString() const;
    Link getMinLink();
};
#endif /* __CNODE_H__ */
