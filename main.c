#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>

int numTabs = 0; 

void recurListing(char* path);
int main(int argc, char *argv[]){
    //TODO: check if there are two args
    //TODO: check if arg is actually a dir

    recurListing(argv[1]);
}

void recurListing(char* path){
    struct dirent *file;
    char newPath[1024];
    DIR* directory = opendir(path);

    if(!directory){
        return;
    }
    else{
        numTabs++;
    }
        

    while((file = readdir(directory)) != NULL){
        char tabs[256] = "";
        if((strcmp(file->d_name,".") != 0 && strcmp(file->d_name,"..") != 0)){ //ignore current dir and last dir
            
            
                for(int i = 0; i < numTabs; i++){
                    strcat(tabs," ");
                }
                printf("%s%s\n",tabs,file->d_name); //print tabs and then the file/dir name
                char newPath[strlen(path)+strlen("/")+strlen(file->d_name)]; 
                strcpy(newPath,path);
                strcat(newPath,"/");
                strcat(newPath,file->d_name);
                
                recurListing(newPath);
            
        }
        
    }
    numTabs = 0;

    
    


}

