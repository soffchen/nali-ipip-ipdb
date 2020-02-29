#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include "ipdb.h"
#include "config.h"

int main(int argc, char *argv[])
{
    ipdb_reader *reader;
    int err = ipdb_reader_new(IPIPDB_PATH, &reader);

    if (!err) {
        char *ip;
        if (argc != 2) {
            ip = (char *)malloc(128);
            ip = fgets(ip, 128, stdin);
        } else {
            ip = argv[1];
        }

        char body[512], last[64], tmp[64];

        err = ipdb_reader_find(reader, ip, "CN", body);

        if (err) return 1;

        int f = 0, p1 = 0, p2 = -1;
        do {
            if (f > 4) break;
                if (*(body + p1) == '\t' || !*(body + p1)) {
                    strncpy(tmp, body + p2 + 1, (size_t) p1 - p2);
                    tmp[p1 - p2 - 1] = 0;
                    
                    if (strcmp(last, tmp)) {
                        printf("%s", tmp);

                        if (f < 4 && strlen(tmp) > 0) {
                            printf(" ");
                        }
                    }

                    strcpy(last, tmp);
                    p2 = p1;
                    ++f;
                }
            } while (*(body + p1++));

        printf("\n");
    }
    else {
        printf("new ipdb reader err: %d\n", err);
        return 1;
    }

    ipdb_reader_free(&reader);

    return 0;
}

