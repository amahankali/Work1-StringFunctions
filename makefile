strtest: StringFunctions.c
	gcc StringFunctions.c -o StringFunctions

run: strtest
	./StringFunctions
