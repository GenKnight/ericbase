#######Makefile Begin#######################

TARGET_NAME := test_database
BUILD_TYPE := Debug
#BUILD_TYPE := Release
#MODULE_TYPE := dynamic_lib
#MODULE_TYPE := static_lib
#MODULE_TYPE := executable

MODULE_TYPE := executable

TARGET := $(TARGET_NAME)

GOV_FLG = 1 

SRCDIRS   := ./src
SRCDIRS   += 


SRCEXTS   := .c .cpp

CFLAGS    := 
CPPFLAGS  :=  

CPPFLAGS  := -g -I./src -I../src

CPPFLAGS  +=  -Duse_namespace -fPIC  -I../../common/include/s_utility -I../../common/include/s_math -I/usr/u03/oracle/rdbms/public/

LDFLAGS   :=  -L ../../common/lib/$(BUILD_TYPE)/s_utility -L ../bin/$(BUILD_TYPE) -L ../../common/lib/$(BUILD_TYPE)/s_dbaccess -l_utility -l_dbaccess 

CC      = g++

SHELL   = /bin/sh

SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))

#OBJS    = $(foreach x,$(SRCEXTS), \
#	  $(patsubst %$(x),./obj/%.o,$(notdir $(filter %$(x),$(SOURCES)i))))
OBJS    = $(foreach x,$(SRCEXTS), \
	  $(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))

DEPS    = $(patsubst %.o,%.d,$(OBJS))


.PHONY : all objs clean cleanall rebuild

all : $(TARGET)

# Rules for creating the dependency files (.d).

#---------------------------------------------------

#%.d : %.c

#	@$(CC) -MM -MD $(CFLAGS) $< 

#%.d : %.cpp

#	@$(CC) -MM -MD $(CPPFLAGS) $<


# Rules for producing the objects.

#---------------------------------------------------


BUILD_PRE : 
	rm -rf obj
	rm -rf bin/$(BUILD_TYPE)
	mkdir obj
	mkdir bin/$(BUILD_TYPE)
ifeq ($(BUILD_TYPE), Debug)
CFLAGS += -g
CPPFLAGS += -g
endif


objs : $(OBJS)
%.o : %.c

	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $(patsubst %.c,%.o, $<) $(CGOV)

%.o : %.cpp
	$(CC) -c $(CPPFLAGS)  $< -o ./obj/$(notdir $(patsubst %.cpp,%.o, $<)) $(CGOV)

# Rules for producing the executable.

#----------------------------------------------

$(TARGET) : BUILD_PRE $(OBJS)
ifeq ($(MODULE_TYPE), dynamic_lib)
	$(CC) -o ./bin/$(BUILD_TYPE)/lib_$(TARGET_NAME).so -shared ./obj/*.o  $(LDFLAGS) $(CGOV)
endif

ifeq ($(MODULE_TYPE), static_lib)
	ar rcs ./bin/$(BUILD_TYPE)/lib_$(TARGET_NAME).a ./obj/*.o  
endif

ifeq ($(MODULE_TYPE), executable)
	$(CC) -o ./bin/$(BUILD_TYPE)/exe_$(TARGET_NAME) ./obj/*.o  $(LDFLAGS) $(CGOV)
endif

-include $(DEPS)

rebuild: clean all


clean :

	@$(RM) ./obj/*.o ./obj/*.d ./bin/$(BUILD_TYPE)/*.so ./bin/$(BUILD_TYPE)/*.a $(OBJS)
#        $(foreach x,$(OBJS), @$(RM) $(x))

cleanall: clean

	@$(RM) $(PROGRAM) $(PROGRAM).exe

### End of the Makefile 

###############################################################################

