#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using std::ios;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

vector<vector<int>> pic;
int n, m;

//每个灰度代表的颜色
const char* colorFont = " `-+=roadO08G$@M";
// const char* colorFont = " .+#@";
const int COLOR_SIZE = strlen(colorFont);

void readFromBMP(char* path){
    std::ifstream file(path, ios::binary);

    if (!file.is_open()){
        cerr << "打开失败" << endl;
        exit(0);
    }

    //获取宽高
    BITMAPFILEHEADER bmpfile;
    BITMAPINFOHEADER bmpinfo;
    file.read((char*)&bmpfile, sizeof(BITMAPFILEHEADER));
    file.read((char*)&bmpinfo, sizeof(BITMAPINFOHEADER));
    n = -bmpinfo.biHeight, m = bmpinfo.biWidth;
    cout << n << ' ' << m << endl;
    cout << "bit count: " << bmpinfo.biBitCount << endl;

    //初始化vector
    pic.clear();
    for (int i=0;i<n;++i){
        pic.push_back(vector<int>(m));
    }
    //读取图片
    unsigned char r, g, b, a;
    char restBuf[5]; //用作行末对齐
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            //颜色反向存储
            file.read((char*)&b, sizeof(unsigned char));
            file.read((char*)&g, sizeof(unsigned char));
            file.read((char*)&r, sizeof(unsigned char));
            file.read((char*)&a, sizeof(unsigned char));
            pic[i][j] = (b+g+r) / 3;
        }
    }

    file.close();
}

int main(int argn, char** args){
    std::ifstream file;
    //图像数据
    for (int i=1;i<argn;++i){
        //根据扩展名读取图片
        int len = strlen(args[i]);
        if (0 == strcmp(args[i]+(len-4), ".bmp")){
            cout << "processing: " << args[i] << endl;
            readFromBMP(args[i]);
        }else{
            cout << "not supported extension" << endl;
            continue;
        }
        //输出
        for (vector<int>& arr: pic){
            for (int& el: arr){
                el = (el * COLOR_SIZE / 256.0);
                cout << colorFont[el] << ' ';
            }
            cout << endl;
        }
    }
    cout << "done." << endl;
    return 0;
}
