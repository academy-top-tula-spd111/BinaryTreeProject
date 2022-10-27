#include <iostream>
#include "BinaryTree.h"

bool XOR(bool a, bool b)
{
    return ((a && !b) || (!a && b));
}

int main()
{
    //BinaryTree<int>* treeInt = new BinaryTree<int>();

    /*treeInt->AddLoop(20);
    treeInt->AddLoop(5);
    treeInt->AddLoop(15);
    treeInt->AddLoop(25);
    treeInt->AddLoop(7);
    treeInt->AddLoop(30);*/

    /*treeInt->AddReq(20);
    treeInt->AddReq(5);
    treeInt->AddReq(15);
    treeInt->AddReq(25);
    treeInt->AddReq(7);
    treeInt->AddReq(30);
    treeInt->AddReq(21);*/

    /*treeInt->Print();
    std::cout << "\n";

    Node<int>* nodeFind;
    nodeFind = treeInt->Search(5);

    treeInt->PrintReq(nodeFind);
    std::cout << "\n";

    std::cout << treeInt->MaxTree()->value << "\n";
    std::cout << treeInt->Max(nodeFind)->value << "\n";
    std::cout << treeInt->MinTree()->value << "\n";
    std::cout << treeInt->Min(treeInt->Search(25))->value << "\n";*/

    std::cout << XOR(0, 0) << "\n";
    std::cout << XOR(1, 0) << "\n";
    std::cout << XOR(0, 1) << "\n";
    std::cout << XOR(1, 1) << "\n";

    //delete treeInt;
}
