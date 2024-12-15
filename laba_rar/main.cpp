#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
using namespace std;

#pragma pack (push, 1)

struct head{
    uint16_t header_crc;
    uint8_t  header_type;
    uint16_t header_flag;
    uint16_t header_size;
};

struct fileHead{
    uint32_t packSize;
    uint32_t unpSize;
    uint8_t hostOS;
    uint32_t filseCrc;
    uint32_t fileTime;
    uint8_t unpVer;
    uint8_t metod;
    uint16_t nameSize;
    uint32_t fileAttr;
};

struct Main_Head{
    uint16_t HighPosav;
    uint32_t PosAV;
};

#pragma pack(pop)

int main()
{
    ifstream file("C:\\Example.rar", ios::binary);
    if(file.is_open())
        {
        cout << "file is open" << endl;

        file.seekg(0, ios::end);
        int sizeFile = file.tellg();
        file.seekg(0, ios::beg);

        vector<char> array(sizeFile, 0);

        file.read(array.data(), sizeFile);
        int index = 20;
        }
}
