#ifndef __AVL_H__
#define __AVL_H__

#include <vector>
#include "Node.h"

class AVLTree
{
private :
    std::vector<Node> m_tabNode;
public :
    void add(Node node);
    void display() const;
    std::string toString() const;
};
#endif /* __AVL_H__ */
