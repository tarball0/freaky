#include <locale.h>
#include <wchar.h>

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");
    wchar_t istring[256];
    int len = swprintf(istring, 256, L"%s", argv[1]);
    int offset;

    for (int i = 0; i < len; i++) {
        if (istring[i] >= 65 && istring[i] <= 90) {
            offset = 119951;
        } else {
            offset = 119945;
        }

        if (istring[i] == 32) {
            wprintf(L" ");
            continue;
        }

        istring[i] += offset;
        wprintf(L"%lc", istring[i]);
    }

    wprintf(L"\n");

    return 0;
}
