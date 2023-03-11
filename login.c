#include"common.h"
#include"main.h"

int login(){
	int state=0,pre_state=0;
	delay(100);
	clrmous(MouseX,MouseY);
	loginbk();

	while(1){
		int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
		//登录框
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(270,300,320,330) == 2)//鼠标在登录框中，且未点击
				{
					pre_state=state;
					state=1;
					if(pre_state!=1)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(270,300,320,330);
					}
				}
				
		else if(mouse_press(270,300,320,330) == 1)//鼠标在登录框中，且点击
		{
			return 0;
		}
		
		//注册框
				else if(mouse_press(340,300,390,330) == 2)//鼠标在注册框中，且未点击
				{
					pre_state=state;
					state=2;
				
					if(pre_state!=2)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(340,300,390,330);
					}
				}
				else if(mouse_press(340,300,390,330) == 1)//鼠标在注册框中，且点击
				{
					delay(100);
					return 3;
				}
				
			//返回框
				else if(mouse_press(5,5,20,17) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=3;
				
					if(pre_state!=3)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						fillpoly(8,v);
					}
				}
				
				else if(mouse_press(5,5,20,17) == 1)//鼠标在返回框中，且点击
				{
					delay(100);
					return 0;
				}
				
//无操作状态
		else
		{
			pre_state=state;
			state=0;
		}	
		
		//鼠标
		if(mouse_press(270,300,320,330)||mouse_press(5,5,20,17)||mouse_press(340,300,390,330)||mouse_press(280,250,500,280)/*||mouse_press(280,300,500,330)||mouse_press(280,350,500,380)*/)
			MouseS=1;
		else
			MouseS=0;
		
		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if(pre_state!=state && pre_state!=0)
		{
			clrmous(MouseX,MouseY);
			delay(5);
			
				switch(pre_state)
				{
					case 1:
						setcolor(WHITE);
						setlinestyle(0,0,1);
						rectangle(608,0,640,32);	
						break;
					case 2:
						setcolor(WHITE);
						setlinestyle(0,0,1);
						rectangle(340,300,390,330);
						break;	
					case 3:
						setcolor(LIGHTBLUE);
						setlinestyle(0,0,1);
						rectangle(5,5,20,17);	
						break;
/*					case 5:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,200,500,230);	
						break;
					case 6:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,300,500,330);	
						break;
					case 7:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,250,500,280);	
						break;
					case 8:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,350,500,380);	
						break;*/
			}
		}
	}	
			
 }
 		
void loginbk(){
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	
/*	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"C:\\borland c\\bgi");*/
	cleardevice();
	setbkcolor(MAGENTA);
	setfillstyle(1,LIGHTBLUE);
	bar(10,10,640-10,480-10);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(10,10,640-10,480-10);

	setfillstyle(1,WHITE);
	//画输入框;
	bar(250-10,150,430,170);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	rectangle(250-10,150,430,170);
	puthz(250-26*3-20,150-3,"用户名",24,26,RED);
	
	setfillstyle(1,WHITE);
	bar(250-10,190+10,430,210+10);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	rectangle(250-10,190+10,430,210+10);
	puthz(250-52-20,190-3+10,"密码",24,26,RED);

	//画登录注册功能键
	setfillstyle(1,WHITE);
	bar(270,300,320,330);
	setcolor(BROWN);
	setlinestyle(0,0,1);
	rectangle(270,300,320,330);
	puthz(270,300+2,"登录",24,26,RED);

	setfillstyle(1,WHITE);
	bar(340,300,390,330);
	setcolor(BROWN);
	setlinestyle(0,0,1);
	rectangle(340,300,390,330);
	puthz(340,300+2,"注册",24,26,RED);

	//画返回键

	setfillstyle(1,LIGHTBLUE);
	setcolor(WHITE);
	fillpoly(8,v);
//	getchar();
//	closegraph();
}
