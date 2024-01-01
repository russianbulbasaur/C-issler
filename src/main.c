#include <string.h>
#include <stdio.h>
#include "object.c"
void serialize(struct Student student,FILE* file);
struct Student deserialize(FILE* file);
void main(int argc,char* argv[]){
    struct Student student;
    strcpy(student.name, "Akshita");
    student.age = 21;

    FILE* file = fopen("temp.o","w+");
    if(file==NULL){
       printf("File reading error\n");
       return;
    }
    serialize(student,file);
    file = fopen("temp.o","r");
    struct Student deserializedStudent = deserialize(file);
    printf("Name : %s\n",deserializedStudent.name);
    printf("Age : %i\n",deserializedStudent.age);
}


void serialize(struct Student student,FILE* file){
     int size = sizeof(struct Student);
     printf("Object size: %i\n",size);
     printf("Name : %s\n",student.name);
     printf("Age : %i\n",student.age);
     fwrite(&student,sizeof(student),1,file);
     fclose(file);
}


struct Student deserialize(FILE* file){
     struct Student newStudent;
     printf("New object size : %i\n",sizeof(newStudent));
     fread(&newStudent,sizeof(newStudent),1,file);
     fclose(file);
     return newStudent;
}
