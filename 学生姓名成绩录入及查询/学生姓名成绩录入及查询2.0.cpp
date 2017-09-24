#include<list>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
bool check(string str);
int main(void){
	//判断是否继续输入 
	char flag;
	//临时存放姓名 
	string name;
	//临时存放成绩 
	string grade;
	//记录一名学生的成绩 
	list<list<string> > grades;
	//记录学生的姓名和成绩，list二维数组 
	list<list<string> >::iterator grades_iter;
	//一条记录的迭代器 
	list<string>::iterator grade_iter;
	grades_iter = grades.begin();
	//记录学生数量 
	int stu_num = 0;
	grades.push_back(list<string>(0));	
	grades_iter = grades.begin();
	//向list中存储数据 
	do{	cout<<"请输入第"<<stu_num+1<<"个学生的名字"<<endl;stu_num++;
		cin>>name;
		//向一条记录中插入学生姓名 
		(*grades_iter).push_back(name);
		int j = 0;
		//向一条记录中插入成绩 
		do{cout<<"请输入成绩[0-100]，或者输入-1即可退出该学生的成绩录入"<<endl;
			cin>>grade;
			//检测输入的成绩是否有误 
			if(!check(grade)){cout<<"输入的数据有误,请重新输入"<<endl;continue;} 
			(*grades_iter).push_back(grade);j++;
			if(grade!="-1") cout<<"第"<<j<<"门成绩录入成功!"<<endl; 
		}while(grade!="-1");
		cout<<"已结束该学生成绩的录入,是否录入下一个学生的成绩,y/n"<<endl;
		cin>>flag;
		if(flag != 'n') grades.push_back(list<string>(0));grades_iter++;
	}while(flag!='n');
	//输出输入的数据 
	grades_iter = grades.begin();
	cout<<"***************学生成绩名单如下:***************\n";
	for(int i = 0;i<grades.size();i++){
		grade_iter =((*(grades_iter)).begin());
		cout<<"\t"<<*((*(grades_iter)).begin())<<"的成绩记录:";
		for(int j=2;j<((*grades_iter).size());j++){
			cout<<"\t"<<*(++grade_iter);}
			cout<<"\n";grades_iter++;
	}cout<<"************************************************\n"; 
	//查询成绩 
	do{
		cout<<"请输入要查询的学生姓名"<<endl;
		//要查询的学生姓名 
		string query_name;
		cin>>query_name;grades_iter = grades.begin();
		//扫描一维的list，直到找到与查询姓名相同的记录 
		for(int i = 0;i<grades.size();i++){
			string temp = *((*(grades_iter++)).begin());
			//找到记录后输出整条记录的成绩 
			if(temp==query_name){
				flag = 'y';//如果查询到则修改标记 
				grade_iter =((*(--grades_iter)).begin());
				cout<<"************************************************\n"; 
				cout<<"\t"<<query_name<<"的成绩记录:";
				for(int j=2;j<((*grades_iter).size());j++){
					cout<<"\t"<<*(++grade_iter);
				}
				cout<<"\n";grades_iter++; 
			}
		}cout<<"************************************************\n";
		//判断用户输入是否有误 
		if(flag == 'n') cout<<"未查询到该学生，请检查用户名是否输入错误"<<endl;
		cout<<"是否退出查询? y/n"<<endl;cin>>flag;
	}while(flag == 'n');
	system("pause"); 
	return 0;
}
//判断用户输入的数据是否符合 规范 
bool check(string str){
	str = str + ".1";
	double res = atof(const_cast<const char *>(str.c_str()));
	if((res>0&&res<=100)||res == -1.1) return true;
		else return false;
}
