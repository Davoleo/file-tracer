/*
    INTESTAZIONE
*/

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>


typedef struct {
    char filename[128];
    char root_dir[4];
    char curr_dir[512];
    char *ptr;
    char *result[1024];
    char separator[1];
    int result_index ;
} Folder;


void init(Folder *folder, const char* filename)
{
    // Initialize data
    memset(folder->result, 0, sizeof(folder->result));
    memset(folder->filename, '\0', sizeof(folder->filename));
    memset(folder->root_dir, '\0', sizeof(folder->root_dir));
    memset(folder->curr_dir, '\0', sizeof(folder->curr_dir));
    strcpy(folder->filename, filename);
    folder->result_index = 0;

    // Initialize directory based on the OS
#ifdef _WIN32
    strcat(folder->root_dir, "C:\\");
        strcat(folder->separator, "\\");
#elif __linux__ || __APPLE__
    strcat(folder->root_dir, "/");
        strcat(folder->separator, "/");
#endif

    strcpy(folder->curr_dir, folder->root_dir);
}


void find_file(Folder *folder)
{
    char directory[512];
    strcpy(directory, folder->curr_dir);
    /*
    If the directory points to the same o the prev
    directory the function retrun NULL
    */
    if(strchr(directory, '.') != NULL || strstr(directory, "..") != NULL || strchr(directory, '$') != NULL)
        return;

    DIR *dir;
    struct dirent *ent;

    // Try to open the directory
    if((dir = opendir(directory)) != NULL)
    {
        // Search in every sub-folder
        while((ent = readdir(dir)) != NULL)
        {
            if(strstr(ent->d_name, folder->filename) != NULL)
            {
                // Set the necessary space for the dir
                folder->result[folder->result_index] = malloc(strlen(directory) + strlen(ent->d_name) +1);
                // Assemble the dir string
                strcpy(folder->result[folder->result_index], directory);
                strcat(folder->result[folder->result_index], ent->d_name);
                // Increase the dir index
                folder->result_index++;
            }
            /*
            Create the string with the dir data
            to be passed to the recursive function
            */
            char temp[512] = "";

            strcat(temp, directory);
            strcat(temp, ent->d_name);
            strcat(temp, folder->separator);
            strcpy(folder->curr_dir, temp);
            // Start the search again with recursion
            find_file(folder);
        }
    }

    // Clear pointer data
    free(dir);
    free(ent);
}


// Print the result array
int print(Folder* folder)
{
    // Check if the array is non empty
    if(folder->result[0])
        // Print array data
        for(int i=0; i < folder->result_index; i++)
            printf("%s\n", folder->result[i]);
    else
        // If the array is empty return an error code
        return 1;

    return 0;
}



