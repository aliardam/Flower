#include <iostream>
#include <cassert>
using namespace std;
//my base class
class flower{
    int fertneed;
    bool fertilized=false;
    int waterneed;
    bool watered=false;
    bool condition=false;
    public :
    void water(int &wateramount){
        if (waterneed<=wateramount)
        {
            wateramount -=waterneed;
            cout<<"Congrats! your flower has been watered !! ";
            watered=true;
        }
        else{
            cout<<"not enough water :,(";
        }
    } 
    void fertilize (int &fertamount){
              if (fertneed<=fertamount)
        {
            fertamount-=fertneed;
            cout<<"Congrats! your flower has been fertilized !! ";
            fertilized=true;
        }
        else{
            cout<<"not enough fertilizer  :,(";
        }
    } 
    } 
};


// my humble tests
void TEST ()
{
    flower* testflower = new rose();
    int wateramount = 0;
    int fertamount = 20;
    testflower->fertilize(fertamount);
    testflower->water(wateramount);
    bool con = testflower->checkcondition();
    assert(!con);
}


int main()
{
TEST();
return 0;
}