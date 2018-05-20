

#include <string.h>
#include <iostream>
#include "Resume.h"

using namespace std;

ResumeA::ResumeA(const char *str)
{
	if(str == NULL) {
		name = new char[1]; 
		name[0] = '\0'; 
	}
	else {
		name = new char[strlen(str)+1];
		strcpy(name, str);
	}
}

ResumeA::~ResumeA() { delete[] name;}

ResumeA::ResumeA(const ResumeA &r) {
	name = new char[strlen(r.name)+1];
	strcpy(name, r.name);
}

ResumeA* ResumeA::Clone() {
    cout<<"ResumeA::Clone:"<<name<<endl;
	return new ResumeA(*this);
}

void ResumeA::Show() {
	cout<<"ResumeA name : "<<name<<endl; 
}