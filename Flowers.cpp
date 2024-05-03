#include <iostream>
#include <cassert>
using namespace std;

// my humble tests
void TEST ()
{
    flower* testflower = new rose();
    int wateramount = 0;
    int fertamount = 20;
    testflower->fertilize();
    testflower->water();
    bool con = testflower->checkcondition;
    assert(!con);
}


int main()
{
TEST();
return 0;
}