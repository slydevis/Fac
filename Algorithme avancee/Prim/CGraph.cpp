#include "CGraph.h"
#include <limits>

#include <iostream>
CGraph CGraph::prim() const {

	CGraph outputPrim;

	// Sommet début de l'algorithme

	std::vector<CNode*> tabArreteTraversante;

	// Sommet début de l'algorithme

	outputPrim.add(tabNodes[0]->getKey());

	tabArreteTraversante.push_back(tabNodes[0]);

	while(tabArreteTraversante.size() < tabNodes.size())
	{
		Link link;
		int minWeight = std::numeric_limits<int>::max();

		for(unsigned i = 0; i < tabArreteTraversante.size(); ++i)
		{
			std::cout << tabArreteTraversante[i]->getKey() << std::endl;
		}

		unsigned key;
		for(unsigned i = 0; i < tabArreteTraversante.size(); ++i)
		{
			Link linkBuff = tabArreteTraversante[i]->getMinLink();

			if(minWeight >= linkBuff.weight)
			{
				link = linkBuff;
				minWeight = linkBuff.weight;
				key = tabArreteTraversante[i]->getKey();
			}
		}

		if(link.to != NULL)
			tabArreteTraversante.push_back(link.to);

		outputPrim.add(link.to->getKey(), key, link.weight);

		// Pour le calcul de l'ultrametrique

	}

    return outputPrim;
}

std::string CGraph::toString() const {
	std::string str = "";
	for(unsigned i = 0; i < tabNodes.size(); ++i)
	{
		CNode* node = tabNodes[i];
		str += node->toString();
	}
    return str;
}

void CGraph::add(int Inode, int key, int poids) {
	CNode* node = new CNode(Inode);

	if(tabNodes.size() != 0)
	{
		for(unsigned i = 0; i < tabNodes.size(); ++i)
			if(tabNodes[i]->getKey() == Inode)
				return;

		for(unsigned i = 0; i < tabNodes.size(); ++i)
		{
			if(tabNodes[i]->getKey() == key)
				node->link(tabNodes[i], poids);
		}
	}

	tabNodes.push_back(node);
}

void CGraph::link(int Inode, int key, int poids) {
	for(unsigned i = 0; i < tabNodes.size(); ++i)
	{
		if(tabNodes[i]->getKey() == Inode)
		{
			for(unsigned j = 0; j < tabNodes.size(); ++j)
			{
				if(tabNodes[j]->getKey() == key)
					tabNodes[i]->link(tabNodes[j], poids);
			}
		}
	}
}

void CGraph::add(int Inode) {
	CNode* node = new CNode(Inode);

	if(tabNodes.size() != 0)
		node->link(tabNodes[0], 1);

	tabNodes.push_back(node);
    return;
}
