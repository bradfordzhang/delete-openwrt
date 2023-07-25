#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

void checkIfThursday() {
    time_t timer;
    struct tm *Now;
    time(&timer);
    Now = localtime(&timer);
    if ((*Now).tm_wday + 1 != 4) {
        printf("Not Thursday");
        exit(0);
    }
}

void delete_dir(const char *dir_path) {
    char cmd[512];
    sprintf(cmd, "sudo rm -rf %s", dir_path);
    system(cmd);
}

int main() {
    checkIfThursday();
    FILE *index = NULL;
    index = fopen("/var/www/openwrt/self/index.text", "r+");
    char date[50], file[150], week;
    while (fscanf(index, "%s %c %s", date, &week, file) != EOF) {
        if (!(date[0] == '0' && date[1] == '1') || (strstr(file, "snapshot") != NULL)) {
            char filepath[512];
            sprintf(filepath, "/var/www/openwrt/self/%s\n", file);
            delete_dir(filepath);
        }
    }
    fclose(index);
    index = fopen("/var/www/openwrt/self/index.text", "w");
    fclose(index);
    return 0;
}
