#include <stdio.h>
#include <stdlib.h>

FILE *fd;
#define numOfClients 4

struct ClientCredentials{
    char name[20];
    int Age;
    char Gender[6];
};

void getCredentials (struct ClientCredentials *clientCredentials , int i){
    printf("\nClient Information for Client %d\n-------------------------------\n",i + 1);
    printf("Type your name : ");
    scanf("%20s" ,clientCredentials->name);
    getchar();
    printf("How old are you : ");
    scanf("%d" ,&clientCredentials->Age);
    getchar();
    printf("Are you Male or Female: ");
    scanf("%6s" ,clientCredentials->Gender);
    getchar();
}


void printToTxt(struct ClientCredentials *clientCredentials , int i ){
    fprintf(fd,"Client Information for Client %d\n-------------------------------\n" , i + 1);
    fprintf(fd, "The Client's Name is %-10s who is a %-6s and %d years old \n\n",clientCredentials->name, clientCredentials->Gender, clientCredentials->Age);
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