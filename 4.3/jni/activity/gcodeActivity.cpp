/***********************************************
/gen auto by zuitools
***********************************************/
#include "gcodeActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mY_ValuePtr;
static ZKTextView* mX_ValuePtr;
static ZKSeekBar* mX_axis_maximumPtr;
static ZKSeekBar* mY_axis_maximumPtr;
static ZKTextView* mcoordinatePtr;
static ZKButton* mMove_XYPtr;
static ZKButton* mMessage_Report_ClosePtr;
static ZKTextView* mMessage_ReportPtr;
static ZKWindow* mhomePtr;
static ZKTextView* mTextView62Ptr;
static ZKButton* mButton50Ptr;
static ZKButton* mButton51Ptr;
static ZKTextView* mTextView61Ptr;
static ZKButton* mButton49Ptr;
static ZKButton* mButton47Ptr;
static ZKTextView* mTextView60Ptr;
static ZKButton* mButton46Ptr;
static ZKButton* mButton45Ptr;
static ZKButton* mButton44Ptr;
static ZKButton* mButton43Ptr;
static ZKButton* mButton42Ptr;
static ZKButton* mButton40Ptr;
static ZKTextView* mTextView59Ptr;
static ZKButton* mButton38Ptr;
static ZKButton* mButton37Ptr;
static ZKButton* mButton36Ptr;
static ZKWindow* mAnti_touchPtr;
static ZKTextView* mTextview38Ptr;
static ZKTextView* mTextview26Ptr;
static ZKTextView* mTextview21Ptr;
static ZKWindow* mczzxPtr;
static ZKTextView* mTextview50Ptr;
static ZKEditText* mEdittext3Ptr;
static ZKWindow* mlockPtr;
static ZKButton* mButton96Ptr;
static ZKTextView* mTextView22Ptr;
static ZKButton* mButton84Ptr;
static ZKButton* mButton85Ptr;
static ZKButton* mButton86Ptr;
static ZKButton* mButton87Ptr;
static ZKButton* mButton88Ptr;
static ZKButton* mButton89Ptr;
static ZKButton* mButton90Ptr;
static ZKButton* mButton91Ptr;
static ZKButton* mButton92Ptr;
static ZKButton* mButton93Ptr;
static ZKButton* mButton94Ptr;
static ZKButton* mButton95Ptr;
static ZKTextView* mTextView18Ptr;
static ZKWindow* mAJPtr;
static ZKButton* mButton168Ptr;
static ZKButton* mButton167Ptr;
static ZKButton* mButton166Ptr;
static ZKButton* mButton165Ptr;
static ZKButton* mButton164Ptr;
static ZKButton* mButton163Ptr;
static ZKButton* mButton162Ptr;
static ZKButton* mButton161Ptr;
static ZKButton* mButton160Ptr;
static ZKButton* mButton159Ptr;
static ZKButton* mButton158Ptr;
static ZKButton* mButton157Ptr;
static ZKButton* mButton156Ptr;
static ZKButton* mButton155Ptr;
static ZKButton* mButton154Ptr;
static ZKButton* mButton153Ptr;
static ZKButton* mButton152Ptr;
static ZKButton* mButton151Ptr;
static ZKButton* mButton150Ptr;
static ZKButton* mButton149Ptr;
static ZKButton* mButton148Ptr;
static ZKButton* mButton147Ptr;
static ZKButton* mButton146Ptr;
static ZKButton* mButton145Ptr;
static ZKButton* mButton144Ptr;
static ZKButton* mButton143Ptr;
static ZKButton* mButton142Ptr;
static ZKButton* mButton141Ptr;
static ZKButton* mButton140Ptr;
static ZKButton* mButton139Ptr;
static ZKButton* mButton138Ptr;
static ZKButton* mButton137Ptr;
static ZKButton* mButton136Ptr;
static ZKButton* mButton135Ptr;
static ZKButton* mButton134Ptr;
static ZKButton* mButton133Ptr;
static ZKButton* mButton132Ptr;
static ZKButton* mButton131Ptr;
static ZKButton* mButton130Ptr;
static ZKButton* mButton129Ptr;
static ZKButton* mButton127Ptr;
static ZKButton* mButton126Ptr;
static ZKButton* mButton125Ptr;
static ZKTextView* mTextView44Ptr;
static ZKTextView* mTextView46Ptr;
static ZKWindow* mAJ1Ptr;
static ZKButton* mButton12Ptr;
static ZKButton* mButton108Ptr;
static ZKButton* mButton107Ptr;
static ZKButton* mButton106Ptr;
static ZKTextView* mTextView43Ptr;
static ZKEditText* mEdittext4Ptr;
static ZKTextView* mTextview60Ptr;
static ZKTextView* mTextView56Ptr;
static ZKTextView* mTextView54Ptr;
static ZKQRCode* mQRCode1Ptr;
static ZKButton* mButton30Ptr;
static ZKTextView* mTextView14Ptr;
static ZKTextView* mTextView2Ptr;
static ZKButton* mButton31Ptr;
static ZKButton* mButton29Ptr;
static ZKListView* mmoretimePtr;
static ZKTextView* mTextview54Ptr;
static ZKTextView* mTextview51Ptr;
static ZKSeekBar* mSeekbar3Ptr;
static ZKButton* mButton19Ptr;
static ZKButton* mButton48Ptr;
static ZKEditText* mEdittext2Ptr;
static ZKTextView* mTextview53Ptr;
static ZKListView* msreccPtr;
static ZKWindow* mmorepmsetPtr;
static ZKListView* mListView2Ptr;
static ZKButton* mButton109Ptr;
static ZKTextView* mTextView45Ptr;
static ZKListView* mListView1Ptr;
static ZKWindow* mmorehmlPtr;
static ZKListView* mListView5Ptr;
static ZKListView* mListView4Ptr;
static ZKListView* mListView3Ptr;
static ZKWindow* mmoregjPtr;
static ZKButton* mButton17Ptr;
static ZKButton* mButton16Ptr;
static ZKButton* mButton15Ptr;
static ZKButton* mButton14Ptr;
static ZKButton* mButton13Ptr;
static ZKTextView* mTextView55Ptr;
static ZKEditText* mEditText2Ptr;
static ZKEditText* mEditText1Ptr;
static ZKWindow* mwifiPtr;
static ZKWindow* mmorePtr;
static ZKButton* mButton100Ptr;
static ZKButton* mButton99Ptr;
static ZKButton* mButton98Ptr;
static ZKButton* mButton97Ptr;
static ZKTextView* mTextView37Ptr;
static ZKButton* mButton128Ptr;
static ZKButton* mButton124Ptr;
static ZKButton* mButton123Ptr;
static ZKButton* mButton122Ptr;
static ZKButton* mButton121Ptr;
static ZKButton* mButton120Ptr;
static ZKButton* mButton119Ptr;
static ZKButton* mButton118Ptr;
static ZKButton* mButton117Ptr;
static ZKButton* mButton116Ptr;
static ZKButton* mButton115Ptr;
static ZKButton* mButton114Ptr;
static ZKButton* mButton113Ptr;
static ZKButton* mButton112Ptr;
static ZKButton* mButton111Ptr;
static ZKButton* mButton110Ptr;
static ZKWindow* mwhcsPtr;
static ZKButton* mButton18Ptr;
static ZKWindow* mwhtpPtr;
static ZKTextView* mTextView42Ptr;
static ZKTextView* mTextView41Ptr;
static ZKTextView* mTextView40Ptr;
static ZKButton* mButton105Ptr;
static ZKButton* mButton104Ptr;
static ZKTextView* mTextView39Ptr;
static ZKButton* mButton103Ptr;
static ZKButton* mButton102Ptr;
static ZKButton* mButton101Ptr;
static ZKButton* mButton59Ptr;
static ZKTextView* mTextview63Ptr;
static ZKButton* mButton39Ptr;
static ZKButton* mButton33Ptr;
static ZKButton* mButton32Ptr;
static ZKTextView* mTextView38Ptr;
static ZKWindow* mwhclPtr;
static ZKTextView* mTextView36Ptr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKSeekBar* mSeekBar4Ptr;
static ZKButton* mButton22Ptr;
static ZKButton* mButton21Ptr;
static ZKButton* mButton24Ptr;
static ZKButton* mButton25Ptr;
static ZKButton* mButton1Ptr;
static ZKButton* mButton20Ptr;
static ZKTextView* mTextView33Ptr;
static ZKTextView* mTextView32Ptr;
static ZKTextView* mTextView30Ptr;
static ZKListView* mListview1Ptr;
static ZKWindow* mwhmovePtr;
static ZKWindow* mWHPtr;
static ZKButton* mButton79Ptr;
static ZKTextView* mTextView58Ptr;
static ZKTextView* mTextView57Ptr;
static ZKButton* mButton35Ptr;
static ZKSeekBar* mSeekBar7Ptr;
static ZKButton* mButton34Ptr;
static ZKButton* mButton83Ptr;
static ZKButton* mButton82Ptr;
static ZKButton* mButton81Ptr;
static ZKButton* mButton80Ptr;
static ZKTextView* mTextView31Ptr;
static ZKTextView* mTextView29Ptr;
static ZKTextView* mTextView28Ptr;
static ZKTextView* mTextView27Ptr;
static ZKTextView* mTextView25Ptr;
static ZKTextView* mTextView24Ptr;
static ZKTextView* mTextView23Ptr;
static ZKTextView* mTextView21Ptr;
static ZKTextView* mTextView20Ptr;
static ZKTextView* mTextView19Ptr;
static ZKWindow* mprintcsPtr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView26Ptr;
static ZKTextView* mTextView17Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView130Ptr;
static ZKTextView* mTextView12Ptr;
static ZKButton* mButton78Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKSeekBar* mSeekbar4Ptr;
static ZKButton* mbtnBackPtr;
static ZKButton* mbtnPausePtr;
static ZKTextView* mTextView53Ptr;
static ZKWindow* mwinPrintPtr;
static ZKButton* mbtnPrintCancelPtr;
static ZKButton* mbtnPrintOKPtr;
static ZKTextView* mdfPtr;
static ZKWindow* mwinQueryPrintPtr;
static ZKButton* mButton11Ptr;
static ZKButton* mButton10Ptr;
static ZKButton* mButton9Ptr;
static ZKWindow* mfishPtr;
static ZKListView* mboardsdPtr;
static ZKListView* mLVFolderPtr;
static ZKWindow* mprintPtr;
static ZKButton* mButton75Ptr;
static ZKButton* mButton4Ptr;
static ZKTextView* mTextView52Ptr;
static ZKTextView* mTextView51Ptr;
static ZKTextView* mTextView50Ptr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mButton5Ptr;
static ZKTextView* mTextView49Ptr;
static ZKTextView* mTextView48Ptr;
static ZKWindow* mtemprcPtr;
static ZKDiagram* mtempbxPtr;
static ZKTextView* mTextView6Ptr;
static ZKButton* mButton77Ptr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView8Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton76Ptr;
static ZKButton* mButton2Ptr;
static ZKButton* mButton180Ptr;
static ZKTextView* mTextView47Ptr;
static ZKTextView* mTextView5Ptr;
static ZKButton* mButton178Ptr;
static ZKButton* mButton179Ptr;
static ZKTextView* mTextView4Ptr;
static ZKWindow* mtempptPtr;
static ZKWindow* mtempPtr;
static ZKSeekBar* mSeekBar3Ptr;
static ZKSeekBar* mSeekBar2Ptr;
static ZKSeekBar* mSeekBar1Ptr;
static ZKButton* mButton41Ptr;
static ZKTextView* mTextview37Ptr;
static ZKTextView* mTextview36Ptr;
static ZKTextView* mTextview34Ptr;
static ZKButton* mButton28Ptr;
static ZKButton* mButton27Ptr;
static ZKButton* mButton26Ptr;
static ZKTextView* mTextView1Ptr;
static ZKButton* mButton23Ptr;
static ZKButton* mButton70Ptr;
static ZKButton* mButton71Ptr;
static ZKButton* mButton72Ptr;
static ZKButton* mButton73Ptr;
static ZKButton* mButton74Ptr;
static ZKTextView* mTextView3Ptr;
static gcodeActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(gcodeActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/gcodeLogic.cc"

/***********/
typedef struct {
    int id;
    const char *pApp;
} SAppInfo;

/**
 *点击跳转window
 */
static SAppInfo sAppInfoTab[] = {
//  { ID_MAIN_TEXT, "TextViewActivity" },
};

/***************/
typedef bool (*ButtonCallback)(ZKButton *pButton);
/**
 * button onclick表
 */
typedef struct {
    int id;
    ButtonCallback callback;
}S_ButtonCallback;

/*TAG:ButtonCallbackTab按键映射表*/
static S_ButtonCallback sButtonCallbackTab[] = {
    ID_GCODE_Move_XY, onButtonClick_Move_XY,
    ID_GCODE_Message_Report_Close, onButtonClick_Message_Report_Close,
    ID_GCODE_Button50, onButtonClick_Button50,
    ID_GCODE_Button51, onButtonClick_Button51,
    ID_GCODE_Button49, onButtonClick_Button49,
    ID_GCODE_Button47, onButtonClick_Button47,
    ID_GCODE_Button46, onButtonClick_Button46,
    ID_GCODE_Button45, onButtonClick_Button45,
    ID_GCODE_Button44, onButtonClick_Button44,
    ID_GCODE_Button43, onButtonClick_Button43,
    ID_GCODE_Button42, onButtonClick_Button42,
    ID_GCODE_Button40, onButtonClick_Button40,
    ID_GCODE_Button38, onButtonClick_Button38,
    ID_GCODE_Button37, onButtonClick_Button37,
    ID_GCODE_Button36, onButtonClick_Button36,
    ID_GCODE_Button96, onButtonClick_Button96,
    ID_GCODE_Button84, onButtonClick_Button84,
    ID_GCODE_Button85, onButtonClick_Button85,
    ID_GCODE_Button86, onButtonClick_Button86,
    ID_GCODE_Button87, onButtonClick_Button87,
    ID_GCODE_Button88, onButtonClick_Button88,
    ID_GCODE_Button89, onButtonClick_Button89,
    ID_GCODE_Button90, onButtonClick_Button90,
    ID_GCODE_Button91, onButtonClick_Button91,
    ID_GCODE_Button92, onButtonClick_Button92,
    ID_GCODE_Button93, onButtonClick_Button93,
    ID_GCODE_Button94, onButtonClick_Button94,
    ID_GCODE_Button95, onButtonClick_Button95,
    ID_GCODE_Button168, onButtonClick_Button168,
    ID_GCODE_Button167, onButtonClick_Button167,
    ID_GCODE_Button166, onButtonClick_Button166,
    ID_GCODE_Button165, onButtonClick_Button165,
    ID_GCODE_Button164, onButtonClick_Button164,
    ID_GCODE_Button163, onButtonClick_Button163,
    ID_GCODE_Button162, onButtonClick_Button162,
    ID_GCODE_Button161, onButtonClick_Button161,
    ID_GCODE_Button160, onButtonClick_Button160,
    ID_GCODE_Button159, onButtonClick_Button159,
    ID_GCODE_Button158, onButtonClick_Button158,
    ID_GCODE_Button157, onButtonClick_Button157,
    ID_GCODE_Button156, onButtonClick_Button156,
    ID_GCODE_Button155, onButtonClick_Button155,
    ID_GCODE_Button154, onButtonClick_Button154,
    ID_GCODE_Button153, onButtonClick_Button153,
    ID_GCODE_Button152, onButtonClick_Button152,
    ID_GCODE_Button151, onButtonClick_Button151,
    ID_GCODE_Button150, onButtonClick_Button150,
    ID_GCODE_Button149, onButtonClick_Button149,
    ID_GCODE_Button148, onButtonClick_Button148,
    ID_GCODE_Button147, onButtonClick_Button147,
    ID_GCODE_Button146, onButtonClick_Button146,
    ID_GCODE_Button145, onButtonClick_Button145,
    ID_GCODE_Button144, onButtonClick_Button144,
    ID_GCODE_Button143, onButtonClick_Button143,
    ID_GCODE_Button142, onButtonClick_Button142,
    ID_GCODE_Button141, onButtonClick_Button141,
    ID_GCODE_Button140, onButtonClick_Button140,
    ID_GCODE_Button139, onButtonClick_Button139,
    ID_GCODE_Button138, onButtonClick_Button138,
    ID_GCODE_Button137, onButtonClick_Button137,
    ID_GCODE_Button136, onButtonClick_Button136,
    ID_GCODE_Button135, onButtonClick_Button135,
    ID_GCODE_Button134, onButtonClick_Button134,
    ID_GCODE_Button133, onButtonClick_Button133,
    ID_GCODE_Button132, onButtonClick_Button132,
    ID_GCODE_Button131, onButtonClick_Button131,
    ID_GCODE_Button130, onButtonClick_Button130,
    ID_GCODE_Button129, onButtonClick_Button129,
    ID_GCODE_Button127, onButtonClick_Button127,
    ID_GCODE_Button126, onButtonClick_Button126,
    ID_GCODE_Button125, onButtonClick_Button125,
    ID_GCODE_Button12, onButtonClick_Button12,
    ID_GCODE_Button108, onButtonClick_Button108,
    ID_GCODE_Button107, onButtonClick_Button107,
    ID_GCODE_Button106, onButtonClick_Button106,
    ID_GCODE_Button30, onButtonClick_Button30,
    ID_GCODE_Button31, onButtonClick_Button31,
    ID_GCODE_Button29, onButtonClick_Button29,
    ID_GCODE_Button19, onButtonClick_Button19,
    ID_GCODE_Button48, onButtonClick_Button48,
    ID_GCODE_Button109, onButtonClick_Button109,
    ID_GCODE_Button17, onButtonClick_Button17,
    ID_GCODE_Button16, onButtonClick_Button16,
    ID_GCODE_Button15, onButtonClick_Button15,
    ID_GCODE_Button14, onButtonClick_Button14,
    ID_GCODE_Button13, onButtonClick_Button13,
    ID_GCODE_Button100, onButtonClick_Button100,
    ID_GCODE_Button99, onButtonClick_Button99,
    ID_GCODE_Button98, onButtonClick_Button98,
    ID_GCODE_Button97, onButtonClick_Button97,
    ID_GCODE_Button128, onButtonClick_Button128,
    ID_GCODE_Button124, onButtonClick_Button124,
    ID_GCODE_Button123, onButtonClick_Button123,
    ID_GCODE_Button122, onButtonClick_Button122,
    ID_GCODE_Button121, onButtonClick_Button121,
    ID_GCODE_Button120, onButtonClick_Button120,
    ID_GCODE_Button119, onButtonClick_Button119,
    ID_GCODE_Button118, onButtonClick_Button118,
    ID_GCODE_Button117, onButtonClick_Button117,
    ID_GCODE_Button116, onButtonClick_Button116,
    ID_GCODE_Button115, onButtonClick_Button115,
    ID_GCODE_Button114, onButtonClick_Button114,
    ID_GCODE_Button113, onButtonClick_Button113,
    ID_GCODE_Button112, onButtonClick_Button112,
    ID_GCODE_Button111, onButtonClick_Button111,
    ID_GCODE_Button110, onButtonClick_Button110,
    ID_GCODE_Button18, onButtonClick_Button18,
    ID_GCODE_Button105, onButtonClick_Button105,
    ID_GCODE_Button104, onButtonClick_Button104,
    ID_GCODE_Button103, onButtonClick_Button103,
    ID_GCODE_Button102, onButtonClick_Button102,
    ID_GCODE_Button101, onButtonClick_Button101,
    ID_GCODE_Button59, onButtonClick_Button59,
    ID_GCODE_Button39, onButtonClick_Button39,
    ID_GCODE_Button33, onButtonClick_Button33,
    ID_GCODE_Button32, onButtonClick_Button32,
    ID_GCODE_Button22, onButtonClick_Button22,
    ID_GCODE_Button21, onButtonClick_Button21,
    ID_GCODE_Button24, onButtonClick_Button24,
    ID_GCODE_Button25, onButtonClick_Button25,
    ID_GCODE_Button1, onButtonClick_Button1,
    ID_GCODE_Button20, onButtonClick_Button20,
    ID_GCODE_Button79, onButtonClick_Button79,
    ID_GCODE_Button35, onButtonClick_Button35,
    ID_GCODE_Button34, onButtonClick_Button34,
    ID_GCODE_Button83, onButtonClick_Button83,
    ID_GCODE_Button82, onButtonClick_Button82,
    ID_GCODE_Button81, onButtonClick_Button81,
    ID_GCODE_Button80, onButtonClick_Button80,
    ID_GCODE_Button78, onButtonClick_Button78,
    ID_GCODE_btnBack, onButtonClick_btnBack,
    ID_GCODE_btnPause, onButtonClick_btnPause,
    ID_GCODE_btnPrintCancel, onButtonClick_btnPrintCancel,
    ID_GCODE_btnPrintOK, onButtonClick_btnPrintOK,
    ID_GCODE_Button11, onButtonClick_Button11,
    ID_GCODE_Button10, onButtonClick_Button10,
    ID_GCODE_Button9, onButtonClick_Button9,
    ID_GCODE_Button75, onButtonClick_Button75,
    ID_GCODE_Button4, onButtonClick_Button4,
    ID_GCODE_Button8, onButtonClick_Button8,
    ID_GCODE_Button7, onButtonClick_Button7,
    ID_GCODE_Button6, onButtonClick_Button6,
    ID_GCODE_Button5, onButtonClick_Button5,
    ID_GCODE_Button77, onButtonClick_Button77,
    ID_GCODE_Button3, onButtonClick_Button3,
    ID_GCODE_Button76, onButtonClick_Button76,
    ID_GCODE_Button2, onButtonClick_Button2,
    ID_GCODE_Button180, onButtonClick_Button180,
    ID_GCODE_Button178, onButtonClick_Button178,
    ID_GCODE_Button179, onButtonClick_Button179,
    ID_GCODE_Button41, onButtonClick_Button41,
    ID_GCODE_Button28, onButtonClick_Button28,
    ID_GCODE_Button27, onButtonClick_Button27,
    ID_GCODE_Button26, onButtonClick_Button26,
    ID_GCODE_Button23, onButtonClick_Button23,
    ID_GCODE_Button70, onButtonClick_Button70,
    ID_GCODE_Button71, onButtonClick_Button71,
    ID_GCODE_Button72, onButtonClick_Button72,
    ID_GCODE_Button73, onButtonClick_Button73,
    ID_GCODE_Button74, onButtonClick_Button74,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
    ID_GCODE_X_axis_maximum, onProgressChanged_X_axis_maximum,
    ID_GCODE_Y_axis_maximum, onProgressChanged_Y_axis_maximum,
    ID_GCODE_Seekbar3, onProgressChanged_Seekbar3,
    ID_GCODE_SeekBar4, onProgressChanged_SeekBar4,
    ID_GCODE_SeekBar7, onProgressChanged_SeekBar7,
    ID_GCODE_Seekbar4, onProgressChanged_Seekbar4,
    ID_GCODE_SeekBar3, onProgressChanged_SeekBar3,
    ID_GCODE_SeekBar2, onProgressChanged_SeekBar2,
    ID_GCODE_SeekBar1, onProgressChanged_SeekBar1,
};


typedef int (*ListViewGetItemCountCallback)(const ZKListView *pListView);
typedef void (*ListViewobtainListItemDataCallback)(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index);
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView, int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
    ID_GCODE_moretime, getListItemCount_moretime, obtainListItemData_moretime, onListItemClick_moretime,
    ID_GCODE_srecc, getListItemCount_srecc, obtainListItemData_srecc, onListItemClick_srecc,
    ID_GCODE_ListView2, getListItemCount_ListView2, obtainListItemData_ListView2, onListItemClick_ListView2,
    ID_GCODE_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
    ID_GCODE_ListView5, getListItemCount_ListView5, obtainListItemData_ListView5, onListItemClick_ListView5,
    ID_GCODE_ListView4, getListItemCount_ListView4, obtainListItemData_ListView4, onListItemClick_ListView4,
    ID_GCODE_ListView3, getListItemCount_ListView3, obtainListItemData_ListView3, onListItemClick_ListView3,
    ID_GCODE_Listview1, getListItemCount_Listview1, obtainListItemData_Listview1, onListItemClick_Listview1,
    ID_GCODE_boardsd, getListItemCount_boardsd, obtainListItemData_boardsd, onListItemClick_boardsd,
    ID_GCODE_LVFolder, getListItemCount_LVFolder, obtainListItemData_LVFolder, onListItemClick_LVFolder,
};


typedef void (*SlideWindowItemClickCallback)(ZKSlideWindow *pSlideWindow, int index);
typedef struct {
    int id;
    SlideWindowItemClickCallback onSlideItemClickCallback;
}S_SlideWindowItemClickCallback;
/*TAG:SlideWindowFunctionsCallbackTab*/
static S_SlideWindowItemClickCallback SSlideWindowItemClickCallbackTab[] = {
};


typedef void (*EditTextInputCallback)(const std::string &text);
typedef struct {
    int id;
    EditTextInputCallback onEditTextChangedCallback;
}S_EditTextInputCallback;
/*TAG:EditTextInputCallback*/
static S_EditTextInputCallback SEditTextInputCallbackTab[] = {
    ID_GCODE_Edittext3, onEditTextChanged_Edittext3,
    ID_GCODE_Edittext4, onEditTextChanged_Edittext4,
    ID_GCODE_Edittext2, onEditTextChanged_Edittext2,
    ID_GCODE_EditText2, onEditTextChanged_EditText2,
    ID_GCODE_EditText1, onEditTextChanged_EditText1,
};

typedef void (*VideoViewCallback)(ZKVideoView *pVideoView, int msg);
typedef struct {
    int id; //VideoView ID
    bool loop; // 是否是轮播类型
    int defaultvolume;//轮播类型时,默认视频音量
    VideoViewCallback onVideoViewCallback;
}S_VideoViewCallback;
/*TAG:VideoViewCallback*/
static S_VideoViewCallback SVideoViewCallbackTab[] = {
};


gcodeActivity::gcodeActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

gcodeActivity::~gcodeActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* gcodeActivity::getAppName() const{
	return "gcode.ftu";
}

//TAG:onCreate
void gcodeActivity::onCreate() {
	Activity::onCreate();
    mY_ValuePtr = (ZKTextView*)findControlByID(ID_GCODE_Y_Value);
    mX_ValuePtr = (ZKTextView*)findControlByID(ID_GCODE_X_Value);
    mX_axis_maximumPtr = (ZKSeekBar*)findControlByID(ID_GCODE_X_axis_maximum);if(mX_axis_maximumPtr!= NULL){mX_axis_maximumPtr->setSeekBarChangeListener(this);}
    mY_axis_maximumPtr = (ZKSeekBar*)findControlByID(ID_GCODE_Y_axis_maximum);if(mY_axis_maximumPtr!= NULL){mY_axis_maximumPtr->setSeekBarChangeListener(this);}
    mcoordinatePtr = (ZKTextView*)findControlByID(ID_GCODE_coordinate);
    mMove_XYPtr = (ZKButton*)findControlByID(ID_GCODE_Move_XY);
    mMessage_Report_ClosePtr = (ZKButton*)findControlByID(ID_GCODE_Message_Report_Close);
    mMessage_ReportPtr = (ZKTextView*)findControlByID(ID_GCODE_Message_Report);
    mhomePtr = (ZKWindow*)findControlByID(ID_GCODE_home);
    mTextView62Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView62);
    mButton50Ptr = (ZKButton*)findControlByID(ID_GCODE_Button50);
    mButton51Ptr = (ZKButton*)findControlByID(ID_GCODE_Button51);
    mTextView61Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView61);
    mButton49Ptr = (ZKButton*)findControlByID(ID_GCODE_Button49);
    mButton47Ptr = (ZKButton*)findControlByID(ID_GCODE_Button47);
    mTextView60Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView60);
    mButton46Ptr = (ZKButton*)findControlByID(ID_GCODE_Button46);
    mButton45Ptr = (ZKButton*)findControlByID(ID_GCODE_Button45);
    mButton44Ptr = (ZKButton*)findControlByID(ID_GCODE_Button44);
    mButton43Ptr = (ZKButton*)findControlByID(ID_GCODE_Button43);
    mButton42Ptr = (ZKButton*)findControlByID(ID_GCODE_Button42);
    mButton40Ptr = (ZKButton*)findControlByID(ID_GCODE_Button40);
    mTextView59Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView59);
    mButton38Ptr = (ZKButton*)findControlByID(ID_GCODE_Button38);
    mButton37Ptr = (ZKButton*)findControlByID(ID_GCODE_Button37);
    mButton36Ptr = (ZKButton*)findControlByID(ID_GCODE_Button36);
    mAnti_touchPtr = (ZKWindow*)findControlByID(ID_GCODE_Anti_touch);
    mTextview38Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview38);
    mTextview26Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview26);
    mTextview21Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview21);
    mczzxPtr = (ZKWindow*)findControlByID(ID_GCODE_czzx);
    mTextview50Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview50);
    mEdittext3Ptr = (ZKEditText*)findControlByID(ID_GCODE_Edittext3);if(mEdittext3Ptr!= NULL){mEdittext3Ptr->setTextChangeListener(this);}
    mlockPtr = (ZKWindow*)findControlByID(ID_GCODE_lock);
    mButton96Ptr = (ZKButton*)findControlByID(ID_GCODE_Button96);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView22);
    mButton84Ptr = (ZKButton*)findControlByID(ID_GCODE_Button84);
    mButton85Ptr = (ZKButton*)findControlByID(ID_GCODE_Button85);
    mButton86Ptr = (ZKButton*)findControlByID(ID_GCODE_Button86);
    mButton87Ptr = (ZKButton*)findControlByID(ID_GCODE_Button87);
    mButton88Ptr = (ZKButton*)findControlByID(ID_GCODE_Button88);
    mButton89Ptr = (ZKButton*)findControlByID(ID_GCODE_Button89);
    mButton90Ptr = (ZKButton*)findControlByID(ID_GCODE_Button90);
    mButton91Ptr = (ZKButton*)findControlByID(ID_GCODE_Button91);
    mButton92Ptr = (ZKButton*)findControlByID(ID_GCODE_Button92);
    mButton93Ptr = (ZKButton*)findControlByID(ID_GCODE_Button93);
    mButton94Ptr = (ZKButton*)findControlByID(ID_GCODE_Button94);
    mButton95Ptr = (ZKButton*)findControlByID(ID_GCODE_Button95);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView18);
    mAJPtr = (ZKWindow*)findControlByID(ID_GCODE_AJ);
    mButton168Ptr = (ZKButton*)findControlByID(ID_GCODE_Button168);
    mButton167Ptr = (ZKButton*)findControlByID(ID_GCODE_Button167);
    mButton166Ptr = (ZKButton*)findControlByID(ID_GCODE_Button166);
    mButton165Ptr = (ZKButton*)findControlByID(ID_GCODE_Button165);
    mButton164Ptr = (ZKButton*)findControlByID(ID_GCODE_Button164);
    mButton163Ptr = (ZKButton*)findControlByID(ID_GCODE_Button163);
    mButton162Ptr = (ZKButton*)findControlByID(ID_GCODE_Button162);
    mButton161Ptr = (ZKButton*)findControlByID(ID_GCODE_Button161);
    mButton160Ptr = (ZKButton*)findControlByID(ID_GCODE_Button160);
    mButton159Ptr = (ZKButton*)findControlByID(ID_GCODE_Button159);
    mButton158Ptr = (ZKButton*)findControlByID(ID_GCODE_Button158);
    mButton157Ptr = (ZKButton*)findControlByID(ID_GCODE_Button157);
    mButton156Ptr = (ZKButton*)findControlByID(ID_GCODE_Button156);
    mButton155Ptr = (ZKButton*)findControlByID(ID_GCODE_Button155);
    mButton154Ptr = (ZKButton*)findControlByID(ID_GCODE_Button154);
    mButton153Ptr = (ZKButton*)findControlByID(ID_GCODE_Button153);
    mButton152Ptr = (ZKButton*)findControlByID(ID_GCODE_Button152);
    mButton151Ptr = (ZKButton*)findControlByID(ID_GCODE_Button151);
    mButton150Ptr = (ZKButton*)findControlByID(ID_GCODE_Button150);
    mButton149Ptr = (ZKButton*)findControlByID(ID_GCODE_Button149);
    mButton148Ptr = (ZKButton*)findControlByID(ID_GCODE_Button148);
    mButton147Ptr = (ZKButton*)findControlByID(ID_GCODE_Button147);
    mButton146Ptr = (ZKButton*)findControlByID(ID_GCODE_Button146);
    mButton145Ptr = (ZKButton*)findControlByID(ID_GCODE_Button145);
    mButton144Ptr = (ZKButton*)findControlByID(ID_GCODE_Button144);
    mButton143Ptr = (ZKButton*)findControlByID(ID_GCODE_Button143);
    mButton142Ptr = (ZKButton*)findControlByID(ID_GCODE_Button142);
    mButton141Ptr = (ZKButton*)findControlByID(ID_GCODE_Button141);
    mButton140Ptr = (ZKButton*)findControlByID(ID_GCODE_Button140);
    mButton139Ptr = (ZKButton*)findControlByID(ID_GCODE_Button139);
    mButton138Ptr = (ZKButton*)findControlByID(ID_GCODE_Button138);
    mButton137Ptr = (ZKButton*)findControlByID(ID_GCODE_Button137);
    mButton136Ptr = (ZKButton*)findControlByID(ID_GCODE_Button136);
    mButton135Ptr = (ZKButton*)findControlByID(ID_GCODE_Button135);
    mButton134Ptr = (ZKButton*)findControlByID(ID_GCODE_Button134);
    mButton133Ptr = (ZKButton*)findControlByID(ID_GCODE_Button133);
    mButton132Ptr = (ZKButton*)findControlByID(ID_GCODE_Button132);
    mButton131Ptr = (ZKButton*)findControlByID(ID_GCODE_Button131);
    mButton130Ptr = (ZKButton*)findControlByID(ID_GCODE_Button130);
    mButton129Ptr = (ZKButton*)findControlByID(ID_GCODE_Button129);
    mButton127Ptr = (ZKButton*)findControlByID(ID_GCODE_Button127);
    mButton126Ptr = (ZKButton*)findControlByID(ID_GCODE_Button126);
    mButton125Ptr = (ZKButton*)findControlByID(ID_GCODE_Button125);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView44);
    mTextView46Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView46);
    mAJ1Ptr = (ZKWindow*)findControlByID(ID_GCODE_AJ1);
    mButton12Ptr = (ZKButton*)findControlByID(ID_GCODE_Button12);
    mButton108Ptr = (ZKButton*)findControlByID(ID_GCODE_Button108);
    mButton107Ptr = (ZKButton*)findControlByID(ID_GCODE_Button107);
    mButton106Ptr = (ZKButton*)findControlByID(ID_GCODE_Button106);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView43);
    mEdittext4Ptr = (ZKEditText*)findControlByID(ID_GCODE_Edittext4);if(mEdittext4Ptr!= NULL){mEdittext4Ptr->setTextChangeListener(this);}
    mTextview60Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview60);
    mTextView56Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView56);
    mTextView54Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView54);
    mQRCode1Ptr = (ZKQRCode*)findControlByID(ID_GCODE_QRCode1);
    mButton30Ptr = (ZKButton*)findControlByID(ID_GCODE_Button30);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView14);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView2);
    mButton31Ptr = (ZKButton*)findControlByID(ID_GCODE_Button31);
    mButton29Ptr = (ZKButton*)findControlByID(ID_GCODE_Button29);
    mmoretimePtr = (ZKListView*)findControlByID(ID_GCODE_moretime);if(mmoretimePtr!= NULL){mmoretimePtr->setListAdapter(this);mmoretimePtr->setItemClickListener(this);}
    mTextview54Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview54);
    mTextview51Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview51);
    mSeekbar3Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_Seekbar3);if(mSeekbar3Ptr!= NULL){mSeekbar3Ptr->setSeekBarChangeListener(this);}
    mButton19Ptr = (ZKButton*)findControlByID(ID_GCODE_Button19);
    mButton48Ptr = (ZKButton*)findControlByID(ID_GCODE_Button48);
    mEdittext2Ptr = (ZKEditText*)findControlByID(ID_GCODE_Edittext2);if(mEdittext2Ptr!= NULL){mEdittext2Ptr->setTextChangeListener(this);}
    mTextview53Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview53);
    msreccPtr = (ZKListView*)findControlByID(ID_GCODE_srecc);if(msreccPtr!= NULL){msreccPtr->setListAdapter(this);msreccPtr->setItemClickListener(this);}
    mmorepmsetPtr = (ZKWindow*)findControlByID(ID_GCODE_morepmset);
    mListView2Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView2);if(mListView2Ptr!= NULL){mListView2Ptr->setListAdapter(this);mListView2Ptr->setItemClickListener(this);}
    mButton109Ptr = (ZKButton*)findControlByID(ID_GCODE_Button109);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView45);
    mListView1Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mmorehmlPtr = (ZKWindow*)findControlByID(ID_GCODE_morehml);
    mListView5Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView5);if(mListView5Ptr!= NULL){mListView5Ptr->setListAdapter(this);mListView5Ptr->setItemClickListener(this);}
    mListView4Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView4);if(mListView4Ptr!= NULL){mListView4Ptr->setListAdapter(this);mListView4Ptr->setItemClickListener(this);}
    mListView3Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView3);if(mListView3Ptr!= NULL){mListView3Ptr->setListAdapter(this);mListView3Ptr->setItemClickListener(this);}
    mmoregjPtr = (ZKWindow*)findControlByID(ID_GCODE_moregj);
    mButton17Ptr = (ZKButton*)findControlByID(ID_GCODE_Button17);
    mButton16Ptr = (ZKButton*)findControlByID(ID_GCODE_Button16);
    mButton15Ptr = (ZKButton*)findControlByID(ID_GCODE_Button15);
    mButton14Ptr = (ZKButton*)findControlByID(ID_GCODE_Button14);
    mButton13Ptr = (ZKButton*)findControlByID(ID_GCODE_Button13);
    mTextView55Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView55);
    mEditText2Ptr = (ZKEditText*)findControlByID(ID_GCODE_EditText2);if(mEditText2Ptr!= NULL){mEditText2Ptr->setTextChangeListener(this);}
    mEditText1Ptr = (ZKEditText*)findControlByID(ID_GCODE_EditText1);if(mEditText1Ptr!= NULL){mEditText1Ptr->setTextChangeListener(this);}
    mwifiPtr = (ZKWindow*)findControlByID(ID_GCODE_wifi);
    mmorePtr = (ZKWindow*)findControlByID(ID_GCODE_more);
    mButton100Ptr = (ZKButton*)findControlByID(ID_GCODE_Button100);
    mButton99Ptr = (ZKButton*)findControlByID(ID_GCODE_Button99);
    mButton98Ptr = (ZKButton*)findControlByID(ID_GCODE_Button98);
    mButton97Ptr = (ZKButton*)findControlByID(ID_GCODE_Button97);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView37);
    mButton128Ptr = (ZKButton*)findControlByID(ID_GCODE_Button128);
    mButton124Ptr = (ZKButton*)findControlByID(ID_GCODE_Button124);
    mButton123Ptr = (ZKButton*)findControlByID(ID_GCODE_Button123);
    mButton122Ptr = (ZKButton*)findControlByID(ID_GCODE_Button122);
    mButton121Ptr = (ZKButton*)findControlByID(ID_GCODE_Button121);
    mButton120Ptr = (ZKButton*)findControlByID(ID_GCODE_Button120);
    mButton119Ptr = (ZKButton*)findControlByID(ID_GCODE_Button119);
    mButton118Ptr = (ZKButton*)findControlByID(ID_GCODE_Button118);
    mButton117Ptr = (ZKButton*)findControlByID(ID_GCODE_Button117);
    mButton116Ptr = (ZKButton*)findControlByID(ID_GCODE_Button116);
    mButton115Ptr = (ZKButton*)findControlByID(ID_GCODE_Button115);
    mButton114Ptr = (ZKButton*)findControlByID(ID_GCODE_Button114);
    mButton113Ptr = (ZKButton*)findControlByID(ID_GCODE_Button113);
    mButton112Ptr = (ZKButton*)findControlByID(ID_GCODE_Button112);
    mButton111Ptr = (ZKButton*)findControlByID(ID_GCODE_Button111);
    mButton110Ptr = (ZKButton*)findControlByID(ID_GCODE_Button110);
    mwhcsPtr = (ZKWindow*)findControlByID(ID_GCODE_whcs);
    mButton18Ptr = (ZKButton*)findControlByID(ID_GCODE_Button18);
    mwhtpPtr = (ZKWindow*)findControlByID(ID_GCODE_whtp);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView42);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView41);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView40);
    mButton105Ptr = (ZKButton*)findControlByID(ID_GCODE_Button105);
    mButton104Ptr = (ZKButton*)findControlByID(ID_GCODE_Button104);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView39);
    mButton103Ptr = (ZKButton*)findControlByID(ID_GCODE_Button103);
    mButton102Ptr = (ZKButton*)findControlByID(ID_GCODE_Button102);
    mButton101Ptr = (ZKButton*)findControlByID(ID_GCODE_Button101);
    mButton59Ptr = (ZKButton*)findControlByID(ID_GCODE_Button59);
    mTextview63Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview63);
    mButton39Ptr = (ZKButton*)findControlByID(ID_GCODE_Button39);
    mButton33Ptr = (ZKButton*)findControlByID(ID_GCODE_Button33);
    mButton32Ptr = (ZKButton*)findControlByID(ID_GCODE_Button32);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView38);
    mwhclPtr = (ZKWindow*)findControlByID(ID_GCODE_whcl);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView36);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView34);
    mSeekBar4Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_SeekBar4);if(mSeekBar4Ptr!= NULL){mSeekBar4Ptr->setSeekBarChangeListener(this);}
    mButton22Ptr = (ZKButton*)findControlByID(ID_GCODE_Button22);
    mButton21Ptr = (ZKButton*)findControlByID(ID_GCODE_Button21);
    mButton24Ptr = (ZKButton*)findControlByID(ID_GCODE_Button24);
    mButton25Ptr = (ZKButton*)findControlByID(ID_GCODE_Button25);
    mButton1Ptr = (ZKButton*)findControlByID(ID_GCODE_Button1);
    mButton20Ptr = (ZKButton*)findControlByID(ID_GCODE_Button20);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView32);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView30);
    mListview1Ptr = (ZKListView*)findControlByID(ID_GCODE_Listview1);if(mListview1Ptr!= NULL){mListview1Ptr->setListAdapter(this);mListview1Ptr->setItemClickListener(this);}
    mwhmovePtr = (ZKWindow*)findControlByID(ID_GCODE_whmove);
    mWHPtr = (ZKWindow*)findControlByID(ID_GCODE_WH);
    mButton79Ptr = (ZKButton*)findControlByID(ID_GCODE_Button79);
    mTextView58Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView58);
    mTextView57Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView57);
    mButton35Ptr = (ZKButton*)findControlByID(ID_GCODE_Button35);
    mSeekBar7Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_SeekBar7);if(mSeekBar7Ptr!= NULL){mSeekBar7Ptr->setSeekBarChangeListener(this);}
    mButton34Ptr = (ZKButton*)findControlByID(ID_GCODE_Button34);
    mButton83Ptr = (ZKButton*)findControlByID(ID_GCODE_Button83);
    mButton82Ptr = (ZKButton*)findControlByID(ID_GCODE_Button82);
    mButton81Ptr = (ZKButton*)findControlByID(ID_GCODE_Button81);
    mButton80Ptr = (ZKButton*)findControlByID(ID_GCODE_Button80);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView31);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView29);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView28);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView27);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView25);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView24);
    mTextView23Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView23);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView21);
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView20);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView19);
    mprintcsPtr = (ZKWindow*)findControlByID(ID_GCODE_printcs);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView9);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView26);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView17);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView15);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView13);
    mTextView130Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView130);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView12);
    mButton78Ptr = (ZKButton*)findControlByID(ID_GCODE_Button78);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView10);
    mSeekbar4Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_Seekbar4);if(mSeekbar4Ptr!= NULL){mSeekbar4Ptr->setSeekBarChangeListener(this);}
    mbtnBackPtr = (ZKButton*)findControlByID(ID_GCODE_btnBack);
    mbtnPausePtr = (ZKButton*)findControlByID(ID_GCODE_btnPause);
    mTextView53Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView53);
    mwinPrintPtr = (ZKWindow*)findControlByID(ID_GCODE_winPrint);
    mbtnPrintCancelPtr = (ZKButton*)findControlByID(ID_GCODE_btnPrintCancel);
    mbtnPrintOKPtr = (ZKButton*)findControlByID(ID_GCODE_btnPrintOK);
    mdfPtr = (ZKTextView*)findControlByID(ID_GCODE_df);
    mwinQueryPrintPtr = (ZKWindow*)findControlByID(ID_GCODE_winQueryPrint);
    mButton11Ptr = (ZKButton*)findControlByID(ID_GCODE_Button11);
    mButton10Ptr = (ZKButton*)findControlByID(ID_GCODE_Button10);
    mButton9Ptr = (ZKButton*)findControlByID(ID_GCODE_Button9);
    mfishPtr = (ZKWindow*)findControlByID(ID_GCODE_fish);
    mboardsdPtr = (ZKListView*)findControlByID(ID_GCODE_boardsd);if(mboardsdPtr!= NULL){mboardsdPtr->setListAdapter(this);mboardsdPtr->setItemClickListener(this);}
    mLVFolderPtr = (ZKListView*)findControlByID(ID_GCODE_LVFolder);if(mLVFolderPtr!= NULL){mLVFolderPtr->setListAdapter(this);mLVFolderPtr->setItemClickListener(this);}
    mprintPtr = (ZKWindow*)findControlByID(ID_GCODE_print);
    mButton75Ptr = (ZKButton*)findControlByID(ID_GCODE_Button75);
    mButton4Ptr = (ZKButton*)findControlByID(ID_GCODE_Button4);
    mTextView52Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView52);
    mTextView51Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView51);
    mTextView50Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView50);
    mButton8Ptr = (ZKButton*)findControlByID(ID_GCODE_Button8);
    mButton7Ptr = (ZKButton*)findControlByID(ID_GCODE_Button7);
    mButton6Ptr = (ZKButton*)findControlByID(ID_GCODE_Button6);
    mButton5Ptr = (ZKButton*)findControlByID(ID_GCODE_Button5);
    mTextView49Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView49);
    mTextView48Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView48);
    mtemprcPtr = (ZKWindow*)findControlByID(ID_GCODE_temprc);
    mtempbxPtr = (ZKDiagram*)findControlByID(ID_GCODE_tempbx);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView6);
    mButton77Ptr = (ZKButton*)findControlByID(ID_GCODE_Button77);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView7);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView8);
    mButton3Ptr = (ZKButton*)findControlByID(ID_GCODE_Button3);
    mButton76Ptr = (ZKButton*)findControlByID(ID_GCODE_Button76);
    mButton2Ptr = (ZKButton*)findControlByID(ID_GCODE_Button2);
    mButton180Ptr = (ZKButton*)findControlByID(ID_GCODE_Button180);
    mTextView47Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView47);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView5);
    mButton178Ptr = (ZKButton*)findControlByID(ID_GCODE_Button178);
    mButton179Ptr = (ZKButton*)findControlByID(ID_GCODE_Button179);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView4);
    mtempptPtr = (ZKWindow*)findControlByID(ID_GCODE_temppt);
    mtempPtr = (ZKWindow*)findControlByID(ID_GCODE_temp);
    mSeekBar3Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_SeekBar3);if(mSeekBar3Ptr!= NULL){mSeekBar3Ptr->setSeekBarChangeListener(this);}
    mSeekBar2Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_SeekBar2);if(mSeekBar2Ptr!= NULL){mSeekBar2Ptr->setSeekBarChangeListener(this);}
    mSeekBar1Ptr = (ZKSeekBar*)findControlByID(ID_GCODE_SeekBar1);if(mSeekBar1Ptr!= NULL){mSeekBar1Ptr->setSeekBarChangeListener(this);}
    mButton41Ptr = (ZKButton*)findControlByID(ID_GCODE_Button41);
    mTextview37Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview37);
    mTextview36Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview36);
    mTextview34Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview34);
    mButton28Ptr = (ZKButton*)findControlByID(ID_GCODE_Button28);
    mButton27Ptr = (ZKButton*)findControlByID(ID_GCODE_Button27);
    mButton26Ptr = (ZKButton*)findControlByID(ID_GCODE_Button26);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView1);
    mButton23Ptr = (ZKButton*)findControlByID(ID_GCODE_Button23);
    mButton70Ptr = (ZKButton*)findControlByID(ID_GCODE_Button70);
    mButton71Ptr = (ZKButton*)findControlByID(ID_GCODE_Button71);
    mButton72Ptr = (ZKButton*)findControlByID(ID_GCODE_Button72);
    mButton73Ptr = (ZKButton*)findControlByID(ID_GCODE_Button73);
    mButton74Ptr = (ZKButton*)findControlByID(ID_GCODE_Button74);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView3);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void gcodeActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
        if (sButtonCallbackTab[i].id == pBase->getID()) {
            if (sButtonCallbackTab[i].callback((ZKButton*)pBase)) {
            	return;
            }
            break;
        }
    }


    int len = sizeof(sAppInfoTab) / sizeof(sAppInfoTab[0]);
    for (int i = 0; i < len; ++i) {
        if (sAppInfoTab[i].id == pBase->getID()) {
            EASYUICONTEXT->openActivity(sAppInfoTab[i].pApp);
            return;
        }
    }

	Activity::onClick(pBase);
}

void gcodeActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void gcodeActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void gcodeActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool gcodeActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void gcodeActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int gcodeActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void gcodeActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void gcodeActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void gcodeActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool gcodeActivity::onTouchEvent(const MotionEvent &ev) {
    return ongcodeActivityTouchEvent(ev);
}

void gcodeActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void gcodeActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void gcodeActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SVideoViewCallbackTab[i].id == pVideoView->getID()) {
        	if (SVideoViewCallbackTab[i].loop) {
                //循环播放
        		videoLoopPlayback(pVideoView, msg, i);
        	} else if (SVideoViewCallbackTab[i].onVideoViewCallback != NULL){
        	    SVideoViewCallbackTab[i].onVideoViewCallback(pVideoView, msg);
        	}
            break;
        }
    }
}

void gcodeActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

	switch (msg) {
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED\n");
    if (callbackTabIndex >= (sizeof(SVideoViewCallbackTab)/sizeof(S_VideoViewCallback))) {
      break;
    }
		pVideoView->setVolume(SVideoViewCallbackTab[callbackTabIndex].defaultvolume / 10.0);
		mVideoLoopErrorCount = 0;
		break;
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_ERROR:
		/**错误处理 */
		++mVideoLoopErrorCount;
		if (mVideoLoopErrorCount > 100) {
			LOGD("video loop error counts > 100, quit loop playback !");
            break;
		} //不用break, 继续尝试播放下一个
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED\n");
        std::vector<std::string> videolist;
        std::string fileName(getAppName());
        if (fileName.size() < 4) {
             LOGD("getAppName size < 4, ignore!");
             break;
        }
        fileName = fileName.substr(0, fileName.length() - 4) + "_video_list.txt";
        fileName = "/mnt/extsd/" + fileName;
        if (!parseVideoFileList(fileName.c_str(), videolist)) {
            LOGD("parseVideoFileList failed !");
		    break;
        }
		if (pVideoView && !videolist.empty()) {
			mVideoLoopIndex = (mVideoLoopIndex + 1) % videolist.size();
			pVideoView->play(videolist[mVideoLoopIndex].c_str());
		}
		break;
	}
}

void gcodeActivity::startVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		//循环播放
    		videoLoopPlayback(videoView, ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED, i);
    		return;
    	}
    }
}

void gcodeActivity::stopVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		if (videoView->isPlaying()) {
    		    videoView->stop();
    		}
    		return;
    	}
    }
}

bool gcodeActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
	mediaFileList.clear();
	if (NULL == pFileListPath || 0 == strlen(pFileListPath)) {
        LOGD("video file list is null!");
		return false;
	}

	ifstream is(pFileListPath, ios_base::in);
	if (!is.is_open()) {
		LOGD("cann't open file %s \n", pFileListPath);
		return false;
	}
	char tmp[1024] = {0};
	while (is.getline(tmp, sizeof(tmp))) {
		string str = tmp;
		removeCharFromString(str, '\"');
		removeCharFromString(str, '\r');
		removeCharFromString(str, '\n');
		if (str.size() > 1) {
     		mediaFileList.push_back(str.c_str());
		}
	}
	LOGD("(f:%s, l:%d) parse fileList[%s], get [%d]files\n", __FUNCTION__,
			__LINE__, pFileListPath, mediaFileList.size());
	for (size_t i = 0; i < mediaFileList.size(); i++) {
		LOGD("file[%d]:[%s]\n", i, mediaFileList[i].c_str());
	}
	is.close();

	return true;
}

int gcodeActivity::removeCharFromString(string& nString, char c) {
    string::size_type   pos;
    while(1) {
        pos = nString.find(c);
        if(pos != string::npos) {
            nString.erase(pos, 1);
        } else {
            break;
        }
    }
    return (int)nString.size();
}

void gcodeActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void gcodeActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void gcodeActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}