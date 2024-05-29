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
    protected:
    vector<string> possiblecolors;
    string color;
    double pricepp;
    int amount;
 
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
int amount;
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
class daisy : public flower {
        public:
        daisy() {
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
    };
        daisy(string _color){
        possiblecolors = {"white", "pink", "yellow", "red", "lavender", "purple"};
        setcolor(_color);
}
};
class sage : public flower {
    public:
    sage() {
    possiblecolors = {"blue", "purple", "red", "pink", "white", "yellow", "orange"};
    };
    sage(string _color){
        possiblecolors = {"blue", "purple", "red", "pink", "white", "yellow", "orange"};
        setcolor(_color);
    }
};
 class rose : public flower {
        public:
        rose() {
        possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};    };
        rose(string _color){
             possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            setcolor(_color);
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