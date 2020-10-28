/*
********************************************************************************************************
						PROJECT #3: TETRIS IN C++
********************************************************************************************************

				PROGRAMMERS:			  SAEEDE MALEKAN & FATEMEH SHAHRABADI
				STUDENT NUMBER:			9331077  & 9331068
				FIELD OF STUDY:			SOFTWANE COMPUTER ENGINEERING

*********************************************************************************************************

*/

//library functions
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int far *scr=(int far*) 0xb8000000;
int D=0,/* IF ALL OF ONE LINE FILLS WHIT SHAPES */p,k=0, /* COLOR OF THE SHAPES*/co,/* o & v & w & l ARE PARTS OF SHAPE*/o,v,w,l,/* WE HAVE FOUR SHAPES RANDOM*/shape,xx=0,oo,/* THESE ARE FOR CHANGING THE SHAPE FROM SHAPE 4 TO SHAPE 1*/tt=0,hh=0,ww=0,vv=0,ff=0;
signed int /* MOVE THE SHAPE RIHT OR LEFT*/ z=0;
// THE LOCATION OF 4 SHAPES THAT CHANGES WHIT Z
int oh[5],vh[5],wh[5],lh[5];
// GAME OVER PAGE
void init2() {
	clrscr();
	for(int j=0;j<2000;j++)
		*(scr+j)=0x77*256+32;
	*(scr+10*80+35)=0x07*256+1;
	*(scr+10*80+36)=0x07*256+'g';
	*(scr+10*80+37)=0x07*256+'a';
	*(scr+10*80+38)=0x07*256+'m';
	*(scr+10*80+39)=0x07*256+'e';
	*(scr+10*80+40)=0x07*256+' ';
	*(scr+10*80+41)=0x07*256+'o';
	*(scr+10*80+42)=0x07*256+'v';
	*(scr+10*80+43)=0x07*256+'e';
	*(scr+10*80+44)=0x07*256+'r';
	*(scr+10*80+45)=0x07*256+2;
}

	init()
	 {
		for (int i=0 ; i<2000 ; i++)
		*(scr+i)=0x77*256+32;
	 }

 // SHAP PREDICTION
void shap(shape)
{
   for(int o=0 ;o<241 ;o++)
   *(scr+o)=0x77*256+32;
	if(shape==0)
	{
	*(scr+0)=0x32*256+32;
	*(scr+1)=0x32*256+32;
	*(scr+80)=0x32*256+32;
	*(scr+81)=0x32*256+32;
	}
	if(shape==1)
	{
	*(scr+0)=0x32*256+32;
	*(scr+80)=0x32*256+32;
	*(scr+160)=0x32*256+32;
	*(scr+161)=0x32*256+32;
	}

	if(shape==2)
	{
	*(scr+0)=0x32*256+32;
	*(scr+80)=0x32*256+32;
	*(scr+160)=0x32*256+32;
	*(scr+240)=0x32*256+32;
	}
	if(shape==3)
	{
	*(scr+0)=0x32*256+32;
	*(scr+1)=0x32*256+32;
	*(scr+81)=0x32*256+32;
	*(scr+82)=0x32*256+32;
	}

	}
char funky(int &i)
			{
	char c=getch();
	if(c==0) {
		i=1;
		c=getch();
		 }
	else
		i=0;
	return(c);

			}


move()
	{ if (D==0)
	  {
	int/*FOR CHOSING COLOR OF THE SHAPES RANDOM */ i=0,/* FOR MOVING LESS THAN 23 ACTION*/t=0;
     /* WHEN BELOW THE SHAP IS NOT ANY THING COUNTINUE MOVING*/	int fs=0;
	i=random(7);
	if(i==1)
	co=0x07;
	if(i==2)
	co=0x17;
	if(i==3)
	co=0x27;
	if(i==4)
	co=0x37;
	if(i==5)
	co=0x47;
	if(i==6)
	co=0x57;
	if(i==7)
	co=0x67;
	if(shape==0)
	{    shape=random(4);
	shap(shape);
		 z=0;
		o=40;
		v=41;
		w=120;
		l=121;

		while(fs==0)

		{   if(t>22)
		break;
			  *(scr+o+z+t*80)=0x77*256+32;
			  *(scr+v+z+t*80)=0x77*256+32;
			  *(scr+w+z+t*80)=0x77*256+32;
			   *(scr+l+z+t*80)=0x77*256+32;
			    /* IF BELOW THE SHAP IS ANOTHER SHAP STOP MOVING BY CHANGING VALUE OF THE FS */
			 if(*(scr+o+z+(t+1)*80)!=0x77*256+32 || *(scr+v+z+(t+1)*80)!=0x77*256+32 || *(scr+w+z+(t+1)*80)!=0x77*256+32 || *(scr+l+z+(t+1)*80)!=0x77*256+32)
			 {
				*(scr+o+z+t*80)=co*256+32;
				*(scr+v+z+t*80)=co*256+32;
				 *(scr+w+z+t*80)=co*256+32;
				  *(scr+l+z+t*80)=co*256+32;
				 fs=1;
				 break;
			 }     /* ELSE COUNTINUE MOVING*/
				  else
				 {
				 *(scr+o+z+(t+1)*80)=co*256+32;
				  *(scr+v+z+(t+1)*80)=co*256+32;
				 *(scr+w+z+(t+1)*80)=co*256+32;
				  *(scr+l+z+(t+1)*80)=co*256+32;
				 }
				   delay(100);
				  t++;
				 if(kbhit())
			{
			  char c=funky (i);
			  // IF YOU WHANT GO RIGHT OR LEFT
				if(c=='M'  && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				 *(scr+v+z+t*80)=0x77*256+32;
				 *(scr+w+z+t*80)=0x77*256+32;
				 *(scr+l+z+t*80)=0x77*256+32;
				 // IF SHAP'S RIGHT IS ANOTHER SHAPE DONT MOVE
				 if(*(scr+o+z+1+(t)*80)!=0x77*256+32 || *(scr+v+z+1+(t)*80)!=0x77*256+32 || *(scr+w+z+1+(t)*80)!=0x77*256+32 || *(scr+l+z+1+(t)*80)!=0x77*256+32)
			      z=z;
			      else
				z++;
				}
				if(c=='K'&& fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				if(*(scr+o+z-1+(t)*80)!=0x77*256+32 || *(scr+v+z-1+(t)*80)!=0x77*256+32 || *(scr+w+z-1+(t)*80)!=0x77*256+32 || *(scr+l+z-1+(t)*80)!=0x77*256+32)
				z=z;
			      else
				z--;
				}

			}

		}
		 /*  IF THE SHAPE COME UP AND COUDENT MOVE GAME IS OVER:"(*/
		if(t==1)
		init2();
		}
	      if(shape==1)
	       {shape=random(4);
		shap(shape);
		tt=0;
		z=0;
	       oh[0]=-40;
	       oh[1]=119;
	       oh[2]=120;
	       oh[3]=120;
	       oh[4]=-40;
	       vh[0]=40;
	       vh[1]=120;
	       vh[2]=40;
	       vh[3]=40;
	       vh[4]=40;
	       wh[0]=120;
	       wh[1]=121;
	       wh[2]=-40;
	       wh[3]=41;
	       wh[4]=120;
	       lh[0]=121;
	       lh[1]=41;
	       lh[2]=-41;
	       lh[3]=42;
	       lh[4]=121;
	       o=oh[3];
	       v=vh[3];
	       w=wh[3];
	       l=lh[3];
		while(fs==0)
		{   if(t>22)
			break;

		   if(hh==1)
			{
			tt=0;
			hh=0;
			}
			  *(scr+o+z+t*80)=0x77*256+32;
			  *(scr+v+z+t*80)=0x77*256+32;
			  *(scr+w+z+t*80)=0x77*256+32;
			   *(scr+l+z+t*80)=0x77*256+32;

			 if(*(scr+o+z+(t+1)*80)!=0x77*256+32 || *(scr+v+z+(t+1)*80)!=0x77*256+32 || *(scr+w+z+(t+1)*80)!=0x77*256+32 || *(scr+l+z+(t+1)*80)!=0x77*256+32)
				{*(scr+o+z+t*80)=co*256+32;
				*(scr+v+z+t*80)=co*256+32;
				 *(scr+w+z+t*80)=co*256+32;
				  *(scr+l+z+t*80)=co*256+32;
				 fs=1;
				 break;
				 }
				  else
				 {
				 *(scr+o+z+(t+1)*80)=co*256+32;
				  *(scr+v+z+(t+1)*80)=co*256+32;
				 *(scr+w+z+(t+1)*80)=co*256+32;
				  *(scr+l+z+(t+1)*80)=co*256+32;
				 }
				   delay(100);
				  t++;
				 if(kbhit())
			{     char c=funky (i);
				if(c=='M' && fs==0 && t<22)
				{

				*(scr+o+z+t*80)=0x77*256+32;
				 *(scr+v+z+t*80)=0x77*256+32;
				 *(scr+w+z+t*80)=0x77*256+32;
				 *(scr+l+z+t*80)=0x77*256+32;
			     if(*(scr+o+z+1+(t)*80)!=0x77*256+32 || *(scr+v+z+1+(t)*80)!=0x77*256+32 || *(scr+w+z+1+(t)*80)!=0x77*256+32 || *(scr+l+z+1+(t)*80)!=0x77*256+32)
			      z=z;
			      else
			       z++;
				}
				if(c=='K' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*+256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				 if(*(scr+o+z-1+(t)*80)!=0x77*256+32 || *(scr+v+z-1+(t)*80)!=0x77*256+32 || *(scr+w+z-1+(t)*80)!=0x77*256+32 || *(scr+l+z-1+(t)*80)!=0x77*256+32)
				z=z;
				 else
				z--;
				}
				if(c=='z' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				 if(tt==3)
				hh=1;

				if(tt==0)
				{o=oh[0];
				v=vh[0];
				w=wh[0];
				l=lh[0];
				}
				if(tt==1){
				o=oh[1];
				v=vh[1];
				w=wh[1];
				l=lh[1];
				}
				if(tt==2){
				o=oh[2];
				v=vh[2];
				w=wh[2];
				l=lh[2];
				}
				if(tt==3){
				o=oh[3];
				v=vh[3];
				w=wh[3];
				l=lh[3];
				}/* IF YOU CHANGE THE SHAPE AND NEXT SHAP EAT ROUND SHAPES DO NOT CHANGE THE SHAPE*/
				if(*(scr+oh[tt+1]+z+t*80)!=0x77*256+32 || *(scr+vh[tt+1]+z+t*80)!=0x77*256+32 || *(scr+wh[tt+1]+z+t*80)!=0x77*256+32 || *(scr+lh[ff+1]+z+t*80)!=0x77*256+32)
				 tt=tt;
				 else
				 tt++;


				}


			}
		}
	       if(t==1)
		init2();
		}


	       if(shape==2)
	       {shape=random(4);
		shap(shape);
		xx=0;
		z=0;
		oh[0]=-120;
	       oh[1]=39+80;
	       oh[2]=-120;
		vh[0]=-40;
	       vh[1]=120;
	       vh[2]=-40;
		wh[0]=40;
	       wh[1]=121;
	       wh[2]=40;
		lh[0]=120;
	       lh[1]=122;
	       lh[2]=120;
	       o=oh[1];
	       v=vh[1];
	       w=wh[1];
	       l=lh[1];

		while(fs==0)
		{   if(t>22)
		break;
		if(oo==1)
			{
			xx=0;
			oo=0;
			}
			  *(scr+o+z+t*80)=0x77*256+32;
			  *(scr+v+z+t*80)=0x77*256+32;
			  *(scr+w+z+t*80)=0x77*256+32;
			   *(scr+l+z+t*80)=0x77*256+32;

			 if(*(scr+o+z+(t+1)*80)!=0x77*256+32 || *(scr+v+z+(t+1)*80)!=0x77*256+32 || *(scr+w+z+(t+1)*80)!=0x77*256+32 || *(scr+l+z+(t+1)*80)!=0x77*256+32)
				{*(scr+o+z+t*80)=co*256+32;
				*(scr+v+z+t*80)=co*256+32;
				 *(scr+w+z+t*80)=co*256+32;
				  *(scr+l+z+t*80)=co*256+32;
				 fs=1;
				 break;
				 }
				  else
				 {
				 *(scr+o+z+(t+1)*80)=co*256+32;
				  *(scr+v+z+(t+1)*80)=co*256+32;
				 *(scr+w+z+(t+1)*80)=co*256+32;
				  *(scr+l+z+(t+1)*80)=co*256+32;
				 }
				   delay(100);
				  t++;
				 if(kbhit())
			{     char c=funky (i);
				if(c=='M' && fs==0 && t<21)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				 *(scr+v+z+t*80)=0x77*256+32;
				 *(scr+w+z+t*80)=0x77*256+32;
				 *(scr+l+z+t*80)=0x77*256+32;
				 if(*(scr+o+z+1+(t)*80)!=0x77*256+32 || *(scr+v+z+1+(t)*80)!=0x77*256+32 || *(scr+w+z+1+(t)*80)!=0x77*256+32 || *(scr+l+z+1+(t)*80)!=0x77*256+32)
			     z=z;
			      else
				z++;
				}
				if(c=='K' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				if(*(scr+o+z-1+(t)*80)!=0x77*256+32 || *(scr+v+z-1+(t)*80)!=0x77*256+32 || *(scr+w+z-1+(t)*80)!=0x77*256+32 || *(scr+l+z-1+(t)*80)!=0x77*256+32)
			     z=z;
			      else
				z--;
				}
				if(c=='z' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				if(xx==1)
				oo=1;

				if(xx==0)
				{o=oh[0];
				v=vh[0];
				w=wh[0];
				l=lh[0];
				}
				if(xx==1){
				o=oh[1];
				v=vh[1];
				w=wh[1];
				l=lh[1];
				}
					if(*(scr+oh[xx+1]+z+t*80)!=0x77*256+32 || *(scr+vh[xx+1]+z+t*80)!=0x77*256+32 || *(scr+wh[xx+1]+z+t*80)!=0x77*256+32 || *(scr+lh[xx+1]+z+t*80)!=0x77*256+32)
					 xx=xx;
				 else
				xx++;

				}
			}

		}
		if(t==1)
	      init2();
	      }
	       if(shape==3)
	       {shape=random(4);
		shap(shape);
		z=0;
		vv=0;
		oh[0]=40;
	       oh[1]=41-80;
	       oh[2]=40;
		vh[0]=41;
	       vh[1]=41;
	       vh[2]=41;
		wh[0]=121;
	       wh[1]=40;
	       wh[2]=121;
		lh[0]=122;
	       lh[1]=40+80;
	       lh[2]=122;
	       o=oh[1];
	       v=vh[1];
	       w=wh[1];
	       l=lh[1];
		while(fs==0)
		{    if(t>22)
		break;
		  if(ww==1)
			{
			vv=0;
			ww=0;
			}
			  *(scr+o+z+t*80)=0x77*256+32;
			  *(scr+v+z+t*80)=0x77*256+32;
			  *(scr+w+z+t*80)=0x77*256+32;
			   *(scr+l+z+t*80)=0x77*256+32;

			 if(*(scr+o+z+(t+1)*80)!=0x77*256+32 || *(scr+v+z+(t+1)*80)!=0x77*256+32 || *(scr+w+z+(t+1)*80)!=0x77*256+32 || *(scr+l+z+(t+1)*80)!=0x77*256+32)
				{*(scr+o+z+t*80)=co*256+32;
				*(scr+v+z+t*80)=co*256+32;
				 *(scr+w+z+t*80)=co*256+32;
				  *(scr+l+z+t*80)=co*256+32;
				 fs=1;
				 break;
				 }
				  else
				 {
				 *(scr+o+z+(t+1)*80)=co*256+32;
				  *(scr+v+z+(t+1)*80)=co*256+32;
				 *(scr+w+z+(t+1)*80)=co*256+32;
				  *(scr+l+z+(t+1)*80)=co*256+32;
				 }
				   delay(100);
				  t++;
				 if(kbhit())
			{     char c=funky (i);
				if(c=='M' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				 *(scr+v+z+t*80)=0x77*256+32;
				 *(scr+w+z+t*80)=0x77*256+32;
				 *(scr+l+z+t*80)=0x77*256+32;
				 if(*(scr+o+z+1+(t)*80)!=0x77*256+32 || *(scr+v+z+1+(t)*80)!=0x77*256+32 || *(scr+w+z+1+(t)*80)!=0x77*256+32 || *(scr+l+z+1+(t)*80)!=0x77*256+32)
			      z=z;
			      else
				z++;
				}
				if(c=='K' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				if(*(scr+o+z+1+(t)*80)!=0x77*256+32 || *(scr+v+z+1+(t)*80)!=0x77*256+32 || *(scr+w+z+1+(t)*80)!=0x77*256+32 || *(scr+l+z+1+(t)*80)!=0x77*256+32)
			      z=z;
			      else
				z--;
				}
				if(c=='z' && fs==0 && t<22)
				{
				*(scr+o+z+t*80)=0x77*256+32;
				*(scr+v+z+t*80)=0x77*256+32;
				*(scr+w+z+t*80)=0x77*256+32;
				*(scr+l+z+t*80)=0x77*256+32;
				if(vv==1)
				ww=1;

				if(vv==0)
				{o=oh[0];
				v=vh[0];
				w=wh[0];
				l=lh[0];
				}
				if(vv==1){
				o=oh[1];
				v=vh[1];
				w=wh[1];
				l=lh[1];
				}
				  if(*(scr+oh[vv+1]+z+t*80)!=0x77*256+32 || *(scr+vh[vv+1]+z+t*80)!=0x77*256+32 || *(scr+wh[vv+1]+z+t*80)!=0x77*256+32 || *(scr+lh[vv+1]+z+t*80)!=0x77*256+32)
					 vv=vv;
					 else
				vv++;

				}


	       }

		}

	     if(t==1)
		init2();
	      }

	 }

	}
docammand(int i,char c) {

if (c=='P')
D=0;
else
D=1;
if(c=='s')
k=1;
}
void main() {
clrscr();
init();

int i,
/* FOR COMING OUT OF THE GAME*/eog=0;
while(eog==0)
{
if(kbhit())
{
char c=funky(i);
docammand(i,c);
move();
for(int t=0;t<25;t++)
{p=0;
for(int x=20;x<60;x++)
{if(*(scr+t*80+x)!=0x77*256+32)
p++;
}
if(p==20)
for(int e=t+1;e>0;e--)
{
for(int f=30;f<50;f++)
{
*(scr+e*80+f)=*(scr+(e-1)*80+f);
}
}
}
if(i==0 && c==27)
eog=1;

}
}
getch();
}