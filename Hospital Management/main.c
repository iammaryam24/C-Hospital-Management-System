// Hospital Management System (simple file-based records)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FNAME "patients.dat"


typedef struct {
int id;
char name[50];
int age;
char disease[50];
} Patient;


void addPatient(){
Patient p;
FILE *fp = fopen(FNAME, "ab");
if(!fp){ perror("File"); return; }
printf("Enter ID: "); scanf("%d", &p.id);
printf("Name: "); scanf(" %49[^"]", p.name);
printf("Age: "); scanf("%d", &p.age);
printf("Disease: "); scanf(" %49[^"]", p.disease);
fwrite(&p, sizeof(Patient), 1, fp);
fclose(fp);
printf("Patient added.\n");
}


void listPatients(){
Patient p;
FILE *fp = fopen(FNAME, "rb");
if(!fp){ printf("No records found.\n"); return; }
printf("ID\tName\tAge\tDisease\n");
while(fread(&p, sizeof(Patient),1,fp)){
printf("%d\t%s\t%d\t%s\n", p.id, p.name, p.age, p.disease);
}
fclose(fp);
}


void searchPatient(){
int id; printf("Enter ID to search: "); scanf("%d", &id);
Patient p; FILE *fp = fopen(FNAME, "rb"); if(!fp){ printf("No records.\n"); return; }
while(fread(&p,sizeof(Patient),1,fp)) if(p.id==id){
printf("Found: %d %s %d %s\n", p.id,p.name,p.age,p.disease); fclose(fp); return;
}
printf("Not found.\n"); fclose(fp);
}


int main(){
int ch;
while(1){
printf("\nHospital Management\n1.Add 2.List 3.Search 4.Exit\nChoice: ");
if(scanf("%d", &ch)!=1) break;
switch(ch){
case 1: addPatient(); break;
case 2: listPatients(); break;
case 3: searchPatient(); break;
case 4: exit(0);
default: printf("Invalid\n");
}
}
return 0;
}