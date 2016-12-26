TARGET_NAME := fndmd
BUILD_TYPE := Debug
MODULE_TYPE := static_lib
CC = g++
BUILD_TYPE := Debug
COMMON_PATH := ../..

SRCDIRS := ./src
SRCEXTS := .cpp

CPPFLAGS := -g -fPIC -std=c++11 -I./src -I$(COMMON_PATH)/contrib -I$(COMMON_PATH)/include/fndnet -I$(COMMON_PATH)/include/fndmd -I$(COMMON_PATH)/include/dllcommon -I$(COMMON_PATH)/include/market

LDFLAGS := 

SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
OBJS= $(patsubst %.cpp,./obj/%.o,$(notdir $(SOURCES)))

vpath %.o   $(dir $(OBJS))
vpath %.cpp $(dir $(SOURCES))

TARGET := $(TARGET_NAME)

all : $(TARGET)

$(OBJS) :
./obj/%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CC) -c $(CPPFLAGS) $< -o $@

$(TARGET) : $(OBJS)
	@mkdir -p ./bin/$(BUILD_TYPE)

ifeq ($(MODULE_TYPE), dynamic_lib)
	$(CC) -o ./bin/$(BUILD_TYPE)/lib_$(TARGET_NAME).so -shared $(OBJS) $(STATIC_LIBS) $(LDFLAGS)
	cp -f ./bin/$(BUILD_TYPE)/lib_$(TARGET_NAME).so $(COMMON_PATH)/lib/$(BUILD_TYPE)
endif

ifeq ($(MODULE_TYPE), static_lib)
	ar rcs ./bin/$(BUILD_TYPE)/lib$(TARGET_NAME).a $(OBJS)
	cp -f ./bin/$(BUILD_TYPE)/lib$(TARGET_NAME).a $(COMMON_PATH)/lib/$(BUILD_TYPE) 
endif

ifeq ($(MODULE_TYPE), executable)
	$(CC) -o ./bin/$(BUILD_TYPE)/exe_$(TARGET_NAME) $(OBJS) $(LDFLAGS)
endif

clean:
	rm -f $(OBJS)
	rm -f libfndmd.a

