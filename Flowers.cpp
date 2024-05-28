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
    protected:
    vector<string> possiblecolors;
    string color;
 
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
    virtual ~flower() {}
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