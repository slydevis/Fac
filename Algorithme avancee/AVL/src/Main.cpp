#include <iostream>
#include "Node.h"
#include "AVL.h"

using namespace std;

int main() {

    std::cout << "Debut" << std::endl;

    Node racine;
    Node filsdroit;
    Node filsgauche;
    Node filsdroit2;
    AVLTree tree;


    filsdroit.setKey(1);
    filsgauche.setKey(2);
    racine.setLeftNode(&filsgauche);
    racine.setRightNode(&filsdroit);

    tree.add(racine);
    tree.add(filsdroit);
    tree.add(filsdroit2);
    tree.add(filsgauche);

    std::cout << tree.toString() << std::endl;

    std::cout << "Fini" << std::endl;
    // racine.display();
    return 0;
}
