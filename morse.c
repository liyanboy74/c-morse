/**
 * Morse Decoder
 * By Liyanboy74
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// 26 Code + 10 Num
const char *morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",\
"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

int serchMorse(char sign[])
{
    int i,s;
    for(i=0;i<36;i++)if(!strcmp(sign,morse[i]))return i;
    return -1;
}

int morse_decod(char ch)
{
    static int i=0;
    static char mBuf[6];

    if(ch=='.'||ch=='-')
    {
        if(i<5)mBuf[i++]=ch;
        return 0;
    }
    else if(ch==' '||ch=='/')
    {
        if(!i)
        {
            if(ch=='/')putchar(' ');
            return 0;
        }
        mBuf[i]='\0';
        i=serchMorse(mBuf);
        if(i<0)
        {
            putchar('?');
            return 1;
        }
        else if(i<26)putchar('A'+i);
        else putchar('0'+i-26);
        if(ch=='/')putchar(' ');
        i=0;
        return 0;
    }
    else i=0;
    return 0;
}

int morse_encod(char ch)
{
    if(ch>='0'&&ch<='9')printf("%s ",morse[ch-'0'+26]);
    else if(ch>='A'&&ch<='Z')printf("%s ",morse[ch-'A']);
    if(ch==' ')printf("/ ");
}

int main()
{
    int mode=0;
    char ch;
    while(ch=getch(),ch!=27)
    {
        ch=toupper(ch);
        if(ch=='\r')printf("\r\n");

        if((ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))mode=0;
        else if(ch=='.'||ch=='-')mode=1;

        if(mode)morse_decod(ch);
        else morse_encod(ch);
    }
    return 0;
}
