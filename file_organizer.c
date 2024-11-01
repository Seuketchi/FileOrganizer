#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>


//Folder titles
const char *folders[] = {
    "Images",
    "Documents",
    "Audio",
    "Video",
    "Code",
    "Archives",
    "Others"
};

int moved_counter = 0;
int error_counter = 0;

//Make directory
void create_directory(const char *folder) {
    struct stat st = {0}; //system call to check files/directory
    if(stat(folder, &st) == -1) //indicates directory doesn't exist
        mkdir(folder,0700);


    }

//Move file
void move_file(const char *filename, const char *dest_folder) {
    int duplicate_counter = 1;

    //store new path to dest_path
    char dest_path[512]; //common value for buffer [512]
    snprintf(dest_path,sizeof(dest_path), "%s/%s", dest_folder,filename);

    //check for duplicates
    while(access(dest_path, F_OK) == 0){ //checks if file already exist in the dest_folder
        snprintf(dest_path,sizeof(dest_path), "%s/%s_%d", filename,dest_folder, duplicate_counter++);
    }
    
    if(rename(filename, dest_path) == 0) {
        printf("MOVED: %s -> %s\n", filename, dest_folder);
        moved_counter++;
    } else {
        printf("Error moving file: %s\n",filename);
        error_counter++;
    }
}

//Categorize file
void categorize_file(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    chdir(directory);

    while((entry = readdir(dp)) != NULL) {
        if(entry->d_type == DT_REG) { //check if file is a regular file
            char *ext = strrchr(entry->d_name, '.');
            if(ext) {
                ext++;

                if(strstr("jpg jpeg png gif bmp tiff svg",ext)){
                    move_file(entry->d_name,folders[0]);
                } else if (strstr("pdf doc docx txt rtf odt xls xlsx ppt pptx", ext)) {
                    move_file(entry->d_name, folders[1]);
                } else if (strstr("mp3 wav wma flac m4a aac", ext)) {
                    move_file(entry->d_name, folders[2]);
                } else if (strstr("mp4 avi mkv mov wmv flv", ext)) {
                    move_file(entry->d_name, folders[3]);
                } else if (strstr("py js html css cpp cs java php", ext)) {
                    move_file(entry->d_name, folders[4]);
                } else if (strstr("zip rar 7z tar gz", ext)) {
                    move_file(entry->d_name, folders[5]);
                } else {
                    move_file(entry->d_name, folders[6]);
                }
            }
        }
    }
    closedir(dp);
}

int main() {
    printf("FILE ORGANIZER\n");
    printf("----------------\n");

    char cwd[1024];

    for (int i = 0; i < sizeof(folders) / sizeof(folders[0]); i++)
    {
        create_directory(folders[i]);
    }


    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1; // Exit if there is an error
    }

    printf("Starting file organization...\n\n");
    categorize_file(".");

    printf("Organization Complete!\n");
    printf("Files moved successfully: %d\n", moved_counter);
    printf("Errors encountered: %d\n",error_counter);
    
    
    return 0;
}
