#include<list>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
bool check(string str);
int main(void){
	//�ж��Ƿ�������� 
	char flag;
	//��ʱ������� 
	string name;
	//��ʱ��ųɼ� 
	string grade;
	//��¼һ��ѧ���ĳɼ� 
	list<list<string> > grades;
	//��¼ѧ���������ͳɼ���list��ά���� 
	list<list<string> >::iterator grades_iter;
	//һ����¼�ĵ����� 
	list<string>::iterator grade_iter;
	grades_iter = grades.begin();
	//��¼ѧ������ 
	int stu_num = 0;
	grades.push_back(list<string>(0));	
	grades_iter = grades.begin();
	//��list�д洢���� 
	do{	cout<<"�������"<<stu_num+1<<"��ѧ��������"<<endl;stu_num++;
		cin>>name;
		//��һ����¼�в���ѧ������ 
		(*grades_iter).push_back(name);
		int j = 0;
		//��һ����¼�в���ɼ� 
		do{cout<<"������ɼ�[0-100]����������-1�����˳���ѧ���ĳɼ�¼��"<<endl;
			cin>>grade;
			//�������ĳɼ��Ƿ����� 
			if(!check(grade)){cout<<"�������������,����������"<<endl;continue;} 
			(*grades_iter).push_back(grade);j++;
			if(grade!="-1") cout<<"��"<<j<<"�ųɼ�¼��ɹ�!"<<endl; 
		}while(grade!="-1");
		cout<<"�ѽ�����ѧ���ɼ���¼��,�Ƿ�¼����һ��ѧ���ĳɼ�,y/n"<<endl;
		cin>>flag;
		if(flag != 'n') grades.push_back(list<string>(0));grades_iter++;
	}while(flag!='n');
	//������������ 
	grades_iter = grades.begin();
	cout<<"***************ѧ���ɼ���������:***************\n";
	for(int i = 0;i<grades.size();i++){
		grade_iter =((*(grades_iter)).begin());
		cout<<"\t"<<*((*(grades_iter)).begin())<<"�ĳɼ���¼:";
		for(int j=2;j<((*grades_iter).size());j++){
			cout<<"\t"<<*(++grade_iter);}
			cout<<"\n";grades_iter++;
	}cout<<"************************************************\n"; 
	//��ѯ�ɼ� 
	do{
		cout<<"������Ҫ��ѯ��ѧ������"<<endl;
		//Ҫ��ѯ��ѧ������ 
		string query_name;
		cin>>query_name;grades_iter = grades.begin();
		//ɨ��һά��list��ֱ���ҵ����ѯ������ͬ�ļ�¼ 
		for(int i = 0;i<grades.size();i++){
			string temp = *((*(grades_iter++)).begin());
			//�ҵ���¼�����������¼�ĳɼ� 
			if(temp==query_name){
				flag = 'y';//�����ѯ�����޸ı�� 
				grade_iter =((*(--grades_iter)).begin());
				cout<<"************************************************\n"; 
				cout<<"\t"<<query_name<<"�ĳɼ���¼:";
				for(int j=2;j<((*grades_iter).size());j++){
					cout<<"\t"<<*(++grade_iter);
				}
				cout<<"\n";grades_iter++; 
			}
		}cout<<"************************************************\n";
		//�ж��û������Ƿ����� 
		if(flag == 'n') cout<<"δ��ѯ����ѧ���������û����Ƿ��������"<<endl;
		cout<<"�Ƿ��˳���ѯ? y/n"<<endl;cin>>flag;
	}while(flag == 'n');
	system("pause"); 
	return 0;
}
//�ж��û�����������Ƿ���� �淶 
bool check(string str){
	str = str + ".1";
	double res = atof(const_cast<const char *>(str.c_str()));
	if((res>0&&res<=100)||res == -1.1) return true;
		else return false;
}
