#include<stdio.h>
#include <string.h>
char * toLowercaseString(char *str){
    int len = strlen(str);
    char * strLowerCase = (char*) malloc(sizeof(char)* len);
    for(int i=0;i<=strlen(str);i++){
        if(str[i]>=65&&str[i]<=90){
            strLowerCase[i]=str[i]+32;
        }else {
            strLowerCase[i]=str[i];
        }        
        
    }
    return strLowerCase;
}

int isEmpty(char *str){
    if (str[0]=='\n' ||str[0]=='\0' || str[0]=='\t')
        return 1;
    return 0;
}
int hasDigit(char *str){
    int len = strlen(str);
    for(int i =0; i < len;i++){
        if (isdigit(str[i])){
            return 1;
        }
        
    }
    return 0;
}
int isProperNoun(char *str){
    if (!isEmpty(str) && str[0]>= 'A' && str[0] <= 'Z'){
        return 1 ;
    }
    return 0;
}
int compareString(char* word1 ,char* word2){
    return strcmp(toLowercaseString(word1),toLowercaseString(word2));
}
int isStopWord(char** stopWordList,int stopListSize, char* word){
    for (int i=0;i< stopListSize; i++){
        if (compareString(stopWordList[i],word) == 0) return 1;
    }
    return 0;
}
FILE * openFile(char *filename, char * type){
    FILE *fp;
    fp = fopen(filename, type);
    if (fp ==NULL){
        printf("Could not open file %s", filename);
    }
    return fp;
}
void readFileText(char* filename,char** stopWordList,int stopListSize)
{
    FILE *fp;
    fp = openFile(filename, "r");
    if (fp == NULL) return;
    int c;
    char *word = malloc(sizeof(char)*100);
    int index = 0;
    int lineNo =1;
    char *strLine = (char*) malloc(sizeof(char)*200);
    char *token = (char*) malloc(sizeof(char)*20);
    const char divider[20] = "\n ,()-.\0";
    int lineNumer = 0;
    while (fgets(strLine,199,fp)!= NULL){
        lineNumer++;
        strLine[strlen(strLine)] = '\0';
        token = strtok(strLine, divider);
        while( token != NULL ) {
            if (!isStopWord(stopWordList,stopListSize,token) && !isEmpty(token) && !hasDigit(token)){
                printf( " %s\n", token );
            }
            token = strtok(NULL, divider);
        }
        

    }
    
    // do{
    // c = fgetc(fp);
    //     if (c == '\n')
    //     {
    //         lineNo+=1;
    //     }        

    //     if (c == '.') {
    //         while (!isupper(c)){
    //             c = fgetc(fp);
    //             if (c == '\n') lineNo+=1; //*
    //             if (c == EOF) // eof thì kết thúc
    //             {
    //                 word[index] = '\0';                           
    //                 // printf(" %s\n ", word); 
    //                 break;
    //             }
    //         }
    //             // fseek(fp, -1, SEEK_CUR);
    //             word[index] = '\0';                           
    //             //printf(" %s\n ", word);
    //             word[0] = 0; //Reset word
    //             index = 0;
    //             c = tolower(c); // lấy chữ đầu tiên của từ viết hoa và để nó thành viết thường
    //         }              
      
    //     if(c == ' ' || c == '\n' || c == '\0' || c == '\t' || c == ',' || c == '(' || c == ')' || c == ':' || c == ';' || c == '-' || c == '!' || c == '\'' || c == '`' || c == '\"') 
    //     {   
    //         if (isupper(c = fgetc(fp)))
    //         {
    //             while (c != ' ' )
    //             {
    //                 c = fgetc(fp);
    //                 if(c == '\n') lineNo+=1;
    //             }
    //             fseek(fp, -1, SEEK_CUR);
    //             word[index] = '\0';                           
    //             //printf(" %s\n ", word);
    //             // if (!check_stopw(stop_w,num_of_stop_w,word))
    //             // {

    //             // }
                
    //             word[0] = 0; //Reset word
    //             index = 0;
    //         }
    //         else
    //         {
    //             fseek(fp, -1, SEEK_CUR);
    //             word[index] = '\0';              
    //             //printf(" %s\n ", word);
    //             word[0] = 0; //Reset word
    //             index = 0;
    //         }         
    //     } else 
    //     {
    //         word[index] = c;   
    //         index++;
    //     }    

    // }while(c != EOF);

    fclose(fp); // Closing the file
}
char ** getListStopWorld(char *filename,int * numWord){
    char str[10];
    char** a = (char **)malloc(50 * sizeof(char *));
    for (int i = 0; i < 50; i++){
        a[i] = (char *)malloc(50 * sizeof(char));
    }
    FILE *fp;
    fp = openFile(filename, "r");
    if (fp ==NULL)  return NULL;
    int i = 0;
    while(!feof(fp)){
        fscanf(fp ,"%s\n", str);
        strcpy(a[i], str);
        (i)++;
    }
    *numWord = i;
    fclose(fp);
    return a;
}
void main (void ){
    char* stopWordFileName = "stopw.txt";
    char* textFileName = "vanban.txt";
    int* numStopWord = malloc(sizeof(int));
    char ** listStopWord = getListStopWorld(stopWordFileName,numStopWord);
    readFileText(textFileName,listStopWord,*numStopWord);
}