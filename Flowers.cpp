#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
string decapitalize(const string& str);
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
        string color;
        int fertneed=10;
        int waterneed=15;
        public:
        void setcolor(string colorname)
        {
            string red, pink, white, yellow, orange, peach, purple; 
            vector<string> possiblecolors = {red, pink, white, yellow, orange, peach, purple };
            colorname = decapitalize(colorname);
            for (int i=0;i<possiblecolors.size();i +=1){
                if (colorname==possiblecolors[i]){
                    color=colorname;
                }
                else{
                    cout<<"input invalid, or the color is not a natural accuring color of this flower. "<<endl;
                }
            }
        }
        string const getcolor() const {
            return color;
        }

    };



// my humble tests
void TEST ()
{
    flower* testflower = new rose();
    int wateramount = 0;
    int fertamount = 20;
    testflower->setcolor(Red);
    testflower->fertilize(fertamount);
    testflower->water(wateramount);
    bool con = testflower->checkcondition();
    assert(!con);
    assert(testflower->getcolor()==red);
}


int main()
{
TEST();
return 0;
}
//ngl i found this online
string decapitalize(const string& str) {
    string result;

    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            result += c + 32; // convert to lowercase
        } else {
            result += c;
        }
    }

    return result;
}