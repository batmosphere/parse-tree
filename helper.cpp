class Helper {
public:
	void reverse(char *p)
	{
		char *q = p;
		while (q && *q) ++q;
		for (--q; p < q; ++p, --q)
			*p = *p ^ *q,
			 *q = *p ^ *q,
			  *p = *p ^ *q;
	}

	bool haschar(char* str, char ch){
		int length = strlen(str);
		for (int i=0;i<length;i++){
			if(str[i]==ch){
				return true;
			}
		}
		return false;
	}
};
