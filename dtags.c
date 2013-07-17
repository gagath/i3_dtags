#include <stdio.h>
#include <stdlib.h>

#include <cJSON.h>

#define BUF_SIZE 2048

int main(int argc, const char *argv[])
{
    char buffer[BUF_SIZE];
    cJSON *root = NULL, *node = NULL, *name = NULL;

    fgets(buffer, BUF_SIZE, stdin);

    root = cJSON_Parse(buffer);
    node = root->child;

    do {
        name = cJSON_GetObjectItem(node, "name");
        printf("%s\n", name->valuestring);
    } while ((node = node->next) != NULL);

    cJSON_Delete(node);
    cJSON_Delete(root);

    return EXIT_SUCCESS;
}
