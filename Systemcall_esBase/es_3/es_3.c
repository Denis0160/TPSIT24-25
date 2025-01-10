#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void ordinaArgomenti(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        for (int j = i + 1; j < argc; j++)
        {
            if (strlen(argv[i]) > strlen(argv[j]))
            {

                char *temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Numero argomenti sbagliato\n");
        return 1;
    }

    ordinaArgomenti(argc, argv);

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    for (int i = 2; i < argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", 1);
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", 1);
    }

    close(fd);
    return 0;
}
