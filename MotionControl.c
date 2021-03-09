################################################################################
################################################################################

                               ## TEAM DETAILS ##
'''
e-Yantra 2015
Task 4 - Firebird Motion Control 
eYRC
Team ID: eYRC#1011
File name: eYRC#1011_algorithm.py
Version: 1.0.0
Author: Meghana B
'''

                            ## PROGRAM DESCRIPTION ##
'''
This is a program that controls the motion of the Firebird robot
'''

################################################################################
################################################################################


int flag = 0, k =0;
while(1)
	{	
		Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
		Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
		Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor

		if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
		{ 	forward();
			
		}

		if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
		{	 forward_mm(82);
			stop();
			_delay_ms(300);
			right_degrees(90); 
			stop();
			_delay_ms(300);
		}

		if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line<0x10))
		{ 
			forward_mm(260);
			stop();
			_delay_ms(300);
			left_degrees(90);
			while(1)
			{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
				Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
				Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
				if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
				{ 	forward();
					
				}
				if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
				{	stop();
					flag = 1;
				}
				if (flag==1)
				break;
			}
			flag = 2;
		}
		if (flag == 2)
		break;
	}
		
			

int x=3, y=2, position1, a, b;
int D1[] = {0,3,1,5,5,0,9,2,7,6,8,4};
int D2[] = {5,15,12,9,20,20};
int positionD1[] = {24,25,26,27,28,29,30,31,32,33,34,35};
int sumpairs[] = {9,6,5,4,5,7,8}

for( int i=0;i<8;i++)
{
	position1 = position1(D1[],positionD1[],sp[i]);
	a = coordx(position1);
	b = coordy(position1);
	if(y==b)
	{ 	if(x==a)
		{	forward_mm(140);
			stop();
			display();
		}
		
		else if(x>a)
		{	
			left_degrees(90);
			stop();
			_delay_ms(500);

			while (x>=0)
			{
				x =x-1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 3;
						_delay_ms(300);
						
					}
					if (flag == 3)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display(); flag = 4; } 
				if (flag == 4)
				break;
			}
		}
	}
					
				
	else if(b>y)	
	{ 	y= y+1;
		while(1)
		{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
			Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
			Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
			if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
			{ 	forward();
				velocity(120,120); 
			}
			if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
			{ stop(); flag = 5; }
			if (flag == 5)
			break;
		}
		
		if(x==a)
		{ forward_mm(30); stop(); _delay_ms(300); display(); } 

		else if(x>a)
		{	
			left_degrees(90);
			stop();
			_delay_ms(500);

			while (x>=0)
			{
				x =x-1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 6;
						_delay_ms(300);
						
					}
					if (flag == 6)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display(); flag = 7; } 
				if (flag == 7)
				break;
			}
		}
			
		
	}



	else if(b<y)	
	{ 	y= y-1;
		while(1)
		{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
			Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
			Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
			if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
			{ 	back();
				velocity(120,120); 
			}
			if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
			{ stop(); flag = 8; }
			if (flag == 8)
			break;
		}
		
		if(x==a)
		{ forward_mm(30); stop(); _delay_ms(300); display(); } 

		else if(x>a)
		{	
			left_degrees(90);
			stop();
			_delay_ms(500);

			while (x>=0)
			{
				x =x-1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display(); flag = 10; } 
				if (flag == 10)
				break;
			}
		}
	}

		

	a = 3; b=2;
	back_mm(30);
	stop();
	_delay_ms(500);
	left_degrees(180);
	stop();
	_delay_ms(500);
	
	if(y==b)
	{
		while(x<=3)
		{	x = x+1;
		
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
			if (x==a)
			{  stop(); _delay_ms(300); flag = 10; } 
			if (flag == 10)
			break;
		}
	}


	else if (y>b)
	{
		y = y-1;
		while(x<=3)
		{	x = x+1;
		
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
			if (x==a)
			{  stop(); _delay_ms(300);  flag = 10; } 
			if (flag == 10)
			break;
		}

		_delay_ms(500);
		right_degrees(90);
		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 11;
						_delay_ms(300);
						
					}
					if (flag == 11)
					break;
				}

		_delay_ms(500);
		left_degrees(90);
	}



	else if (y<b)
	{
		y = y+1;
		while(x<=3)
		{	x = x+1;
		
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
			if (x==a)
			{ forward_mm(30); stop(); _delay_ms(300); flag = 10; } 
			if (flag == 10)
			break;
		}

		_delay_ms(500);
		left_degrees(90);
		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 11;
						_delay_ms(300);
						
					}
					if (flag == 11)
					break;
				}

		_delay_ms(500);
		right_degrees(90);
	}


	x = 4; y= 2;
	while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 12;
						_delay_ms(300);
						
					}
					if (flag == 12)
					break;
				}

	_delay_ms(500);
	left_degrees(90);

	int position2 = position2(D2[],D2even[k]);
	a = coordx(position2);
	b = coordy(position2);
	if(y==b)
	{	if(x==a);
		{ forward_mm(30); stop(); _delay_ms(500); display1(); }
		
		else if(x<a)
		{	
			right_degrees(90);
			stop();
			_delay_ms(500);
			while (x<=9)
			{
				x =x+1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 3;
						_delay_ms(300);
						
					}
					if (flag == 3)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display1(); flag = 4; } 
				if (flag == 4)
				break;
			}
		}
	}

	else if(y<b)
	{
		y = y+1;
		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						 
					}
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 5;
						_delay_ms(300);
						
					}
					if (flag == 5)
					break;	
				
				}
		if(x==a)
		{ forward_mm(30); stop(); display1(); }
		else if(x<a)
		{
			_delay_ms(500);
			right_degrees(90);
			stop();
			while (x<=9)
			{
				x =x+1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 6;
						_delay_ms(300);
						
					}
					if (flag == 6)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display1(); flag = 7; } 
				if (flag == 7)
				break;
			}
		}
	}

	else if(y>b)
	{	y = y-1;
		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	back();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 8;
						_delay_ms(300);
						
					}
					if (flag == 8)
					break;
				}
		if(y==b)
		{	
			if(x==a)
			{ forward_mm(30); stop(); _delay_ms(500); display1(); }

			else if(x<a)
			{	_delay_ms(500);
			right_degrees(90);
			stop();
			while (x<=9)
			{
				x =x+1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display1(); flag = 10; } 
				if (flag == 10)
				break;
			}
		}
		else 
		{	y=y-1;
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	back();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 8;
						_delay_ms(300);
						
					}
					if (flag == 8)
					break;
				}
			if(x==a)
			{ forward_mm(30); stop(); _delay_ms(500); display1(); }
			else if (x<a)
			{	_delay_ms(500);
				right_degrees(90);
				stop();
				while (x<=9)
				{
					x =x+1;
				while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 9;
						_delay_ms(300);
						
					}
					if (flag == 9)
					break;
				}
				if (x==a)
				{ forward_mm(30); stop(); _delay_ms(300); display1(); flag = 10; } 
				if (flag == 10)
				break;
				}
			}
		}
	}
			
	
	a =4; b=2;
	left_degrees(180);
	stop();
	_delay_ms(1000);
	if(y==b)
	{	while(x>=4)
		{	x = x-1;
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 1;
						_delay_ms(300);
						
					}
					if (flag == 1)
					break;
				}
			if(x==a)
			{stop(); _delay_ms(500); flag=2;}
			if(flag==2)
			break;
		}
	}
	
	if(y>b)
	{	while(x>=4)
		{	x = x-1;
		
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 3;
						_delay_ms(300);
						
					}
					if (flag == 3)
					break;
				}
			if (x==a)
			{  stop(); _delay_ms(300); flag = 4; } 
			if (flag == 4)
			break;
		}
		y = y-1;
		_delay_ms(500);
		left_degrees(90);
		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 5;
						_delay_ms(300);
						
					}
					if (flag ==5)
					break;
				}
		

		_delay_ms(500);
		right_degrees(90);
	}

	else if(y<b)
	{
		
		while(x>=4)
		{	x = x-1;
		
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{ 	forward();
						velocity(120,120); 
					}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 3;
						_delay_ms(300);
						
					}
					if (flag == 3)
					break;
				}
			if (x==a)
			{  stop(); _delay_ms(300); flag = 4; } 
			if (flag == 4)
			break;
		}
		_delay_ms(500);
		right_degrees(90);
		stop();
		if(y = b-1)
		{
			while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{forward();
					velocity(120,120);}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 5;
						_delay_ms(300);
						
					}
					
					if(flag==5)
					break;
				}
			left_degrees(90);
		}
		if(y = b-2)
		{		while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{forward();
					velocity(120,120);}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 6;
						_delay_ms(300);
						
					}
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line>0x10))
					{forward();
						velocity(120,120); }
					
					if(flag==6)
					break;
				}
		}
	}
	left_degrees(90);
	stop();
	while(1)
				{ 	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
					Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
					Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
					if((Center_white_line>0x10)&&(Left_white_line<0x10) &&(Right_white_line<0x10))
					{forward();
					velocity(120,120);}
					if((Center_white_line>0x10)&&(Left_white_line>0x10) &&(Right_white_line>0x10))
					{ 	stop();
						flag = 7;
						_delay_ms(300);
						
					}
					if(flag==7)
					break;
				}
	right_degrees(90);
	stop();
	if(i % 2!= 0)
	k = k+1;
	x=3;y=2;
}

		
		
				
