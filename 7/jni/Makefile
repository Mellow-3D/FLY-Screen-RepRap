#Generally, there is no need to modify the file
#z6s
LOCAL_PATH=$(dir  $(abspath $(lastword $(MAKEFILE_LIST))))
ZKSW_PREBUILT_LIB_PATH := $(ZKSW_REAL_PREBUILT)/lib
ZKSW_PREBUILT_INCLUDE_PATH := $(ZKSW_REAL_PREBUILT)/include

EASYUI_COMMON_INCLUDE := $(LOCAL_PATH)/include

#Configuration source file directory
PROJ_ROOT_PATH  :=./
#Source file extension
PROJ_SRC_SUFFIX := %.cpp %.c
PROJ_HEAD_SUFFIX := %.h
# Recursively traverse all files in the directory
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))  
# Obtain the corresponding source file
PROJ_ALL_FILES := $(foreach src_path,$(PROJ_ROOT_PATH), $(call rwildcard,$(src_path),*.*) )   
PROJ_SRC_FILES := $(filter $(PROJ_SRC_SUFFIX),$(PROJ_ALL_FILES))   
PROJ_HEAD_FILES := $(filter $(PROJ_HEAD_SUFFIX),$(PROJ_ALL_FILES))   

LOCAL_SRC_FILES  := $(PROJ_SRC_FILES) 
LOCAL_HEAD_FILES := $(PROJ_HEAD_FILES) 

#Source file directory structure
PROJ_DIR_TREE := $(dir $(foreach src_path, $(LOCAL_SRC_FILES), $(call rwildcard,$(src_path),*/) ) )  
PROJ_DIR_TREE := $(sort $(PROJ_DIR_TREE))  


OBJS_ROOT_DIR=../obj/
OBJS_1 = $(patsubst %.cpp,%.o,$(LOCAL_SRC_FILES))
OBJS_2 = $(patsubst %.c,%.o,$(OBJS_1))
OBJS   = $(addprefix $(OBJS_ROOT_DIR),$(OBJS_2))
OBJS_DIR_TREE=$(addprefix $(OBJS_ROOT_DIR),$(PROJ_DIR_TREE))

CFLAGS=-Os -pipe -march=armv5te -mtune=arm926ej-s -fno-caller-saves -Wno-unused-result -mfloat-abi=soft  -Wformat -Werror=format-security -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro       -Wl,--warn-common -Wl,--warn-once -Wl,-z,combreloc -Wl,-z,defs    -DUSE_ANDROID_LOG
CXXFLAGS=-Os -pipe -march=armv5te -mtune=arm926ej-s -fno-caller-saves -Wno-unused-result -mfloat-abi=soft  -Wformat -Werror=format-security -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -Wno-virtual-dtor -Wl,-z,defs -DUSE_ANDROID_LOG 

CXXFLAGS+= -fexceptions -fpermissive -Wall -O2 

INCLUDE_DIR := -I$(EASYUI_COMMON_INCLUDE) \
					-I$(ZKSW_PREBUILT_INCLUDE_PATH)/gui \
					-I$(ZKSW_PREBUILT_INCLUDE_PATH)/uClibc++ \
					-I$(ZKSW_PREBUILT_INCLUDE_PATH)/system \
					-I. 

LDFLAGS = -luClibc++ -leasyui -llog
LDFLAGS += -L$(ZKSW_PREBUILT_LIB_PATH)/system -L. 

TARGET=../libs/armeabi/libzkgui.so

ifeq ($(TARGET), $(wildcard $(TARGET)))
	DELETE_TARGET=$(TARGET)
endif

# alias commads if compile on windows
RM =rm
MKDIR=mkdir
ECHO=echo
ifeq ($(OS),Windows_NT)
	RM=win32-rm
	MKDIR=win32-mkdir
	ECHO=win32-echo
else
	#keep default
endif
#alias end

all: prepare $(TARGET)
	@$(ECHO) 
	@$(ECHO) "[armeabi] Install        : libzkgui.so => libs/armeabi/libzkgui.so"
	

$(OBJS_ROOT_DIR)%.o: %.cpp $(LOCAL_HEAD_FILES)
	@$(ECHO) "[armeabi] Compile++      : "$< 
	@$(CC) -c $< -o $@ $(CXXFLAGS) $(INCLUDE_DIR) $(LDFLAGS) 
	
$(OBJS_ROOT_DIR)%.o: %.c $(LOCAL_HEAD_FILES)
	@$(ECHO) "[armeabi] Compile++      : "$< 
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_DIR) $(LDFLAGS) 

$(TARGET):$(OBJS) 
	@$(ECHO) "[armeabi] SharedLibrary  : "$@ 
	@$(CC) -fPIC -shared $^ -o $@ $(LDFLAGS) $(CXXFLAGS) ../obj/Main.o
	
prepare: 
	@$(ECHO) "[armeabi] GCC            : "$(CC) 
	@-$(MKDIR) ../libs/armeabi -p 
	@-$(MKDIR) $(OBJS_DIR_TREE) -p
	@-$(RM) $(TARGET) -rf
	
clean:
	@$(ECHO) "[armeabi] Clean          : "$(OBJS_ROOT_DIR) 
	@-$(RM)  $(OBJS_ROOT_DIR) -rf 
	@$(ECHO) "[armeabi] Clean          : "$(TARGET)
	@-$(RM)  $(TARGET) -rf 

.PHONY:all clean prepare $(TARGET)
