#include <stdio.h>

int main(){
}

//This function is called when 20-sim attaches the dll.
int Initialize(){
	FILE* f = fopen("log.txt","a");
	fprintf(f, "Init\n");
	fclose(f);

}

//This function is called when 20-sim detaches the dll.
int Terminate(){
	FILE* f = fopen("log.txt","a");
	fprintf(f, "Term\n");
	fclose(f);

}

//called at the start of a simulation run
int InitializeRun(){
	FILE* f = fopen("log.txt","a");
	fprintf(f, "InitRun\n");
	fclose(f);

}

//called at the end of a simulation run
int TerminateRun(){
	FILE* f = fopen("log.txt","a");
	fprintf(f, "TermRun\n");
	fclose(f);

}

int myFunction(double* inarr, int inputs, double* outarr, int outputs, int major){
	//let's assume input is [time, x]
	//output is [x+time]
	FILE* f = fopen("log.txt","a");
	fprintf(f, "-myFunction called\n");
	fclose(f);
	outarr[0] = inarr[1]+inarr[0];
	return(0);
}