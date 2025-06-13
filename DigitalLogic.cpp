#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Function to display the truth table for OR gate
void ORGate() { 
    cout << "\nTruth Table for OR Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << (0 | 0) << "\n";
    cout << "0 1 | " << (0 | 1) << "\n";
    cout << "1 0 | " << (1 | 0) << "\n";
    cout << "1 1 | " << (1 | 1) << "\n";
}

// Function to display the truth table for AND gate
void ANDGate() {
    cout << "\nTruth Table for AND Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << (0 & 0) << "\n";
    cout << "0 1 | " << (0 & 1) << "\n";
    cout << "1 0 | " << (1 & 0) << "\n";
    cout << "1 1 | " << (1 & 1) << "\n";
}

// Function to display the truth table for NOT gate
void NOTGate() {
    cout << "\nTruth Table for NOT Gate:\n";
    cout << "A | Output\n";
    cout << "0 | " << (!0) << "\n";
    cout << "1 | " << (!1) << "\n";
}

// Function to display the truth table for NAND gate
void NANDGate() {
    cout << "\nTruth Table for NAND Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << !(0 & 0) << "\n";
    cout << "0 1 | " << !(0 & 1) << "\n";
    cout << "1 0 | " << !(1 & 0) << "\n";
    cout << "1 1 | " << !(1 & 1) << "\n";
}

// Function to display the truth table for NOR gate
void NORGate() {
    cout << "\nTruth Table for NOR Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << !(0 | 0) << "\n";
    cout << "0 1 | " << !(0 | 1) << "\n";
    cout << "1 0 | " << !(1 | 0) << "\n";
    cout << "1 1 | " << !(1 | 1) << "\n";
}

// Function to display the truth table for XOR gate
void XORGate() {
    cout << "\nTruth Table for XOR Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << (0 ^ 0) << "\n";
    cout << "0 1 | " << (0 ^ 1) << "\n";
    cout << "1 0 | " << (1 ^ 0) << "\n";
    cout << "1 1 | " << (1 ^ 1) << "\n";
}

// Function to display the truth table for XNOR gate
void XNORGate() {
    cout << "\nTruth Table for XNOR Gate:\n";
    cout << "A B | Output\n";
    cout << "0 0 | " << !(0 ^ 0) << "\n";
    cout << "0 1 | " << !(0 ^ 1) << "\n";
    cout << "1 0 | " << !(1 ^ 0) << "\n";
    cout << "1 1 | " << !(1 ^ 1) << "\n";
}

// Function to display the binary addition
void BinaryAddition() {
    string bin1, bin2;
    cout << "\nEnter the first binary number: ";
    cin >> bin1;
    cout << "Enter the second binary number: ";
    cin >> bin2;
    int num1 = stoi(bin1, 0, 2);
    int num2 = stoi(bin2, 0, 2);
    int sum = num1 + num2;
    cout << "Binary Sum: " << bitset<8>(sum) << "\n";
    cout << "Decimal Sum: " << sum << "\n";
}

// Function to display one's complement
void OnesComplement() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '0') {
            binary[i] = '1';
        }
        else {
            binary[i] = '0';
        }
    }
    cout << "1's Complement: " << binary << "\n";
}


// Function to display two's complement
void TwosComplement() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;

    // Step 1: Calculate 1's complement by flipping the bits
    string onesComplement = "";
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '0') {
            onesComplement += '1'; 
        }
        else {
            onesComplement += '0';
        }
    }
    // Step 2: Add 1 to the 1's complement to get 2's complement
    string twosComplement = "";
    int carry = 1;
    for (int i = onesComplement.length() - 1; i >= 0; i--) {
        // Add the carry (1 from the previous step)
        if (onesComplement[i] == '1' && carry == 1) {
            twosComplement = '0' + twosComplement;  // Result is '0' and carry remains 1
        }
        else if (onesComplement[i] == '0' && carry == 1) {
            twosComplement = '1' + twosComplement;  // Result is '1' and carry becomes 0
            carry = 0;  // There's no carry
        }
        else {
            twosComplement = onesComplement[i] + twosComplement;  // Copy remaining bits
        }
    }
    cout << "2's Complement: " << twosComplement << "\n";
}

// Function for Half Adder
void HalfAdder() {
    bool a, b;
    cout << "\nEnter first input (A): ";
    cin >> a;
    cout << "Enter second input (B): ";
    cin >> b;
    bool sum = a ^ b;
    bool carry = a & b;
    cout << "Half Adder Output: Sum = " << sum << ", Carry = " << carry << endl;
}

// Function for Full Adder
void FullAdder() {
    bool a, b, carryIn;
    cout << "\nEnter first input (A): ";
    cin >> a;
    cout << "Enter second input (B): ";
    cin >> b;
    cout << "Enter carry input (C_in): ";
    cin >> carryIn;
    bool sum = a ^ b ^ carryIn;
    bool carryOut = (a & b) | (carryIn & (a ^ b)); 
    cout << "Full Adder Output: Sum = " << sum << ", Carry Out = " << carryOut << endl;
}

// Function for Decimal to Binary conversion
void DecimalToBinary() {
    int decimal;
    cout << "\nEnter a decimal number: ";
    cin >> decimal;
    // Check if the number is negative
    if (decimal < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return;
    }
    // When the decimal is 0
    if (decimal == 0) {
        cout << "Binary Representation: 0" << endl;
        return;
    }
    string binary = "";
    while (decimal > 0) {
        // Find the remainder when divided by 2 (0 or 1)
        int remainder = decimal % 2;
        binary = to_string(remainder) + binary;  // Add the remainder to the left side of the binary string
        decimal = decimal / 2;
    }
    cout << "Binary Representation: " << binary << "\n";
}

// Function for Binary to Decimal conversion
void BinaryToDecimal() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;

    int decimal = 0; 
    int power = 1;   //Power of 2 (starting from 2^0)

    // Loop through the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2; //Multiply power by 2 for next bit
    }
    cout << "Decimal Representation: " << decimal << "\n";
}

// Function to display menu and handle input
int displayMenu() {
    cout << "\n-----------------------------------------------\n";
    cout << "\n------------------ Main Menu ------------------\n";
    cout << "1) OR Gate Truth Table\n";
    cout << "2) AND Gate Truth Table\n";
    cout << "3) NOT Gate Truth Table\n";
    cout << "4) NOR Gate Truth Table\n";
    cout << "5) NAND Gate Truth Table\n";
    cout << "6) XOR Gate Truth Table\n";
    cout << "7) XNOR Gate Truth Table\n";
    cout << "8) Binary Addition\n";
    cout << "9) 1's Complement\n";
    cout << "10) 2's Complement\n";
    cout << "11) Half Adder\n";
    cout << "12) Full Adder\n";
    cout << "13) Decimal to Binary Conversion\n";
    cout << "14) Binary to Decimal Conversion\n";
    cout << "15) Exit\n";
    cout << "----------------------------------------------\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 15) {
        cout << "Invalid choice. Please enter a number between 1 and 11: ";
        cin >> choice; 
    }
    return choice;
}

// Main program logic
int main() {
    while (true) {
        int choice = displayMenu();
        switch (choice) {
        case 1: ORGate(); 
            break;
        case 2: ANDGate(); 
            break;
        case 3: NOTGate(); 
            break;
        case 4: NORGate();
            break; 
        case 5: NANDGate();                         
            break; 
        case 6: XORGate();                         
            break; 
        case 7: XNORGate();
            break;
        case 8: BinaryAddition(); 
            break;
        case 9: OnesComplement(); 
            break;
        case 10: TwosComplement(); 
            break;
        case 11: HalfAdder(); 
            break;
        case 12: FullAdder(); 
            break;
        case 13: DecimalToBinary(); 
            break;
        case 14: BinaryToDecimal(); 
            break;
        case 15:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}