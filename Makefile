
main: main.cpp
	g++ -o $@ $^

.PHONY: clean

clean:
	@rm -f main *.o *.so *.a *.obj 
