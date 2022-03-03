#pragma once
#include "uart/ProtocolSender.h"
#include "storage/StoragePreferences.h"
#include "uart/UartContext.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "security/SecurityManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "utils/BrightnessHelper.h"
#include "entry/EasyUIContext.h"
#include "manager/ConfigManager.h"
#include "os/MountMonitor.h"
#include <algorithm>
#include "gcodes.h"
#include "json/json.h"

void Hardware_serial_transmission(const std::string& data) ;

int gindex=1; //记录已经储存的gcode反馈界面的命令条数
vector<string> Command_Feedback; //储存命令反馈界面
vector<string> File_Gcodes;//储存文件或者宏文件名称及文件夹
vector<string> Current_Temperature;//储存实时温度，用于在Display_value线程中将数据刷新显示出来
vector<string> Target_Temperature;//储存目标温度，用于在Display_value线程中将数据刷新显示出来
vector<string> Machine_Pos;//储存机器坐标，用于在Display_value线程中将数据刷新显示出来
vector<string> Fan_Percent;//风扇速度，用于在Display_value线程中将数据刷新显示出来

int Motion_Event_X = 0,Motion_Event_Y = 0;

int X_Axis_maximum = 0,Y_Axis_maximum = 0 ;//初始化XY最大值，用于移动界面点击移动


int whT=0;//维护界面左右转换T


	  gcodeml c;
	  extern  gcodeml c;



//	  // 波形数据存储区
//	  #define DIAGRAM_SIZE 100
//	  static MPPOINT sPoints[DIAGRAM_SIZE];
//	  static MPPOINT sPoints1[DIAGRAM_SIZE];
//
//	  // 取波形数据里面的偏移值
//	  static int sPointIndex = 0;
//
//	  static void movePoints(MPPOINT *p, int size) {
//	  	for (int i = 0; i < size - 1; i++) {
//	  		p[i].y = p[i + 1].y;
//	  	}
//	  	p[size - 1].y = 0;
//	  }






	  void  setxs(int a);//切换按钮


	  static std::string sContentStr;//键盘相关设置
	  static void addOneChar(char ch) {
	  	sContentStr += ch;
	  	mTextView22Ptr->setText(sContentStr);
	  	mTextView46Ptr->setText(sContentStr);
	  }

	  static void delOneChar() {
	  	if (!sContentStr.empty()) {
	  		sContentStr.erase(sContentStr.length() - 1, 1);
	  		mTextView22Ptr->setText(sContentStr);
	  		mTextView46Ptr->setText(sContentStr);
	  	}
	  }


	  string fn = "A4MAX.fly3d";//预览图片

	  //用于移动界面，将距离刷新到列表里
typedef struct {
	const char* mainText;
	bool bOn;
} S_TEST_DATA;
static S_TEST_DATA sDataTestTab[] = {
	{ "100mm", false },
	{ "10mm", true },
	{ "1mm", false },
	{ "0.1mm", false },
	{ "0.01mm", false },
};


//用于定时关机界面显示
typedef struct {
	const char* mainText;
	bool bOn;
} more_time;
static more_time moretime[] = {
	{ "Sleep overtime",  false },
	{ "10S",    false },
	{ "30S",    false  },
	{ "1minute",   false },
	{ "2minute",   false },
	{ "5minute",   false },
	{ "30minute",  false },
	{ "1hour",   false },

};

//用于设置界面显示选项
typedef struct {
	const char* mainText;
	bool bOn;
} Screen_settings;
static Screen_settings Screensetdata[] = {
		{ "password" },
		{ "display" },
//		{ "Double X" },
		{ "multi touch" },
		{ "language" },
		{ "upgrade" },
	};




int Message_Report_Switch = 0;//用于报告关闭，在定时器检查值为1时，过一会就关闭
int gcodenum = 0;//gcode文件条数
int xzgcodenum= 0;//当前选中的文件条数
int currmode = 0 ;//当前模式，0主板sd卡，1宏命令

char Levelinga[30],Levelingb[30],Levelingc[30],Levelingd[30],Levelinge[30];


void Leveling_init(){
	std::string Leveling1 = StoragePreferences::getString("Leveling1", "");
	std::string Leveling2 = StoragePreferences::getString("Leveling2", "");
	std::string Leveling3 = StoragePreferences::getString("Leveling3", "");
	std::string Leveling4 = StoragePreferences::getString("Leveling4", "");
	std::string Leveling5 = StoragePreferences::getString("Leveling5", "");

	snprintf(Levelinga,sizeof(Levelinga),"%s",Leveling1.c_str());
	snprintf(Levelingb,sizeof(Levelingb),"%s",Leveling2.c_str());
	snprintf(Levelingc,sizeof(Levelingc),"%s",Leveling3.c_str());
	snprintf(Levelingd,sizeof(Levelingd),"%s",Leveling4.c_str());
	snprintf(Levelinge,sizeof(Levelinge),"%s",Leveling5.c_str());
}





namespace { // 加个匿名作用域，防止多个源文件定义相同类名，运行时冲突

//实现长按监听接口
class LongClickListener : public ZKBase::ILongClickListener {

         virtual void onLongClick(ZKBase *pBase) {

        	 Message_Report_Switch = 1;
             mMessage_ReportPtr->setTextColor(0x000000);
             mMessage_ReportPtr->setTextTr("storepos");
	    	 mMessage_ReportPtr->setVisible(true);




                LOGD("触发长按事件");
          char buf[30];


       if(pBase == mButton40Ptr){
             snprintf(buf,sizeof(buf),"G1 X%s Y%s F6000\r\n",Machine_Pos[0].c_str(),Machine_Pos[1].c_str());
             LOGD("当前坐标：%s",buf);
             StoragePreferences::putString("Leveling1", buf);  }//第一个点

       if(pBase == mButton42Ptr){
              snprintf(buf,sizeof(buf),"G1 X%s Y%s F6000\r\n",Machine_Pos[0].c_str(),Machine_Pos[1].c_str());
              LOGD("当前坐标2：%s",buf);
              StoragePreferences::putString("Leveling2", buf);  }//第一个点

       if(pBase == mButton43Ptr){
               snprintf(buf,sizeof(buf),"G1 X%s Y%s F6000\r\n",Machine_Pos[0].c_str(),Machine_Pos[1].c_str());
               LOGD("当前坐标3：%s",buf);
               StoragePreferences::putString("Leveling3", buf);  }//第一个点

       if(pBase == mButton44Ptr){
               snprintf(buf,sizeof(buf),"G1 X%s Y%s F6000\r\n",Machine_Pos[0].c_str(),Machine_Pos[1].c_str());
               LOGD("当前坐标4：%s",buf);
               StoragePreferences::putString("Leveling4", buf);  }//第一个点

       if(pBase == mButton45Ptr){
               snprintf(buf,sizeof(buf),"G1 X%s Y%s F6000\r\n",Machine_Pos[0].c_str(),Machine_Pos[1].c_str());
               LOGD("当前坐标5：%s",buf);
               StoragePreferences::putString("Leveling5", buf);  }//第一个点


       Leveling_init();

//                static int count = 0;
//
//                char buf[128] = {0};
//                snprintf(buf, sizeof(buf), "长按事件触发次数 %d", ++count);
//                //每次触发长按事件，修改按键的文字
//                mButton40Ptr->setText(buf);
         }
            };}
static LongClickListener longButtonClickListener;

vector<string> maxspeeds;
vector<string> PID;
vector<string> STEP;



//将温度以及坐标等信息更新到屏幕上单独的线程


class Display_value: public Thread {
public:
  /**
   * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
   * return true   继续线程
   *        false  退出线程
   */
  virtual bool readyToRun() {
  //  LOGD("Thread 已经创建完成");


    return true;
  }

  /**
   * 线程循环函数
   *
   * return true  继续线程循环
   *        false 推出线程
   */

  virtual bool threadLoop() {
   // LOGD("线程循环函数");


          //当对应的温度界面打开后，再更新界面
	 	if((mtempPtr->isVisible() || mwinPrintPtr->isVisible() || mwhclPtr->isVisible() ) && Target_Temperature.size()>=2 && Current_Temperature.size() >= 2){
	 				mTextView47Ptr->setText(Target_Temperature[whT+1]);//喷头活动温度
	 				mTextView16Ptr->setText(Target_Temperature[whT+1]);//喷头活动温度
	 				mTextView24Ptr->setText(Target_Temperature[whT+1]);//喷头活动温度
	 				mTextView41Ptr->setText(Target_Temperature[whT+1]);//喷头活动温度



	 				mTextView51Ptr->setText(Target_Temperature[0]);//热床活动温度
	 				mTextView130Ptr->setText(Target_Temperature[0]);//热床活动温度
	 				mTextView20Ptr->setText(Target_Temperature[0]);//热床活动温度

		     mTextView5Ptr->setText(Current_Temperature[whT+1]);//喷头实时温度
		     mTextView17Ptr->setText(Current_Temperature[whT+1]);//喷头实时温度
		     mTextView25Ptr->setText(Current_Temperature[whT+1]);//喷头实时温度
		     mTextView42Ptr->setText(Current_Temperature[whT+1]);//喷头实时温度

		     mTextView52Ptr->setText(Current_Temperature[0]);//热床实时温度
		     mTextView15Ptr->setText(Current_Temperature[0]);//热床实时温度
		     mTextView21Ptr->setText(Current_Temperature[0]);//热床实时温度
	 	}



		 if((mhomePtr->isVisible() || mwhmovePtr->isVisible() )&&  Machine_Pos.size() >= 3){
			mTextView34Ptr->setText(Machine_Pos[0].c_str());//x坐标
			mTextview34Ptr->setText(Machine_Pos[0].c_str());//x坐标
			mTextView35Ptr->setText(Machine_Pos[1].c_str());//Y坐标
			mTextview36Ptr->setText(Machine_Pos[1].c_str());//Y坐标
			mTextView36Ptr->setText(Machine_Pos[2].c_str());//Z坐标
			mTextview37Ptr->setText(Machine_Pos[2].c_str());//Z坐标
		 }


    //检查是否有退出线程的请求，如果有，则返回false，立即退出线程
    if (exitPending()) {
       return false;
    }

      usleep(1000 * 500);//500ms执行一次

    //返回真，继续下次线程循环
    return true;
  }
};

static  Display_value display_value;



/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  1000},//定时器id=0,
	{1,  600},
	{2,  50},
	{3,  3000},
};

static string printerCode;//缓存串口接收到的数据


//文件列表界面相关

enum FileType { E_FILETYPE_HOME, E_FILETYPE_BACK, E_FILETYPE_FOLDER, E_FILETYPE_FILE, E_FILETYE_MAX };

struct FileInfo {
	string fileName;
	FileType fileType;
	long datetime;
};
bool compare(const FileInfo& inf1, const FileInfo& inf2) {
	return inf1.datetime > inf2.datetime;
}

bool canSend = false;
FILE* f;
FILE* f2;
vector<FileInfo> fileInfos;
string currentDirectory;
string fileName;





  int atimes = 0,timef = 0,timeh = 0,timet = 0,dytime=0,sytime=0;//打印时间计算

   int TR=0,TL=0;
   int whclsdds=150,whclsdcs=300,whclsdgs=1800;

 int lockkg=0;
 int fsfail=0;//发送失败标志
 float jl = 10;
 int filesize = 0;//文件总大小用于计算进度条
 int curfilesize = 0;
 int curprintcs = 0;//当前打印按钮参数设置

 //这里的参数为温度设置
 int tempptwd = 200;
 int temprcwd = 60;


//打完关机标志
 int finishoff = 0;


 //这里的参数为维护里的参数设置
 int xcd=300,ycd=300,zcd=300,xyspeed=3600,zspeed=600;
 int hcsd=300,xzkg=0,xztime=0; ;
 int lbts=10;//列表条数
 int ptkg = 0;
 int jcsd = 0;//挤出速度按钮用
 int can_in=1;





//设置背景kg
 int bjkg1 = 0,bjkg2 = 0;
//开机循环发送脉冲等参数
int stepkg=0;

char macros_print_path[40] = "M98 P\"0:/macros/";
char macros_print_patha[45] = "M98 P\"0:/macros/";
string print_file_path = "M20 S2 P0:/gcodes";



 // 获取当前时间，精确到ms
 int getCurrentTime() {
 	timeval tv;
 	gettimeofday(&tv, NULL);
 	return tv.tv_sec * 1000 + tv.tv_usec / 1000;  //毫秒
 }



 static bool onUI_Timer(int id);







  void printinit(){

	 atimes = 0,timef = 0,timeh = 0,timet = 0,dytime=0,sytime=0;
     canSend= true;
     mfishPtr->setVisible(false);
     mwinPrintPtr->setVisible(true);
     mboardsdPtr->setVisible(false);
     setxs(3);
 }



 // 发送一行
 static void sendLine() {

 }
 void printGCode(string file, int index) {
 	if(f)
 		fclose(f);

 	/// 这里假设你的文件位于TF卡根目录下的gcode.txt。根据实际情况修改
 	char buf[1024];
 	f = fopen( file.c_str(), "r");
 	if(f == NULL) {
 		mwinPrintPtr->hideWnd();
 		mwinQueryPrintPtr->hideWnd();

 		return;
 	} else


 		fgets(buf, sizeof(buf), f);
 	int printoffset = 0;
 	if(buf[0]==1){//如果有图片就跳过图片
if(buf[12]>0)
 	 printoffset = buf[12];
if(buf[11]>0)
printoffset = buf[11]<<8|buf[12];

if(buf[10]>0)
printoffset = buf[10]<<16|buf[11]<<8|buf[12];

if(buf[9]>0)
	printoffset = buf[9]<<24|buf[10]<<16|buf[11]<<8|buf[12];
 	LOGD("off:%d",printoffset);
 	}
 	else
 		printoffset = 0;
	if(index > 0) {
 	 		for(int i = 0; i < index; i++)
 	 			fgets(buf, sizeof(buf), f);
 	 	}
 	fseek(f,0,SEEK_END);//把文件指针放到文件末尾的位置
 	filesize=ftell(f);//得到文件大小，以字节为单位
    fseek(f,printoffset,SEEK_SET);//文件指针设置到文件开头
 	//fseek(f,115224,SEEK_SET);//文件指针设置到文件开头

 	sendLine();
 }

 // 列出TF卡中的文件夹
 void listFiles(string folder, string subFolder) {
 	// /mnt/extsd就是顶级目录

 	if((folder == "/mnt") && (subFolder == ".."))
 		return;

 	fileInfos.clear();
 //	fileInfos.push_back({"返回主目录", E_FILETYPE_HOME});
 //	fileInfos.push_back({"返回上级目录", E_FILETYPE_BACK});

 	if(subFolder == "..") {			// 上一级目录
 		for(int len = folder.length(); len > 0; len --) {
 			if(folder[len - 1] == '/') {
 				currentDirectory = folder.substr(0, len);
 				LOGD("%d",len);
 				break;
 		}
 		}
 	} else {
 		currentDirectory = folder + "/" + subFolder;
 	}

     DIR *d;
     struct dirent *file;
     if(!(d = opendir(currentDirectory.c_str())))  {
         LOGE("无法打开目录 %s!!!\n",currentDirectory.c_str());
 		mLVFolderPtr->refreshListView();
         return;
     }

//     while((file = readdir(d)) != NULL) {
//         if(strncmp(file->d_name, ".", 1) == 0)
//             continue;
//
//         if(file->d_type == DT_REG )
//         	fileInfos.push_back({file->d_name, E_FILETYPE_FILE});
//         else if(file->d_type == DT_DIR)
//         	fileInfos.push_back({file->d_name, E_FILETYPE_FOLDER});
//     }

     while ((file = readdir(d)) != NULL) {
     		if (strncmp(file->d_name, ".", 1) == 0)
     			continue;

     		struct stat file_stat;
     		stat((currentDirectory + "/" + file->d_name).c_str(), &file_stat);

     		if (file->d_type == DT_REG) {
     			if(strstr(file->d_name, "g") != NULL) {
     				FileInfo inf = { file->d_name, E_FILETYPE_FILE, file_stat.st_mtime };
     				fileInfos.push_back(inf);
     			}
     		} else if (file->d_type == DT_DIR) {
     			FileInfo inf = { file->d_name, E_FILETYPE_FOLDER, file_stat.st_mtime };
     			fileInfos.push_back( inf);
     		}
     	}
     	closedir(d);

     	sort(fileInfos.begin() + 2, fileInfos.end(), compare);

 	mLVFolderPtr->refreshListView();

 }









 namespace { // 加个匿名作用域，防止多个源文件定义相同类名，运行时冲突
 // 实现自己的监听接口
 class MySlidePageChangeListener : public ZKSlideWindow::ISlidePageChangeListener {
 public:
     virtual void onSlidePageChange(ZKSlideWindow *pSlideWindow, int page) {
         LOGD("page: %d\n", page);
     }
 };
 }
 // 定义监听对象
 static MySlidePageChangeListener ptSlidePageChangeListener;

 /**
  * 当界面构造时触发
  */
 static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	//	listFiles("/mnt", ".");
	//	setflyImage(mTextView9Ptr, CONFIGMANAGER->getResFilePath(fn), false);
	//  mptPtr->setSlidePageChangeListener(&ptSlidePageChangeListener);
    //	 	for (int i = 0; i < DIAGRAM_SIZE; i++) {
    //	 		sPoints[i].x = (100 * i) / DIAGRAM_SIZE;
    //	 		sPoints[i].y = 50;
    //	 	}
	 mButton40Ptr->setLongClickListener(&longButtonClickListener);
	 mButton42Ptr->setLongClickListener(&longButtonClickListener);
	 mButton43Ptr->setLongClickListener(&longButtonClickListener);
	 mButton44Ptr->setLongClickListener(&longButtonClickListener);
	 mButton45Ptr->setLongClickListener(&longButtonClickListener);
 }

 /**
  * 当切换到该界面时触发
  */
 static void onUI_intent(const Intent *intentPtr) {
     if (intentPtr != NULL) {
         //TODO
     }
 }

 /*
  * 当界面显示时触发
  */
 static void onUI_show() {


	 //获取用户设定的最大XY值，如果没有设定默认300mm
	 X_Axis_maximum = StoragePreferences::getInt("X_axis_maximum", 300);
	 Y_Axis_maximum = StoragePreferences::getInt("Y_axis_maximum", 300);
	 mX_ValuePtr->setText(X_Axis_maximum);
	 mY_ValuePtr->setText(Y_Axis_maximum);





	 Leveling_init();
	 display_value.run("this is thread name");
	 Command_Feedback.push_back("Click here to send order") ;
//	 	sprintf(id, "%d%d%d%d%d%d%d%d", devID[0],devID[1],devID[2],devID[3],devID[4],devID[5],devID[6],devID[7]);

//	 	char* lock = strstr(key2, id);//验证当前屏幕id是否在key里

//	  if (lock == NULL){
//		 mTextview38Ptr->setText(id);
//
//	    	mczzxPtr->setVisible(true);
//
//	 	}

 	std::string key = StoragePreferences::getString("key", "");

 	if(strcmp(key.c_str(),"")==0){
 //	 		mMainMenuPtr->setVisible(true);
 		}
 	else{
     if(strcmp(key.c_str(),"0")>0){
     mlockPtr->setVisible(true);
     }
 	}

 }

 /*
  * 当界面隐藏时触发
  */
 static void onUI_hide() {

 }

 /*
  * 当界面完全退出时触发
  */
 static void onUI_quit() {
	 mButton40Ptr->setLongClickListener(NULL);
	 mButton42Ptr->setLongClickListener(NULL);
	 mButton43Ptr->setLongClickListener(NULL);
	 mButton44Ptr->setLongClickListener(NULL);
	 mButton45Ptr->setLongClickListener(NULL);

 }









void jdfile(string strLine){
	 string strLinea = strLine;
	 char* stra = strstr(strLinea.c_str(),"printing byte");

		 		  	stra=stra+14;		// 前置去除空白
		 		//	LOGD("%s",stra);
		 		  char* tokena = strtok(stra, "/");
		 		 int a = atoi(tokena);
		 		//LOGD("%d",a);

		 		  	tokena = strtok(NULL, "\\");
		 		  	//LOGD("%s",tokena);
		 		  	int b = atoi(tokena);
		 		  	mSeekbar4Ptr->setProgress( a*100/b);
		 		    char bufff[10];
		 		    sprintf(bufff,"%d%%",a*100/b);

		 		    mTextView53Ptr->setText(bufff);

		 		  	//string hda = tokena;
}
//IP地址解析
void IPaddress(string strLine){

		 if(strstr(strLine.c_str(),"IP address")){
				 string strLinea = strLine;

				char* stra = strstr(strLinea.c_str(),"IP address");
				stra=stra+11;		// 前置去除空白
				//string hda = "IP:";
				char* tokena = strtok(stra, "\\");
				string hda= tokena;
				 mTextView55Ptr->setText(hda);}

}


 /**
  * 串口数据回调接口
  */

 // 处理没有ok的字符串
 void processPrinterCodeLine(string strLine) {

	// LOGD("串口反馈：%s",strLine.c_str());
	 //打印结束设置进度条
	 if(strstr(strLine.c_str(),"Finished printing")){
		mSeekbar4Ptr->setProgress(100);
		mTextView53Ptr->setText("100%");
		 canSend= false;
			if(finishoff == 1)
			 Hardware_serial_transmission("M81");
			 finishoff = 0;
	 }

	//Stopped at height 1.548 mm
	 if(strstr(strLine.c_str(),"Stopped at height")){
				string strLinea = strLine;
				    char* stra = strstr(strLinea.c_str(),"Stopped at height")+18;// 前置去除空白
				    char* tokena = strtok(stra, "mm");
					  mButton49Ptr->setText(tokena);
					  return;
	 }
    //web打印后自动跳转到打印界面
	 if(strstr(strLine.c_str(),"fraction_printed")){
			string strLinea = strLine;
			    char* stra = strstr(strLinea.c_str(),"fraction_printed")+18;// 前置去除空白
			    char* tokena = strtok(stra, ",");
					string hda = tokena;

					//获取打印速度
					float dyjd=atof(hda.c_str())*100;
					mSeekbar4Ptr->setProgress(dyjd);
					char buf[10];
					sprintf(buf,"%0.2f%%",dyjd);
				    mTextView53Ptr->setText(buf);

		 if(canSend == false &&can_in == 1){

                   printinit();

          }

	 }

	 //获取ip地址
	 if(strstr(strLine.c_str(),"IP address")){//
			 IPaddress(strLine);}

	 if(strstr(strLine.c_str(),"status") || strstr(strLine.c_str(),"files") || strstr(strLine.c_str(),"resp")){
 char buf[256];
	 Json::Reader reader;
	 Json::Value Numerical;


	 std::string json_string = strLine;
	 if (reader.parse(json_string, Numerical, false)) {
	   //LOGD("解析成功");


	   //解析sd卡文件
	   if (Numerical.isMember("files")) {
	      Json::Value obj = Numerical["files"];
	      if (obj.isArray()) {
	            gcodenum = 0;
	            File_Gcodes.clear();
	        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
	        	File_Gcodes.push_back( obj[i].asString().c_str()); //获得值储存
	        	gcodenum ++;
	        	//  LOGD("文件：%s",obj[i].asString().c_str());
	        }
				//gcodenum=gcodenum+1;
                mboardsdPtr->refreshListView();
                mboardsdPtr->setSelection(gcodenum);
	      }
	    }


	   //解析实时温度
	   if (Numerical.isMember("heaters")) {
	      Json::Value obj = Numerical["heaters"];
	      Current_Temperature.clear();
	      if (obj.isArray()) {
	        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
	        	sprintf(buf,"%0.2f",atof(obj[i].asString().c_str()));
	        	Current_Temperature.push_back(buf); //获得值储存
	        }
	      }
	    }
	   //解析目标温度
	   if (Numerical.isMember("active")) {
	      Json::Value obj = Numerical["active"];
	      Target_Temperature.clear();
	      if (obj.isArray()) {
	        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
	        	sprintf(buf,"%0.2f",atof(obj[i].asString().c_str()));
	        	Target_Temperature.push_back( buf); //获得值储存
	        }
	      }
	    }

	   //解析坐标
	   if (Numerical.isMember("pos")) {
	      Json::Value obj = Numerical["pos"];
	      Machine_Pos.clear();
	      if (obj.isArray()) {

	        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
	        	snprintf(buf,sizeof(buf),"%0.2f",atof(obj[i].asString().c_str()));
	          //  LOGD("坐标：%s",buf);
	        	Machine_Pos.push_back(buf); //获得值储存
	        }
	      }
	    }

	   //解析风扇速度
//	   if (Numerical.isMember("fanPercent")) {
//	      Json::Value obj = Numerical["fanPercent"];
//	      if (obj.isArray()) {
//	        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
//	        	sprintf(buf,"%0.2f",atof(obj[i].asString().c_str()));
//	        	Fan_Percent[i] = obj[i].asString().c_str(); //获得值储存
//	        }
//	      }
//	    }

	   //解析调试界面

	   if (Numerical.isMember("resp")) {

           if(Command_Feedback.size() >= 200)
        	  Command_Feedback.clear();//计算总共记录了多少条反馈的命令，200条清理一次

          // LOGD("坐标：%s",Numerical["resp"].asString().c_str());
           if( strlen (Numerical["resp"].asString().c_str()) > 1 )
          {
	         Command_Feedback.push_back(Numerical["resp"].asString().c_str()) ; //获得值储存
	         // gindex++;//计算总共记录了多少条反馈的命令，200条清理一次。
			 //
		     mListView2Ptr->refreshListView();
		     mListView2Ptr->setSelection(Command_Feedback.size()-2);
	          if(strstr(Numerical["resp"].asString().c_str(),"Speed factor")){
			     mButton83Ptr->setText(strstr(Numerical["resp"].asString().c_str(),"Speed factor")+13);
			   }
          }

	    }



	 }


 }



 }

 static void onProtocolDataUpdate(const SProtocolData &data) {

 	printerCode += data.str;					// 字符串连接起来
 	int posEnter = printerCode.find("\n");

 	while (posEnter >= 0) {						// 已经找到\n，进行处理
 		if(posEnter > 0)
 			processPrinterCodeLine(printerCode.substr(0, posEnter));

 		printerCode = printerCode.erase(0, posEnter + 1);		// 删除\n以前的数据和\n本身
 		posEnter = printerCode.find("\n");
 	}
 }
 /**
  * 定时器触发函数
  * 不建议在此函数中写耗时操作，否则将影响UI刷新
  * 参数： id
  *         当前所触发定时器的id，与注册时的id相同
  * 返回值: true
  *             继续运行当前定时器
  *         false
  *             停止运行当前定时器
  */

 static int cstimea = 0;
 static bool onUI_Timer(int id){

	 //定时器0
	 if(id == 0){


			 if(can_in > 1){
				 can_in--; }
			 Hardware_serial_transmission("M408 S0\r\n");


		 //屏幕休眠
	 	  if(StoragePreferences::getBool("pmcs", false)&&(BRIGHTNESSHELPER->isScreenOn())){

	 		  cstimea++;
	 		  if(cstimea>StoragePreferences::getInt("cstime", 10)){
	 				mAnti_touchPtr->setVisible(true);
	 			  BRIGHTNESSHELPER->screenOff();
	 			  cstimea = 0;
	 		  }
	 	  }//屏幕休眠

	 	  //打印计时
		  if(canSend) {

			  dytime++;
		   		atimes++;
		    		if (atimes > 59) {
		    			atimes = 0;
		    			timef++;
		    		}
		    		if (timef >= 59) {
		    			timef = 0;
		    			timeh++;
		    		}
		    		if (timeh > 23) {
		    			timeh = 0;
		    			timet++;
		    		}
		    	   	char bufdytime[30];
		    	   	if(timeh>0){
		    		    	 if(timet>0)
		    		    	   sprintf(bufdytime,"Print Time:%dd%dh%dm%ds",timet,timeh,timef,atimes);
		    		    	 else
		    		    	    sprintf(bufdytime,"Print Time：:%dh%dm%ds",timeh,timef,atimes);
		    		 }else
		    		   sprintf(bufdytime,"Print Time:%dm%ds",timef,atimes);
		    		mTextView10Ptr->setText(bufdytime);//显示
		    		} //打印计时




	 }

 if(id == 3 && Message_Report_Switch == 1){
	 Message_Report_Switch = 0;
	 mMessage_ReportPtr->setVisible(false);


 }

	 if(id==2){



if(xztime>0){//卸载按钮动画展示

	mButton33Ptr->setBackgroundPic("whclkgjk.png");
	xztime--;
	if(xztime==0)
	mButton33Ptr->setBackgroundPic("whclkgjg.png");
}
if(xztime<0){//卸载按钮动画展示

	mButton32Ptr->setBackgroundPic("whclkgck.png");
	xztime++;
	if(xztime==0)
	mButton32Ptr->setBackgroundPic("whclkgcg.png");
}
	    if(TR>0){
	    	static int CS = 0;
	  	char path[50] = {0};
	  	if(ptkg==2){
	  	snprintf(path, sizeof(path), "whdt%d.png", CS);
	  	mTextView39Ptr->setBackgroundPic(path);}
	  	 if(ptkg == 1){
	  		snprintf(path, sizeof(path), "tempbj%d.png", CS);
	  		  	mTextView4Ptr->setBackgroundPic(path);}
	  	   CS++;
        if(CS == 6){
	     CS =0;
         TR--;}
	    }

         if(TL>0){
         static int CS = 6;
         CS--;
		 char path[50] = {0};
		  	if(ptkg==2){
		  	snprintf(path, sizeof(path), "whdt%d.png", CS);
		  	mTextView39Ptr->setBackgroundPic(path);}
		  	 if(ptkg == 1){
		  		snprintf(path, sizeof(path), "tempbj%d.png", CS);
		  		  	mTextView4Ptr->setBackgroundPic(path);}

		 if(CS == 0){
		 	CS =6;
		     TL--;}}}









//这里是检测当前有没有按下异形按钮，避免在定时器里重复刷新按钮背景
	  if(mButton26Ptr->isPressed()){
	    			 mTextView1Ptr->setBackgroundPic("movexhome.png");
	    			 bjkg1 = 1;
	  }
	    		 else if(mButton27Ptr->isPressed()){
	    			 mTextView1Ptr->setBackgroundPic("moveyhome.png");
	    			 bjkg1 = 1;
	    		 }
	    		 else if(mButton28Ptr->isPressed()){
	    			 mTextView1Ptr->setBackgroundPic("movezhome.png");
	    			 bjkg1 = 1;
	    		 }
	    		 else if(mButton26Ptr->isPressed()==false&&mButton27Ptr->isPressed()==false&&mButton28Ptr->isPressed()==false&&bjkg1 == 1)
	    		 {	 mTextView1Ptr->setBackgroundPic("movebj.png");bjkg1 = 0;
	    		 }



     return true;
 }



 /**
  * 有新的触摸事件时触发
  * 参数：ev
  *         新的触摸事件
  * 返回值：true
  *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
  *         false
  *            触摸事件将继续传递到控件上
  */
 static int timea = 0;
  static bool ongcodeActivityTouchEvent(const MotionEvent &ev) {


 	 int timeb;
      switch (ev.mActionStatus) {
  		case MotionEvent::E_ACTION_DOWN://触摸按下
  			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
  			Motion_Event_X = ev.mX;
  			Motion_Event_Y = ev.mY;


  			//双击归位
  			  if(StoragePreferences::getBool("SJ", false)){
  			  timeb =getCurrentTime();
  			 		 	if((timeb - timea < StoragePreferences::getInt("SJtime", 160))&&canSend==false)
  			 		Hardware_serial_transmission("G28\r\n");
  			 		 	timea = timeb;}

  			  if(StoragePreferences::getBool("pmcs", false)){//读取是否开启了休眠
  							 cstimea = 0;}


  			break;
  		case MotionEvent::E_ACTION_MOVE://触摸滑动
  			break;
  		case MotionEvent::E_ACTION_UP:

  			//定时休眠开启屏幕

				  if(!BRIGHTNESSHELPER->isScreenOn()){//屏幕背光关闭中
				   BRIGHTNESSHELPER->screenOn();
				   mAnti_touchPtr->setVisible(false); //抬起后关闭防触摸界面
				   cstimea = 0;
			  }

			  //触摸抬起
  			break;
  		default:
  			break;
  	}
  	return false;
  }
 static bool onButtonClick_btnPause(ZKButton *pButton) {//暂停打印
     //LOGD(" ButtonClick btnPause !!!\n");

 	if (!pButton->isSelected()) {//如果暂停

    canSend = false;
    can_in = 0;
 	Hardware_serial_transmission("M226\r\n");
 	mbtnPausePtr->setTextTr("continue");//显示
 	}
 	else{
 	mbtnPausePtr->setTextTr("Pause");//显示
 	Hardware_serial_transmission("M24\r\n");
 	canSend = true;
 	 can_in = 1;
 	if(currmode!=0)
 	  sendLine();   }
 	pButton->setSelected(!pButton->isSelected());
     return false;
 }




 static bool onButtonClick_btnPrintOK(ZKButton *pButton) {//************************************************开始打印***************************************************************
     //LOGD(" ButtonClick btnPrintOK !!!\n");
	 if(currmode == 0){
		 char buf[128];
	     printinit();//打印初始化
	     if( strlen(print_file_path.c_str()) > 17 )
	        snprintf(buf,sizeof(buf),"M32 %s/%s\r\n",print_file_path.c_str()+18,File_Gcodes[xzgcodenum].c_str());
	     else
	    	 snprintf(buf,sizeof(buf),"M32 %s\r\n",File_Gcodes[xzgcodenum].c_str());

	     // LOGD("打印文件路径：%s",buf);
	     Hardware_serial_transmission(buf);


	 mwinPrintPtr->setVisible(true);
	 mboardsdPtr->setVisible(false);
	 mwinQueryPrintPtr->hideWnd();

	 canSend=true;
	 }




	      return false;
 }

 static bool onButtonClick_btnPrintCancel(ZKButton *pButton) {

 	mwinQueryPrintPtr->hideWnd();

     return false;
 }





 static int getListItemCount_LVFolder(const ZKListView *pListView) {
     //LOGD("getListItemCount_LVFolder !\n");
     return fileInfos.size();
 }

 static void obtainListItemData_LVFolder(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
 	static const char* backgroundPics[] = {	"home.png", "up.png", "folder.png", "file.png", "file.png"
 	};
 	static FileType savedFileType = E_FILETYE_MAX;
 	ZKListView::ZKListSubItem* sub = pListItem->findSubItemByID(ID_GCODE_Icon);//获取每个文件id
 	FileInfo fi = fileInfos[index];
 	if(fi.fileType != savedFileType) {
 		sub->setBackgroundPic(backgroundPics[fi.fileType]);//设置背景图
 		savedFileType = fi.fileType;
 	}
 	pListItem->setText(fi.fileName);//设置文件名字

	ZKListView::ZKListSubItem* inf = pListItem->findSubItemByID(ID_GCODE_Icon);
	if(strstr(fi.fileName.c_str(), "fly") != NULL){


	}
	else
		inf->setBackgroundPic("");

 }

 //文件页面
 static void onListItemClick_LVFolder(ZKListView *pListView, int index, int id) {
     //LOGD(" onListItemClick_ LVFolder  !!!\n");
 	FileInfo fi = fileInfos[index];
 	switch (fi.fileType) {
 	//case E_FILETYPE_HOME:
 	//	pListView->setVisible(false);
 	//	mMainMenuPtr->setVisible(true);
 	//	break;

 //	case E_FILETYPE_BACK:
 //		listFiles(currentDirectory, "..");
 //		break;

 	case E_FILETYPE_FOLDER:
 		listFiles(currentDirectory, fi.fileName);
 		break;

 	case E_FILETYPE_FILE:
 		pListView->setVisible(false);
 		mwinQueryPrintPtr->showWnd();
 		mwinPrintPtr->hideWnd();
 		fileName = currentDirectory + "/" + fi.fileName;
 		if(strstr(fi.fileName.c_str(), "") != NULL){

 		}
 		break;

 	default:
 		break;
 	}
 }
 static bool onButtonClick_btnBack(ZKButton *pButton) {//********************************************停止打印*******************************************************************************
     //LOGD(" ButtonClick btnBack !!!\n");
	 Hardware_serial_transmission("M226\r\n");
	 Hardware_serial_transmission("M0\r\n");
//
// 	if(statkg != 0)//如果没打印完
// 	printcel=1;//取消打印标志
// 	canSend = false;
// 	gcode.clear();
 	mwinPrintPtr->hideWnd();
 	mfishPtr->setVisible(true);
    canSend=false;
    can_in = 10;
     return false;
 }



 //加热开关
 static bool onButtonClick_Button2(ZKButton *pButton) {
 	//LOGD(" ButtonClick Button2 !!!\n");
	 tempptwd--;
	 mButton3Ptr->setText(tempptwd);

 	return false;
 }
 static bool onButtonClick_Button3(ZKButton *pButton) {
 	//LOGD(" ButtonClick Button3 !!!\n");
	 curprintcs = 30;
	 mAJPtr->setVisible(true);
 	return false;
 }




 static bool onButtonClick_Button17(ZKButton *pButton) {
	 std::string wifiname = StoragePreferences::getString("wifiname", "");
	 std::string wifipassword = StoragePreferences::getString("wifipassword", "");

	 Hardware_serial_transmission("M552 S0\r\n");
	 Thread::sleep(800);
	 Hardware_serial_transmission("M587 S\"");
	 wifiname += "\" ";
	 wifiname += "P\"";
	 wifiname += wifipassword.c_str();
	 wifiname += "\"\r\n";
	 Hardware_serial_transmission(wifiname.c_str());
	 LOGD("%s",wifiname.c_str());
	 Thread::sleep(800);
	 Hardware_serial_transmission("M552 S1\r\n");
 			    return false;
 		}




 static bool onButtonClick_Button1(ZKButton *pButton) {
	 std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//XY速度
		 const char* axismoves=" F2500\r\n";
 		char buf[10];
 					sprintf(buf,"%0.2f",jl);
 					Hardware_serial_transmission("G91 \r\n");
 				Hardware_serial_transmission("G1 X");
 				Hardware_serial_transmission(buf);
 				if(strcmp(xyspeedf.c_str(),"")!=0){
 					Hardware_serial_transmission(" F");
 	 				Hardware_serial_transmission(xyspeedf);
 	 				Hardware_serial_transmission("\r\n");
 	 					}
 	 					else
 				Hardware_serial_transmission(axismoves);
 				Hardware_serial_transmission("G90 \r\n");
 	    return false;
 }
 static bool onButtonClick_Button20(ZKButton *pButton) {
     //LOGD(" ButtonClick Button20 !!!\n");
	 std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//XY速度
	 const char* axismoves=" F2500\r\n";
 			char buf[10];
 						sprintf(buf,"%0.2f",jl);
 						Hardware_serial_transmission("G91 \r\n");
 					Hardware_serial_transmission("G1 X-");
 					Hardware_serial_transmission(buf);
 					if(strcmp(xyspeedf.c_str(),"")!=0){
 						Hardware_serial_transmission(" F");
 						Hardware_serial_transmission(xyspeedf);
 						Hardware_serial_transmission("\r\n");
 					}
 					else
 					Hardware_serial_transmission(axismoves);
 					Hardware_serial_transmission("G90\r\n");
 		    return false;
 }

 static bool onButtonClick_Button21(ZKButton *pButton) {
     //LOGD(" ButtonClick Button21 !!!\n");
	 std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//X长度
		 const char* axismoves=" F2500\r\n";
	 char buf[10];
 				sprintf(buf,"%0.2f",jl);
 				Hardware_serial_transmission("G91 \r\n");
 			Hardware_serial_transmission("G1 Y");
 			Hardware_serial_transmission(buf);
			if(strcmp(xyspeedf.c_str(),"")!=0){
				Hardware_serial_transmission(" F");
 						Hardware_serial_transmission(xyspeedf.c_str());
 						Hardware_serial_transmission("\r\n");
 					}
 					else
 			Hardware_serial_transmission(axismoves);
 			Hardware_serial_transmission("G90 \r\n");
     return false;
 }

 static bool onButtonClick_Button22(ZKButton *pButton) {
     //LOGD(" ButtonClick Button22 !!!\n");
	 std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//X长度
		 const char* axismoves=" F2500\r\n";
 		char buf[10];
 					sprintf(buf,"%0.2f",jl);
 					Hardware_serial_transmission("G91 \r\n");
 				Hardware_serial_transmission("G1 Y-");
 				Hardware_serial_transmission(buf);
 				if(strcmp(xyspeedf.c_str(),"")!=0){
 					Hardware_serial_transmission(" F");
 	 						Hardware_serial_transmission(xyspeedf);
 	 						Hardware_serial_transmission("\r\n");
 	 					}
 	 					else
 				Hardware_serial_transmission(axismoves);
 				Hardware_serial_transmission("G90\r\n");
 	    return false;
 }

 static bool onButtonClick_Button23(ZKButton *pButton) {
     //LOGD(" ButtonClick Button23 !!!\n");
	 Hardware_serial_transmission("G28\r\n");
     return false;
 }

 static bool onButtonClick_Button24(ZKButton *pButton) {
     //LOGD(" ButtonClick Button24 !!!\n");
	 std::string zspeedf = StoragePreferences::getString("Zspeed", "");//X长度
		 const char* axismoves=" F600\r\n";
 			char buf[10];
 						sprintf(buf,"%0.2f",jl);
 						Hardware_serial_transmission("G91 \r\n");
 					Hardware_serial_transmission("G1 Z-");
 					Hardware_serial_transmission(buf);
 					if(strcmp(zspeedf.c_str(),"")!=0){
 						Hardware_serial_transmission(" F");
 		 						Hardware_serial_transmission(zspeedf.c_str());
 		 						Hardware_serial_transmission("\r\n");
 		 					}
 		 					else
 					Hardware_serial_transmission(axismoves);
 					Hardware_serial_transmission("G90 \r\n");
 		    return false;
 }

 static bool onButtonClick_Button25(ZKButton *pButton) {
     //LOGD(" ButtonClick Button25 !!!\n");
	 std::string zspeedf = StoragePreferences::getString("Zspeed", "");//X长度
		 const char* axismoves=" F600\r\n";
 		char buf[10];
 					sprintf(buf,"%0.2f",jl);
 					Hardware_serial_transmission("G91 \r\n");
 				Hardware_serial_transmission("G1 Z");
 				Hardware_serial_transmission(buf);
 				if(strcmp(zspeedf.c_str(),"")!=0){
 					Hardware_serial_transmission(" F");
 			 	Hardware_serial_transmission(zspeedf.c_str());
 			 	Hardware_serial_transmission("\r\n");
 			 	}
 			 	else
 				Hardware_serial_transmission(axismoves);
 				Hardware_serial_transmission("G90 \r\n");
 	    return false;
 }

 static bool onButtonClick_Button26(ZKButton *pButton) {
     //LOGD(" ButtonClick Button26 !!!\n");

 	Hardware_serial_transmission("G28 X\r\n");
     return false;
 }

 static bool onButtonClick_Button27(ZKButton *pButton) {
     //LOGD(" ButtonClick Button27 !!!\n");

	 Hardware_serial_transmission("G28 Y\r\n");
     return false;
 }

 static bool onButtonClick_Button28(ZKButton *pButton) {
     //LOGD(" ButtonClick Button28 !!!\n");

 				Hardware_serial_transmission("G28 Z\r\n");
 	    return false;
 }

 static int getListItemCount_Listview1(const ZKListView *pListView) {
     //LOGD("getListItemCount_Listview1 !\n");
 	return sizeof(sDataTestTab) / sizeof(S_TEST_DATA);
 }

 static void obtainListItemData_Listview1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
 	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_SubItem1);
 	pListItem->setText(sDataTestTab[index].mainText);
 	psubButton->setSelected(sDataTestTab[index].bOn);
 }

 static void onListItemClick_Listview1(ZKListView *pListView, int index, int id) {
     //LOGD(" onListItemClick_ Listview1  !!!\n");
 	//sDataTestTab[index].bOn = !sDataTestTab[index].bOn;
 	    sDataTestTab[0].bOn = false;
 		sDataTestTab[1].bOn = false;
 		sDataTestTab[2].bOn = false;
 		sDataTestTab[3].bOn = false;
 		sDataTestTab[4].bOn = false;
 		sDataTestTab[index].bOn = true;
 		switch (index){
 		case 0: jl=100;break;
 		case 1: jl=10;break;
 		case 2: jl=1;break;
 		case 3: jl=0.1;break;
 		case 4: jl=0.01;break;

 		}

 }


 static bool onButtonClick_Button32(ZKButton *pButton) {
	 pButton->setSelected(!pButton->isSelected());
		 char buf[20];
		 std::string hccdf = StoragePreferences::getString("hccd", "");
		 std::string csf = StoragePreferences::getString("cs", "");
	 	Hardware_serial_transmission("G91\r\n");
	 	Hardware_serial_transmission("G1 E-");

	 	if(strcmp(hccdf.c_str(),"")!=0){  //自定义了长度
	 	Hardware_serial_transmission(hccdf);
	 	 Hardware_serial_transmission(" F");

	    	if(strcmp(csf.c_str(),"")!=0){//自定义了长度   速度
	 	             Hardware_serial_transmission(csf);
	 	        	 Hardware_serial_transmission("\r\n");
	 		 	     xztime=-atoi(hccdf.c_str())*60*20/atoi(csf.c_str());//距离/时间

	 	         }
	    	else{
	    		      sprintf(buf,"%d\r\n",hcsd);
	    		      Hardware_serial_transmission(buf);
	    		      xztime=-atoi(hccdf.c_str())*60*20/hcsd;
	    		             }
	 	}




	 	else{
	 		Hardware_serial_transmission("100");
	 	    Hardware_serial_transmission(" F");
	 		   if(strcmp(csf.c_str(),"")!=0){
	 	 	             Hardware_serial_transmission(csf);
	 	 	            Hardware_serial_transmission("\r\n");
	 	 		 	     xztime=-100*60*20/atoi(csf.c_str());
	 	 	         }
	 	    	   else{
	 	    		      sprintf(buf,"%d\r\n",hcsd);
	 	    		      Hardware_serial_transmission(buf);
	 	    		      xztime=-100*60*20/hcsd;

	 	    	   }
	 	}

	    Hardware_serial_transmission("G90\r\n");


	     return false;
	 }


 static bool onButtonClick_Button33(ZKButton *pButton) {
     //LOGD(" ButtonClick Button33 !!!\n");


	 pButton->setSelected(!pButton->isSelected());
	 char buf[20];
	 std::string hccdf = StoragePreferences::getString("hccd", "");
	 std::string csf = StoragePreferences::getString("cs", "");
 	Hardware_serial_transmission("G91\r\n");
 	Hardware_serial_transmission("G1 E");

 	if(strcmp(hccdf.c_str(),"")!=0){  //自定义了长度
 	Hardware_serial_transmission(hccdf);
 	 Hardware_serial_transmission(" F");



 	 if(jcsd == 0){//默认按钮常速

     	 if(strcmp(csf.c_str(),"")!=0){//自定义了速度
  	             Hardware_serial_transmission(csf);
  	        	 Hardware_serial_transmission("\r\n");
  		 	     xztime=atoi(hccdf.c_str())*60*20/atoi(csf.c_str());//距离/时间

  	         }
     	 else{//mei 自定义了速度
     		      sprintf(buf,"%d\r\n",hcsd);
     		      Hardware_serial_transmission(buf);
     		      xztime=atoi(hccdf.c_str())*60*20/hcsd;

     		             }  }
    else{
 		  sprintf(buf,"%d\r\n",hcsd);
 		    Hardware_serial_transmission(buf);
 		    xztime=atoi(hccdf.c_str())*60*20/hcsd;



 	 }



 	}




 	else{
 		Hardware_serial_transmission("100");
 	    Hardware_serial_transmission(" F");
 	 	 if(jcsd == 0){//默认按钮常速

 	     	 if(strcmp(csf.c_str(),"")!=0){//自定义了速度
 	  	             Hardware_serial_transmission(csf);
 	  	        	 Hardware_serial_transmission("\r\n");
 	  		 	     xztime=100*60*20/atoi(csf.c_str());//距离/时间

 	  	         }
 	     	 else{
 	     		      sprintf(buf,"%d\r\n",hcsd);
 	     		      Hardware_serial_transmission(buf);
 	     		      xztime=100*60*20/hcsd;
 	     		             }  }
 	    else{
 	 		  sprintf(buf,"%d\r\n",hcsd);
 	 		    Hardware_serial_transmission(buf);
 	 		    xztime=100*60*20/hcsd;



 	 	 }
 	}

    Hardware_serial_transmission("G90\r\n");

    return false;
 }




 static void onEditTextChanged_Edittext2(const std::string &text) {
     //LOGD(" onEditTextChanged_ Edittext2 %s !!!\n", text.c_str());

 }

 static bool onButtonClick_Button41(ZKButton *pButton) {
     //LOGD(" ButtonClick Button41 !!!\n");

 	Hardware_serial_transmission("M84\r\n");
     return false;
 }





 static bool onButtonClick_Button48(ZKButton *pButton) {
     //LOGD(" ButtonClick Button48 !!!\n");
 	 StoragePreferences::putString("key", mEdittext2Ptr->getText().c_str());
 	 mTextview53Ptr->setText("Saved successfully");

     return false;
 }


 static void onEditTextChanged_Edittext3(const std::string &text) {
     //LOGD(" onEditTextChanged_ Edittext3 %s !!!\n", text.c_str());
 	std::string key = StoragePreferences::getString("key", "null");
 	if(strcmp( key.c_str(), text.c_str())== 0){

 		mlockPtr->setVisible(false);
         lockkg=1;
 	}
 	else
 		//LOGD("输入内容：%s,data密码：%s",text.c_str(),key.c_str());
 		mTextview50Ptr->setText("Incorrect password");
 }


 static void onProgressChanged_Seekbar3(ZKSeekBar *pSeekBar, int progress) {
     //LOGD(" ProgressChanged Seekbar3 %d !!!\n", progress);
 	BRIGHTNESSHELPER->setBrightness(progress);
 	mTextview54Ptr->setText(progress);
 }






 static void onProgressChanged_Seekbar4(ZKSeekBar *pSeekBar, int progress) {
     //LOGD(" ProgressChanged Seekbar4 %d !!!\n", progress);



 }

 static void onEditTextChanged_Edittext4(const std::string &text) {
     //LOGD(" onEditTextChanged_ Edittext4 %s !!!\n", text.c_str());
 	StoragePreferences::putString("printpause", text.c_str());
 }




static void onProgressChanged_SeekBar1(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBar1 %d !!!\n", progress);
}
static void onProgressChanged_SeekBar2(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBar2 %d !!!\n", progress);
}

static void onProgressChanged_SeekBar3(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBar3 %d !!!\n", progress);
}



void  setxs(int a){
	mhomePtr->setVisible(false);
	mtempPtr->setVisible(false);
	mprintPtr->setVisible(false);
	mWHPtr->setVisible(false);
	mmorePtr->setVisible(false);
    mButton70Ptr->setSelected(false);
    mButton71Ptr->setSelected(false);
    mButton72Ptr->setSelected(true);
    mButton73Ptr->setSelected(false);
    mButton74Ptr->setSelected(false);

	switch(a){
	case 1:mhomePtr->setVisible(true);     mButton70Ptr->setSelected(true);    mTextView3Ptr->setBackgroundPic("movexj.png");             break;
	case 2:mtempPtr->setVisible(true);     mButton71Ptr->setSelected(true);    mTextView3Ptr->setBackgroundPic("tempxj.png");         break;
	case 3:mprintPtr->setVisible(true);    mButton72Ptr->setSelected(false);   mTextView3Ptr->setBackgroundPic("printxj.png");          break;
	case 4:mWHPtr->setVisible(true);       mButton73Ptr->setSelected(true);    mTextView3Ptr->setBackgroundPic("whxj.png");              break;
	case 5:mmorePtr->setVisible(true);     mButton74Ptr->setSelected(true);    mTextView3Ptr->setBackgroundPic("morexj.png"); ;          break;

	}}








static bool onButtonClick_Button70(ZKButton *pButton) {
	 setxs(1);

    return false;
}

static bool onButtonClick_Button71(ZKButton *pButton) {
	 setxs(2);
	 mButton3Ptr->setText(tempptwd);

    return false;
}

static bool onButtonClick_Button72(ZKButton *pButton) {


//	mLVFolderPtr->setSelection(1);//跳转到第一行
	    setxs(3);//切换背景

        if(mwinPrintPtr->isVisible()){
        	mfishPtr->setVisible(false);
        	mwinPrintPtr->setVisible(true);



        }
		else{
		mfishPtr->setVisible(true);
		mboardsdPtr->setVisible(false);}//








    return false;
}

static bool onButtonClick_Button73(ZKButton *pButton) {

	setxs(4);


    return false;
}

static bool onButtonClick_Button74(ZKButton *pButton) {
	//mwifiPtr->setVisible(true);
    setxs(5);

    std::string wifiname = StoragePreferences::getString("wifiname", "");
    std::string wifipassword = StoragePreferences::getString("wifipassword", "");
    mEditText1Ptr ->setText(wifiname.c_str());
    mEditText2Ptr ->setText(wifipassword.c_str());




    return false;
}



static bool onButtonClick_Button75(ZKButton *pButton) {



    if (!pButton->isSelected()){//切换到热床
    	 mtemprcPtr->setVisible(true);
    	 mtempptPtr->setVisible(false);
    	 mButton6Ptr->setText(temprcwd);
    }
    else{ mtemprcPtr->setVisible(false);
        mtempptPtr->setVisible(true);}
        pButton->setSelected(!pButton->isSelected());


    return false;
}

static bool onButtonClick_Button76(ZKButton *pButton) {
   // LOGD(" ButtonClick Button76 !!!\n");
tempptwd++;
mButton3Ptr->setText(tempptwd);


    return false;
}

static bool onButtonClick_Button77(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button77 !!!\n");
    if (!pButton->isSelected()){//加热开启
        char buf[50];
        Hardware_serial_transmission("M104 S");
        sprintf(buf,"%d\r\n",tempptwd);
        Hardware_serial_transmission(buf);
    }
        else
        Hardware_serial_transmission("M104 S0\r\n");



               	pButton->setSelected(!pButton->isSelected());


    return false;
}




static bool onButtonClick_Button78(ZKButton *pButton) {
    //LOGD(" ButtonClick Button78 !!!\n");

	if (!pButton->isSelected()) {//如果开启
			finishoff = 1;

	 	}
	 	else
	 		finishoff = 0;

		pButton->setSelected(!pButton->isSelected());
	    return false;
}
static bool onButtonClick_Button79(ZKButton *pButton) {

	if (!pButton->isSelected()) {

		Hardware_serial_transmission("M220\r\n");
		mprintcsPtr->showWnd();
	 	}
	 	else {	mprintcsPtr->hideWnd();

	 	}
	pButton->setSelected(!pButton->isSelected());

    return false;
}




static bool onButtonClick_Button80(ZKButton *pButton) {
   // LOGD(" ButtonClick Button80 !!!\n");
    mAJPtr->showWnd();
    curprintcs = 0;
    return false;
}

static bool onButtonClick_Button81(ZKButton *pButton) {
   // LOGD(" ButtonClick Button81 !!!\n");
	mAJPtr->showWnd();
    curprintcs = 1;
    return false;
}

static bool onButtonClick_Button82(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button82 !!!\n");
	mAJPtr->showWnd();
    curprintcs = 2;
    return false;
}

static bool onButtonClick_Button83(ZKButton *pButton) {
   // LOGD(" ButtonClick Button83 !!!\n");
	mAJPtr->showWnd();
    curprintcs = 3;
    return false;
}
static bool onButtonClick_Button84(ZKButton *pButton) {
	//LOGD(" ButtonClick Button84 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button85(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button85 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button86(ZKButton *pButton) {
   // LOGD(" ButtonClick Button86 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button87(ZKButton *pButton) {
   // LOGD(" ButtonClick Button87 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button88(ZKButton *pButton) {
   // LOGD(" ButtonClick Button88 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button89(ZKButton *pButton) {
   // LOGD(" ButtonClick Button89 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button90(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button90 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button91(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button91 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button92(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button92 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button93(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button93 !!!\n");
 	mAJPtr->hideWnd();
 	sContentStr.clear();
	mTextView22Ptr->setText(sContentStr);
    return false;
}
static bool onButtonClick_Button94(ZKButton *pButton) {
   // LOGD(" ButtonClick Button94 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button95(ZKButton *pButton) {
    //LOGD(" ButtonClick Button95 !!!\n");
 	mAJPtr->hideWnd();

	switch(curprintcs){

	case 0:Hardware_serial_transmission("M140 S");
	Hardware_serial_transmission(sContentStr);break;

	case 1:Hardware_serial_transmission("M104 S");
	Hardware_serial_transmission(sContentStr);break;

	case 2:Hardware_serial_transmission("M106 S");
	Hardware_serial_transmission(sContentStr);break;

	case 3://backok++;
	Hardware_serial_transmission("M220 S");
	Hardware_serial_transmission(sContentStr);break;

	case 4: StoragePreferences::putString("Leveling_high", sContentStr);
		     char buf[10];
		     snprintf(buf,sizeof(buf),"%smm",sContentStr.c_str());
	         mButton46Ptr->setText(buf)	;break;

	case 20: StoragePreferences::putInt("SJtime", atoi(sContentStr.c_str()));   mButton30Ptr->setText(sContentStr.c_str());      break;



	case 30: Hardware_serial_transmission("M104 S"); tempptwd = atoi(sContentStr.c_str());
	         mButton3Ptr->setText(tempptwd);
	         Hardware_serial_transmission(sContentStr.c_str());break;
	case 31: Hardware_serial_transmission("M140 S"); temprcwd = atoi(sContentStr.c_str());
		         mButton3Ptr->setText(temprcwd);
		         Hardware_serial_transmission(sContentStr.c_str());break;


	}
	//backok++;
	Hardware_serial_transmission("\r\n");
	//LOGD("sContentStr:%s",sContentStr.c_str());
 	sContentStr.clear();
	mTextView22Ptr->setText(sContentStr);
    return false;
}
static bool onButtonClick_Button96(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button96 !!!\n");
	delOneChar();
    return false;
}


void  setwhbj(int a){
	mwhmovePtr->setVisible(false);
	mwhclPtr->setVisible(false);
	mwhtpPtr->setVisible(false);
	mwhcsPtr->setVisible(false);

	switch(a){
	case 0: mwhmovePtr->setVisible(true);mTextView37Ptr->setBackgroundPic("whsetbj.png");          break;
	case 1: mwhclPtr->setVisible(true);mTextView37Ptr->setBackgroundPic("whsetbj1.png");           break;
	case 2: mwhtpPtr->setVisible(true);mTextView37Ptr->setBackgroundPic("whsetbj2.png");           break;
	case 3: mwhcsPtr->setVisible(true); mTextView37Ptr->setBackgroundPic("whsetbj3.png");           break;
	//case 4: mTextView37Ptr->setBackgroundPic("whsetbj4.png");           break;
	//case 5: mTextView37Ptr->setBackgroundPic("whsetbj.png");           break;

	}
}
static bool onButtonClick_Button97(ZKButton *pButton) {
   // LOGD(" ButtonClick Button97 !!!\n");

	setwhbj(0);
    return false;
}

static bool onButtonClick_Button98(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button98 !!!\n");


	setwhbj(1);
    return false;
}

static bool onButtonClick_Button99(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button99 !!!\n");
	setwhbj(2);


	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		char buf[10];
		snprintf(buf,sizeof(buf),"%smm",Leveling_high.c_str());
	mButton46Ptr->setText(buf)	;}
    return false;
}

static bool onButtonClick_Button100(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button100 !!!\n");
	setwhbj(3);
		char buf[50];
		std::string xcdf = StoragePreferences::getString("Xcd", "");//X长度
		std::string ycdf = StoragePreferences::getString("Ycd", "");//X长度
		std::string zcdf = StoragePreferences::getString("Zcd", "");//X长度
		std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//X长度
		std::string zspeedf = StoragePreferences::getString("Zspeed", "");//X长度


		if(strcmp(xcdf.c_str(),"")!=0)
		sprintf(buf,"Xaxis length：%s",xcdf.c_str());
		else
		sprintf(buf,"Xaxis length：%d",xcd);
		mButton110Ptr->setText(buf);

		if(strcmp(ycdf.c_str(),"")!=0)
		sprintf(buf,"Yaxis length：%s",ycdf.c_str());
			else
		sprintf(buf,"Yaxis length：%d",ycd);
		mButton111Ptr->setText(buf);

		if(strcmp(zcdf.c_str(),"")!=0)
		sprintf(buf,"Zaxis length：%s",zcdf.c_str());
			else
		sprintf(buf,"Zaxis length：%d",zcd);
		mButton112Ptr->setText(buf);


		if(strcmp(xyspeedf.c_str(),"")!=0)
		sprintf(buf,"XY move speed：%s",xyspeedf.c_str());
			else
		sprintf(buf,"XY move speed：%d",xyspeed);
		mButton113Ptr->setText(buf);


		if(strcmp(zspeedf.c_str(),"")!=0)
		sprintf(buf,"Z move speed：%s",zspeedf.c_str());
			else
		sprintf(buf,"Z move speed：%d",zspeed);
		mButton114Ptr->setText(buf);

		std::string hccdf = StoragePreferences::getString("hccd", "");//
		std::string dsf = StoragePreferences::getString("ds", "");//
		std::string csf = StoragePreferences::getString("cs", "");//
		std::string gsf = StoragePreferences::getString("gs", "");//

		if(strcmp(hccdf.c_str(),"")!=0)
			sprintf(buf,"Extrusion length：%s",hccdf.c_str());
				else
			sprintf(buf,"Extrusion length：100");
			mButton115Ptr->setText(buf);

			if(strcmp(dsf.c_str(),"")!=0)
				sprintf(buf,"LOW speed：%s",dsf.c_str());
					else
				sprintf(buf,"LOW speed：150");
				mButton116Ptr->setText(buf);

				if(strcmp(csf.c_str(),"")!=0)
					sprintf(buf,"Constant speed：%s",csf.c_str());
						else
					sprintf(buf,"Constant speed：300");
					mButton117Ptr->setText(buf);

					if(strcmp(gsf.c_str(),"")!=0)
						sprintf(buf,"HIGH speed：%s",gsf.c_str());
							else
						sprintf(buf,"HIGH speed：1800");
						mButton118Ptr->setText(buf);

	    return false;
	}
static bool onButtonClick_Button101(ZKButton *pButton) {
    //LOGD(" ButtonClick Button101 !!!\n");

	//pButton->setSelected(!pButton->isSelected());
	   mButton101Ptr->setSelected(true);
	   mButton102Ptr->setSelected(true);
	   mButton103Ptr->setSelected(false);
	jcsd =1;
	mTextView38Ptr->setBackgroundPic("whclsdds.png");
	std::string dsf = StoragePreferences::getString("ds", "");
		if(strcmp(dsf.c_str(),"")!=0)
			hcsd = atoi(dsf.c_str());
			else
			hcsd = 150;
    return false;
}
static bool onButtonClick_Button102(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button102 !!!\n");
	   mButton101Ptr->setSelected(false);
	   mButton102Ptr->setSelected(false);
	   mButton103Ptr->setSelected(false);
//	pButton->setSelected(!pButton->isSelected());
	jcsd =0;
	std::string zsf = StoragePreferences::getString("zs", "");
	mTextView38Ptr->setBackgroundPic("whclsdcs.png");
	if(strcmp(zsf.c_str(),"")!=0)
		hcsd = atoi(zsf.c_str());
		else
		hcsd = 300;
    return false;
}

static bool onButtonClick_Button103(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button103 !!!\n");
	   mButton101Ptr->setSelected(false);
	   mButton102Ptr->setSelected(true);
	   mButton103Ptr->setSelected(true);
	jcsd =1;
	mTextView38Ptr->setBackgroundPic("whclsdgs.png");
	std::string gsf = StoragePreferences::getString("gs", "");
			if(strcmp(gsf.c_str(),"")!=0)
				hcsd = atoi(gsf.c_str());
				else
				hcsd = 1800;
    return false;
}
static bool onButtonClick_Button104(ZKButton *pButton) {
   // LOGD(" ButtonClick Button104 !!!\n");
	ptkg=2;
	TL++;
	whT++;

	char buf[50];
	  //sprintf(buf,"Z:%s",Axis[2].va.c_str());
	if(whT>6)
		whT=0;
		  sprintf(buf,"Nozzle%d",whT);
		  mTextView4Ptr->setTextTr(buf);
		  mTextView39Ptr->setTextTr(buf);
		sprintf(buf,"T%d\r\n",whT);
	 Hardware_serial_transmission(buf);
    return false;
}

static bool onButtonClick_Button105(ZKButton *pButton) {
    //LOGD(" ButtonClick Button105 !!!\n");
	ptkg=2;
	TR++;
	whT--;

	char buf[50];
	  //sprintf(buf,"Z:%s",Axis[2].va.c_str());
	if(whT<0)
		whT=6;
		  sprintf(buf,"Nozzle%d",whT);
		  mTextView4Ptr->setTextTr(buf);
		  mTextView39Ptr->setTextTr(buf);
		  sprintf(buf,"T%d\r\n",whT);
		Hardware_serial_transmission(buf);

    return false;
}
static int getListItemCount_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
	return sizeof(Gcode) / sizeof(gcodeml);

}

static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");
	pListItem->setText(Gcode[index].mainText);
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");
	 mTextView45Ptr->setText(Gcode[index].nrText);

}
static bool onButtonClick_Button109(ZKButton *pButton) {
    //LOGD(" ButtonClick Button109 !!!\n");
	curprintcs = 40;
	 mAJ1Ptr->showWnd();
    return false;
}

void  setmorebj(int a){
	mmorehmlPtr->setVisible(false);
	mmoregjPtr->setVisible(false);
	mmorepmsetPtr->setVisible(false);
	mwifiPtr->setVisible(false);

	switch(a){
	case 0: mwifiPtr->setVisible(true);mTextView43Ptr->setBackgroundPic("morebj0.png");           break;
	case 1: mmoregjPtr->setVisible(true);mTextView43Ptr->setBackgroundPic("morebj1.png");          break;
	case 2: mmorehmlPtr->setVisible(true);mTextView43Ptr->setBackgroundPic("morebj2.png");           break;
	case 3: mmorepmsetPtr->setVisible(true);mTextView43Ptr->setBackgroundPic("morebj3.png");           break;

	}
}


static bool onButtonClick_Button12(ZKButton *pButton) {
   // LOGD(" ButtonClick Button12 !!!\n");
	 setmorebj(0);
    return false;
}

static bool onButtonClick_Button106(ZKButton *pButton) {
   // LOGD(" ButtonClick Button106 !!!\n");
	 setmorebj(1);
    return false;
}

static bool onButtonClick_Button107(ZKButton *pButton) {
   // LOGD(" ButtonClick Button107 !!!\n");
	 setmorebj(2);

    return false;
}

static bool onButtonClick_Button108(ZKButton *pButton) {
   // LOGD(" ButtonClick Button108 !!!\n");
	 setmorebj(3);
    return false;
}
static bool onButtonClick_Button110(ZKButton *pButton) {
    //LOGD(" ButtonClick Button110 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 10;
	//StoragePreferences::putString("printpause", text.c_str());

    return false;
}

static bool onButtonClick_Button111(ZKButton *pButton) {
   // LOGD(" ButtonClick Button111 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 11;
    return false;
}

static bool onButtonClick_Button112(ZKButton *pButton) {
   // LOGD(" ButtonClick Button112 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 12;
    return false;
}

static bool onButtonClick_Button113(ZKButton *pButton) {
   // LOGD(" ButtonClick Button113 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 13;
    return false;
}

static bool onButtonClick_Button114(ZKButton *pButton) {
   // LOGD(" ButtonClick Button114 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 14;
    return false;
}

static bool onButtonClick_Button115(ZKButton *pButton) {
   // LOGD(" ButtonClick Button115 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 15;
    return false;
}

static bool onButtonClick_Button116(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button116 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 16;
    return false;
}

static bool onButtonClick_Button117(ZKButton *pButton) {
   // LOGD(" ButtonClick Button117 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 17;
    return false;
}

static bool onButtonClick_Button118(ZKButton *pButton) {
   // LOGD(" ButtonClick Button118 !!!\n");
    mAJ1Ptr->showWnd();
    curprintcs = 18;
    return false;
}

static bool onButtonClick_Button119(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button119 !!!\n");
    return false;
}

static bool onButtonClick_Button120(ZKButton *pButton) {
    //LOGD(" ButtonClick Button120 !!!\n");
    return false;
}

static bool onButtonClick_Button121(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button121 !!!\n");
    return false;
}

static bool onButtonClick_Button122(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button122 !!!\n");
    return false;
}

static bool onButtonClick_Button123(ZKButton *pButton) {
   // LOGD(" ButtonClick Button123 !!!\n");
    return false;
}

static bool onButtonClick_Button124(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button124 !!!\n");
    return false;
}
static bool onButtonClick_Button125(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button125 !!!\n");
    return false;
}
static bool onButtonClick_Button126(ZKButton *pButton) {
   // LOGD(" ButtonClick Button126 !!!\n");


	//mAJ1Ptr->hideWnd();
	switch(curprintcs){

	case 10: StoragePreferences::putString("Xcd", sContentStr.c_str());break;
	case 11: StoragePreferences::putString("Ycd", sContentStr.c_str());break;
	case 12: StoragePreferences::putString("Zcd", sContentStr.c_str());break;
	case 13: StoragePreferences::putString("XYspeed", sContentStr.c_str());break;
	case 14: StoragePreferences::putString("Zspeed", sContentStr.c_str());break;

	/*
	 * 耗材装载参数设置
	 */

	case 15: StoragePreferences::putString("hccd", sContentStr.c_str());break;
	case 16: StoragePreferences::putString("ds", sContentStr.c_str());break;
	case 17: StoragePreferences::putString("cs", sContentStr.c_str());break;
	case 18: StoragePreferences::putString("gs", sContentStr.c_str());break;









	case 40:Hardware_serial_transmission(sContentStr);
	        Hardware_serial_transmission("\r\n");break;


//脉冲速度pid








	case 100:Hardware_serial_transmission(sContentStr.c_str());
	         Hardware_serial_transmission("\r\n");
	         char buf[150];
	        		 sprintf(buf,"Send：%s\r\n",sContentStr.c_str());
	        		 Command_Feedback.push_back(buf) ;
	        		// gindex++;
	        		 mListView2Ptr->refreshListView();
	        		 mListView2Ptr->setSelection(Command_Feedback.size()-2);
	        		// LOGD("键盘内容：%s",sContentStr.c_str());
	        		 break;

	}
	std::string xcdf = StoragePreferences::getString("Xcd", "");//X
	std::string ycdf = StoragePreferences::getString("Ycd", "");//X长度
	std::string zcdf = StoragePreferences::getString("Zcd", "");//X长度
	std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//X长度
	std::string zspeedf = StoragePreferences::getString("Zspeed", "");//X长度

	std::string hccdf = StoragePreferences::getString("hccd", "");//耗材长度
	std::string dsf = StoragePreferences::getString("ds", "");//低速
	std::string csf = StoragePreferences::getString("cs", "");//常速
	std::string gsf = StoragePreferences::getString("gs", "");//高速



char buf[100];
switch(curprintcs){
case 10:sprintf(buf,"Xaxis length：%s",xcdf.c_str());mButton110Ptr->setText(buf); break;
case 11:sprintf(buf,"Yaxis length：%s",ycdf.c_str());mButton111Ptr->setText(buf); break;
case 12:sprintf(buf,"Zaxis length：%s",zcdf.c_str());mButton112Ptr->setText(buf); break;
case 13:sprintf(buf,"XY move speed：%s",xyspeedf.c_str());mButton113Ptr->setText(buf); break;
case 14:sprintf(buf,"Z move speed：%s",zspeedf.c_str());mButton114Ptr->setText(buf); break;




case 15:sprintf(buf,"Extrusion length：%s",hccdf.c_str());mButton115Ptr->setText(buf); break;
case 16:sprintf(buf,"LOW speed：%s",dsf.c_str());mButton116Ptr->setText(buf); break;
case 17:sprintf(buf,"Constant speed:%s",csf.c_str());mButton117Ptr->setText(buf); break;
case 18:sprintf(buf,"HIGH speed：%s",gsf.c_str());mButton118Ptr->setText(buf); break;







	}

	//backok++;

 	sContentStr.clear();
	mTextView46Ptr->setText("");
    return false;


	return false;
}

static bool onButtonClick_Button128(ZKButton *pButton) {
   // LOGD(" ButtonClick Button128 !!!\n");

	StoragePreferences::remove("Xcd");
	StoragePreferences::remove("Ycd");
	StoragePreferences::remove("Zcd");
	StoragePreferences::remove("XYspeed");
	StoragePreferences::remove("Zspeed");
	StoragePreferences::remove("hccd");
	StoragePreferences::remove("ds");
	StoragePreferences::remove("cs");
	StoragePreferences::remove("gs");
    char buf[50];
	sprintf(buf,"Xaxis length：%d",xcd);
	mButton110Ptr->setText(buf);
	sprintf(buf,"Yaxis length：%d",ycd);
	mButton111Ptr->setText(buf);
    sprintf(buf,"Zaxis length：%d",zcd);
	mButton112Ptr->setText(buf);
	sprintf(buf,"XY move speed：%d",xyspeed);
	mButton113Ptr->setText(buf);
	sprintf(buf,"Z move speed：%d",zspeed);
	mButton114Ptr->setText(buf);





    return false;
}

static bool onButtonClick_Button127(ZKButton *pButton) {
    //LOGD(" ButtonClick Button127 !!!\n");
	addOneChar('1');
    return false;
}
static bool onButtonClick_Button129(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button129 !!!\n");
	addOneChar('0');
    return false;
}

static bool onButtonClick_Button130(ZKButton *pButton) {
    //LOGD(" ButtonClick Button130 !!!\n");
    addOneChar('2');
    return false;
}

static bool onButtonClick_Button131(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button131 !!!\n");
	addOneChar('3');
    return false;
}

static bool onButtonClick_Button132(ZKButton *pButton) {
    //LOGD(" ButtonClick Button132 !!!\n");
	addOneChar('4');
    return false;
}

static bool onButtonClick_Button133(ZKButton *pButton) {
    //LOGD(" ButtonClick Button133 !!!\n");
	addOneChar('5');
    return false;
}

static bool onButtonClick_Button134(ZKButton *pButton) {
   // LOGD(" ButtonClick Button134 !!!\n");
	addOneChar('6');
    return false;
}

static bool onButtonClick_Button135(ZKButton *pButton) {
   // LOGD(" ButtonClick Button135 !!!\n");
	addOneChar('7');
    return false;
}

static bool onButtonClick_Button136(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button136 !!!\n");
	addOneChar('8');
    return false;
}

static bool onButtonClick_Button137(ZKButton *pButton) {
   // LOGD(" ButtonClick Button137 !!!\n");
    addOneChar('9');
    return false;
}

static bool onButtonClick_Button138(ZKButton *pButton) {
   // LOGD(" ButtonClick Button138 !!!\n");
    addOneChar('-');
    return false;
}

static bool onButtonClick_Button139(ZKButton *pButton) {
   // LOGD(" ButtonClick Button139 !!!\n");
	 addOneChar('.');
    return false;
}

static bool onButtonClick_Button140(ZKButton *pButton) {
   // LOGD(" ButtonClick Button140 !!!\n");
	 addOneChar('A');
    return false;
}

static bool onButtonClick_Button141(ZKButton *pButton) {
   // LOGD(" ButtonClick Button141 !!!\n");
	 addOneChar('B');
    return false;
}

static bool onButtonClick_Button142(ZKButton *pButton) {
    //LOGD(" ButtonClick Button142 !!!\n");
	 addOneChar('C');
    return false;
}

static bool onButtonClick_Button143(ZKButton *pButton) {
    //LOGD(" ButtonClick Button143 !!!\n");
	 addOneChar('D');
    return false;
}

static bool onButtonClick_Button144(ZKButton *pButton) {
    //LOGD(" ButtonClick Button144 !!!\n");
	 addOneChar('E');
    return false;
}

static bool onButtonClick_Button145(ZKButton *pButton) {
   // LOGD(" ButtonClick Button145 !!!\n");
	 addOneChar('F');
    return false;
}

static bool onButtonClick_Button146(ZKButton *pButton) {
   // LOGD(" ButtonClick Button146 !!!\n");
	 addOneChar('G');
    return false;
}

static bool onButtonClick_Button147(ZKButton *pButton) {
   // LOGD(" ButtonClick Button147 !!!\n");
	 addOneChar('H');
    return false;
}

static bool onButtonClick_Button148(ZKButton *pButton) {
   // LOGD(" ButtonClick Button148 !!!\n");
	 addOneChar('I');
    return false;
}

static bool onButtonClick_Button149(ZKButton *pButton) {
   // LOGD(" ButtonClick Button149 !!!\n");
	 addOneChar('J');
    return false;
}

static bool onButtonClick_Button150(ZKButton *pButton) {
   // LOGD(" ButtonClick Button150 !!!\n");
	 addOneChar('K');
    return false;
}

static bool onButtonClick_Button151(ZKButton *pButton) {
   // LOGD(" ButtonClick Button151 !!!\n");
	 addOneChar('L');
    return false;
}

static bool onButtonClick_Button152(ZKButton *pButton) {
   // LOGD(" ButtonClick Button152 !!!\n");
	 addOneChar('M');
    return false;
}

static bool onButtonClick_Button153(ZKButton *pButton) {
   // LOGD(" ButtonClick Button153 !!!\n");
	 addOneChar('N');
    return false;
}

static bool onButtonClick_Button154(ZKButton *pButton) {
   // LOGD(" ButtonClick Button154 !!!\n");
	 addOneChar('O');
    return false;
}

static bool onButtonClick_Button155(ZKButton *pButton) {
   // LOGD(" ButtonClick Button155 !!!\n");
	 addOneChar('P');
    return false;
}

static bool onButtonClick_Button156(ZKButton *pButton) {
   // LOGD(" ButtonClick Button156 !!!\n");
	 addOneChar('Q');
    return false;
}

static bool onButtonClick_Button157(ZKButton *pButton) {
   // LOGD(" ButtonClick Button157 !!!\n");
	 addOneChar('R');
    return false;
}

static bool onButtonClick_Button158(ZKButton *pButton) {
   // LOGD(" ButtonClick Button158 !!!\n");
	 addOneChar('S');
    return false;
}

static bool onButtonClick_Button159(ZKButton *pButton) {
   // LOGD(" ButtonClick Button159 !!!\n");
	 addOneChar('T');
    return false;
}

static bool onButtonClick_Button160(ZKButton *pButton) {
   // LOGD(" ButtonClick Button160 !!!\n");
	 addOneChar('U');
    return false;
}

static bool onButtonClick_Button161(ZKButton *pButton) {
    //LOGD(" ButtonClick Button161 !!!\n");
	 addOneChar('V');
    return false;
}

static bool onButtonClick_Button162(ZKButton *pButton) {
    //LOGD(" ButtonClick Button162 !!!\n");
	 addOneChar('W');
    return false;
}

static bool onButtonClick_Button163(ZKButton *pButton) {
    //LOGD(" ButtonClick Button163 !!!\n");
	 addOneChar('X');
    return false;
}

static bool onButtonClick_Button164(ZKButton *pButton) {
   // LOGD(" ButtonClick Button164 !!!\n");
	 addOneChar('Y');
    return false;
}

static bool onButtonClick_Button165(ZKButton *pButton) {
   // LOGD(" ButtonClick Button165 !!!\n");
	 addOneChar('Z');
    return false;
}
static bool onButtonClick_Button166(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button166 !!!\n");
	 addOneChar(' ');
    return false;
}

static bool onButtonClick_Button167(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button167 !!!\n");
	delOneChar();
    return false;
}

static bool onButtonClick_Button168(ZKButton *pButton) {
//    LOGD(" ButtonClick Button168 !!!\n");
    mAJ1Ptr->hideWnd();
    sContentStr.clear();
    	mTextView46Ptr->setText("");
    return false;
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView2 !\n");
    return Command_Feedback.size();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView2  !!!\n");

	pListItem->setText(Command_Feedback[index]);
//	pListItem->setText(shu[index]);
}

static void onListItemClick_ListView2(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView2  !!!\n");
	curprintcs = 100;
	mAJ1Ptr->showWnd();
	// LOGD("%s",Gc[gindex].mainText);
}

static bool onButtonClick_Button178(ZKButton *pButton) {
   // LOGD(" ButtonClick Button178 !!!\n");
	ptkg=1;
	TR++;
	whT--;
	bjkg2=0;
	char buf[50];
	  //sprintf(buf,"Z:%s",Axis[2].va.c_str());
	if(whT<0)
		whT=6;
	  sprintf(buf,"Nozzle%d",whT);
		  mTextView4Ptr->setTextTr(buf);
		  mTextView39Ptr->setTextTr(buf);
		  sprintf(buf,"T%d\r\n",whT);
			Hardware_serial_transmission(buf);
 	 	mButton77Ptr->setSelected(pButton->isSelected());
 	 	mTextView7Ptr->setBackgroundPic("temprcxsoff.png");

 		switch(whT){
 		case 0:if(atoi(Target_Temperature[1].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 1:if(atoi(Target_Temperature[2].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 2:if(atoi(Target_Temperature[3].c_str())>0) { mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 3:if(atoi(Target_Temperature[4].c_str())>0) { mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 4:if(atoi(Target_Temperature[5].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 5:if(atoi(Target_Temperature[6].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 6:if(atoi(Target_Temperature[7].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;

 		}
    return false;
}

static bool onButtonClick_Button179(ZKButton *pButton) {
    //LOGD(" ButtonClick Button179 !!!\n");
	ptkg=1;
	TL++;
		whT++;

		char buf[50];
		  //sprintf(buf,"Z:%s",Axis[2].va.c_str());
		if(whT>6)
			whT=0;
			sprintf(buf,"Nozzle%d",whT);
			mTextView4Ptr->setTextTr(buf);
			mTextView39Ptr->setTextTr(buf);
			sprintf(buf,"T%d\r\n",whT);
		    Hardware_serial_transmission(buf);
	 	 	mButton77Ptr->setSelected(false);
	 	 	mTextView7Ptr->setBackgroundPic("temprcxsoff.png");
	 switch(whT){


 		case 1:if(atoi(Target_Temperature[2].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 2:if(atoi(Target_Temperature[3].c_str())>0) { mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 3:if(atoi(Target_Temperature[4].c_str())>0) { mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 4:if(atoi(Target_Temperature[5].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 5:if(atoi(Target_Temperature[6].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;
 		case 6:if(atoi(Target_Temperature[7].c_str())>0){ mButton77Ptr->setSelected(true);mTextView7Ptr->setBackgroundPic("temprcxson.png");}break;

 		}






    return false;
}
static bool onButtonClick_Button180(ZKButton *pButton) {
	 curprintcs = 30;
	 mAJPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button4(ZKButton *pButton) {
	 curprintcs = 31;
	mAJPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
	   if (!pButton->isSelected()){//加热开启
	        char buf[50];
	        Hardware_serial_transmission("M140 S");
	        sprintf(buf,"%d\r\n",temprcwd);
	    Hardware_serial_transmission(buf);
	    mTextView49Ptr->setBackgroundPic("temprcxson.png");
	   }
	        else{
	        mTextView49Ptr->setBackgroundPic("temprcxsoff.png");
	        Hardware_serial_transmission("M140 S0\r\n");}
             pButton->setSelected(!pButton->isSelected());


    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {

    curprintcs = 31;
   	 mAJPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {
	temprcwd--;
		mButton6Ptr->setText(temprcwd);
    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {

	temprcwd++;
	mButton6Ptr->setText(temprcwd);
    return false;
}
static int getListItemCount_ListView3(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView3 !\n");
    return 10;
}

static void obtainListItemData_ListView3(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView3  !!!\n");
	pListItem->setText(maxspeeds[index]);
}

static void onListItemClick_ListView3(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView3  !!!\n");
	 mAJ1Ptr->setVisible(true);
	 switch(index){
	 case 0:curprintcs=59;break;
	 case 1:curprintcs=60;break;
	 case 2:curprintcs=61;break;
	 case 3:curprintcs=62;break;
	 case 4:curprintcs=63;break;
	 case 5:curprintcs=64;break;
	 case 6:curprintcs=65;break;
	 case 7:curprintcs=66;break;
	 case 8:curprintcs=67;break;


	 }
}
static int getListItemCount_ListView4(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView4 !\n");
    return 3;
}

static void obtainListItemData_ListView4(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView4  !!!\n");
	pListItem->setText(PID[index]);
}

static void onListItemClick_ListView4(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView4  !!!\n");
	 mAJ1Ptr->setVisible(true);
	 switch(index){
	 case 0:curprintcs=68;break;
	 case 1:curprintcs=69;break;
	 case 2:curprintcs=70;break;



	 }

}
static int getListItemCount_ListView5(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView5 !\n");

    return 9;
}

static void obtainListItemData_ListView5(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView5  !!!\n");
	//pListItem->setText(STEP[index]);
}

static void onListItemClick_ListView5(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView5  !!!\n");

	 mAJ1Ptr->setVisible(true);
	 switch(index){
	 case 0:curprintcs=50;break;
	 case 1:curprintcs=51;break;
	 case 2:curprintcs=52;break;
	 case 3:curprintcs=53;break;
	 case 4:curprintcs=54;break;
	 case 5:curprintcs=55;break;
	 case 6:curprintcs=56;break;
	 case 7:curprintcs=57;break;
	 case 8:curprintcs=58;break;


	 }


}
static bool onButtonClick_Button9(ZKButton *pButton) {
   // LOGD(" ButtonClick Button9 !!!\n");
	 currmode = 0;
	 print_file_path = "M20 S2 P0:/gcodes";
	 Hardware_serial_transmission("M20 S2 P0:/gcodes\r\n");
	 mboardsdPtr->setVisible(true);
	 mfishPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button10(ZKButton *pButton) {
   // LOGD(" ButtonClick Button10 !!!\n");



	sprintf(macros_print_patha,"M98 P\"0:/macros/");
	sprintf(macros_print_path,"M98 P\"0:/macros/");
	currmode = 1;
	 Hardware_serial_transmission("M20 S2 P0:/macros\r\n");
	// snprintf(macros_print_path, sizeof(macros_print_path), "M98 P\"0:/macros/");

	 mboardsdPtr->setVisible(true);
	 mfishPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button11(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button11 !!!\n");
	currmode = 1;
	listFiles("/mnt", ".");
    return false;
}
static int getListItemCount_boardsd(const ZKListView *pListView) {
    //LOGD("getListItemCount_boardsd !\n");
    return gcodenum;
}

static void obtainListItemData_boardsd(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ boardsd  !!!\n");
	pListItem->setText(File_Gcodes[index]);

    char buf[20];
     sprintf(buf,"%s", File_Gcodes[index].c_str());
		if(buf[0] != '*'){
  	char path[50] = {0};
  snprintf(path, sizeof(path), "fileicon1.png");
	ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_file_icon);
         icon->setBackgroundPic(path);
		}
		else{
		  	char path[50] = {0};
		  snprintf(path, sizeof(path), "fileicon.png");
			ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_file_icon);
		         icon->setBackgroundPic(path);
				}

}

static void onListItemClick_boardsd(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ boardsd  !!!\n");
	 xzgcodenum = index;

	if(currmode == 0){

      char buf[128];
      sprintf(buf,"%s", File_Gcodes[xzgcodenum].c_str());

		//LOGD("%c",buf[0]);
		if(buf[0] != '*'){//非文件夹

			mwinQueryPrintPtr->setVisible(true);

		}

		else{//文件夹
			  print_file_path += "/";
			  print_file_path += buf+1;//去除*
			  Hardware_serial_transmission(print_file_path.c_str());
			  Hardware_serial_transmission("\r\n");
		}











	}

	if(currmode == 1){
        char buf[128];
      sprintf(buf,"%s", File_Gcodes[xzgcodenum].c_str());

		//LOGD("%c",buf[0]);
		if(buf[0] != '*'){
         //LOGD("路径2：%s",macros_print_patha);
		 Hardware_serial_transmission(macros_print_patha);
		 Hardware_serial_transmission("/");
		 Hardware_serial_transmission(File_Gcodes[xzgcodenum].c_str());
		 Hardware_serial_transmission("\"\r\n");

		}

		else{snprintf(macros_print_patha,sizeof(macros_print_patha),"%s%s",macros_print_path,buf+1);
			//sprintf(macros_print_patha,"%s%s",macros_print_path,buf+1);
		snprintf(macros_print_path,sizeof(macros_print_path),"%s/",macros_print_patha);

		LOGD("路径a：%s",macros_print_patha);
		LOGD("路径b：%s",macros_print_path);
			Hardware_serial_transmission("M20 S2 P0:/macros/");
			Hardware_serial_transmission(macros_print_patha+15);
			Hardware_serial_transmission("\r\n");
		}


	}





}
static void onEditTextChanged_EditText1(const std::string &text) {
    //LOGD(" onEditTextChanged_ EditText1 %s !!!\n", text.c_str());
	StoragePreferences::putString("wifiname", text.c_str());
}

static void onEditTextChanged_EditText2(const std::string &text) {
    //LOGD(" onEditTextChanged_ EditText2 %s !!!\n", text.c_str());
	StoragePreferences::putString("wifipassword", text.c_str());
}

static bool onButtonClick_Button13(ZKButton *pButton) {
   // LOGD(" ButtonClick Button13 !!!\n");
	 Hardware_serial_transmission("M552 S-1\r\n");

    return false;
}

static bool onButtonClick_Button14(ZKButton *pButton) {
   // LOGD(" ButtonClick Button14 !!!\n");
	 Hardware_serial_transmission("M552\r\n");

    return false;
}

static bool onButtonClick_Button15(ZKButton *pButton) {
   // LOGD(" ButtonClick Button15 !!!\n");

	 Hardware_serial_transmission("M552 S1\r\n");

    return false;
}

static bool onButtonClick_Button16(ZKButton *pButton) {
	 Hardware_serial_transmission("M552 S2\r\n");

 				    return false;
 	}


static bool onButtonClick_Button18(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button18 !!!\n");
	 Hardware_serial_transmission("G32\r\n");

    return false;
}
static bool onButtonClick_Button39(ZKButton *pButton) {

    return false;
}

static bool onButtonClick_Button59(ZKButton *pButton) {
	if (!pButton->isSelected()){

		 Hardware_serial_transmission("M302 P1\r\n");

		}
		 else{
		 		Hardware_serial_transmission("M302 S170\r\n");

		 	}

	pButton->setSelected(!pButton->isSelected());

    return false;
}
static int getListItemCount_srecc(const ZKListView *pListView) {
    //LOGD("getListItemCount_srecc !\n");
	return sizeof(Screensetdata) / sizeof(Screen_settings);
}

static void obtainListItemData_srecc(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ srecc  !!!\n");

	pListItem->setTextTr(Screensetdata[index].mainText);

	ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_moreseticon);
  	char path[50] = {0};
  snprintf(path, sizeof(path), "morexs%d.png", index);
         icon->setBackgroundPic(path);
}

void setyc(){
	 mEdittext2Ptr->setVisible(false);mTextview53Ptr->setVisible(false);mButton48Ptr->setVisible(false);
	 mTextview51Ptr->setVisible(false);mTextview54Ptr->setVisible(false);mSeekbar3Ptr->setVisible(false);
	// mButton12Ptr->setVisible(false);
	 mButton29Ptr->setVisible(false);
	 mButton30Ptr->setVisible(false);
	 mButton31Ptr->setVisible(false);
	 mTextView2Ptr->setVisible(false);
	 mTextView14Ptr->setVisible(false);
	 mmoretimePtr->setVisible(false);
	 mTextView54Ptr->setVisible(false);mTextView56Ptr->setVisible(false);
	 	        mQRCode1Ptr->setVisible(false);

}
static void onListItemClick_srecc(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ srecc  !!!\n");
	 int a;
switch(index){

	case 0: setyc(); mEdittext2Ptr->setVisible(true);mTextview53Ptr->setVisible(true);mButton48Ptr->setVisible(true); break;

	case 1: setyc();
	        mmoretimePtr->setVisible(true);
	       if(StoragePreferences::getBool("pmcs", false)){
	                      moretime[0].bOn = true;}

           else{
	 	              moretime[0].bOn = false;}

	        switch(StoragePreferences::getInt("cstime", 30)/10){
	        moretime[1].bOn = false;
	        moretime[2].bOn = false;
	        moretime[3].bOn = false;
	        moretime[4].bOn = false;
	        moretime[5].bOn = false;
	        moretime[6].bOn = false;
	        moretime[7].bOn = false;
 	    	case 1:   moretime[1].bOn = true;   break;
 		    case 3:   moretime[2].bOn = true;   break;
 	    	case 6:   moretime[3].bOn = true;   break;
 	    	case 12:  moretime[4].bOn = true;   break;
 	    	case 30:  moretime[5].bOn = true;   break;
 	    	case 180: moretime[6].bOn = true;   break;
 	    	case 360: moretime[7].bOn = true;   break;
	         } mmoretimePtr->refreshListView();

	           a=BRIGHTNESSHELPER->getBrightness();mSeekbar3Ptr->setProgress(a);mTextview54Ptr->setText(a); mTextview51Ptr->setVisible(true);mTextview54Ptr->setVisible(true);mSeekbar3Ptr->setVisible(true); break;

//	case 2: if(StoragePreferences::getBool("SX", false)){
//		      mButton19Ptr->setSelected(true);
//		      mButton19Ptr->setText("双X模式:开");
//               	}
//	           else
//		        mButton12Ptr->setSelected(false);
//		        setyc(); mButton19Ptr->setVisible(true);break;

	case 2: if(StoragePreferences::getBool("SJ", false)){
	        mButton31Ptr->setSelected(true);
	        mButton31Ptr->setTextTr("Double-click home:open");
	        int sjtime = StoragePreferences::getInt("SJtime", 160);
	        mButton30Ptr->setText(sjtime);
            	}
            else
	        mButton31Ptr->setSelected(false);
	        setyc(); mButton31Ptr->setVisible(true);mButton31Ptr->setTextTr("Double-click home:close");mButton30Ptr->setVisible(true);	 mTextView2Ptr->setVisible(true);
	   	    mTextView14Ptr->setVisible(true);
	   	 mButton29Ptr->setVisible(true);
	   	    break;

	case 3: setyc();EASYUICONTEXT->openActivity("LanguageSettingActivity");   	                           break;
	case 4: setyc();mTextView54Ptr->setText("Scan the QR code to get the github connection, download the corresponding Updata.img and put it into the root directory of the sd card, and insert it on the screen to upgrade");
		     mTextView54Ptr->setVisible(true);mTextView56Ptr->setVisible(true);
	         mQRCode1Ptr->setVisible(true);





	}
}
static bool onButtonClick_Button19(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button19 !!!\n");
    return false;
}

static int getListItemCount_moretime(const ZKListView *pListView) {
    //LOGD("getListItemCount_moretime !\n");
    return   sizeof(moretime) / sizeof(more_time);;
}

static void obtainListItemData_moretime(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ moretime  !!!\n");
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_SubItem2);
	pListItem->setTextTr(moretime[index].mainText);
	psubButton->setSelected(moretime[index].bOn);
}

static void onListItemClick_moretime(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ moretime  !!!\n");


	//moretime[0].bOn = false;
	if(index == 0){
	 		       if(StoragePreferences::getBool("pmcs", false)){
	 			      StoragePreferences::putBool("pmcs", false);
	 			      moretime[0].bOn = false;
	 		    }
	 		   else{

	 			 StoragePreferences::putBool("pmcs", true);
	 			 	 moretime[0].bOn = true;
	 			}	}
	else{
	moretime[1].bOn = false;
	moretime[2].bOn = false;
	moretime[3].bOn = false;
	moretime[4].bOn = false;
	moretime[5].bOn = false;
	moretime[6].bOn = false;
	moretime[7].bOn = false;

	moretime[index].bOn = true;
 		switch (index){

 		case 1:StoragePreferences::putInt("cstime", 10);   break;
 		case 2:StoragePreferences::putInt("cstime", 30);   break;
 		case 3:StoragePreferences::putInt("cstime", 60);   break;
 		case 4:StoragePreferences::putInt("cstime", 120);  break;
 		case 5:StoragePreferences::putInt("cstime", 300);  break;
 		case 6:StoragePreferences::putInt("cstime", 1800); break;
 		case 7:StoragePreferences::putInt("cstime", 3600); break;

 		}

}}
static bool onButtonClick_Button29(ZKButton *pButton) {
   // LOGD(" ButtonClick Button29 !!!\n");
	   EASYUICONTEXT->openActivity("TouchCalibrationActivity");
    return false;
}

static bool onButtonClick_Button30(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button30 !!!\n");
	 curprintcs = 20;
	mAJPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button31(ZKButton *pButton) {
   // LOGD(" ButtonClick Button31 !!!\n");
    if (!pButton->isSelected()){
           mButton31Ptr->setTextTr("Double-click home:open");
     StoragePreferences::putBool("SJ", true);
    		}
    		else{
           mButton31Ptr->setTextTr("Double-click home:close");
     StoragePreferences::putBool("SJ", false);
    		}
    		pButton->setSelected(!pButton->isSelected());

    return false;
}
static bool onButtonClick_Button34(ZKButton *pButton) {
   // LOGD(" ButtonClick Button34 !!!\n");
	int progress = mSeekBar7Ptr->getProgress();
	mSeekBar7Ptr->setProgress(progress-1);

	//char buf[10];
			//	sprintf(buf,"%0.2f",0.01);
			Hardware_serial_transmission("G91\r\n");
			Hardware_serial_transmission("G1 Z-0.01\r\n");
			Hardware_serial_transmission("G90 \r\n");
    return false;
}

static void onProgressChanged_SeekBar7(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBar7 %d !!!\n", progress);
}

static bool onButtonClick_Button35(ZKButton *pButton) {
   // LOGD(" ButtonClick Button35 !!!\n");
	int progress = mSeekBar7Ptr->getProgress();
	mSeekBar7Ptr->setProgress(progress+1);
	//	char buf[10];
	//				sprintf(buf,"%0.2f",0.01);
					Hardware_serial_transmission("G91\r\n");
				Hardware_serial_transmission("G1 Z0.01\r\n");
				Hardware_serial_transmission("G90 \r\n");
    return false;
}



static bool onButtonClick_Button36(ZKButton *pButton) {
   // LOGD(" ButtonClick Button45 !!!\n");
	Hardware_serial_transmission("G28 X\r\n");
    return false;
}

static bool onButtonClick_Button37(ZKButton *pButton) {
	Hardware_serial_transmission("G28 Y\r\n");
    return false;
}

static bool onButtonClick_Button38(ZKButton *pButton) {
	Hardware_serial_transmission("G28 Z\r\n");
    return false;
}
static bool onButtonClick_Button40(ZKButton *pButton) {
   // LOGD(" ButtonClick Button40 !!!\n");
//	std::string Leveling1 = StoragePreferences::getString("Leveling1", "");
	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	LOGD("%s",Leveling_high.c_str());
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		Hardware_serial_transmission("G91\r\nG1 Z");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\nG90\r\n");

		Hardware_serial_transmission(Levelinga);
		Hardware_serial_transmission("G91\r\nG1 Z-");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\n");
	}
	else{

		Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
		Hardware_serial_transmission(Levelinga);
		Hardware_serial_transmission("G91\r\nG1 Z-5 F360\r\n");
	}
	Hardware_serial_transmission("G90\r\n");

    mButton40Ptr->setSelected(pButton->isPressed());
    mButton42Ptr->setSelected(pButton->isPressed());
    mButton43Ptr->setSelected(pButton->isPressed());
    mButton44Ptr->setSelected(pButton->isPressed());
    mButton45Ptr->setSelected(pButton->isPressed());
    pButton->setSelected(!pButton->isSelected());




    return false;
}
static bool onButtonClick_Button42(ZKButton *pButton) {
//	std::string Leveling2 = StoragePreferences::getString("Leveling2", "");

	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		Hardware_serial_transmission("G91\r\nG1 Z");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\nG90\r\n");

		Hardware_serial_transmission(Levelingb);
		Hardware_serial_transmission("G91\r\nG1 Z-");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\n");
	}
	else{

		Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
		Hardware_serial_transmission(Levelingb);
		Hardware_serial_transmission("G91\r\nG1 Z-5 F360\r\n");
	}
	Hardware_serial_transmission("G90\r\n");



    mButton40Ptr->setSelected(pButton->isPressed());
    mButton42Ptr->setSelected(pButton->isPressed());
    mButton43Ptr->setSelected(pButton->isPressed());
    mButton44Ptr->setSelected(pButton->isPressed());
    mButton45Ptr->setSelected(pButton->isPressed());
    pButton->setSelected(!pButton->isSelected());

	return false;
}

static bool onButtonClick_Button43(ZKButton *pButton) {
//	std::string Leveling3 = StoragePreferences::getString("Leveling3", "");

	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		Hardware_serial_transmission("G91\r\nG1 Z");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\nG90\r\n");

		Hardware_serial_transmission(Levelingc);
		Hardware_serial_transmission("G91\r\nG1 Z-");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\n");
	}
	else{

		Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
		Hardware_serial_transmission(Levelingc);
		Hardware_serial_transmission("G91\r\nG1 Z-5 F360\r\n");
	}
	Hardware_serial_transmission("G90\r\n");

    mButton40Ptr->setSelected(pButton->isPressed());
    mButton42Ptr->setSelected(pButton->isPressed());
    mButton43Ptr->setSelected(pButton->isPressed());
    mButton44Ptr->setSelected(pButton->isPressed());
    mButton45Ptr->setSelected(pButton->isPressed());
    pButton->setSelected(!pButton->isSelected());
	return false;
}

static bool onButtonClick_Button44(ZKButton *pButton) {
	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		Hardware_serial_transmission("G91\r\nG1 Z");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\nG90\r\n");

		Hardware_serial_transmission(Levelingd);
		Hardware_serial_transmission("G91\r\nG1 Z-");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\n");
	}
	else{

		Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
		Hardware_serial_transmission(Levelingd);
		Hardware_serial_transmission("G91\r\nG1 Z-5 F360\r\n");
	}
	Hardware_serial_transmission("G90\r\n");

    mButton40Ptr->setSelected(pButton->isPressed());
    mButton42Ptr->setSelected(pButton->isPressed());
    mButton43Ptr->setSelected(pButton->isPressed());
    mButton44Ptr->setSelected(pButton->isPressed());
    mButton45Ptr->setSelected(pButton->isPressed());
    pButton->setSelected(!pButton->isSelected());
	return false;
}

static bool onButtonClick_Button45(ZKButton *pButton) {

	std::string Leveling_high = StoragePreferences::getString("Leveling_high", "NULL");
	if(strcmp(Leveling_high.c_str(),"NULL")!=0){
		Hardware_serial_transmission("G91\r\nG1 Z");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\nG90\r\n");

		Hardware_serial_transmission(Levelinge);
		Hardware_serial_transmission("G91\r\nG1 Z-");
		Hardware_serial_transmission(Leveling_high);
		Hardware_serial_transmission(" F360\r\n");
	}
	else{

		Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
		Hardware_serial_transmission(Levelinge);
		Hardware_serial_transmission("G91\r\nG1 Z-5 F360\r\n");
	}
	Hardware_serial_transmission("G90\r\n");

    mButton40Ptr->setSelected(pButton->isPressed());
    mButton42Ptr->setSelected(pButton->isPressed());
    mButton43Ptr->setSelected(pButton->isPressed());
    mButton44Ptr->setSelected(pButton->isPressed());
    mButton45Ptr->setSelected(pButton->isPressed());
    pButton->setSelected(!pButton->isSelected());
	return false;
}
static bool onButtonClick_Button46(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button46 !!!\n");
    mAJPtr->showWnd();
       curprintcs = 4;

    return false;
}
static bool onButtonClick_Button47(ZKButton *pButton) {
   // LOGD(" ButtonClick Button47 !!!\n");
	Hardware_serial_transmission("G29\r\n");

    return false;
}
static bool onButtonClick_Button49(ZKButton *pButton) {
//    LOGD(" ButtonClick Button49 !!!\n");
	Hardware_serial_transmission("G91\r\nG1 Z5 F360\r\nG90\r\n");
	Hardware_serial_transmission("G30 S-1\r\n");
	mButton49Ptr->setText("-  -  -  -  -");
    return false;
}
static bool onButtonClick_Button51(ZKButton *pButton) {
	if (!pButton->isSelected()){
			 			Hardware_serial_transmission("M280 P0 S10\r\n");
			 			}
			 			else{
			 				Hardware_serial_transmission("M280 P0 S90\r\n");

			 			}
			 			pButton->setSelected(!pButton->isSelected());
    return false;
}
static bool onButtonClick_Button50(ZKButton *pButton) {
 //   LOGD(" ButtonClick Button50 !!!\n");

	 if (!pButton->isSelected()){
		  mTextView62Ptr->setVisible(true);
	 			 			}
	 else{
	 			 mTextView62Ptr->setVisible(false);

	 			 			}
	 pButton->setSelected(!pButton->isSelected());

    return false;
}
static bool onButtonClick_Message_Report_Close(ZKButton *pButton) {
  //  LOGD(" ButtonClick Message_Report_Close !!!\n");
    return false;
}
static bool onButtonClick_Move_XY(ZKButton *pButton) {
	 std::string xyspeedf = StoragePreferences::getString("XYspeed", "");//XY速度

    LayoutPosition Move_XY_button_pos = pButton->getPosition();
    LayoutPosition coordinate_pos = mcoordinatePtr->getPosition();

    //获取分辨率
	float Move_Resolution_X = X_Axis_maximum / (float)Move_XY_button_pos.mWidth;
	float Move_Resolution_Y = Y_Axis_maximum / (float)Move_XY_button_pos.mHeight;

	//获取移动像素点
    int pixel_x = Motion_Event_X - Move_XY_button_pos.mLeft;
    int pixel_y = Move_XY_button_pos.mHeight - (Motion_Event_Y-Move_XY_button_pos.mTop);


//LOGD("x最大值%d,%f:%d",X_Axis_maximum,Move_Resolution_X,pixel_x);

	char buf[30];
				sprintf(buf,"G1 X%0.2f Y%0.2f",Move_Resolution_X*pixel_x,Move_Resolution_Y*pixel_y);
			Hardware_serial_transmission("G90\r\n");
			Hardware_serial_transmission(buf);
			if(strcmp(xyspeedf.c_str(),"")!=0){
				Hardware_serial_transmission(" F");
 				Hardware_serial_transmission(xyspeedf);
 				Hardware_serial_transmission("\r\n");
 			}
 			else
			Hardware_serial_transmission(" F2500\r\n");

    LayoutPosition coordinate(Motion_Event_X-coordinate_pos.mWidth/2, Motion_Event_Y-coordinate_pos.mHeight, coordinate_pos.mWidth, coordinate_pos.mHeight);
    mcoordinatePtr->setPosition(coordinate);


//	LOGD(" X:%d,Y:%d\n",Motion_Event_X,Motion_Event_Y);
    return false;
}
static void onProgressChanged_X_axis_maximum(ZKSeekBar *pSeekBar, int progress) {
	StoragePreferences::putInt("X_axis_maximum", progress);
	X_Axis_maximum = progress;
	mX_ValuePtr->setText(progress);
}

static void onProgressChanged_Y_axis_maximum(ZKSeekBar *pSeekBar, int progress) {
	StoragePreferences::putInt("Y_axis_maximum", progress);
	Y_Axis_maximum = progress;
	mY_ValuePtr->setText(progress);
}
