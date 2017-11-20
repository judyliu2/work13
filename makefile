tester: piper.o
	@gcc piper.o -o tester

piper.o: piper.c
	@gcc -c piper.c

run: tester
	@./tester

clean:
	@rm *.o
	@rm *~
