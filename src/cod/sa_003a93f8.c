__attribute__((section(".text.func_003A93F8")))
char *func_003A93F8(char *s, char *p)
{
    int i;

    if (*s == 0) {
        if (*p != 0)
            return 0;
        return s;
    }
    while (*s != 0) {
        for (i = 0; ; i++) {
            if (p[i] == 0)
                return s;
            if (p[i] != s[i])
                break;
        }
        s++;
    }
    return 0;
}
