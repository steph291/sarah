#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 230
int main() {


    FILE *fp1;
    char str[MAXCHAR];
    char* filename = "/home/titou/Desktop/conversations/email/email.txt";


    //char* countemail ="blaqbla";

    system("curl -su user:passwd https://mail.google.com/mail/feed/atom > /home/titou/Desktop/conversations/email/email.txt");

    fp1 = fopen(filename, "r");

    if (fp1 == NULL){
        printf("Could not open file %s",filename);
        exit(1);
    }

    fgets(str, MAXCHAR, fp1);

    if(strstr(str,"<fullcount>0</fullcount>")){ // verifying the count of 0 email
          system("espeak -vfr+f2 -s150 \"aucun nouveau courriel.\"");
    }else{
          system("espeak -vfr+f2 -s150 \"nouveau courriel !\"");
    }
    fclose(fp1);
    remove("/home/titou/Desktop/conversations/email/email.txt");
    return 0;
}
