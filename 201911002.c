#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//çaðrýldýðý yere dönen menü jonksiyonu
int menu(void){
	int a;
	printf("1- Play Card Matching\n2- Play Digit Game\n3- Quit\n");
	scanf("%d",&a);
	return(a);
}
//ilk oyunun rastgele kart çekme fonksiyonu
int value(void){
	int n;
	n=1+rand()%13;
 	return(n);
}
//kartlara isim atayan fonksiyon
char suit(void){
	int n;
	
	n=1+rand()%4;
	switch(n){
		case 1:
		return('C');
		case 2:
		return('D');
		case 3:
		return('H');
		case 4:
		return('S');
	}
}
//gönderilen iki deðerin eþitliðini ölçüyor
int control(char s1,char s2){
	if(s1==s2){
	return(1);
	}
	else{
	return(0);	
	}
}
//1 ile 9 arasýnda input isteyen fonksiyon 2.soru için
int input(void){
	int x;
	scanf("%d",&x);
	if(x<0||x>9){
	 	printf("Error, please enter a number between 0-9.\n");
		scanf("%d",&x);
	}
	return(x);	
}
//2. oyunun 0 ile 9 arasýnda rakam üreten fonksiyon
int random(void){
	
	int n;
	n=rand()%9+1;
	return(n);
}
//2. oyun için eþitlik arayan kontrol
int check(int a,int b){
	if(a==b){
		return(1);
	}
	else{
		return(0);
	}
}
int main(void){
	srand(time(NULL));
	int i,j,v1,v2,s1,s2,x,l,menu1,gues=0,num1=0,num2=0,num3=0,num4=0,k,m,y=0,z=0;
	float sum1,sum2,sum3;
	for(i=0;i<99999;i++){//bu sayede fonk 99999 kere istendiði zaman menüyü çaðýrabilecek
	int count1=0,count2=0,count3=0,count4=0,count5=0;	
	menu1=menu();
		
		if(menu1==1){
			sum2=0;
			for(j=1;j<9999;j++){
			sum1=0;	
			printf("\nRound %d:\n",j);
			v1=value();
			v2=value();
			s1=suit();
			s2=suit();
				printf("%d of %c, %d of %c\n",v1,s1,v2,s2);
			if(control(s1,s2)==1){
				sum1=v1+v2;
				
				printf("%.1f points gained.\n",sum1);
			}
			else if((s1=='S'&&s2=='C')||(s2=='S'&&s1=='C')){
				sum1=(v1+v2)/2.0;
				printf("%.1f points gained.\n",sum1);
			}
			else{
				printf("No points gained.\n");
			}
			sum2+=sum1;
			printf("Current Score: %.1f\n",sum2);
			if(v1-v2==3||v2-v1==3){
				printf("\nGame ended after %d rounds.\n",j);
				printf("Final score is %.1f.\n\n",sum2);
				break;
			}
			}
		}
		else if(menu1==2){
			int count1=0,count2=0,count3=0,count4=0,count5=0;
			int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
			int num5=0,num6=0,num7=0,num8=0,num9=0,num10=0;
			int a1,a2,a3,a4;
			int b1=0,b2=0,b3=0,b4=0;
			int y,z,v,w;
			sum3=20;
			printf("Input 4 digits: ");
			num1=input();
			num2=input();
			num3=input();
			num4=input();
			
			for(k=1;k<99999999;k++){//bu sayede fonk 99999 kere tahmin edecek
				printf("Attempt %d:\n",k);
				gues=random();
				printf("Computer guesses %d.\n",gues);
				if(check(num1,gues)==1&&count2<1){//eþleþen sayýlarý bulmak için 
					printf("Correct.\n");
					sum3+=5;
					a1=gues;
					printf("Current points: %.1f\n",sum3);
					count2++;// 1 kere puanlanmasý için
					count1++;//istenen sayýlara koydum 4 ulaþtýðýnda fordan çýkacak
					y=k;
				}
				else if(check(num2,gues)==1&&count3<1){
					printf("Correct.\n");
					sum3+=5;
					a2=gues;
					printf("Current points: %.1f\n",sum3);
					count3++;
					count1++;
					z=k;
					
				}
				else if(check(num3,gues)==1&&count4<1){
					printf("Correct.\n");
					sum3+=5;
					a3=gues;
					printf("Current points: %.1f\n",sum3);
					count4++;
					count1++;
					v=k;
				}
				else if(check(num4,gues)==1&&count5<1){
					printf("Correct.\n");
					sum3+=5;
					a4=gues;
					printf("Current points: %.1f\n",sum3);
					count5++;
					count1++;
					w=k;
				}
				
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&c1<1){
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num5=gues;
					c1++;// 1 kere puanlanmasý için 
					
				}
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&check(num5,gues)==0&&c2<1){//ondan önceki sayýya eþit olmayacak þekilde kontrol ettim
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num6=gues;
					c2++;}
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&check(num5,gues)==0&&check(num6,gues)==0&&c3<1){
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num7=gues;
					c3++;}
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&check(num5,gues)==0&&check(num6,gues)==0&&check(num7,gues)&&c4<1){
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num8=gues;
					c4++;}	
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&check(num5,gues)==0&&check(num6,gues)==0&&check(num7,gues)&&check(num8,gues)==0&&c5<1){
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num9=gues;
					c5++;}
				else if(check(num1,gues)==0&&check(num2,gues)==0&&check(num3,gues)==0&&check(num4,gues)==0&&check(num5,gues)==0&&check(num6,gues)==0&&check(num7,gues)&&check(num8,gues)==0&&check(num9,gues)==0&&c6<1){
					printf("Incorrect.\n");
					sum3-=4;
					printf("Current points: %.1f\n",sum3);
					num10=gues;
					c6++;}	
					
					printf("Lap score: %.1f\n",sum3);
				
					
				
				if(sum3<0||count1==4){
					break;
				}
				
		}
		if(y<z&&z<v&&v<w){//ilk tahmini bulmak için 24 ihtimal var bunlarýn herbiri için if kullandým.dönüþ sayýsýný kullanarak hangisinin ilk girdiðini buldum.
			printf("First order guess: %d %d %d %d\n",a1,a2,a3,a4);
			if(check(a1,num1)==1&&check(a2,num2)==1&&check(a3,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
		    printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
		}
			else{
				printf("Incorrect\n");
			}
		}
		else if(y<z&&z<w&&w<v){
			printf("First order guess: %d %d %d %d\n",a1,a2,a4,a3);
			if(check(a1,num1)==1&&check(a2,num2)==1&&check(a4,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);}
			
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(y<v&&v<z&&z<w){
			printf("First order guess: %d %d %d %d\n",a1,a3,a2,a4);
			if(check(a1,num1)==1&&check(a3,num2)==1&&check(a2,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(y<v&&v<w&&w<z){
			printf("First order guess: %d %d %d %d\n",a1,a3,a4,a2);
			if(check(a1,num1)==1&&check(a3,num2)==1&&check(a4,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(y<w&&w<v&&v<z){
			printf("First order guess: %d %d %d %d\n",a1,a4,a3,a2);
			if(check(a1,num1)==1&&check(a4,num2)==1&&check(a3,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(y<w&&w<z&&z<v){
			printf("First order guess: %d %d %d %d\n",a1,a4,a2,a3);
			if(check(a1,num1)==1&&check(a4,num2)==1&&check(a2,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(z<y&&y<v&&v<w){
			printf("First order guess: %d %d %d %d\n",a2,a1,a3,a4);
			if(check(a2,num1)==1&&check(a1,num2)==1&&check(a3,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(z<y&&y<w&&w<v){
			printf("First order guess: %d %d %d %d\n",a2,a1,a4,a3);
			if(check(a2,num1)==1&&check(a1,num2)==1&&check(a4,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
		}
			else{
				printf("Incorrect\n");
			}
		
		}
		else if(z<v&&v<y&&y<w){
			printf("First order guess: %d %d %d %d\n",a2,a3,a1,a4);
			if(check(a2,num1)==1&&check(a3,num2)==1&&check(a1,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(z<v&&v<w&&w<y){
			printf("First order guess: %d %d %d %d\n",a2,a3,a4,a1);
			if(check(a2,num1)==1&&check(a3,num2)==1&&check(a4,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(z<w&&w<v&&v<y){
			printf("First order guess: %d %d %d %d\n",a2,a4,a3,a1);
			if(check(a2,num1)==1&&check(a4,num2)==1&&check(a3,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(z<w&&w<y&&y<v){
			printf("First order guess: %d %d %d %d\n",a2,a4,a1,a3);
			if(check(a2,num1)==1&&check(a4,num2)==1&&check(a1,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(v<z&&z<y&&y<w){
			printf("First order guess: %d %d %d %d\n",a3,a2,a1,a4);
			if(check(a3,num1)==1&&check(a2,num2)==1&&check(a1,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(v<z&&z<w&&w<y){
			printf("First order guess: %d %d %d %d\n",a3,a2,a4,a1);
			if(check(a3,num1)==1&&check(a2,num2)==1&&check(a4,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(v<y&&y<z&&z<w){
			printf("First order guess: %d %d %d %d\n",a3,a1,a2,a4);
			if(check(a3,num1)==1&&check(a1,num2)==1&&check(a2,num3)==1&&check(a4,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(v<y&&y<w&&w<z){
			printf("First order guess: %d %d %d %d\n",a3,a1,a4,a2);
			if(check(a3,num1)==1&&check(a1,num2)==1&&check(a4,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
		}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(v<w&&w<z&&z<y){
			printf("First order guess: %d %d %d %d\n",a3,a4,a2,a1);
			if(check(a3,num1)==1&&check(a4,num2)==1&&check(a2,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
		
		}
		else if(v<w&&w<y&&y<z){
			printf("First order guess: %d %d %d %d\n",a3,a4,a1,a2);
			if(check(a3,num1)==1&&check(a4,num2)==1&&check(a1,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(w<z&&z<v&&v<y){
			printf("First order guess: %d %d %d %d\n",a4,a2,a3,a1);
			if(check(a4,num1)==1&&check(a2,num2)==1&&check(a3,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
		}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(w<z&&z<y&&y<v){
			printf("First order guess: %d %d %d %d\n",a4,a2,a1,a3);
			if(check(a4,num1)==1&&check(a2,num2)==1&&check(a1,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(w<y&&y<v&&v<z){
			printf("First order guess: %d %d %d %d\n",a4,a1,a3,a2);
			if(check(a4,num1)==1&&check(a1,num2)==1&&check(a3,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(w<y&&y<z&&z<v){
			printf("First order guess: %d %d %d %d\n",a4,a1,a2,a3);
			if(check(a4,num1)==1&&check(a1,num2)==1&&check(a2,num3)==1&&check(a3,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
		}
			else{
				printf("Incorrect\n");
			}
			
		}
		else if(w<v&&v<z&&z<y){
			printf("First order guess: %d %d %d %d\n",a4,a3,a2,a1);
			if(check(a4,num1)==1&&check(a3,num2)==1&&check(a2,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			break;
		}
		else if(w<v&&v<y&&y<z){
			printf("First order guess: %d %d %d %d\n",a4,a3,a1,a2);
			if(check(a4,num1)==1&&check(a3,num2)==1&&check(a1,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 1 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			}
			else{
				printf("Incorrect\n");
			}
			
		}
		 printf("Second order guess: %d %d %d %d\n",a3,a4,a1,a2);//rakamlarýn yerini kendim deðiþtirdim.
			if(check(a3,num1)==1&&check(a4,num2)==1&&check(a1,num3)==1&&check(a2,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 2 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			menu1=menu();}
			else{
				printf("Incorrect\n");}
		printf("Third order guess: %d %d %d %d\n",a4,a3,a2,a1);
			if(check(a4,num1)==1&&check(a3,num2)==1&&check(a2,num3)==1&&check(a1,num4)==1){
			printf("Correct\n");
			sum3+=10;
			printf("Game ended after %d attempts.\nAfter 3 guesses computer guessed the order correctly.\nFinal score is %.1f.\n",k,sum3);
			menu1=menu();}
			else{
				printf("Incorrect\n");	
				printf("Game ended after %d attempts.\nAfter 3 guesses computer guessed the order incorrectly.\nFinal score is %.1f.\n",k,sum3);	
			}
			
	}
		else if(menu1==3){
			printf("Goodbye!");
			
		}
	
		
	}
return(0);	
}
