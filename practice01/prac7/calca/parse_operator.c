char parse_operator(const char* str, int* i) {
    while (str[*i] == ' ') (*i)++;
    char op = str[*i];
    if (op != '\0') (*i)++;
    return op;
}
