//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
//#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>      // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//string timer[3]={0};
fstream dataFile;
int canvas[650][650]={{0}};
double startx=40,starty=40;
int k=200, l=80, m=100, n=200, ten=10, tatti=0, points1=0, countFood=0, length=1, i=0, j=0, check, timed=0, out=0, tens=0, oldmove=0, flag=3, sum=0, state=3, go=0, sel=1, col=-10, speed=0, level=1, in=0, loss, powertime=0, playerbonus1=0, totalscore1=0, playerbonus2=0, totalscore2=0, points2=0, counter=0;
int usercode[4]={0};
int level1[4]={1, 2, 3, 4};
int level2[4]={4, 2, 4, 1};
void Display(){



    glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors
	if (state==0)
	{
	
	for (i=0; i<650; i++)
	{	
		for (j=0; j<650; j++)
			canvas[i][j]=0;
	}
	
	k=200;
	l=80;
	m=100; 
	n=200; 
	ten=10; 
	points1=0;
	countFood=0;
	length=1;
	i=0;
	j=0;
	timed=0;
	out=0;
	tens=0;
	oldmove=0;
	sum=0;
	speed=0;
	in=0;
	powertime=0;
	playerbonus1=0;
	totalscore1=0; 
	playerbonus2=0; 
	totalscore2=0; 
	points2=0;	
	
	}
	
	else if (state==1)
	{	
		for (j=0; j<650; j++)
			canvas[i][j]=0;	
 dataFile.open("savefile.txt", ios::in);
 				//while (!eof())
 				{

					dataFile>>k;
					dataFile>>l;
					dataFile>>m; 
					dataFile>>n; 
					dataFile>>ten; 
					dataFile>>points1;
					dataFile>>countFood;
					dataFile>>length;
					dataFile>>i;
					dataFile>>j;
					dataFile>>timed;
					dataFile>>out;
					dataFile>>tens;
					dataFile>>oldmove;
					dataFile>>sum;
					dataFile>>speed;
					dataFile>>in;
					dataFile>>powertime;
					dataFile>>playerbonus1;
					dataFile>>totalscore1;
					dataFile>>playerbonus2;
					dataFile>>totalscore2;
					dataFile>>points2;
					dataFile>>flag;					
					dataFile.close();	
					}
	}


	if (flag==0)
	{
	//Resume/continue state
	state=3;

	//Movement theory
	if (tatti==1 and oldmove!=2)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l+=10;
		totalscore1=totalscore1+points1;
		}
		canvas[l][k]=length;
		oldmove=1;
		l-=10;		
	} 
	else if (tatti==1 and oldmove==2)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
		oldmove=2;		
			l+=10;
		} 
			
	if (tatti==2 and oldmove!=1)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
		oldmove=2;		
			l+=10;
		} 	
	else if (tatti==2 and oldmove==1)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l+=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
		oldmove=1;
		l-=10;
	} 	
			
	if (tatti==3 and oldmove!=4)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
			oldmove=3;
			k+=10;
			} 

	else if (tatti==3 and oldmove==4)	
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k+=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
			oldmove=4;
			k-=10;
			}							

	if (tatti==4 and oldmove!=3)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k+=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
			oldmove=4;
			k-=10;
			}

	else if (tatti==4 and oldmove==3)	
	{		
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;

			oldmove=3;
			k+=10;
			}							

	//Check-board theory
	for (i=40;i<600;i+=10)
		for (j=160;j<510;j+=10)
		{
			canvas[i][j]-=1;
			if (canvas[i][j]>=1)
				DrawSquare( i, j, 10, colors[10]);
		}	


	//Eat-food and food generation theory
	if (m==l and n==k)
	{
		do
		{
		m=GetRandInRange(7, 58)*10;
    		n=GetRandInRange(19, 49)*10; 
    		}
	    	while ( (canvas[m][n] > 0) or m==l or n==k or (l/k==m/n));
				
		       
	 	if (countFood%5==0)
	   	{
	   		length+=5;
			points1+=10;
			speed+=110;

		}
		else
		{
	   		length+=1;
   	   		points1+=5;
   		}
   		powertime=0;
   		countFood++;
   		tens=0;
    	}
    	
 	

	//Power food time theory
	if (countFood%5==0)
	{
			powertime++;
    			DrawLine( 120 , 547 ,  178-powertime , 547 , 20 , colors[WHITE] );			
			if (powertime==58)
			{
				countFood++;
		   		powertime=0;
		   	}			    	
    	}
    	
    	
    	//No-bound theory
    	if (l<60)
    	{
       		l=580;
    	}
    	if (l>580)
    	{
    		l=60;
    	}
    	if (k<180)
    	{
       		k=490;
    	}
    	if (k>490)
    	{
    		k=180;
    	}    	

    		cout<<"x="<<l<<" y="<<k;


	
	timed++;

		out=timed;
	in=points1*2;
	
 	if (countFood%5==0)
 		DrawCircle( m+5 , n+5 , 10 , colors[40]);
	else
 		DrawCircle( m+5 , n+5 , 5 , colors[100]);

		
		
	// BOUNDARIES / GAME SPACE / AREA / EXTRA SENTENCES	
	    DrawLine( 50+4 , 170 ,  50+4 , 500 , 10 , colors[DARK_BLUE] );
	    DrawLine( 650-60+4 , 170 ,  650-60+4 , 500 , 10 , colors[DARK_BLUE] );	
	    DrawLine( 50+4 , 170+4 ,  590+4 , 170+4 , 10 , colors[DARK_BLUE] );	    
	    DrawLine( 50+4 , 500+4 ,  590+4 , 500+4 , 10 , colors[DARK_BLUE] );
		
    DrawSquare( l , k ,10,colors[20]); 
    
    
    DrawString( 50, 600, "Score", colors[MISTY_ROSE]);
    DrawString( 50, 570, "Time", colors[MISTY_ROSE]);
    
        DrawString( 290, 90, "LEVEL 1", colors[GOLD]);
    
    DrawString3( 50, 100, points1, colors[GOLD]);
    DrawString4( 50, 80, "PLAYER 1", colors[GOLD]);        

    DrawString3( 600, 100, points2, colors[GOLD]);        

	if (tens==1)	
	{
		    DrawString4( 455, 80, "INSERT COIN TO PLAY", colors[GOLD]);
		if (timed%5==0)
			tens=0;
	}
	else
	{
		    DrawString4( 455, 80, "INSERT COIN TO PLAY", colors[BLACK]);
		if (timed%5==0)
			tens=1;
	}	    
	
    //DrawTriangle( 300, 50 , 500, 50 , 400 , 250, colors[YELLOW] );  // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
    
    //Score and Time Bars with time-end theory
    DrawLine( 120 , 607 ,  550 , 607 , 20 , colors[WHITE] );
    DrawLine( 120 , 607 ,  120+in , 607 , 20 , colors[GREEN] );    
    
    DrawLine( 120 , 577 ,  550 , 577 , 20 , colors[WHITE] );
    
    if (550-out+(points1*4)>=550)    
	    DrawLine( 120 , 577 ,  550 , 577 , 20 , colors[BLUE] );  
    else
	    DrawLine( 120 , 577 ,  550-out+(points1*4) , 577 , 20 , colors[BLUE] );  
    
    
    if ((550-out+(points1*4))<120)
	{
		flag=1;
		loss=2;
		totalscore1=totalscore1+points1;
	}
	
	if (in>430)
	{
		flag=8;
		level=2;
		playerbonus1=550-out+(points1*4);
	}
}


//LEVEL 2

	else if (flag==10)
	{
	//Resume/continue state
	state=3;

	//Movement theory
	if (tatti==1 and oldmove!=2)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l+=10;
		totalscore1=totalscore1+points1;
		}
		canvas[l][k]=length;
		oldmove=1;
		l-=10;		
	} 
	else if (tatti==1 and oldmove==2)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
		oldmove=2;		
			l+=10;
		} 
			
	if (tatti==2 and oldmove!=1)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l-=10;
		totalscore1=totalscore1+points1;
		
		}

		canvas[l][k]=length;
		oldmove=2;		
			l+=10;
		} 	
	else if (tatti==2 and oldmove==1)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		l+=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
		oldmove=1;
		l-=10;
	} 	
			
	if (tatti==3 and oldmove!=4)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k-=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
			oldmove=3;
			k+=10;
			} 

	else if (tatti==3 and oldmove==4)	
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k+=10;
		totalscore1=totalscore1+points1;
		}

		canvas[l][k]=length;
			oldmove=4;
			k-=10;
			}							

	if (tatti==4 and oldmove!=3)
	{
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k+=10;
		totalscore1=totalscore1+points1;		
		}

		canvas[l][k]=length;
			oldmove=4;
			k-=10;
			}

	else if (tatti==4 and oldmove==3)	
	{		
		if (canvas[l][k]>0)
		{
		system("canberra-gtk-play -f lose.wav");		
		flag=1;
		loss=1;
		k-=10;
		totalscore1=totalscore1+points1;		
		}

		canvas[l][k]=length;

			oldmove=3;
			k+=10;
			}							

	//Check-board theory
	for (i=40;i<600;i+=10)
		for (j=160;j<510;j+=10)
		{
			canvas[i][j]-=1;
			if (canvas[i][j]>=1)
				DrawSquare( i, j, 10, colors[10]);
		}	


	//Eat-food and food generation theory
	if (m==l and n==k)
	{
		do
		{
		m=GetRandInRange(7, 58)*10;
    		n=GetRandInRange(19, 49)*10; 
    		}
	    	while ( (canvas[m][n] > 0) or m==l or n==k or (l/k==m/n));
				
		       
	 	if (countFood%5==0)
	   	{
	   		length+=5;
			points1+=15;
			speed+=140;

		}
		else
		{
	   		length+=1;
   	   		points1+=10;
   		}
   		powertime=0;
   		countFood++;
   		tens=0;
    	}
    	
 	

	//Power food time theory
	if (countFood%5==0)
	{
			powertime++;
    			DrawLine( 120 , 547 ,  162-powertime , 547 , 20 , colors[WHITE] );			
			if (powertime==42)
			{
				countFood++;
		   		powertime=0;
		   	}			    	
    	}
    	
    	
    	//No-bound theory
    	if (l<60)
    	{
       		l=580;
    	}
    	if (l>580)
    	{
    		l=60;
    	}
    	if (k<180)
    	{
       		k=490;
    	}
    	if (k>490)
    	{
    		k=180;
    	}    	

    		cout<<"x="<<l<<" y="<<k;


	
	timed++;

	out=timed+(0.25*timed);
	in=points1;
	
 	if (countFood%5==0)
 		DrawCircle( m+5 , n+5 , 10 , colors[40]);
	else
 		DrawCircle( m+5 , n+5 , 5 , colors[100]);

		
		
	// BOUNDARIES / GAME SPACE / AREA / EXTRA SENTENCES / OBSTACLES	
	    DrawLine( 50+4 , 170 ,  50+4 , 500 , 10 , colors[DARK_BLUE] );
	    DrawLine( 650-60+4 , 170 ,  650-60+4 , 500 , 10 , colors[DARK_BLUE] );	
	    DrawLine( 50+4 , 170+4 ,  590+4 , 170+4 , 10 , colors[DARK_BLUE] );	    
	    DrawLine( 50+4 , 500+4 ,  590+4 , 500+4 , 10 , colors[DARK_BLUE] );

	    DrawLine( 200+4 , 170+4 ,  200+4 , 300 , 10 , colors[DARK_BLUE] );	    
	    DrawLine( 650-60-146 , 170 ,  650-60-146 , 500 , 10 , colors[DARK_BLUE] );	

	// OBSTACLE COLLISION	
		for (i=170; i<600; i++)
			canvas[440][i]=10;
		for (i=170; i<300; i++)
			canvas[200][i]=10;			
			

    DrawSquare( l , k ,10,colors[20]); 
    
    
    DrawString( 50, 600, "Score", colors[MISTY_ROSE]);
    DrawString( 50, 570, "Time", colors[MISTY_ROSE]);
    
    DrawString( 290, 90, "LEVEL 2", colors[GOLD]);   
    
    DrawString3( 50, 100, points1, colors[GOLD]);
    DrawString4( 50, 80, "PLAYER 1", colors[GOLD]);        

    DrawString3( 600, 100, points2, colors[GOLD]);        

	if (tens==1)	
	{
		    DrawString4( 455, 80, "INSERT COIN TO PLAY", colors[GOLD]);
		if (timed%5==0)
			tens=0;
	}
	else
	{
		    DrawString4( 455, 80, "INSERT COIN TO PLAY", colors[BLACK]);
		if (timed%5==0)
			tens=1;
	}	    
	
    //DrawTriangle( 300, 50 , 500, 50 , 400 , 250, colors[YELLOW] );  // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
    
    //Score and Time Bars with time-end theory
    DrawLine( 120 , 607 ,  600 , 607 , 20 , colors[WHITE] );
    DrawLine( 120 , 607 ,  120+in , 607 , 20 , colors[GREEN] );    
    
    DrawLine( 120 , 577 ,  600 , 577 , 20 , colors[WHITE] );
    
    if (600-out+(points1*3)>=600)    
	    DrawLine( 120 , 577 ,  600 , 577 , 20 , colors[BLUE] );  
    else
	    DrawLine( 120 , 577 ,  600-out+(points1*3) , 577 , 20 , colors[BLUE] );  
    
    
    if ((600-out+(points1*3))<120)
	{
		flag=1;
		loss=2;
		totalscore1=totalscore1+points1;
	}
	
	if (in>480)
	{
		flag=8;
		level=3;
		playerbonus1=600-out+(points1*4);
	}
}



	else if (flag==1)
	{
	 i=rand()%150;
	 //j=rand()%150;	 
	 DrawString2( 260, 355, "GAME OVER", colors[i]); // this will print given string at x=50 , y=600
         //DrawString2( 310, 325, "OVER", colors[j]); // this will print given string at x=50 , y=570

	if (loss==1)
        	DrawString( 240, 330, "You ate yourself.", colors[BLUE]); // this will print given string at x=50 , y=570	
	else if (loss==2)
        	DrawString( 255, 330, "Time's up!", colors[BLUE]); // this will print given string at x=50 , y=570			
        DrawString2( 200, 280, "Your final score is: ", colors[GOLD]); // this will print given string at x=50 , y=570			
        DrawString3( 380, 280, totalscore1, colors[GOLD]); // this will print given string at x=50 , y=570			

        		
	if (points1==0)
	{
	col++;
		if (col==5)
			points1=1;
	}
	else if (points1==1)
	{
	col--;
		if (col==-5)
			points1=0;
	}
	
         DrawString2( 140, 200, "Press ENTER to save score and return to menu", colors[col]);	
         
                  
         if (go==1)
	 {
 		dataFile.open("scores.txt", ios::out);
 		{
 			dataFile<<totalscore1;
 		}	
		dataFile.close();		 
	 	state=0;
		flag=3;
		go=0;
	 }
	}
	
	
	
	
	
	
	else if (flag==3)
	{
	 i=rand()%10+20;	 
	 DrawString2( 260, 405, "S", colors[col+30]); // this will print given string at x=50 , y=600
         DrawString2( 258, 403, "S", colors[WHITE]);
	 DrawString2( 280, 405, "N", colors[col+30]); 
         DrawString2( 278, 403, "N", colors[WHITE]);
	 DrawString2( 300, 405, "A", colors[col+30]); 
         DrawString2( 298, 403, "A", colors[WHITE]);
	 DrawString2( 320, 405, "K", colors[col+30]); 
         DrawString2( 318, 403, "K", colors[WHITE]);
	 DrawString2( 340, 405, "E", colors[col+30]); 
         DrawString2( 338, 403, "E", colors[WHITE]); 
	 DrawString2( 380, 405, "2", colors[col+30]); 
         DrawString2( 378, 403, "2", colors[WHITE]);                                             	 
	 
	 if (sel==1)
	 	DrawString( 265, 355, "New Game", colors[WHITE]); // this will print given string at x=50 , y=600
	else
	 	DrawString( 265, 355, "New Game", colors[DARK_SLATE_GRAY]);
	 
	 if (sel==2)
         	DrawString( 250, 325, "Resume Game", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
	        DrawString( 250, 325, "Resume Game", colors[DARK_SLATE_GRAY]); 	 
	 
	 if (sel==3)
	 	DrawString( 238, 295, "Enter Level Code", colors[WHITE]); // this will print given string at x=50 , y=600
         else
	 	DrawString( 238, 295, "Enter Level Code", colors[DARK_SLATE_GRAY]);
         
         if (sel==4)
         	DrawString( 240, 265, "See High Scores", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
         	DrawString( 240, 265, "See High Scores", colors[DARK_SLATE_GRAY]);	 		


	if (points1==0)
	{
	col++;
		if (col==5)
			points1=1;
	}
	else if (points1==1)
	{
	col--;
		if (col==-5)
			points1=0;
	}
	
         DrawString2( 230, 200, "Press ESC key to quit", colors[col]);	
         DrawString4( 30, 50, "© FAST 2018", colors[WHITE]);
         DrawString4( 30, 40, "\"Snake 2 by Saad Bazaz\" and all related entities created by ", colors[WHITE]);
         DrawString4( 30, 30, "Saad Ahmed Bazaz with the support of CS faculty of", colors[WHITE]);
         DrawString4( 30, 20, "FAST University, Islamabad.", colors[WHITE]);            	         		
	if (go==1)
	{
		switch (sel)
		{
			case 1:
				flag=0;
				state=0;
				go=0;
				break;
			case 2:
				state=1;
				go=0;
				break;
			case 3:
				flag=5;
				go=0;
				points1=0;
				check=0;
				break;
			case 4:
				flag=6;
				go=0;
				break;
		}
	}
	}
	
	
	
	else if (flag==7)
	{
	
	 DrawString2( 270, 405, "PAUSED", colors[100]);
	
	 if (sel==1)
	 	DrawString( 265, 355, "Resume", colors[WHITE]); // this will print given string at x=50 , y=600
	else
	 	DrawString( 265, 355, "Resume", colors[DARK_SLATE_GRAY]);
	 
	 if (sel==2)
         	DrawString( 282, 325, "Save", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
	        DrawString( 282, 325, "Save", colors[DARK_SLATE_GRAY]); 	 
	 
	 if (sel==3)
	 	DrawString( 215, 295, "Quit to Main Menu", colors[WHITE]); // this will print given string at x=50 , y=600
         else
	 	DrawString( 215, 295, "Quit to Main Menu", colors[DARK_SLATE_GRAY]);
         
         if (sel==4)
         	DrawString( 230, 265, "Quit to Ubuntu", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
         	DrawString( 230, 265, "Quit to Ubuntu", colors[DARK_SLATE_GRAY]);	 		
	
	
	if (go==1)
	{
		switch (sel)
		{
			case 1:
				flag=counter;
				go=0;
				break;
			case 2:

					dataFile.open("savefile.txt", ios::out);
					dataFile<<k;
					dataFile<<"\n";
					dataFile<<l;
					dataFile<<"\n";
					dataFile<<m;
					dataFile<<"\n"; 
					dataFile<<n;
					dataFile<<"\n"; 
					dataFile<<ten;
					dataFile<<"\n"; 
					dataFile<<points1;
					dataFile<<"\n";
					dataFile<<countFood;
					dataFile<<"\n";
					dataFile<<length;
					dataFile<<"\n";
					dataFile<<i;
					dataFile<<"\n";
					dataFile<<j;
					dataFile<<"\n";
					dataFile<<timed;
					dataFile<<"\n";
					dataFile<<out;
					dataFile<<"\n";
					dataFile<<tens;
					dataFile<<"\n";
					dataFile<<oldmove;
					dataFile<<"\n";
					dataFile<<sum;
					dataFile<<"\n";
					dataFile<<speed;
					dataFile<<"\n";
					dataFile<<in;
					dataFile<<"\n";
					dataFile<<powertime;
					dataFile<<"\n";
					dataFile<<playerbonus1;
					dataFile<<"\n";
					dataFile<<totalscore1;
					dataFile<<"\n"; 
					dataFile<<playerbonus2;
					dataFile<<"\n"; 
					dataFile<<totalscore2;
					dataFile<<"\n"; 
					dataFile<<points2;
					dataFile<<"\n";
					dataFile<<counter;
					dataFile<<"\n";						
					dataFile.close();
							
				flag=counter;
				go=0;
				break;
			case 3:
				flag=3;
				go=0;
				break;
			case 4:
				exit(1);
				go=0;
				break;
		}
	}	
	}
	
	
	else if (flag==5)
	{
		 DrawString2( 240, 405, "ENTER THE CODE", colors[100]);
		 
	 if (sel==1)
	 	DrawString( 150, 265, "1", colors[WHITE]); // this will print given string at x=50 , y=600
	else
	 	DrawString( 150, 265, "1", colors[DARK_SLATE_GRAY]);
	 
	 if (sel==2)
         	DrawString( 250, 265, "2", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
	        DrawString( 250, 265, "2", colors[DARK_SLATE_GRAY]); 	 
	 
	 if (sel==3)
	 	DrawString( 350, 265, "3", colors[WHITE]); // this will print given string at x=50 , y=600
         else
	 	DrawString( 350, 265, "3", colors[DARK_SLATE_GRAY]);
         
         if (sel==4)
         	DrawString( 450, 265, "4", colors[WHITE]); // this will print given string at x=50 , y=570	
	 else
         	DrawString( 450, 265, "4", colors[DARK_SLATE_GRAY]);	 		
	
	
	if (go==1)
	{
		switch (sel)
		{
			case 1:
				usercode[points1]=1;
				go=0;
				points1++;
				break;
			case 2:
				usercode[points1]=2;
				go=0;
				points1++;
				break;
			case 3:
				usercode[points1]=3;
				go=0;
				points1++;
				break;
			case 4:
				usercode[points1]=4;
				go=0;
				points1++;
				break;
		}
	}
	if (points1==4)
	{
	for (i=0, check=0; i<4; i++)
	{
		if (usercode[i]==level1[i])
			check++;
	}
	if (check==4)
	{
		state=0;
		flag=0;
		for (i=0; i<4; i++)
			usercode[i]=0;
		check=0;
		go=0;
	}	
	for (i=0, check=0; i<4; i++)
	{
		if (usercode[i]==level2[i])
			check++;
	}
	if (check==4)
	{
		state=0;
		flag=10;
		for (i=0; i<4; i++)
			usercode[i]=0;
	}		
	}		 
		 
	}
	
	else if (flag==6)
	{
		 DrawString2( 260, 450, "SCOREBOARD", colors[100]);
		int first;
 dataFile.open("scores.txt", ios::in);
 		{
 			dataFile>>first;
 		}		
		dataFile.close();		

		 DrawString3( 310, 325, first, colors[WHITE]);
 		DrawCircle( 317 , 300 , 15 , colors[GOLD]);		 
		 DrawString( 310, 295, "1", colors[BLACK]);
		 
		 /*DrawString3( 310, 310, second, colors[BLACK]);
 		DrawCircle( 200 , 200 , 15 , colors[SILVER]);		 
		 DrawString( 193, 195, "2", colors[BLACK]);
		 
		 DrawString3( 310, 310, third, colors[BLACK]);
 		DrawCircle( 450 , 200 , 15 , colors[BROWN]);		 
		 DrawString( 443, 195, "3", colors[BLACK]);*/	
		 
		 if (go==1)
		 {
		 	flag=3;
		 	go=0;
		 }	 		 
	}	
	
	else if (flag==8)
	{
		 DrawString2( 230, 450, "LEVEL     PASSED", colors[100]);
		 DrawString( 220, 400, "Your score:", colors[GOLD]);
		 DrawString3( 360, 400, points1, colors[GOLD]);		 
		 DrawString( 220, 360, "Time bonus:", colors[LIGHT_BLUE]);
		 DrawString3( 360, 360, playerbonus1, colors[LIGHT_BLUE]);		 
		 		 
	if (tens==0)
	{
	col++;
		if (col==5)
			tens=1;
	}
	else if (tens==1)
	{
	col--;
		if (col==-5)
			tens=0;
	}
	
         DrawString2( 175, 280, "Press ENTER to proceed to next level", colors[col]);
         		 
		 if (level==2)
		{
			 DrawString( 290, 450, "1", colors[YELLOW]);
			 DrawString2( 230, 200, "LEVEL CODE:", colors[100]);
			 DrawString( 355, 200, "1234", colors[YELLOW]);			 
		}
		 if (level==3)
		{
			 DrawString( 290, 450, "2", colors[YELLOW]);
			 DrawString2( 230, 200, "LEVEL CODE:", colors[100]);
			 DrawString( 355, 200, "4241", colors[YELLOW]);			 
		}		
		if (go==1)
		{
			if (level == 2)
				flag=10;
			else if (level == 3)
				flag=20;
			go=0;
		}
	}	
		
		
		 		 	






   glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT   /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
    tatti=1;
	        if (flag==5 and sel!=1)
	        	sel--;	    
    										// what to do when left key is pressed...
      
    } else if (key == GLUT_KEY_RIGHT  /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	tatti=2;
		        if (flag==5 and sel!=4)
	        	sel++;
		  } 
	else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/ {
	        tatti=3;
	        
	        if ((flag==3 or flag==7) and sel!=1)
	        	sel--;
    	    }
    else if (key == GLUT_KEY_DOWN)   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/ {
	tatti=4;
	
		        if ((flag==3 or flag==7) and sel!=4)
	        	sel++;
    }
    

    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}


void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC) {
   //call flag 4, which can save the game or quit
   
   if (flag==0)
   {	counter=flag;
        flag=7;
   }
   else if (flag==10)
   {	counter=flag;
   	flag=7;
   }
   else
   	exit(1); // pause the program when escape key is pressed.
    }
    if (key == 'R' || key=='r') {

    state=0;
    }
    
    
    
    else if (int(key) == 13)
    {  
    go=1;
	}
    

    glutPostRedisplay();

}



void Timer(int m) {

// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc((1000.0-speed)/ FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	/*while (state!=0)
	{
	if (state==1)
		continue;
	else 
		break;*/

    int width = 650, height = 650; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("Saad Bazaz's Snake 2"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(1000 / FPS, Timer, 0);
// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    
    return 1;
}
#endif /* Snake Game */

