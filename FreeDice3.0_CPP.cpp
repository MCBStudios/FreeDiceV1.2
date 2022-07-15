//引入库
#include<iostream>//用于cin和cout 
#include<cstdio>//scanf和printf 
#include<cstdlib>//？？？ 
#include<time.h>//随机数 
#include<windows.h>//Sleep 

//声明命名空间
using namespace std;

//初始化全局变量
//为提高可移植性，请使用long
long mode;//用于记录用户所选模式

long settings_start,settings_end;//用于在9-设置中记录用户选择的开始-停止数值

long random_number;//用于存储模式2~8的随机数

long random_number_max=49,clearlag0=0,clearlag1=0;

//显示启动图像
void startup_screen() {

	cout<<("|---------|-----|")<<endl;
	cout<<("|等待中...|准备 |")<<endl;
	cout<<("|         | 开始|")<<endl;
	cout<<("|---------|-----|")<<endl;
	cout<<("按 1 进入帮助模式")<<endl;
	cout<<("按2~8进入预置模式")<<endl;
	cout<<("按 9 进 入 设 置 ")<<endl;

}

//获取用户输入，选择模式
void mode_select() {

	cout<<("输入模式符号并按回车执行")<<endl;
	cout<<(">_ ");
	scanf("%d",&mode);

}

//按1进入帮助模式
void help_mode() {

	cout<<endl;
	cout<<("FreeDice使用手册  -  By MCB Studios")<<endl;
	cout<<endl;
	cout<<("预置模式共7种，设置可调独立抽号区间")<<endl;
	cout<<endl;
	cout<<("按 2 抽 1 ~ 49号 ，按 3 抽 1 ~ 12组")<<endl;
	cout<<("按 4 抽 1 ~ 44号 ，按 5 抽 1 ~ 11组")<<endl;
	cout<<endl;
	cout<<("V1.5将支持.txt抽号! V2.0将加入中文!")<<endl; 
	cout<<endl;
	cout<<("FreeDice3.0-C++ 内部版本1.0 Release")<<endl;
	cout<<("Made with Dev-C++  &  TDM-GCC 4.9.2")<<endl;
	cin.get();

}

//获取随机数
void random_choose() {
    
    if (mode == 2) random_number_max = 49 ;
	else if (mode == 3) random_number_max = 12 ;
	else if (mode == 4) random_number_max = 44 ;
	else if (mode == 5) random_number_max = 11 ;
	else random_number_max = 49 ;
	
	srand(time(0));
	for (long i=0; i<=5; i++) {

		long sum = rand() % random_number_max+1;
		cout<< sum << endl ;
		Sleep (500);
	}
}

//用户自定义设置
void current_settings() {

	cout<<"请输入开始号：";
	cin>>settings_start;
	cout<<endl<<"请输入结束号：";
	cin>>settings_end;

	srand(time(0)) ;
	for (long i=0; i<=5; i++) {

		long current_sum = rand() % settings_end+1;
		if (current_sum <= settings_start) current_sum = rand() % settings_end+1;
		else cout<< current_sum << endl ;
		Sleep (500);
	}

}

//显示退出画面
void finish_window() {

	cout<<("按回车退出...")<<endl;
	cin.get();//为防止程序直接退出，读取一个键击
	cin.get(); //再来一个

}

//主函数
int main() {
	startup_screen();

	mode_select();
	if (mode == 1) {
		help_mode();
		mode_select();
		random_choose();
	} else if (mode >= 2 && mode <=8) {
		

		random_choose();
	} else if (mode == 9) {

		current_settings() ;
	}

	finish_window();
	return 0;
}
