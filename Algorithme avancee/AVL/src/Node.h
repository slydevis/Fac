#ifndef __NODE_H__
#define __NODE_H__

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
    unsigned getKey() const;
    unsigned getH() const;
    Node* getLeftNode() const;
    Node* getRightNode() const;
    void display() const;
};

#endif /* __NODE_H__ */
