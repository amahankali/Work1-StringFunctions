#include <stdio.h>
#include <stdlib.h>

int strlenA(char *s)
{
	int i = 0;
	while(*(s + i)) i++;
	return i;
}

//adds s2 to the end of s1 and returns a pointer to s1
char *strcatA(char *s1, char *s2)
{
	//find address of null character in s1
	int len1 = strlenA(s1);
	char *nullLoc = (s1 + len1);
	char *s2Loc = s2;
	while(*(s2Loc))
	{
		*(nullLoc) = *(s2Loc);
		nullLoc++;
		s2Loc++;
	}
	*nullLoc = 0;
	return s1;
}

//adds first n characters of s2 to s1 and returns s1
//if s2 has less than n characters, just adds all of s2
char *strncatA(char *s1, char *s2, int n)
{
	int len1 = strlenA(s1);
	char *nullLoc = (s1 + len1);
	while(*s2 && n)
	{
		*(nullLoc) = *(s2);
		nullLoc++;
		s2++;
		n--;
	}
	*(nullLoc) = 0;
	return s1;
}

//copies first n characters of s2 into s1
//adds a null character after the copied characters
//returns s1
char *strncpyA(char *s1, char *s2, int n)
{
	char* currentLoc = s1;
	int count = 0;
	while(*(s2) && (n - count))
	{
		*(currentLoc) = *(s2);
		//printf("%s\n", s2);
		if(*(currentLoc) == 0) break;
		currentLoc++; s2++; count++;
	}
	*(currentLoc) = 0;
	return s1;
}

int strcmpA(char *s1, char *s2)
{
	while(*s1 && *s2)
	{
		if(*s1 - *s2) return *s1 - *s2;
		s1++; s2++;
	}
	return *s1 - *s2;
}

char *strchrA(char *s, int c)
{
	while(*s != c && *s != 0) s++;
	if(*s == 0) return 0;
	return s;
}

//searches for s2 in s1
//if s2 is empty returns s1
//returns pointer to occurrence of s2 if there is one
//otherwise returns null
char *strstrA(char *s1, char *s2)
{
	int len2 = strlenA(s2);
	if(len2 == 0) return s1;

	int mainLen = strlenA(s1);
	int i = 0;
	for(; i < mainLen; i++)
	{
		if(i + len2 - 1 >= mainLen) return 0;

		////////////////
		int j = i;
		char *p1 = s1 + i;
		char *p2 = s2;
		int works = 1;
		for(; j < mainLen; j++)
		{
			if(*p2 == 0) break;
			if(*p1 - *p2)
			{
				works = 0;
				break;
			}
			p1++;
			p2++;
		}
		if(works) return s1 + i;
		////////////////
	}
	return 0;
}


int main () {

	printf("=============================================================Test Results=============================================================\n");
	///////////////////Test for strlenA///////////////////
	char sTest[50];
	int i = 0;
	for(; i < 8; i++) sTest[i] = i + 65;
	sTest[8] = 0;

	printf("length of %s: %d\n", sTest, strlenA(sTest));
	printf("length of %s: %d\n", sTest, strlenA(sTest));

	printf("\n");

	///////////////////Test for strcatA///////////////////
	printf("====Testing strcatA====\n");
	char sTest2[50];
	sTest2[1] = 83;
	sTest2[2] = 88;
	sTest2[3] = 78;
	sTest2[4] = 68;
	sTest2[5] = 0;

	printf("concatenating sTest2(%s) to sTest(%s):\n", sTest2, sTest);
	strcatA(sTest, sTest2);
	printf("results: sTest(%s), sTest2(%s)\n", sTest, sTest2);
	printf("length of sTest(%s): %d\n", sTest, strlenA(sTest));
	printf("\n");

	printf("again, concatenating sTest2(%s) to sTest(%s):\n", sTest2, sTest);
	strcatA(sTest, sTest2);
	printf("results: sTest(%s), sTest2(%s)\n", sTest, sTest2);
	printf("length of sTest(%s): %d\n", sTest, strlenA(sTest));
	printf("\n");

	///////////////////Test for strncatA///////////////////
	printf("====Testing strncatA====\n");
	int n = 2;
	printf("concatenating first %d chars of sTest2(%s) to sTest(%s)\n", n, sTest2, sTest);
	strncatA(sTest, sTest2, n);
	printf("results: sTest(%s), sTest2(%s)\n", sTest, sTest2);
	printf("length of sTest(%s): %d\n\n", sTest, strlenA(sTest));

	printf("again, concatenating first %d chars of sTest2(%s) to sTest(%s)\n", n, sTest2, sTest);
	strncatA(sTest, sTest2, n);
	printf("results: sTest(%s), sTest2(%s)\n", sTest, sTest2);
	printf("length of sTest(%s): %d\n\n", sTest, strlenA(sTest));

	///////////////////Test for strncpyA///////////////////
	printf("====Testing strncpyA====\n");
	char s1[50];
	char s2[50];

	i = 0;
	for(; i < 5; i++) s1[i] = 65 + i;
	s1[5] = 0;

	i = 0;
	for(; i < 7; i++) s2[i] = 48 + i;
	s1[7] = 0;

	n = 200000000;
	printf("copying first %d characters of s2(%s) into s1(%s):\n", n, s2, s1);
	strncpyA(s1, s2, n);
	printf("results: s1(%s), s2(%s)\n", s1, s2);
	printf("\n");

	n = 2;
	printf("copying first %d characters of s2(%s) into s1(%s):\n", n, s2, s1);
	strncpyA(s1, s2, n);
	printf("results: s1(%s), s2(%s)\n", s1, s2);
	printf("\n");

	///////////////////Test for strcmpA///////////////////
	printf("====Testing strcmpA====\n");
	char* cmp1 = "eifjiejfijefiejrifie";
	char* cmp2 = "eifjiejfijefiejri";

	printf("comparing %s and %s: %d\n", cmp1, cmp2, strcmpA(cmp1, cmp2));
	printf("\n");

	///////////////////Test for strchrA///////////////////
	printf("====Testing strchrA====\n");
	char* mainString = "acfghylkmnoi, fmujdtntz";

	int length = strlenA(mainString);
	i = 0;
	for(; i < length; i++)
	{
		char searching = *(mainString + i);
		printf("searching for %c in %s: %s\n", searching, mainString, strchrA(mainString, searching));
	}
	i = 0;
	length = strlenA(sTest);
	for(; i < length; i++)
	{
		char searching = *(sTest + i);
		printf("searching for %c in %s: %s\n", searching, mainString, strchrA(mainString, searching));
	}

	///////////////////Test for strstrA///////////////////
	printf("====Testing strstrA====\n");
	char* searchString = "ghylkmn";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "acfghylkr";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "acfghylk";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "noi";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "noif";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "dtntz";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "dtntzei";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));	

	searchString = "fmujdtnt";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "fmujdtntz";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));

	searchString = "fmujdtntzieewi";
	printf("searching for %s in %s: %s\n\n", searchString, mainString, strstrA(mainString, searchString));


	printf("======================================================================================================================================\n");
	return 0;
}