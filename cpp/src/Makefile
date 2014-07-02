
maintarget = mmath

sources = Main.cpp Config.cpp Logger.cpp UTFConverter.cpp Spider.cpp HtmlParser.cpp MySQL.cpp WebDB.cpp CurrentTime.cpp HttpClient.cpp Utils.cpp Url.cpp PageTemplate.cpp Thread.cpp Sysinfo.cpp dmmm_dbface.cpp dmmm_utils.cpp OpenSSL.cpp AverageRanking.cpp HtmlNode.cpp MemUsage.cpp RunInfo.cpp ServerUtils.cpp 

VPATH = utils main db dmmm 

objects := $(patsubst %.cpp, %.o, $(sources))
dependencies := $(patsubst %.cpp, %.d, $(sources))

include_dirs = -I include -I dmmm -I /usr/include/mysql -I /usr/include/mysql++/ -I /usr/include/boost

include_libs = -lm -L/usr/lib /usr/lib/libboost_filesystem-mt.so /usr/lib/x86_64-linux-gnu/libarchive.so -ltld -lmysqlclient /usr/lib/libmysqlpp.so.3 /usr/lib/libboost_thread-mt.so /usr/lib/libboost_date_time-mt.so /usr/lib/libboost_system-mt.so /usr/lib/libboost_wserialization-mt.so /usr/lib/libboost_regex-mt.so /usr/lib/libboost_serialization-mt.so /usr/lib/libboost_filesystem-mt.so -lpthread -lcrypto -lcurl -ltld

include Makefile.flags

CC = g++

all: ../bin/beauterror ../bin/$(maintarget) ../cgi/drive.cgi ../ngrams/ngrams

install: 
	cp -r ../bin /data/

../bin/$(maintarget): $(objects)
	@echo linking $(maintarget)
	@$(CC) -o ../bin/$(maintarget) $(objects) $(linkflags) $(include_libs)  

$(objects): %.o: %.cpp %.d Makefile.flags ../bin/beauterror
	@echo compiling $<
	@$(CC) -c $(cflags) $(include_dirs) $< -o $@ 2>&1 | ../bin/beauterror

$(dependencies): %.d: %.cpp
	@echo making dependencies for $<
	@$(SHELL) -ec '$(CC) -MM $(include_dirs) $< | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@'

../bin/beauterror: utils/beauterror.cpp
	g++ utils/beauterror.cpp -o ../bin/beauterror

/usr/bin/$(maintarget): Makefile
	echo "#!/bin/bash" > /usr/bin/$(maintarget)
	echo $(shell pwd)/../bin/drive '$$@' >> /usr/bin/$(maintarget)
	chmod +x /usr/bin/$(maintarget)

../cgi/drive.cgi: cgi/cgi.cpp Makefile.flags
	@echo compiling drive.cgi
	@$(CC) cgi/cgi.cpp $(cflags) -I include $(linkflags) -o ../cgi/drive.cgi

../ngrams/ngrams: ngrams/NGramsServer.cpp ngrams/NGramsServer.h utils/ServerUtils.h utils/ServerUtils.cpp ngrams/NGramDB.h ngrams/NGramDB.cpp Makefile.flags
	@echo compiling ngrams
	@$(CC) utils/ServerUtils.cpp ngrams/NGramsServer.cpp ngrams/NGramDB.cpp $(cflags) -I include $(linkflags) $(include_libs) -o ../ngrams/ngrams

valgrind:
	cd ..;	valgrind ./bin/$(maintarget) --leak-check=full

Makefile.flags:

clean:
	rm -f *.o *.d ../bin/* 

ifneq ($(MAKECMDGOALS),clean)
-include $(sources:.cpp=.d)
endif
