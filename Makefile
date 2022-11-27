#   Makefile    编译工程模板

#   把源码放./src
#   把头文件放./inc


#   如果有用到库则需修改添加库名库和路径
#   然后直接 make


#   .o文件生成在obj文件夹
#   可执行文件生成在ouput文件夹


TARGET = app#程序名称
VERSION = _V_1.0_out#执行文件版本后缀
CC = gcc#编译器
DEBUG = -DUSE_DEBUG#调试
CFLAGS = -Wall#开详细警告

  
SOURCES = $(wildcard ./src/*.c)#源文件的文件夹./src
INCLUDES = -I ./inc#头文件的文件夹./inc

  

OBJ = $(patsubst %.c, %.o, $(SOURCES))#目标文件

  
# LIB_NAMES  =-lfun_a -lfun_so
# LIB_PATH  =-L./lib

  
LIB_NAMES = #库名
LIB_PATH = #库路径


#links 连接为可执程序
$(TARGET):$(OBJ)

	 @mkdir -p output
	 $(CC) $(addprefix ./obj/,$(notdir $(OBJ))) $(LIB_PATH) $(LIB_NAMES) -o output/$(TARGET)$(VERSION)

#compile 编译为目标文件
%.o: %.c

	 @mkdir -p obj
	 $(CC) $(INCLUDES) $(DEBUG) -c $(CFLAGS) $< -o obj/$(notdir $@)


.PHONY:clean #伪指令 输入make clear 删除生成的工程编译文件

clean:

	 @echo "Remove linked and compiled files......"
	 rm -rf $(TARGET) output
	 rm -rf obj/$(notdir $(OBJ)) obj


.PHONY:run #伪指令 输入make run 运行生成的可执行程序

run:

	 ./output/$(TARGET)$(VERSION)


	 