#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // Variable Init
    char in[30];
    
    // Out, then In
    std::cout << "Roman Numeral:";
    cin.getline(in, 30);

    // Assign characters to vector
    std::vector<char> num(in, in + sizeof(in)/sizeof(*in));

    // Print out each level of vector
    for(char i: num) {
        if(islower(i)) {
            i = toupper(i);
        }
        
        std::cout << i << "";
    }
}