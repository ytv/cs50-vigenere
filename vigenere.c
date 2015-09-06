#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool barCheckFx(string s);
char crypt4UpperFx(int m, int i);
char crypt4LowerFx(int m, int i);
bool isUpperFx(char c);
bool isLowerFx(char c);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("ERROR: argc != 2\n");
        return 1;
    }
    else if(barCheckFx(argv[1]) == false)
    {
        printf("ERROR: argv[1] is not entirely alphabetic\n");
        return 1;
    }
    else
    {        
        string key = argv[1];
        int keyLen = strlen(key);
        int keyArr[keyLen];
        
        for(int i = 0; i < keyLen; i++)
        {
            if(isUpperFx(key[i]))
            {
                keyArr[i] = key[i]-'A';
            }
            else
            {
                keyArr[i] = key[i]-'a';
            }
        }
        
        string passPhrase = GetString();
        int passPhraseLen = strlen(passPhrase);
        int i = 0;
        int j = 0;
        
        while(i < passPhraseLen)
        {   
            if(j == keyLen)
            {
                j = 0;
            }     
            
            int n = (int)passPhrase[i];
                
            if(isUpperFx(n)) 
            {                
                printf("%c", crypt4UpperFx(n, keyArr[j]));
                j++;
            }
            else if(isLowerFx(n)) 
            {
                printf("%c", crypt4LowerFx(n, keyArr[j]));
                j++;
            }
            else //if passPhrase[i] is not an alphabetic character
            {
                printf("%c",passPhrase[i]);
            }
            
            i++;
            
        }
           
        printf("\n");
        
        return 0;
       
    }

}

bool barCheckFx(string s)
{
    bool valid = true;
    int len = strlen(s);
    
    for(int i = 0; i < len; i++)
    { 
        if(isalpha(s[i]))
        {}
        else
        {
            valid = false;
        }
    }
    
    return valid;
}

bool isUpperFx(char c)
{
    int n = (int)c;
    if(n >= 65 && n <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLowerFx(char c)
{
    int n = (int)c;
    if(n >= 92 && n <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char crypt4UpperFx(int m, int i)
{    
    if(m + i > 90)
        return m + i - 90 + 65 - 1;
    else
        return m + i;
}

char crypt4LowerFx(int m, int i)
{
    if(m + i > 122)
        return m + i - 122 + 97 - 1;
    else
        return m + i;
}
