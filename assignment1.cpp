#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>

#define pi 3.14159265358979323846264338

using namespace std;

class rgb {
	private:
		int r,g,b;
	public:
		rgb()		{ r=0;g=0;b=0; }
		rgb(int Rin, int Gin, int Bin)	{ r=Rin;g=Gin;b=Bin; }
		void set_values(int,int,int);
		int getR();
		int getG();
		int getB();
//		int *vals()		{ return [r,g,b]; }
//		~rgb()		{ cout << “rgb deleted.\n”; }
};
void rgb::set_values (int Rin, int Gin, int Bin) {
	r = Rin;
	g = Gin;
	b = Bin;
}
int rgb::getR(){
	return r;
}
int rgb::getG(){
	return g;
}
int rgb::getB(){
	return b;
}
int randVal(int min, int max){
	return min + (rand() % static_cast<int>(max - min + 1));
}
/*void drawCircle(int x, int y, int r1, rgb image[int][int]){
	double counter = 1;
	double xcenter = x;
	double ycenter = y;
	double r = r1;
	double xit = xcenter+r*sin(counter*pi/180);
	double yit = ycenter+r*sin(counter*pi/180);
	while(xit!=xcenter and yit!=ycenter){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}
}*/
int main(void){
	int i,i2,j,j2,k,l;
	int a1, a2, b1, b2, c1, c2;
	int size = 800;
	srand(time(NULL));

	// make matrix of image pixel values
	printf("P3 800 800 1\n");

	rgb image[size][size];
	for (j=0;j<size;j++){
		for (j2=0;j2<size;j2++){
			image[j][j2] = rgb();
		}
	}

	// assign random points of triangle
	a1 = randVal(0,size);b1 = randVal(0,size);c1 = randVal(0,size);a2 = randVal(0,size);b2 = randVal(0,size);c2 = randVal(0,size);
	//a1 = 100;a2 = 100;b1 = 10;b2 = 700;c1 = 700;c2 = 700;

	// checking for colinearity
	while(b1==a1 and a1==c1){	b1 = randVal(0,size); }
	while(a2==c2 and c2==b2){	
		c1 = randVal(0,size);
		while((a2==b2 and a1==b1) or (c2==b2 and c1==b1)){
			b1 = randVal(0,size);
		}
	}
	//printf("a1: %d\n",a1);	printf("b1: %d\n",b1);	printf("c1: %d\n",c1);
	//printf("a2: %d\n",a2);	printf("b2: %d\n",b2);	printf("c2: %d\n",c2);
	
	image[a1][a2].set_values(1,0,0);
	image[b1][b2].set_values(0,1,0);
	image[c1][c2].set_values(0,0,1);


	//bresenham for triangle

	// x1, x2, y1, y2
	int allvals[] = {a1,a2,c1,c2, b1,b2,c1,c2, a1,a2,b1,b2};
	for (i = 0; i < 3; i++){
		int it = i*4;
		int x1 = allvals[it];
		int x2 = allvals[it+2];
		int y1 = allvals[it+1];
		int y2 = allvals[it+3];

// >>>:(

		double trials = 1000.0;
		double xslope = (x2-x1)/trials;
		double yslope = (y2-y1)/trials;
		for (int iter = 0; iter < 1000; iter++){
			image[(int)(x1+xslope*iter)][(int)(y1+yslope*iter)].set_values(1,1,1);
		}

		/*if (x1>x2){
			int temp = x1;
			x1 = x2;
			x2 = temp;
			int temp2 = y1;
			y1 = y2;
			y2 = temp2;
		}
// >:(
		
		double currx = x1;
		double curry = y1;
		/*if ((y2-y1)==0){
			if (x1>x2){
				int temp = x1;
				x1 = x2;
				x2 = temp;
				int temp2 = y1;
				y1 = y2;
				y2 = temp2;
			}
			currx = x1;
			curry = y1;
			while(curry<y2){
				image[(int)currx][(int)curry].set_values(1,1,1);
				curry++;
			}
		}
		else{
			int m = (y2-y1)/(x2-x1);
			while (currx<x2)
			{
				image[(int)currx][(int)curry].set_values(1,1,1);
				currx++;
				curry = m*currx + curry;
			}
		}*/
/*		int x = x1;
		int y = y1;

		int deltax = x2-x1;
		int deltay = y2-y1;
		int p = 2*deltay-deltax;
		
		while(x<x2)
		{
			if(p>=0)
			{
				image[x][y].set_values(1,1,1);
				y++;
				p = p + 2*deltay - 2*deltax;
			}
			else
			{
				image[x][y].set_values(1,1,1);
				p = p + 2*deltay;
			}
			x++;
		}
		/*
		double m = (double)deltay/deltax;
		int j = allvals[it+2];
		double e = m-1.0;
		
		for (l=x1; l<x2; l++){
			image[l][j].set_values(1,1,1);
			if(e>=0){
				j += 1;
				e -= 1.0;
			}
			//end if?
			e += m;
		}*/
	}


	//print circle
	/*double counter = 1;
	double xcenter = 400;
	double ycenter = 400;
	double r = 200;
	double xit = xcenter+r*sin(counter*pi/180);
	double yit = ycenter+r*cos(counter*pi/180);
	double xinit = xcenter+r*sin(0);
	double yinit = ycenter+r*cos(0);
	while(xit!=xinit or yit!=yinit){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}*/

	
	int xincircle, yincircle;
	//find ab midpoint
	double ab_xmid = (a1+b1)/2.0;
	double ab_ymid = (a2+b2)/2.0;
	/*//find bc midpoint
	int bc_xmid = (int)(b1+c1)/2;
	int bc_ymid = (int)(b2+c2)/2;

	if((b2-a2)==0){
		xincircle = ab_xmid;
		yincircle = -1*((c1-b1)/(c2-b2))*(xincircle-bc_xmid)+bc_ymid;
	}
	else if((c2-b2)==0){
		yincircle = bc_ymid;
		xincircle = (yincircle-ab_ymid)/(-1*((b1-a1)/(b2-a2))+ab_xmid);
	}
	else
	{
		//slopes
		double ab_mid_slope = -1*((b1-a1)/(b2-a2));
		double bc_mid_slope = -1*((c1-b1)/(c2-b2));
		//find intersection
		xincircle = (int)(ab_mid_slope*ab_xmid-ab_ymid-bc_mid_slope*bc_xmid+bc_ymid)/(ab_mid_slope-bc_mid_slope);
		yincircle = (int)(ab_mid_slope*(xincircle-ab_xmid)+ab_ymid);
	}*/
	
	//test lines
	/*double trials = 1000.0;
	double xslope = (x2-x1)/trials;
	double yslope = (y2-y1)/trials;
	for (int iter = 0; iter < 1000; iter++){
		image[(int)(x1+xslope*iter)][(int)(y1+yslope*iter)].set_values(1,1,1);
	}
	double trials = 1000.0;
	double xslope = (x2-x1)/trials;
	double yslope = (y2-y1)/trials;
	for (int iter = 0; iter < 1000; iter++){
		image[(int)(x1+xslope*iter)][(int)(y1+yslope*iter)].set_values(1,1,1);
	}*/



	
	//INCIRCLE!!!!!!!!!!!!1

	double ABlen = sqrt((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2));
	double BClen = sqrt((b1-c1)*(b1-c1)+(b2-c2)*(b2-c2));
	double AClen = sqrt((c1-a1)*(c1-a1)+(c2-a2)*(c2-a2));
	
	xincircle = (ABlen*c1 + BClen*a1 + AClen*b1)/(AClen + BClen + ABlen);
	yincircle = (ABlen*c2 + BClen*a2 + AClen*b2)/(AClen + BClen + ABlen);
	double area = abs( (a1*(b2-c2)+b1*(c2-a2)+c1*(a2-b2)) /2 );
	double perimeter = (ABlen+BClen+AClen);
	double radius_incircle = area * 2 / perimeter;
//sqrt((xincircle-ab_xmid)*(xincircle-ab_xmid)+(yincircle-ab_ymid)*(yincircle-ab_ymid));


	double counter = 1;
	double xcenter = xincircle;
	double ycenter = yincircle;
	double r = radius_incircle;
	double xit = xcenter+r*sin(counter*pi/180);
	double yit = ycenter+r*cos(counter*pi/180);
	double xinit = xcenter+r*sin(0);
	double yinit = ycenter+r*cos(0);
	while(xit!=xinit or yit!=yinit){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}




	//CIRCUMCIRCLE!!!!!!!!!

	double D = 2*(a1*(b2-c2)+b1*(c2-a2)+c1*(a2-b2));
	double xcircumcircle = 1/D*( (a1*a1+a2*a2) * (b2-c2) + (b1*b1+b2*b2) * (c2-a2) + (c1*c1+c2*c2) * (a2-b2) );
	double ycircumcircle = 1/D*( (a1*a1+a2*a2) * (c1-b1) + (b1*b1+b2*b2) * (a1-c1) + (c1*c1+c2*c2) * (b1-a1) );
	double radius_circumcircle = sqrt((xcircumcircle-a1)*(xcircumcircle-a1)+(ycircumcircle-a2)*(ycircumcircle-a2));




	counter = 1;
	xcenter = xcircumcircle;
	ycenter = ycircumcircle;
	r = radius_circumcircle;
	xit = xcenter+r*sin(counter*pi/180);
	yit = ycenter+r*cos(counter*pi/180);
	xinit = xcenter+r*sin(0);
	yinit = ycenter+r*cos(0);
	while(xit!=xinit or yit!=yinit){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		if((int)xit<800 and (int)yit<800 and (int)xit>0 and (int)yit>0)image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}



	//centroid as part of the euler line
	double xcentroid = (a1+b1+c1)/3.0;
	double ycentroid = (a2+b2+c1)/3.0;
	
	//euler line
	double eulerslope = (ycentroid-ycircumcircle)/(xcentroid-xcircumcircle);
	
	double xstart = 0;
	double ystart = eulerslope*(xstart-xcentroid)+ycentroid;
	double xend = 800;
	double yend = eulerslope*(xend-xcentroid)+ycentroid;
	
	double trials = 1000.0;
	double xslope = (xend-xstart)/trials;
	double yslope = (yend-ystart)/trials;
	for (int iter = 0; iter < 1000; iter++){
		int xeuler = (int)(xstart+xslope*iter);
		int yeuler = (int)(ystart+yslope*iter);
		if(xeuler<800 and yeuler<800 and xeuler>0 and yeuler>0)image[xeuler][yeuler].set_values(1,1,1);
	}



	//PERPENDICULAR OF AB
	/*double trials = 1000.0;
	int x1 = ab_xmid;
	int y1 = ab_ymid;
	int x2 = x1+-1*((b1-a1)/(b2-a2))*1000;
	int y2 = y1+1/(-1*((b1-a1)/(b2-a2)))*1000;
	double xslope = (x2-x1)/trials;
	double yslope = (y2-y1)/trials;
	for (int iter = 0; iter < 1000; iter++){
		image[(int)(x1+xslope*iter)][(int)(y1+yslope*iter)].set_values(1,1,1);
	}*/
	/*//MIDPOINT OF BC
	counter = 1;
	xcenter = bc_xmid;
	ycenter = bc_ymid;
	r = 10;
	xit = xcenter+r*sin(counter*pi/180);
	yit = ycenter+r*cos(counter*pi/180);
	xinit = xcenter+r*sin(0);
	yinit = ycenter+r*cos(0);
	while(xit!=xinit or yit!=yinit){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}
	//MIDPOINT OF AB
	counter = 1;
	xcenter = ab_xmid;
	ycenter = ab_ymid;
	r = 10;
	xit = xcenter+r*sin(counter*pi/180);
	yit = ycenter+r*cos(counter*pi/180);
	xinit = xcenter+r*sin(0);
	yinit = ycenter+r*cos(0);
	while(xit!=xinit or yit!=yinit){
		xit = xcenter+r*sin(counter*pi/180);
		yit = ycenter+r*cos(counter*pi/180);
		image[(int)xit][(int)yit].set_values(1,1,1);
		counter++;
	}*/




	// print to ppm file using ./a.out > assignment1.ppm
	for (i = 0; i < size; i++) {
		for (i2=0;i2<size;i2++){
			//printf("%c%c%c", 255, 255, 255);
			printf("%d %d %d ", image[i][i2].getR(), image[i][i2].getG(), image[i][i2].getB());
		}
	}
	return 0;
}
