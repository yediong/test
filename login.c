#include"common.h"
#include"main.h"

int login(){
	int state=0,pre_state=0;
	delay(100);
	clrmous(MouseX,MouseY);
	loginbk();

	while(1){
		int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
		//��¼��
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(270,300,320,330) == 2)//����ڵ�¼���У���δ���
				{
					pre_state=state;
					state=1;
					if(pre_state!=1)//��ֹ�ظ�����
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(270,300,320,330);
					}
				}
				
		else if(mouse_press(270,300,320,330) == 1)//����ڵ�¼���У��ҵ��
		{
			return 0;
		}
		
		//ע���
				else if(mouse_press(340,300,390,330) == 2)//�����ע����У���δ���
				{
					pre_state=state;
					state=2;
				
					if(pre_state!=2)//��ֹ�ظ�����
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(340,300,390,330);
					}
				}
				else if(mouse_press(340,300,390,330) == 1)//�����ע����У��ҵ��
				{
					delay(100);
					return 3;
				}
				
			//���ؿ�
				else if(mouse_press(5,5,20,17) == 2)//����ڷ��ؿ��У���δ���
				{
					pre_state=state;
					state=3;
				
					if(pre_state!=3)//��ֹ�ظ�����
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						fillpoly(8,v);
					}
				}
				
				else if(mouse_press(5,5,20,17) == 1)//����ڷ��ؿ��У��ҵ��
				{
					delay(100);
					return 0;
				}
				
//�޲���״̬
		else
		{
			pre_state=state;
			state=0;
		}	
		
		//���
		if(mouse_press(270,300,320,330)||mouse_press(5,5,20,17)||mouse_press(340,300,390,330)||mouse_press(280,250,500,280)/*||mouse_press(280,300,500,330)||mouse_press(280,350,500,380)*/)
			MouseS=1;
		else
			MouseS=0;
		
		//���״̬�����ı䣬��֮ǰ�����޲���״̬����������������
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
	//�������;
	bar(250-10,150,430,170);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	rectangle(250-10,150,430,170);
	puthz(250-26*3-20,150-3,"�û���",24,26,RED);
	
	setfillstyle(1,WHITE);
	bar(250-10,190+10,430,210+10);
	setcolor(BLACK);
	setlinestyle(0,0,1);
	rectangle(250-10,190+10,430,210+10);
	puthz(250-52-20,190-3+10,"����",24,26,RED);

	//����¼ע�Ṧ�ܼ�
	setfillstyle(1,WHITE);
	bar(270,300,320,330);
	setcolor(BROWN);
	setlinestyle(0,0,1);
	rectangle(270,300,320,330);
	puthz(270,300+2,"��¼",24,26,RED);

	setfillstyle(1,WHITE);
	bar(340,300,390,330);
	setcolor(BROWN);
	setlinestyle(0,0,1);
	rectangle(340,300,390,330);
	puthz(340,300+2,"ע��",24,26,RED);

	//�����ؼ�

	setfillstyle(1,LIGHTBLUE);
	setcolor(WHITE);
	fillpoly(8,v);
//	getchar();
//	closegraph();
}
