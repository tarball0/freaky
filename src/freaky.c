#include <locale.h>
#include <wchar.h>

#define FREAKY_UPPER 119951
#define FREAKY_LOWER 119945

void freakyprint(int, int, int, wchar_t *);

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");
    wchar_t istring[256];
	if (argc < 2) {
		wprintf(L"Usage: freaky [-f type] text");
	}

	else if (argc == 2) {
		int len = swprintf(istring, 256, L"%s", argv[1]);
		freakyprint(FREAKY_LOWER, FREAKY_UPPER, len, istring);
		wprintf(L"\n");
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
}
