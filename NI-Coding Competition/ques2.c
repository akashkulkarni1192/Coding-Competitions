/* 
*  Candidate name: 
*  Candidate USN:
*  Question number 2: Decode the message?
*/

#include <stdio.h>
#include <string.h>

#define CHARS 28
#define MAX_CODE_LENGTH 12
#define MAX_STRING_LENGTH 1024

char chars[CHARS] = {'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z'};

// dots = 1
// dash = 2
// space = 0
char morseCode[CHARS][MAX_CODE_LENGTH]=
{
	{"102"},		//A
	{"2010101"},	//B
	{"2010201"},	//C
	{"20101"},		//D
	{"1"},			//E
	{"1010201"},	//F
	{"20201"},		//G
	{"1010101"},	//H
	{"101"},		//I
	{"1020202"},	//J
	{"20102"},		//K
	{"1020101"},	//L
	{"202"},		//M
	{"201"},		//N
	{"20202"},		//O
	{"1020201"},	//P
	{"2020102"},	//Q
	{"10201"},		//R
	{"10101"},		//S
	{"2"},			//T
	{"10102"},		//U
	{"1010102"},	//V
	{"10202"},		//W
	{"2010102"},	//X
	{"2010202"},	//Y
	{"2020101"}		//Z
};

//10001010102000100010201000201020200020101010002020200020101000201020200000001020101000101000100010101
// .                                                                   .......
char* DecodeMorseCode(char* encodedString, int length)
{
	/* Write the code here. */
	int i,j,k=0;
	char temp[20],decodedString[MAX_STRING_LENGTH]={0},ch[5];
	for(i=0;i<length;i++){
		if(encodedString[i]!='0')
			temp[k++]=encodedString[i];
		else if(encodedString[i+1]!='0')
			temp[k++]=encodedString[i];
		else{
			temp[k]='\0';
			for(j=0;j<26;j++)
				if(strcmp(morseCode[j],temp)==0)
					break;
			if(j<26){
				ch[0]=chars[j];
				ch[1]='\0';
				strcat(decodedString,ch);
				printf("\ndecodedString = %s\t\t(appended %s)",decodedString,ch);
				i+=2;
			}else{
				return "-1";
			}
			if(encodedString[i+1]=='0' && encodedString[i+2]=='0' && encodedString[i+3]=='0' && encodedString[i+4]=='0'){
				strcat(decodedString," ");
				printf("\ndecodedString = %s\t\t(appended %s)",decodedString," ");
				i+=4;
			}
			k=0;
			temp[0]='\0';
		}
	}
	temp[k]='\0';
	for(j=0;j<26;j++)
		if(strcmp(morseCode[j],temp)==0)
			break;
	if(j<26){
		ch[0]=chars[j];
		ch[1]='\0';
		strcat(decodedString,ch);
		printf("\ndecodedString = %s\t\t(appended %s)",decodedString,ch);
		i+=2;
	}else{
		return "-1";
	}
	return decodedString;
}

int main(void)
{
	char encodedString[MAX_STRING_LENGTH] = {0};
	/* Please do not modify the line below. Revert your changes before submission, if you make any. */
	scanf("%s", encodedString);
	/* Please do not modify the line below. Revert your changes before submission, if you make any. */
	printf("\n\n%s\n", DecodeMorseCode(encodedString, strlen(encodedString)));
	return 0;
}
