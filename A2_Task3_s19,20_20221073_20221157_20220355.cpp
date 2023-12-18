#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class MEMORY{

protected:

    int size=256;

public:
    vector<string> data;
    MEMORY()
    {
        data.resize(size);
    }
    string read (int address){
        if(address< size )

            return data[address]+data[address+1];
        else {
            cout << "invalid -access a cell that is out of rang-";
            throw out_of_range("unacceptable ");
        }

    }
    void write(int address, string value){
        if(address<size) {
            data[address] = value.substr(0,2);
            data[address+1] = value.substr(2,2);
        }
        else
            cout<<"invalid -access a cell that is out of rang-";

    }
    void write_val(int add,string val)
    {
        if(val.size()==1)
            val='0'+val;
        data[add]=val;
    }
    void print_data(){
        for(int i=0;i<data.size();i++) cout<<data[i]<<" ";

    }


};
class CPU {
private:
    MEMORY& memory;
    vector<int> registers;
    int pc;

public:
    CPU(MEMORY& member) : memory(member), registers(16, 0), pc(0) {}

    string fetch() {
        string instruction = memory.read(pc);
        return instruction;

    }
//     '5'->5    'A'   'B'
    int decode(string s ){
        int value;
        if(isalpha(s[0])) {
            value = s[0] - 'A' + 10;
            value *= 16;
        }
        else {
            value=s[0]-'0';
            value*=16;
        }
        if(isalpha(s[1])) {
            value+=( s[1] - 'A' + 10);
        }
        else {
            value+=s[1]-'0';
        }
        return value;
    }// A 10*16 +11 171
    void execute(char opcode ,char operand1 ,char operand2,char operand3 ){
        char number,number2;
        string tmp;
        switch (opcode){
            case '1':
                //Load the value from memory at operand2 into register at operand1
                tmp+=operand2;
                tmp+=operand3;
                registers[operand1 - '0'] = decode(memory.read(decode(tmp)));
                pc+=2;
                break;
            case '2':
                //Load the immediate value operand2 into register at operand1
                tmp+=operand2;
                tmp+=operand3;
                registers[operand1-'0']= decode(tmp);
                pc+=2;
                break;
            case '3':
                if(operand1 == 0){
                    //Special case for screen output:print the value in register at operand2
                    cout<<"Screen out: "<<registers[operand2-'0']<<endl;
                }
                else{
                    //Store the value in register at operand1 into memory at operand2
                    tmp+=operand2;
                    tmp+=operand3;
                    memory.write_val(decode(tmp), to_string(registers[operand1-'0']));
                }
                pc+=2;
                break;
            case '4':
                //Copy the value from register at operand into register operand2
                registers[operand2-'0']=registers[operand1-'0'];
                pc+=2;
                break;
            case '5':
                //Add the values in operand1 and operand2 and store result in register at operand1
                number=registers[operand2-'0'],number2=registers[operand3-'0'];
                registers[operand1-'0']=number+number2;
                pc+=2;
                break;
            case 'B':
                // Jump to the address specified by operand2 if the value in register at operand1 is equal to register at R0
if(registers[operand1-'0']==registers[0]){
tmp+=operand2;
tmp+=operand3;
pc= decode(tmp);
}
else
{
pc+=2;
}
break;
case 'C':
//Halt instruction,print a message and end Execution
cout<<"HALT instruction #"<<" "<<"Ending execution."<<endl;
pc=-1;

break;

default:
cout<<"Unsupported opcode :"<<static_cast<int>(opcode)<<" . Ending execution ."<<endl;
pc = -1; //Set pc to -ve  value to exit the loop.
break;

}
}

void run(){
    //Fetching
    while (true) {
        //Fetch the next instruction from memory
        string instruction = fetch();

        //Decoding
        char opcode=instruction[0];
        char operand1=instruction[1], operand2=instruction[2],operand3=instruction[3];

        //Executing
        execute(opcode, operand1, operand2,operand3);
        // halt
        if(pc<0)
            return;

    }
}
void print(){
    for(int i =0; i<16;i++){
        cout<<to_string(i)<<" : has value : "<<hex<<uppercase<<registers[i]<<"\n";
    }
    cout<<"\n\n";
}
void print_me(){
    for(int i =0; i<256;i++){
        cout<<to_string(i)<<" : has mem : "<<memory.data[i]<< "\n";
    }
}
};



int main() {
    int memorySize=256;
    MEMORY memory;
    CPU cpu(memory);
    ifstream inFile;
    inFile.open("si.txt");
    if(!inFile.is_open())cout<<"file doesn't exist";
    //string answer;
    int answer;
    cout<<"1- Do you want to execute a file" <<"OR"<< "2-End the program? ";
    cin>>answer;

    int address=0;
    if(answer==1){
        string order;
        while(inFile>>order){
            memory.write(address,order);
            address+=2;
        }


    }

    inFile.close();

    cpu.run();
    cpu.print();
    cpu.print_me();


    return 0;
}