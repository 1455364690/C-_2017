#include<iostream>
#include<vector>
using std::vector;
using namespace std;
int main(void){	
	//ѧ������ 
	int stu_num;
	cout<<"����ѧ����"<<std::endl; 
	cin>>stu_num;
	//��ųɼ� 
	vector< vector<double> > grades(0);
	//���ѧ������ 
	vector<string> names(0);
	//��ʱ������� 
	string name;
	//��ʱ��ųɼ� 
	double grade;
	//¼��ɼ���ѧ������ 
	for(int i = 0;i<stu_num;i++){
		cout<<"�������"<<i+1<<"��ѧ��������"<<endl;
		cin>>name;
		grades.push_back(vector<double>(0));
		names.push_back(name); 
		int j = 0;
		do{
			cout<<"�������"<<j+1<<"���ɼ�,����-1�˳�����"<<endl;
			cin>>grade;
			grades[i].push_back(grade);
			j++;
		}while(grade!=-1);
	} 
	//��ѯ�ɼ� 
	cout<<"������Ҫ��ѯ��ѧ������"<<endl;
	string query_name;int query_num = stu_num;cin>>query_name;
	while(query_num==stu_num){//�������������ҵ���Ӧѧ�������ı�� 
		for(int i = 0;i<stu_num;i++){
			if(query_name==names[i]){
				query_num = i;
				//���ѧ���ĳɼ� 
				for(int j = 0;j<grades[query_num].size()-1;j++)
					cout<<"��"<<j+1<<"�ųɼ�Ϊ:"<<grades[query_num][j]<<endl;
				break;
			}
		}//��������������ʱ�������� 
		if(query_num==stu_num){
			cout<<"��������������ѡ���Ƿ���������,y/n"<<endl;
			cin>>query_name;
			if(query_name=="y"){
				cout<<"������Ҫ��ѯ��ѧ������"<<endl;
				cin>>query_name;
			}else	query_num=0;	
		}
	}
	system("pause"); 
	return 0;
}
