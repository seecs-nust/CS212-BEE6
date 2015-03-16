#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class student{
	
public:
	
	int id;
	string  Firstname;
	string Lastname;
	vector<int> RawMarks;
	string grade;
	
	
};


class course{
	float weitage[5];
	float marks[5];

public:
	Course(){
		weitage[0]=5;
		weitage[1]=10;
		weitage[2]=15;
		weitage[3]=30;
		weitage[4]=40;

		marks[0]=20;
		marks[1]=30;
		marks[2]=40;
		marks[3]=100;
		marks[4]=200;

	}
	std::vector<student> enrolled;
	void computegrade();
};

void course::computegrade () {
	
	for(int i=0; i<enrolled.size(); i++){
	
		float MarksPersentage=0;
		
		for(int j=0;j<enrolled[i].RawMarks.size();j++){
			MarksPersentage += ((enrolled[i].RawMarks[j]*weitage[i])/marks[i]);
	
		}

		if(MarksPersentage>80){
			enrolled[i].grade="H";}
		else if(MarksPersentage>=50){
			enrolled[i].grade="R";}
		else if(MarksPersentage<50){
			enrolled[i].grade="F";}

		cout<<"Name: "<<enrolled[i].Firstname <<"    Grade: "<<enrolled[i].grade<<endl;

	}
}

int main()
{
	ifstream indata;
	course cs121;
	indata.open("C:\\Users\\Laraib\\Documents\\file\\sample.csv");
	
	string line;
	//cout<<"1";
	if(indata.is_open()){
		
		while(getline(indata,line)){
			string field;
			stringstream covline(line);
			vector<string> fields;

			while(getline(covline,field,',')){
				//cout<<"field:";
			
				fields.push_back(field);
			}
			student std1;
			if(fields.size() > 11){
				std1.Lastname=fields[0];
				std1.Firstname=fields[1];
				std1.id=std::stoi(fields[2]);
				std1.RawMarks.push_back(std::stoi(fields[3]));
				std1.RawMarks.push_back(std::stoi(fields[5]));
				std1.RawMarks.push_back(std::stoi(fields[7]));
				std1.RawMarks.push_back(std::stoi(fields[9]));
				std1.RawMarks.push_back(std::stoi(fields[11]));
			
				cs121.enrolled.push_back(std1);
			
			}
		}
		cs121.computegrade();
	}
	else{
		cout<<"Unable to open file";
	}
	_getch();


	return 0;
}
//Modified