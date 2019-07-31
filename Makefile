
main: main.cpp helper.o
	g++ -o $@ $^

helper.o: helper.cpp
	g++ -c $^

.PHONY: clean

clean:
	@rm -f main *.o *.so *.a *.obj 
