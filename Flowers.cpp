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
class flower{
    int amount=1;
    protected:
    vector<string> possiblecolors;
    string color;
    double pricepp;
 
    public :
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
    string const getcolor() { return color;}
    double const getprice(){
    return amount * pricepp;
}
void setamount(int _am){
    if (_am<20 && _am>0){
        amount=_am;
    }
    else{
        throw invalid_argument("flower amount is an invalid number.");
    }
}
    virtual ~flower() {}
    };
class Bouquet {
protected:
    vector<flower*> _flowers;
    vector<decoration*> _decorations;
    double Price;
public:
double const getFullPrice (){
    double flowersum;
    double decsum;
    for (flower* flower : _flowers) {
        flowersum+=flower->getprice();
        }
        for (decoration* dec : _decorations){
            decsum+=dec->getprice();
        }
        return flowersum+decsum;
}
    virtual Bouquet* makeBouquet() = 0;
    virtual ~Bouquet() {
        for (flower* flower : _flowers) {
            delete flower;
        }
        for (decoration* dec : _decorations){
            delete dec;
        }
    }
};
class decoration {
protected:
int amount=1;
int amountlimit;
double pricepp; //price per piece
public:
void setamnt(int amnt){
    if (amountlimit>=amnt && amnt>0){
        amount=amnt;
    }
    else
    throw invalid_argument("invalid number of decorations");
}
int const getamnt(){return amount;}
double const getprice(){
    return amount * pricepp;
}
};
class ribbon : public decoration {
    string color="white";
    vector<string> possiblecolors= {"white","black","green","blue","red","yellow","gray","orange","pink"};
    public:
    ribbon()
    {
        amountlimit=5;
        pricepp=0.75;
    }
    ribbon(string _color)
    {
        amountlimit=5;
        pricepp=0.75;
        setcolor(_color);
    }
        ribbon(string _color,int am)
    {
        amountlimit=5;
        pricepp=0.75;
        setcolor(_color);
        setamnt(am);
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
         cout << "input invalid, or the color is not currantly available in our shop " << endl;
    }
    string const getcolor(){return color;}
};
class Wrappingpaper : public decoration {
    string color="white";
    vector<string> possiblecolors= {"white","black","green","blue","red","yellow","gray","orange","pink"};
    public:
    Wrappingpaper()
    {
        amountlimit=6;
        pricepp=0.5;
    }
    Wrappingpaper(string _color)
    {
        amountlimit=6;
        pricepp=0.5;
        setcolor(_color);
    }
    Wrappingpaper(string _color,int am)
    {
        amountlimit=6;
        pricepp=0.5;
        setcolor(_color);
        setamnt(am);
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
         cout << "input invalid, or the color is not currantly available in our shop " << endl;
    }
    string const getcolor(){return color;}
};
class daisy : public flower {
        public:
        daisy() {
        pricepp=1.50;
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
    };
        daisy(string _color){
        pricepp=1.50;
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
        setcolor(_color);
}
    daisy(string _color,int _am){
        pricepp=1.50;
        possiblecolors =  {"white", "pink", "yellow", "red", "lavender", "purple"};
        setcolor(_color);
        setamount(_am);
    }
};
class sunflower : public flower {
    public:
    sunflower() {
    pricepp=2.50;
    possiblecolors = {"yellow", "red", "orange", "mahogany", "white"};
    };
    sunflower(string _color){
        pricepp=2.50;
        possiblecolors = {"yellow", "red", "orange", "mahogany", "white"};
        setcolor(_color);
    }
    sunflower(string _color,int _am){
        pricepp=2.50;
        possiblecolors = {"yellow", "red", "orange", "mahogany", "white"};
        setcolor(_color);
        setamount(_am);
    }
};
 class rose : public flower {
        public:
        
        rose() {
        pricepp=3.75;
        possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
        }
        rose(string _color){
            pricepp=3.75;
             possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            setcolor(_color);
            }; 
       rose(string _color,int _am){
        pricepp=3.75;
             possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            setcolor(_color);
            setamount(_am);
            };
    };
// my humble tests
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

int main() {
    testRoseColor();
    testDaisyColor();
    return 0;
}