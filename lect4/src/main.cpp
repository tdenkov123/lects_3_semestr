#include "LinkList.h"

int main(int argc, char* argv[]) {
    LinkList<int> lst;

    lst.appendElement(1, 0);
    lst.appendElement(5, 1);
    lst.appendElement(3, 2);
    lst.appendElement(4, 3);
    lst.appendElement(2, 4);

    lst.PrintList();
    lst.RemoveNode(2);
    lst.PrintList();

    return 0;
}