double myrandd(void){
	static int ri = 1;
	double rr;
	ri = ri * 48828125 + 19;
	if(ri < 0)
		ri = (ri + 2147483647) + 1;
	rr = (double) ri * 0.4656613e-9;
	return rr;
}
