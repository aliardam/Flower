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
    private:
    int fertneed;
    int waterneed;
    bool fertilized=false;
    bool watered=false;
    bool condition=false;
    bool pollinated=false;
    protected:
    void plnmaketrue(){
        pollinated=true;
    }
    public :
    bool Pollinated(){return pollinated;}
    void water(int &wateramount){
        if (waterneed<=wateramount)
        {
            wateramount -=waterneed;
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
    virtual void setcolor (const string& colorname) = 0;
    virtual string const getcolor() = 0;
    virtual void givepollen(pollinator&)=0;
    virtual void pollinate(pollinator)=0;
    virtual bool dethornned() { return false; } // default implementation
    virtual ~flower() {}
    };

    class rose : public flower {
        string color;
        int const fertneed=10;
        int const waterneed=15;
        bool dethorned = false; //roses have thorns so yea.
        public:
        rose() {
        acceptable_pollinators = {"insect"};
    };
        rose(string _color){
            setcolor(_color);
            acceptable_pollinators = {"insect"};
        }; 
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
                void givepollen(pollinator& inputpl) override {
            for (int i=0; i<acceptable_pollinators.size(); i++){
            if (inputpl.gettype()==acceptable_pollinators[i])
            {inputpl.collectpln();
            return;}
        }
            cout<<"This pollinator cannot collect pollen from this flower, try again"<<endl;
        }
                void pollinate (pollinator inputpl) override {
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
         return false;
        } 
        bool dethornned () override {
            return dethorned;
        }
    };
class daisy : public flower {
        string color;
        int const fertneed=8;
        int const waterneed=10;
        public:
        daisy() {
        acceptable_pollinators = {"insect"};
    };
        daisy(string _color){
            setcolor(_color);
            acceptable_pollinators = {"insect"};
        };
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
        void givepollen(pollinator& inputpl) override {
            if (plncompatible(inputpl))
            {
            inputpl.collectpln();
            return;
            }
            cout<<"This pollinator cannot collect pollen from this flower, try again"<<endl;
        }
        void pollinate (pollinator inputpl) override {
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
         return false;
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
}

void testDaisyColor() {
    flower* testflower = new daisy("White");
    assert(testflower->getcolor() == "white");
    testflower = new daisy("InvalidColor");
    assert(testflower->getcolor() == "unknown");
}

void testRoseFertilization() {
    flower* testflower = new rose();
    int fertamount = 20;
    testflower->fertilize(fertamount);
    assert(testflower->checkcondition());
}

void testDaisyFertilization() {
    flower* testflower = new daisy();
    int fertamount = 20;
    testflower->fertilize(fertamount);
    assert(testflower->checkcondition());
}

void testRoseWatering() {
    flower* testflower = new rose();
    int wateramount = 20;
    testflower->water(wateramount);
    assert(testflower->checkcondition());
}

void testDaisyWatering() {
    flower* testflower = new daisy();
    int wateramount = 20;
    testflower->water(wateramount);
    assert(testflower->checkcondition());
}

void testRosePollination() {
    flower* testflower = new rose();
    pollinator pollinatorA("insect");
    testflower->givepollen(pollinatorA);
    testflower->pollinate(pollinatorA);
    assert(testflower->Pollinated());
}

void testDaisyPollination() {
    flower* testflower = new daisy();
    pollinator pollinatorA("insect");
    testflower->givepollen(pollinatorA);
    testflower->pollinate(pollinatorA);
    assert(testflower->Pollinated());
}

void testRoseDeThorning() {
    rose* testrose = new rose();
    assert(testrose->dethornned() == false);
    testrose->dethorn();
    assert(testrose->dethornned());//sorry for this horrible mess im running out of words
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
    return 0;
}