//Temp TXT FILE FOR CODE REMOVED
[a-zA-Z_][a-zA-Z0-9_]* {
	/* Identifiers */
	ident2ast(yytext);
	return IDENT;
}

[0-9]+ {
	/* Numbers */
	unsigned int val = atoi(yytext);
	if (val > UINT_MAX) {
		fprintf(stderr, "%s:%d: Number %s exceeds the maximum allowed value\n", filename, yylineno, yytext);
		return YYerror;
	}
	number2ast(val);
	return NUMBER;
}


[ \t\n\r] { /* Ignore whitespace */ }

. { /* Unrecognized character */
	fprintf(stderr, "%s:%d: Unrecognized character: %s\n", filename, yylineno, yytext);
	errors_noted = true;
}