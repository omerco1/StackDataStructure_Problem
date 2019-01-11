
class Pcalc {  

public: 
    struct t_token {
    bool is_number; // true if number, false if operator (- + or ,)
    int num; // valid only if is_number is true
    char op; // valid only if is_number is false.
    int tok_len; // number of chars in the token
                // always =1 if is_number is false
                // otherwise, it contains the number of digits if is_number is true
    };

    // input s  pointer to the beginning og the next token text
    // output: fills the field of te struct pointed by tok
    void get_token(const char *s, t_token *tok);

    //TODO
    void parseIn(const char* a); 
};
