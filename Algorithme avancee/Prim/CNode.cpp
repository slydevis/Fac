#include <vector>
#include <sstream>
#include <iostream>
#include <limits>
#include "CNode.h"

CNode::CNode(int key): IKey(key), parent(NULL) {}

int CNode::getKey() const {
    return this->IKey;
}

std::vector<Link> CNode::getLink() const {
    return this->tabLink;
}

void CNode::setKey(int key) {
    IKey = key;
}

void CNode::link(CNode* node, int weight) {
    Link newLink;
    newLink.weight =  weight;
    newLink.to = this;
    newLink.run = false;
    //node->setParent(this);
    node->tabLink.push_back(newLink);
}

std::string CNode::toString() const {
	std::ostringstream os;
	for(unsigned i = 0; i < this->tabLink.size(); ++i)
	{
		os << this->IKey << " -- "
		   << tabLink[i].to->IKey
		   << " [label=\" " << tabLink[i].weight << "\", arrowtail=dot, arrowhead=open];\n";
	}
	return os.str();
}

Link CNode::getMinLink() {

	Link minNode;

	minNode.to = NULL;
	minNode.weight = std::numeric_limits<int>::max();

	for(unsigned i = 0; i < tabLink.size(); ++i)
	{
		if(minNode.weight > tabLink[i].weight)
		{
			if(!tabLink[i].run)
			{
				tabLink[i].run = true;
				minNode = tabLink[i];
			}
		}
	}

	return minNode;
}
