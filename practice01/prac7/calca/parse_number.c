int parse_number(const char* str, int* i) {
    int res = 0;
    int sign = 1;
    while (str[*i] == ' ') (*i)++; 
    if (str[*i] == '-') {
        sign = -1;
        (*i)++;
    }
    while (str[*i] >= '0' && str[*i] <= '9') {
        res = res * 10 + (str[*i] - '0');
        (*i)++;
    }
    return res * sign;
}
