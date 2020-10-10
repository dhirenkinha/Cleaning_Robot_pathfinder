#include <iostream>
#include "colors.hpp"
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;
using namespace rang;


void clear(){
#if defined(__unix__) || defined(__unix) || defined(__linux__)
#define OS_LINUX
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define OS_WIN
#elif defined(__APPLE__) || defined(__MACH__)
#define OS_MAC
#else
#error Unknown Platform
#endif
#if defined(OS_LINUX) || defined(OS_MAC)
system("clear");

#elif defined(OS_WIN)
system("CLS");
#endif
}


void displayMap(){
	ifstream ob;
	char s[100];
	ob.open("floormap.txt");
	int map[10][100];
	memset(map,-1,sizeof(map));
	for(int i=0;i<10;++i){
			ob.getline(s,101);
			for(int k=0;k<100;++k){
				if(s[k]=='0' or s[k]=='1')
					map[i][k]=s[k]-'0';
			}
		
	}
	for(int i=0;i<10;++i){
		for(int j=0;j<100;++j){
			if(map[i][j]==0 or map[i][j]==1){
				if(map[i][j]==0)
					cout<<fgB::red;
				else
					cout<<fgB::green;
				cout<<map[i][j];
			}
		}
		cout<<"\n";
	}
}

int main()
{	int ch;
	cout<<style::bold<<style::italic;
	cout<<fgB::yellow;
	cout<<"\t\tWELCOME\n\n";
	cout<<style::reset<<fgB::blue;
	cout<<"\t1.Clean Spots\n";
	cout<<"\t2.Configure home location\n";
	cout<<"\t3.Display floor map\n";
	cin>>ch;
	getchar();
	if(ch==3){
		clear();
		displayMap();
	}
	cout<<"Exit?";
	getchar();
	clear();
	


	return 0;
}