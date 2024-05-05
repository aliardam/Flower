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
    bool checkcondition(){
        if (watered || fertilized)
        condition=true;
        else
        condition=false;
        return condition;
    }
    virtual ~flower() {}
    };

    class rose : public flower {
        int fertneed=10;
        int waterneed=15;

    };



// my humble tests
void TEST ()
{
    flower* testflower = new rose();
    int wateramount = 0;
    int fertamount = 20;
    testflower->setcolor(red);
    testflower->fertilize(fertamount);
    testflower->water(wateramount);
    bool con = testflower->checkcondition();
    assert(!con);
    assert(getcolor==red);
}


int main()
{
TEST();
return 0;
}