#include<stdio.h>
#include<string.h>


void checkInfoQR() {
    /*
    Hint:
    - Look up for strstr()
    - Look up for printf() using precision field
    */
   //input info string
    char qr[67];
    scanf("%s",qr);
    
    //check for type of bank
    char *type = NULL;
    type = strstr(qr, "BKB");
    if (type != NULL ){
        printf("%s: %s\n","Bank name", "BKB");

        char aNumber[14];
        memset(aNumber, '\0', sizeof(aNumber));
        strncpy(aNumber, qr+14, 13);
        printf("%s: %s\n","Account number",aNumber);

        char aName[31];
        memset(aName, '\0', sizeof(aName));
        strncpy(aName, qr+27, strlen(qr)-35);
        printf("%s: %s\n","Account holder name",aName);

        char day[3], month[3], year[5];
        memset(day, '\0', sizeof(day));
        memset(month, '\0', sizeof(month));
        memset(year, '\0', sizeof(year));
        strncpy(day,    qr+strlen(qr)-35+27, 2);
        strncpy(month,  qr+strlen(qr)-35+27+2, 2);
        strncpy(year,    qr+strlen(qr)-35+27+4, 4);
        printf("%s: %s/%s/%s","Creation time",day,month,year);

    }
    type=NULL;
    type= strstr(qr,"KHB");
    if (type != NULL ){
        printf("%s: %s\n","Bank name", "KHB");

        char aNumber[16];
        memset(aNumber, '\0', sizeof(aNumber));
        strncpy(aNumber, qr+22, 15);
        printf("%s: %s\n","Account number",aNumber);

        char aName[31];
        memset(aName, '\0', sizeof(aName));
        strcpy(aName, qr+37);
        printf("%s: %s\n","Account holder name",aName);

        char day[3], month[3], year[5];
        memset(day, '\0', sizeof(day));
        memset(month, '\0', sizeof(month));
        memset(year, '\0', sizeof(year));
        strncpy(month,    qr+11, 2);
        strncpy(day,  qr+11+2, 2);
        strncpy(year,    qr+11+4, 4);
        printf("%s: %s/%s/%s","Creation time",day,month,year);
    }
    type= NULL;
    type= strstr(qr,"HBB");
    if (type != NULL ){
        printf("%s: %s\n","Bank name", "HBB");

        char aNumber[9];
        memset(aNumber, '\0', sizeof(aNumber));
        strncpy(aNumber, qr+11+strlen(qr)-28, 8);
        printf("%s: %s\n","Account number",aNumber);

        char aName[31];
        memset(aName, '\0', sizeof(aName));
        strncpy(aName,  qr+11, strlen(qr)-28);
        printf("%s: %s\n","Account holder name",aName);

        char day[3], month[3], year[5];
        memset(day, '\0', sizeof(day));
        memset(month, '\0', sizeof(month));
        memset(year, '\0', sizeof(year));
        strncpy(day,    qr+11+strlen(qr)-28+8+4, 2);
        strncpy(month,  qr+11+strlen(qr)-28+8+2, 2);
        strncpy(year,   qr+11+strlen(qr)-28+8, 2);
        printf("%s: %s/%s/20%s","Creation time",day,month,year);
    }
}

void convertQR() {
    /*
    Hint:
    - Look up for strcmp(), strlen(), strcpy(), strncpy()
    */
    char type2[3];
    memset(type2, '\0', sizeof(type2));
    scanf("%s",&type2);
    char qr[67];
    scanf("%s",qr);
    char newQr[67];
    memset(newQr, '\0', sizeof(newQr));

    if (strcmp(type2, "KHB")!=0){
        if(strcmp(type2,"HBB")!=0){
            if(strcmp(type2,"BKB")!=0){
                printf("%s","Invalid bank to convert to");
                return;
            }
        }
    }
    char aNumber[16];
    memset(aNumber, '\0', sizeof(aNumber));
    char aName[31];
    memset(aName, '\0', sizeof(aName));
    char day[3], month[3], year[5];
    memset(day, '\0', sizeof(day));
    memset(month, '\0', sizeof(month));
    memset(year, '\0', sizeof(year));

    char *type = NULL;
    type = strstr(qr, "BKB");
    if (type != NULL ){
        strncpy(aNumber, qr+14, 13);
        strncpy(aName, qr+27, strlen(qr)-35);
        
        strncpy(day,    qr+strlen(qr)-35+27, 2);
        strncpy(month,  qr+strlen(qr)-35+27+2, 2);
        strncpy(year,    qr+strlen(qr)-35+27+4, 4);
        char* res = strstr(type2,"KHB");
        if (res !=  NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,month);
            strcat(newQr,day);
            strcat(newQr,year);
            strcat(newQr,"BKB");
            strcat(newQr,aNumber);
            strcat(newQr,aName);
            printf("%s", newQr);
        }
        res= NULL;
        res= strstr(type2,"HBB");
        if(res !=NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,aName);
            strcat(newQr,aNumber);
            char temp[3];
            memset(temp, '\0', sizeof(temp));
            strncpy(temp, year+2,2);
            strcat(newQr,temp);
            strcat(newQr,month);
            strcat(newQr,day);
            strcat(newQr,"BKB");
            printf("%s", newQr);
        }
        res= NULL;
        res= strstr(type2,"BKB");
        if (res!= NULL) printf("%s",qr);
    }
    type=NULL;
    type= strstr(qr,"KHB");
    if (type != NULL ){
        
        strncpy(aNumber, qr+22, 15);
        
        strcpy(aName, qr+37);

        strncpy(month,    qr+11, 2);
        strncpy(day,  qr+11+2, 2);
        strncpy(year,    qr+11+4, 4);

        char* res = strstr(type2,"BKB");
        if (res !=  NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,"KHB");
            strcat(newQr,aNumber);
            strcat(newQr,aName);
            strcat(newQr,day);
            strcat(newQr,month);
            strcat(newQr,year);
            printf("%s", newQr);
        }
        res= NULL;
        res= strstr(type2,"HBB");
        if(res !=NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,aName);
            strcat(newQr,aNumber);
            char temp[3];
            memset(temp, '\0', sizeof(temp));
            strncpy(temp, year+2,2);
            strcat(newQr,temp);
            strcat(newQr,month);
            strcat(newQr,day);
            strcat(newQr,"KHB");
            printf("%s", newQr);
        }
        res= NULL;
        res= strstr(type2,"KHB");
        if (res!= NULL) printf("%s",qr);
    }
    type= NULL;
    type= strstr(qr,"HBB");
    if (type != NULL ){

        strncpy(aNumber, qr+11+strlen(qr)-28, 8);
        
        strncpy(aName,  qr+11, strlen(qr)-28);
       
        strncpy(day,    qr+11+strlen(qr)-28+8+4, 2);
        strncpy(month,  qr+11+strlen(qr)-28+8+2, 2);
        strncpy(year,   qr+11+strlen(qr)-28+8, 2);
        
        char* res = strstr(type2,"BKB");
        if (res !=  NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,"HBB");
            strcat(newQr,aNumber);
            strcat(newQr,aName);
            strcat(newQr,day);
            strcat(newQr,month);
            strcat(newQr,"20");
            strcat(newQr,year);
            printf("%s", newQr);
        }
        res=NULL;
        res = strstr(type2,"KHB");
        if (res !=  NULL){
            strcat(newQr,"00020101021");
            strcat(newQr,month);
            strcat(newQr,day);
            strcat(newQr,"20");
            strcat(newQr,year);
            strcat(newQr,"HBB");
            strcat(newQr,aNumber);
            strcat(newQr,aName);
            printf("%s", newQr);
        }
        res= NULL;
        res= strstr(type2,"HBB");
        if (res!= NULL) printf("%s",qr);
    }

}

void encryptQR() {
    /*
    Hint:
    - Look up for sprintf(), strcat(), strncat()
    */
    char type2[6];
    char temp;
    scanf("%c",&temp);
    fgets(type2,30,stdin);
    char qr[67];
    scanf("%s",qr);

    char mode1[2],mode2[2],mode3[2];
    memset(mode1, '\0', sizeof(mode1));
    memset(mode2 , '\0', sizeof(mode2));
    memset(mode3 , '\0', sizeof(mode3));
    strncpy(mode1,type2,1);
    strncpy(mode2,type2+2,1);
    strncpy(mode3,type2+4,1);

    //KHAI BAO BIEN
    char aNumber[16];
    memset(aNumber, '\0', sizeof(aNumber));
    char aName[31];
    memset(aName, '\0', sizeof(aName));
    char day[3], month[3], year[5];
    memset(day, '\0', sizeof(day));
    memset(month, '\0', sizeof(month));
    memset(year, '\0', sizeof(year));

    //TACH STRING
    char *type = NULL;
    type = strstr(qr, "BKB");
    if (type != NULL ){
        strncpy(aNumber, qr+14, 13);
        strncpy(aName, qr+27, strlen(qr)-35);
        
        strncpy(day,    qr+strlen(qr)-35+27, 2);
        strncpy(month,  qr+strlen(qr)-35+27+2, 2);
        strncpy(year,    qr+strlen(qr)-35+27+4, 4);
    }
    type=NULL;
    type= strstr(qr,"KHB");
    if (type != NULL ){
        
        strncpy(aNumber, qr+22, 15);
        
        strcpy(aName, qr+37);

        strncpy(month,    qr+11, 2);
        strncpy(day,  qr+11+2, 2);
        strncpy(year,    qr+11+4, 4);
  
    }
    type= NULL;
    type= strstr(qr,"HBB");
    if (type != NULL ){

        strncpy(aNumber, qr+11+strlen(qr)-28, 8);
        
        strncpy(aName,  qr+11, strlen(qr)-28);
       
        strncpy(day,    qr+11+strlen(qr)-28+8+4, 2);
        strncpy(month,  qr+11+strlen(qr)-28+8+2, 2);
        strncpy(year,   qr+11+strlen(qr)-28+8, 2);
        
    }

    char newName[93];
    memset(newName, '\0', sizeof(newName));

    int flag1=0;
    char* case1 = NULL;
    case1= strstr(mode1,"1");
    if(case1!=NULL){
        int temp1;
        char temp2[4];
        for (int i=0; i<strlen(aName);i++){
            temp1=aName[i];
            sprintf(temp2, "%d", temp1);
            strcat(newName,temp2);
        }
        flag1=1;
    }
    
    case1=NULL;
    case1= strstr(mode1,"2");
    if(case1!=NULL){
        int temp1;
        char temp2[4];
        for (int i=0; i<strlen(aName);i++){
            temp1=aName[i];
            if (temp1<=90 && temp1>=65){
                temp1=temp1-65;
            }
            else{
                temp1=temp1-71;
            }
            sprintf(temp2, "%d", temp1);
            if (temp1<10){
                strcat(newName,"0");
            }
            strcat(newName,temp2);
        }
        flag1=1;
    }
    
    case1=NULL;
    case1= strstr(mode1,"0");
    if (case1!=NULL){
        strcat(newName,aName);
        flag1=1;
    }
    if (flag1==0){
        printf("%s","Invalid encrypting parameters");
        return;
    }

    int flag2=0;
    char newNumber[16];
    memset(newNumber, '\0', sizeof(newNumber));
    char *case2= NULL;
    case2 = strstr(mode2,"1");
    if (case2!=NULL){
        for (int i = strlen(aNumber)-1;i>=0;i--){
            int temp1= aNumber[i];
            temp1=temp1-48;
            char temp2[2];
            sprintf(temp2, "%d", temp1);
            strcat(newNumber,temp2);
        }
        flag2=1;
    }
    case2=NULL;
    case2= strstr(mode2,"0");
    if (case2!=NULL){
        strcat(newNumber,aNumber);
        flag2=1;
    }
    
    if (flag2==0){
        printf("%s","Invalid encrypting parameters");
        return;
    }
    //ghep string
    
    char newQr[200];
    memset(newQr, '\0', sizeof(newQr));

    type = NULL;
    type = strstr(qr,"BKB");
    if (type!=NULL){
        strcat(newQr,"00020101021");
        strcat(newQr,"BKB");
        strcat(newQr,newNumber);
        strcat(newQr,newName);
        strcat(newQr,day);
        strcat(newQr,month);
        strcat(newQr,year);
    }
    
    type = NULL;
    type = strstr(qr,"KHB");
    if (type !=  NULL){
        strcat(newQr,"00020101021");
        strcat(newQr,month);
        strcat(newQr,day);
        strcat(newQr,year);
        strcat(newQr,"KHB");
        strcat(newQr,newNumber);
        strcat(newQr,newName);
    }

    type= NULL;
    type= strstr(qr,"HBB");
    if(type !=NULL){
        strcat(newQr,"00020101021");
        strcat(newQr,newName);
        strcat(newQr,newNumber);
        strcat(newQr,year);
        strcat(newQr,month);
        strcat(newQr,day);
        strcat(newQr,"HBB");
    }

    int flag3=0;
    char alphabet[]="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";
    int offset = (11*strlen(newName))%62;
    char* case3=NULL;
    case3= strstr(mode3,"0");
    if (case3!=NULL){
        printf("%s",newQr);
        flag3=1;
    }
    case3=NULL;
    case3= strstr(mode3,"1");
    if (case3!=NULL){
        int temp2;
        char temp3;
        int newPos;
        for (int i=0;i<strlen(newQr);i++){
            temp2=newQr[i];
            if (temp2>=65 && temp2<=90){
                temp2=(temp2-65)*2;
            }
            else if (temp2>=97 && temp2<=122){
                temp2=(temp2-97)*2+1;
            }
            else{
                temp2= temp2-48+52;
            }
            newPos= (temp2+offset)%62;
            temp3=alphabet[newPos];
            printf("%c",temp3);
        }
        flag3=1;
    }
    if (flag3==0){
        printf("%s","Invalid encrypting parameters");
        return;
    }
    
}

int main(){
    int menu_code;
    scanf("%d", &menu_code);
    if(menu_code == 1) {
        checkInfoQR();
    } else if (menu_code == 2) {
        convertQR();
    } else {
        encryptQR();
    }
    return 0;
}
