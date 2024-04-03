libStdMysql.so:StdMysql.cpp
	g++ -shared -fPIC StdMysql.cpp -o libStdMysql.so

.PHONY: clean install

clean:
	rm -f libStdMysql.so
install:
	cp libStdMysql.so /usr/lib
	cp StdMysql.h /usr/include