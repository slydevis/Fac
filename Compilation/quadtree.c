void Q(int x0, int y0, int t) {
	if(uc == '(') {
		uc = yylex();
		Q(x0, y0 + t/2, t/2);
		
		if(uc == ',') {
			uc = yylex();
			Q(x0 + t/2, y0, t/2);
			if(uc == ',') {
				uc = yylex();
				Q(x0, y0, t/2);
				if(uc == ',') {
					uc = yylex();
					Q(x0 + t/2, y0, t/2);
					if(uc == ')') {
						uc = yylex();
					}
				}
			}
		}
	}
	else {
		if(uc <= 'z' && uc >= 'a') {
			printf("RECT %d %d %d %d %c\n", x0, y0, x0 + t, y0 + t, uc);
			uc = yylex();
		}
		else { printf("Error !!!!!\n"); exit(1); }
	}
}
