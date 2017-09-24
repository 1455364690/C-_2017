#include<iostream>
#include<vector>
using std::vector;
using namespace std;
int main(void){	
	//学生数量 
	int stu_num;
	cout<<"输入学生数"<<std::endl; 
	cin>>stu_num;
	//存放成绩 
	vector< vector<double> > grades(0);
	//存放学生姓名 
	vector<string> names(0);
	//临时存放姓名 
	string name;
	//临时存放成绩 
	double grade;
	//录入成绩和学生姓名 
	for(int i = 0;i<stu_num;i++){
		cout<<"请输入第"<<i+1<<"个学生的名字"<<endl;
		cin>>name;
		grades.push_back(vector<double>(0));
		names.push_back(name); 
		int j = 0;
		do{
			cout<<"请输入第"<<j+1<<"个成绩,输入-1退出输入"<<endl;
			cin>>grade;
			grades[i].push_back(grade);
			j++;
		}while(grade!=-1);
	} 
	//查询成绩 
	cout<<"请输入要查询的学生姓名"<<endl;
	string query_name;int query_num = stu_num;cin>>query_name;
	while(query_num==stu_num){//从姓名向量中找到对应学生姓名的编号 
		for(int i = 0;i<stu_num;i++){
			if(query_name==names[i]){
				query_num = i;
				//输出学生的成绩 
				for(int j = 0;j<grades[query_num].size()-1;j++)
					cout<<"第"<<j+1<<"门成绩为:"<<grades[query_num][j]<<endl;
				break;
			}
		}//当输入姓名出错时，处理部分 
		if(query_num==stu_num){
			cout<<"姓名输入有误，请选择是否重新输入,y/n"<<endl;
			cin>>query_name;
			if(query_name=="y"){
				cout<<"请输入要查询的学生姓名"<<endl;
				cin>>query_name;
			}else	query_num=0;	
		}
	}
	system("pause"); 
	return 0;
}
