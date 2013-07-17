/*
 * File        : dtags.c
 * Author      : Romain 'MicroJoe' Porte
 *
 * Description : Utility to manage dynamic tags with i3 WM such as renamming,
 *               navigating, etc.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cJSON.h>

#define BUF_SIZE 2048

int main(int argc, const char *argv[])
{
    char buffer[BUF_SIZE];
    size_t contentSize = 1;

    cJSON *root = NULL, *node = NULL, *name = NULL;

    /* Reading stdin */
    char *content = malloc(sizeof(char) * BUF_SIZE);
    if (content == NULL) {
        perror("Failed to allocate content");
        exit(1);
    }

    content[0] = '\0';

    while(fgets(buffer, BUF_SIZE, stdin))
    {
        char *old = content;
        contentSize += strlen(buffer);
        content = realloc(content, contentSize);
        if (content == NULL) {
            perror("Failed to reallocate content");
            free(old);
            exit(2);
        }
        strcat(content, buffer);
    }

    if (ferror(stdin)) {
        free(content);
        perror("Error reading from stdin.");
        exit(3);
    }

    /* Parsing JSON data */

    root = cJSON_Parse(content);
    node = root->child;

    do {
        name = cJSON_GetObjectItem(node, "name");
        printf("%s\n", name->valuestring);
    } while ((node = node->next) != NULL);

    cJSON_Delete(node);
    cJSON_Delete(root);

    return EXIT_SUCCESS;
}
