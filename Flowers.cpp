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
class pollinator 
{
 string _type;
 string canpollinate;
 bool haspollen=false;
 public:
 pollinator(string typeX){ settype(typeX); };
 void const settype (string _inputtype){
     vector<string> possibletypes = {"insect","bird","bat","wind"};
    string typeY;
            typeY = decapitalize(_inputtype);
            for (int i=0;i<possibletypes.size();i +=1){
                if (typeY == possibletypes[i]) {
                _type = typeY;
                return;
            }
        
}
throw invalid_argument("invalid pollinator type");
}
void const setcnplnt(string flower_type){
    canpollinate=flower_type;
}
string const getcnplnt(){ return canpollinate;}
string const gettype(){
    return _type;
}
void collectpln(){haspollen=true;}
void rmpollen(){haspollen=false;}
bool Haspollen(){return haspollen;}
};
//my base class
class flower{
    protected:
    vector<string> acceptable_pollinators;
    vector<string> possiblecolors;
    string color;
    int fertneed;
    int waterneed;
    bool fertilized=false;
    bool watered=false;
    bool condition=false;
    bool pollinated=false;
    void plnmaketrue(){
        pollinated=true;
    }
    public :
    bool Pollinated(){return pollinated;}
    void water(int &wateramount){
        if (waterneed<=wateramount)
        {
            wateramount -=waterneed;
            waterneed=0;
            cout<<"Congrats! your flower has been watered !! "<<endl;
            watered=true;
        }
        else{
            throw invalid_argument("not enough water :,(");
        }
    } 
    void fertilize (int &fertamount){
            if (fertneed<=fertamount)
        {
            fertamount-=fertneed;
            fertneed = 0;
            cout<<"Congrats! your flower has been fertilized !! "<<endl;
            fertilized=true;
        }
        else{
            throw invalid_argument("not enough fertilizer  :,(");
        }
    } 
    bool checkcondition(){
        if (watered || fertilized)
        condition=true;
        else
        condition=false;
        return condition;
    }
    void setcolor (string& colorname)
    {
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
        void givepollen(pollinator& inputpl) {
        if (plncompatible(inputpl))
        {
        inputpl.collectpln();
        return;
        }
        cout<<"This pollinator cannot collect pollen from this flower, try again"<<endl;
    }
    void pollinate (pollinator inputpl) {
        if (plncompatible(inputpl))
        {
        plnmaketrue();
        inputpl.rmpollen();
        }
        else
        {
            cout<<"this pollinator cannot pollinate your flower "<<endl;
        }
    }
    bool plncompatible(pollinator inputpl){
     for (int i=0; i<acceptable_pollinators.size(); i++){
        if (inputpl.gettype()==acceptable_pollinators[i]){return true;}
     }
     return false;}
    string const getcolor() { return color;}
    virtual void dethorn() {throw invalid_argument("this flower doesnt have thorns");}
    virtual bool dethornned() { return false; } // default implementation
    virtual void prune(){};
    virtual bool is_pruned(){return false;}// default implementation
    virtual ~flower() {}
    };

 class rose : public flower {
        bool dethorned = false; //roses have thorns so yea.
        public:
        rose() {
        possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
        acceptable_pollinators = {"insect"};
        fertneed=10;
        waterneed=15;
        possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
    };
        rose(string _color){
             possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            setcolor(_color);
            acceptable_pollinators = {"insect"};
            fertneed=10;
            waterneed=15;
            }; 
        void dethorn()override{
            dethorned=true;
            cout<<"your flower has been de-thorned"<<endl;
        }
        bool dethornned () override {
            return dethorned;
        }
    };
class daisy : public flower {
        int fertneed=8;
        int waterneed=10;
        public:
        daisy() {
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
        acceptable_pollinators = {"insect"};
        fertneed=8;
        waterneed=10;
    };
        daisy(string _color){
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
        setcolor(_color);
        acceptable_pollinators = {"insect"};
        fertneed=8;
        waterneed=10;
}
};
class sage : public flower {
    bool pruned = false;
    public:
    sage() {
    possiblecolors = {"blue", "purple", "red", "pink", "white", "yellow", "orange"};
    acceptable_pollinators = {"bird", "insect"};
    fertneed=1;
    waterneed=2;
    };
    sage(string _color){
        possiblecolors = {"blue", "purple", "red", "pink", "white", "yellow", "orange"};
        setcolor(_color);
        acceptable_pollinators = {"bird", "insect"};
        fertneed=1;
        waterneed=2;
    }; 
     void prune() {
        if (is_pruned()) {
            cout << "This sage plant has already been pruned." << endl;
            return;
        }
        cout << "Pruning the sage plant..." << endl;
        pruned = true;
    }
        bool is_pruned() {
        return pruned;
    }

};

// my not so humble tests
void testPollinatorType() {
    pollinator pollinatorA("insect");
    pollinator pollinatorB("bird");
    assert(pollinatorA.gettype() == "insect");
    assert(pollinatorB.gettype() == "bird");
}

void testPollinatorPollenCollection() {
    pollinator pollinatorA("insect");
    flower* testflower = new rose();
    testflower->givepollen(pollinatorA);
    assert(pollinatorA.Haspollen());
}

void testRoseColor() {
    flower* testflower = new rose("Red");
    assert(testflower->getcolor() == "red");
    testflower = new rose("InvalidColor");
    assert(testflower->getcolor() == "unknown");
    delete testflower;
}

void testDaisyColor() {
    flower* testflower = new daisy("White");
    assert(testflower->getcolor() == "white");
    testflower = new daisy("InvalidColor");
    assert(testflower->getcolor() == "unknown");
    delete testflower;
}

void testRoseFertilization() {
    flower* testflower = new rose();
    int fertamount = 20;
    testflower->fertilize(fertamount);
    assert(testflower->checkcondition());
    delete testflower;
}

void testDaisyFertilization() {
    flower* testflower = new daisy();
    int fertamount = 20;
    testflower->fertilize(fertamount);
    assert(testflower->checkcondition());
    delete testflower;
}

void testRoseWatering() {
    flower* testflower = new rose();
    int wateramount = 20;
    testflower->water(wateramount);
    assert(testflower->checkcondition());
    delete testflower;
}

void testDaisyWatering() {
    flower* testflower = new daisy();
    int wateramount = 20;
    testflower->water(wateramount);
    assert(testflower->checkcondition());
    delete testflower;
}

void testRosePollination() {
    flower* testflower = new rose();
    pollinator pollinatorA("insect");
    testflower->givepollen(pollinatorA);
    testflower->pollinate(pollinatorA);
    assert(testflower->Pollinated());
    delete testflower;
}

void testDaisyPollination() {
    flower* testflower = new daisy();
    pollinator pollinatorA("insect");
    testflower->givepollen(pollinatorA);
    testflower->pollinate(pollinatorA);
    assert(testflower->Pollinated());
    delete testflower;
}

void testRoseDeThorning() {
    rose* testrose = new rose();
    assert(testrose->dethornned() == false);
    testrose->dethorn();
    assert(testrose->dethornned());//sorry for this horrible mess im running out of words
    delete testrose;
}

void testSagePollinatorPollenCollection() {
    pollinator pollinatorA("insect");
    flower* testflower = new sage();
    testflower->givepollen(pollinatorA);
    assert(pollinatorA.Haspollen());
    delete testflower;
}

void testSageColor() {
    flower* testflower = new sage("Blue");
    assert(testflower->getcolor() == "blue");
    testflower = new sage("InvalidColor");
    assert(testflower->getcolor() == "unknown");
    delete testflower;
}

void testSageCondition() {
    flower* testflower = new sage();
    int wateramount = 10;
    int fertamount = 10;
    testflower->water(wateramount);
    testflower->fertilize(fertamount);
    assert(testflower->checkcondition());
    delete testflower;
}

void testSagePollination() {
    flower* testflower = new sage();
    pollinator pollinatorA("bird");
    testflower->givepollen(pollinatorA);
    testflower->pollinate(pollinatorA);
    assert(testflower->Pollinated());
    delete testflower;
}
void testSagePrune() {
    flower* testflower = new sage("purple");
    assert(!testflower->is_pruned());
    testflower->prune();
    assert(testflower->is_pruned());
    delete testflower;
}
int main() {
    testPollinatorType();
    testPollinatorPollenCollection();
    testRoseColor();
    testDaisyColor();
    testRoseFertilization();
    testDaisyFertilization();
    testRoseWatering();
    testDaisyWatering();
    testRosePollination();
    testDaisyPollination();
    testRoseDeThorning();
    testSagePollination();
    testSageColor();
    testSagePollinatorPollenCollection();
    testSageCondition();
    testSagePrune();
    return 0;
}