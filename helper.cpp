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
};
