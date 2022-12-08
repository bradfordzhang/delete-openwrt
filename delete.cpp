#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    freopen("/var/www/openwrt/self/index.text", "r", stdin);
    char date[10], file[50], week;
    while (scanf("%s %c %s", date, &week, file) != EOF) {
        if ( !(date[0] == '0' && date[1] == '1') && (strstr(file, "-v")==NULL ) ) {
            string tmp = file;
            cout << "sudo rm -rf /var/www/openwrt/self/" + tmp << endl;
        }
    }
    return 0;
}
