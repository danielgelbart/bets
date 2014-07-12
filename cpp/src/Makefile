
maintarget = mmath

sources = Main.cpp Config.cpp Logger.cpp CurrentTime.cpp Utils.cpp Thread.cpp dmmm_dbface.cpp dmmm_utils.cpp MemUsage.cpp RunInfo.cpp ServerUtils.cpp 

VPATH = utils main dmmm 

objects := $(patsubst %.cpp, %.o, $(sources))
dependencies := $(patsubst %.cpp, %.d, $(sources))

include_dirs = -I include -I dmmm -I utils -I /usr/include/mysql -I /usr/include/mysql++/ -I /usr/include/boost 

include_libs = -lm -L/usr/lib /usr/lib/libboost_filesystem-mt.so /usr/lib/x86_64-linux-gnu/libarchive.so -lmysqlclient /usr/lib/libmysqlpp.so.3 /usr/lib/libboost_date_time-mt.so /usr/lib/libboost_thread-mt.so /usr/lib/libboost_system-mt.so /usr/lib/libboost_wserialization-mt.so /usr/lib/libboost_serialization-mt.so /usr/lib/libboost_filesystem-mt.so -lpthread -lcrypto /usr/lib/libboost_regex-mt.so /usr/lib/libapophenia.so

include Makefile.flags

CC = g++

all: ../bin/$(maintarget) 

install: 
	cp -r ../bin 

../bin/$(maintarget): $(objects)
	@echo linking $(maintarget)
	@$(CC) -o ../bin/$(maintarget) $(objects)  $(include_libs)  

$(objects): %.o: %.cpp %.d Makefile.flags 
	@echo compiling $<
	@$(CC) -c $(cflags) $(include_dirs) $< -o $@ 2>&1 

$(dependencies): %.d: %.cpp
	@echo making dependencies for $<
	@$(SHELL) -ec '$(CC) -MM $(include_dirs) $< | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@'

valgrind:
	cd ..;	valgrind ./bin/$(maintarget) --leak-check=full

Makefile.flags:

clean:
	rm -f *.o *.d ../bin/* 

ifneq ($(MAKECMDGOALS),clean)
-include $(sources:.cpp=.d)
endif
