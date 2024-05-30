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
class driedleaves : public decoration {
    string color="white";
    vector<string> possiblecolors= {"green","brown","orange","red","yellow"};
    public:
    driedleaves()
    {
        amountlimit=5;
        pricepp=0.5;
    }
    driedleaves(string _color)
    {
        amountlimit=5;
        pricepp=0.5;
        setcolor(_color);
    }
        driedleaves(string _color,int am)
    {
        amountlimit=5;
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
        }
       rose(string _color,int _am){
        pricepp=3.75;
             possiblecolors = {"red", "pink", "white","yellow","orange","peach","purple"};
            setcolor(_color);
            setamount(_am);
        }
    };
class Tulips : public flower {
public:
    Tulips() {
        pricepp = 2.00; // Price per piece
        possiblecolors = {"red", "yellow", "pink", "white", "purple"};
    }
    Tulips(string _color) {
        pricepp = 2.00;
        possiblecolors = {"red", "yellow", "pink", "white", "purple"};
        setcolor(_color);
    }
    Tulips(string _color, int _am) {
        pricepp = 2.00;
        possiblecolors = {"red", "yellow", "pink", "white", "purple"};
        setcolor(_color);
        setamount(_am);
    }
};
class FuneralBouquet : public Bouquet {
public:
    FuneralBouquet* makeBouquet() override {
        _flowers.push_back(new rose("white", 3));
        _flowers.push_back(new Tulips("white", 2));
        _decorations.push_back(new ribbon("black", 1));
        _decorations.push_back(new Wrappingpaper("gray", 1));
        return this;
    }
};

class WeddingBouquet : public Bouquet {
public:
    WeddingBouquet* makeBouquet() override {
        _flowers.push_back(new rose("white", 4));
        _flowers.push_back(new daisy("pink", 3));
        _flowers.push_back(new sunflower("yellow", 2));
        _decorations.push_back(new ribbon("white", 2));
        _decorations.push_back(new driedleaves("green", 3));
        return this;
    }
};

class ValentineBouquet : public Bouquet {
public:
    ValentineBouquet* makeBouquet() override {
        _flowers.push_back(new rose("red", 6));
        _flowers.push_back(new Tulips("red", 4));
        _decorations.push_back(new ribbon("red", 1));
        _decorations.push_back(new Wrappingpaper("white", 1));
        return this;
    }
};

class DateBouquet : public Bouquet {
public:
    DateBouquet* makeBouquet() override {
        _flowers.push_back(new rose("pink", 3));
        _flowers.push_back(new daisy("white", 2));
        _flowers.push_back(new sunflower("orange", 1));
        _decorations.push_back(new ribbon("pink", 1));
        _decorations.push_back(new driedleaves("brown", 2));
        return this;
    }
};

class HospitalBouquet : public Bouquet {
public:
    HospitalBouquet* makeBouquet() override {
        _flowers.push_back(new rose("yellow", 3));
        _flowers.push_back(new daisy("lavender", 2));
        _flowers.push_back(new Tulips("purple", 2));
        _decorations.push_back(new ribbon("green", 1));
        _decorations.push_back(new Wrappingpaper("blue", 1));
        return this;
    }
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

void testFuneralBouquet() {
    Bouquet* bouquet = new FuneralBouquet();
    bouquet = bouquet->makeBouquet();
    assert(bouquet->getFullPrice() == 16.5);
    delete bouquet;
}

void testWeddingBouquet() {
    Bouquet* bouquet = new WeddingBouquet();
    bouquet = bouquet->makeBouquet();
    assert(bouquet->getFullPrice() == 27.5);
    delete bouquet;
}

void testValentineBouquet() {
    Bouquet* bouquet = new ValentineBouquet();
    bouquet = bouquet->makeBouquet();
    assert(bouquet->getFullPrice() ==31.75);
    delete bouquet;
}

void testDateBouquet() {
    Bouquet* bouquet = new DateBouquet();
    bouquet = bouquet->makeBouquet();
    assert(bouquet->getFullPrice() == 18.5);
    delete bouquet;
}

void testHospitalBouquet() {
    Bouquet* bouquet = new HospitalBouquet();
    bouquet = bouquet->makeBouquet();
    assert(bouquet->getFullPrice() == 19.5);
    delete bouquet;
}

int main() {
    testRoseColor();
    testDaisyColor();
    testFuneralBouquet();
    testWeddingBouquet();
    testValentineBouquet();
    testDateBouquet();
    testHospitalBouquet();
    return 0;
}