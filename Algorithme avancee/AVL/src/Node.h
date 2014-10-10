#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node
{
private :
    unsigned m_key;
    unsigned m_h;
    Node* m_leftNode;
    Node* m_rightNode;
public :
    Node();
    void setLeftNode(Node* node);
    void setRightNode(Node* node);
    void setKey(unsigned key);
    void setH(unsigned h);
    std::string toString() const;
    unsigned getKey() const;
    unsigned getH() const;
    Node* getLeftNode() const;
    Node* getRightNode() const;
    int maxHeight(Node *p);
};

#endif /* __NODE_H__ */
