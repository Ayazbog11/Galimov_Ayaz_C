int evaluate(const char* expr) {
    int i = 0;
    int total_res = 0;
    char last_op = '+'; 
    int term = parse_number(expr, &i);
    while (expr[i] != '\0' && expr[i] != '\n') {
        char op = parse_operator(expr, &i);
        if (op == '\0') break;
        int next_val = parse_number(expr, &i);
        if (op == '*' || op == '/') {
            term = apply(term, next_val, op);
        } 
        else {
            total_res = apply(total_res, term, last_op);
            term = next_val;
            last_op = op; 
        }
    }
    return apply(total_res, term, last_op);
}
