#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    Node racine;
    Node filsdroit;
    Node filsgauche;
    Node filsdroit2;

    filsdroit.setKey(1);
    filsgauche.setKey(2);
    racine.setLeftNode(&filsgauche);
    racine.setRightNode(&filsdroit);

    racine.display();
    return 0;
}
