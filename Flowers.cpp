#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
string decapitalize(const string& str);
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
            cout<<"Congrats! your flower has been watered !! "<<endl;
            watered=true;
        }
        else{
            cout<<"not enough water :,("<<endl;
        }
    } 
    void fertilize (int &fertamount){
              if (fertneed<=fertamount)
        {
            fertamount-=fertneed;
            cout<<"Congrats! your flower has been fertilized !! "<<endl;
            fertilized=true;
        }
        else{
            cout<<"not enough fertilizer  :,("<<endl;
        }
    } 
    bool checkcondition(){
        if (watered || fertilized)
        condition=true;
        else
        condition=false;
        return condition;
    }
    virtual void setcolor (const string& colorname) = 0;
    virtual string const getcolor() = 0;
    virtual ~flower() {}
    };

    class rose : public flower {
        string color;
        int fertneed=10;
        int waterneed=15;
        bool dethorned = false;
        public:
        void setcolor (const string& colorname) override
        {
            vector<string> possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            string colorname_;
            colorname_ = decapitalize(colorname);
            for (int i=0;i<possiblecolors.size();i +=1){
                if (colorname_ == possiblecolors[i]) {
                color = colorname_;
                return;
            }
            }
             cout << "input invalid, or the color is not a natural accuring color of this flower. " << endl;
        color = "unknown"; // set default color
        }
        string const getcolor() override {
            return color;
        }
        void dethorn(){
            dethorned=true;
            cout<<"your flower has been de-thorned"<<endl;
        }
    };
class daisy : public flower {
            string color;
        int fertneed=8;
        int waterneed=10;
        public:
        void setcolor (const string& colorname) override
        {
            vector<string> possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
            string colorname_;
            colorname_ = decapitalize(colorname);
            for (int i=0;i<possiblecolors.size();i +=1){
                if (colorname_ == possiblecolors[i]) {
                color = colorname_;
                return;
            }
            }
             cout << "input invalid, or the color is not a natural accuring color of this flower. " << endl;
        color = "unknown"; // set default color
        }
        string const getcolor() override {
            return color;
        }
        };

// my humble tests
void TEST ()
{
    flower* testflower = new rose();
    int wateramount = 0;
    int fertamount = 20;
    string colorname = "Red";
    testflower->setcolor(colorname);
    testflower->fertilize(fertamount);
    testflower->water(wateramount);
    bool con = testflower->checkcondition();
    assert(!con);
    assert(testflower->getcolor()=="red");
    flower* testflower2 = new daisy();
    flower* testflower3 = new daisy();
    testflower2->setcolor("White");
    assert(testflower2->getcolor()=="white");
    assert(!testflower2->checkcondition())
    pollinator pollinatorA("insect");
    pollinator pollinatorB("bird");
    pollinatorA.take_pollen(testflower2);
    pollinatorB.take_pollen(testflower2);
    testflower3->pollinate(pollinatorA);
    assert(!pollinatorB.haspollen);
    assert(testflower3->pollinated());
}
int main()
{
TEST();
return 0;
}