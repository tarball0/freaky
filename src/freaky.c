#include <locale.h>
#include <wchar.h>

#define FREAKY_UPPER 119951
#define FREAKY_LOWER 119945
#define SANANDREAS_LOWER 120101
#define SANANDREAS_UPPER 120107

void freakyprint(int, int, int, wchar_t *);
void printusage();

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");
    wchar_t istring[256];
    int len;
    if (argc < 2) {
        printusage();
    }

    else if (argc == 2) {
        len = swprintf(istring, 256, L"%s", argv[1]);
        freakyprint(FREAKY_LOWER, FREAKY_UPPER, len, istring);
    }

    else if (argc == 4) {
        wchar_t input_flag[16];
        wchar_t formatting[16];
        swprintf(input_flag, 16, L"%s", argv[1]);

        if (wcscmp(input_flag, L"-f") == 0) {
            swprintf(formatting, 16, L"%s", argv[2]);
            if (wcscmp(formatting, L"sanandreas") == 0) {
                len = swprintf(istring, 256, L"%s", argv[3]);
                freakyprint(SANANDREAS_LOWER, SANANDREAS_UPPER, len, istring);
            } else {
            }

        } else {
            printusage();
        }
    }

    else {
        printusage();
    }

    return 0;
}

void freakyprint(int offset_lower, int offset_upper, int len,
                 wchar_t *istring) {

    for (int i = 0; i < len; i++) {
        if (istring[i] >= 65 && istring[i] <= 90) {
            wprintf(L"%lc", istring[i] + offset_upper);
        }

        else if (istring[i] == 32) {
            wprintf(L" ");
            continue;
        }

        else {
            wprintf(L"%lc", istring[i] + offset_lower);
        }
    }
    wprintf(L"\n");
}

void printusage() { wprintf(L"Usage: freaky [-f type] text"); }
