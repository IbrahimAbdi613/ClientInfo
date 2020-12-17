#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fd;
#define numOfClients 2

struct ClientCredentials{
    char name[20];
    int Age;
    char Gender[6];
};

void getCredentials (struct ClientCredentials *clientCredentials , int i){
    printf("\nClient Information for Client %d\n-------------------------------\n",i + 1);
    printf("Type your name : ");
    scanf("%s" ,clientCredentials->name);
    getchar();
    printf("How old are you : ");
    scanf("%d" ,&clientCredentials->Age);
    getchar();
    printf("Are you Male or Female: ");
    scanf("%s" ,clientCredentials->Gender);
    getchar();
}

 
void printToTxt(struct ClientCredentials *clientCredentials , int i ){
    fprintf(fd,"Client Information for Client %d\n-------------------------------\n" , i + 1);
    fprintf(fd, "The Client's Name is ");
    for (int i = 0; i < strlen(clientCredentials->name); i++){
       fprintf(fd, "%c" , clientCredentials->name[i]);
    }

    fprintf(fd, " who is a ");
    for (int i = 0; i < strlen(clientCredentials->Gender); i++){
       fprintf(fd, "%c" , clientCredentials->Gender[i]);
    }
    fprintf(fd, " and is %d years old \n\n", clientCredentials->Age);
}
int main(){
    fd = fopen("Clients_Credentials.txt", "w");
    if(!fd){
        printf("ERROR: could not open file\n");
    }
    struct ClientCredentials clientCredentials[numOfClients];
    for (int i = 0; i < numOfClients; i++){
        getCredentials(&clientCredentials[i] , i);
        printToTxt(&clientCredentials[i] , i);
    }

}