#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#define difficulty 5
#define charismagoal 25
#define feargoal 25
//charisma needed to win is 100 or more fear needed to win is 100 or more
//difficulty controls how likely strikes are, with lower numbers being harder.
using namespace std;


class playertype{
		int charisma, fear, hp;
		string choice;
		char name[45];
	public:
		setname();
		convoeffect(int selection,int effect);
		stats(int whichstat);
		hpHit(){
			cout<<"\n\nYou got a strike!\n\n";
			hp-=1;
			if(hp<=0){
				charisma-=999;
				fear-=999;
				cout<<"\n\n Oh no! That's your second strike.\nYou are sent to detention.\n\n YOU LOSE";
				exit(0);
				
			}
		}
		victoryCheck();
		
};
playertype::setname(){
	cout<<"Would you like to play as:\nChadly Chaderson:\nCaptain of the football team, chess club enthusiast, \nvolunteer at the animal shelter, face of the anti-bullying campagin.\n\n";
	cout<<"Or as Gene Wilton:\nSon of the principal, and not afraid to bring it up.\n\n";
	cout<<"Enter 1 to play as Chadly Chaderson, or 2 to play as Gene Wilton: \n";
	cin>>choice[0];
	for(int x=1 ; x>0 ; x++){
		if(choice[0] == '1' || choice[0]==2){
			switch(choice[0]){
				case '1':
					charisma=25;
					fear=10;
					hp=2;
					cout<<"You, Chadly Chaderson are marked present in homeroom.";
					break;
					
				case '2':
					charisma=10;
					fear=25;
					hp=2;
					cout<<"You, Gene Wilton are marked present in homeroom.";
					break;
		
			}
			break;
		}else{
			cout<<"I'm sorry, I don't see that person on the attendance sheet. Please enter either 1 for Chad, or 2 for Gene: ";
			cin>>choice[0];
		}
		
	}

	
}
playertype::convoeffect(int selection,int effect){
	switch(selection){
		case 1:
			charisma+=effect;
			cout<<"\n\nYou got "<< effect<<" charisma\ntotal= "<<charisma<<"\n";
			break;
		case 2:
			fear+=effect;
			cout<<"\n\nYou got "<< effect<<" fear\ntotal= "<<fear<<"\n";
			break;
		case 3:
			charisma-=effect;
			cout<<"\n\nYou lost "<< effect<<" charisma\ntotal= "<<charisma<<"\n";
			break;
		case 4:
			fear-=effect;
			cout<<"\n\nYou lost "<< effect<<" fear\ntotal= "<<fear<<"\n";
			break;
		case 5:
			hp+=0;
			cout<<"Nothing feels different\n";
			break;
	}
	
}


playertype::victoryCheck(){
	if(charisma>charismagoal){
		cout<<"All right "<< name<<" You deserve it. You were all anyone talked about at the lockers!";
		cout<<"\n\nVICTORY!!\n\nScore: "<<charisma;
	}else if(fear>feargoal){
		cout<<"All right "<< name<<" You deserve it. You were all anyone talked about at the lockers!";
		cout<<"\n\nVICTORY!!\n\nScore: "<<fear;
	}else if(charisma<charismagoal){
		cout<<"Sorry "<< name<<" You're just not what we're looking for right now.";
		cout<<"\n\nYou lose\n\nScore: "<<charisma;
	}else if(fear<feargoal){
		cout<<"Sorry "<< name<<" You're just not what we're looking for right now.";
		cout<<"\n\nYou lose\n\nScore: "<<fear;
	}
}






//I had to create the player here to make it work
playertype player1;
//This defines all interactions
void Interaction(int chooseInteraction, string resp[10][3][3]){ 
	int dieroll, randeffect, randselection;
		srand(time(NULL));
		dieroll=(1+rand()%3);
		randeffect=(rand()%(41-15)+15); //random between 40 and 15
		for(int i=0;i<3;i++){
			cout<<resp[chooseInteraction-1][dieroll-1][i]; //first person,random interaction,all three lines (adjusted cause 0 is first)
		}
		if(dieroll==1){
			randselection=(1+rand()%2);
			player1.convoeffect(randselection,randeffect);
		}else if(dieroll==2){
			randselection=(rand()%(5-3)+3);
			player1.convoeffect(randselection,randeffect);
		}else{
			player1.convoeffect(5,randeffect);
		}
		
	}


void interactioncheckreset(int anarray[4]){
	for(int a=0; a<5;a++){
		anarray[a]=0;
	}
}
//THE MAIN IS HERE!	
int main(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //this is from w3schools and it provides color
	
	string line,junk;
	string responses[10][3][3];
	int sentence, interactionchoice, victoryORdefeat, strikechance;
	int interactioncheck[4]={0,0,0,0};
	int strike=0;
	ifstream myfile;
	myfile.open("YearbookQuest.txt");
	if(myfile.is_open()){ //This reads the file into arrays to be pulled later.
		getline(myfile,junk);
		for(int who=0;who<11;who++){
			for(int which=0;which<3;which++){
				for( int respLen=0;respLen<3;respLen++){
					getline(myfile,responses[who][which][respLen]);
				}
			}
		}
		myfile.close();
	}else{
		cout<<"Unable to open file.";
	}
	
	
	cout<<"Welcome to Wilton High, \na blue ribbon school of excellence known for its journalism.";
	cout<<" More specifically \nfor its yearbook. Read all over country, the Wilton High yearbook has";
	cout<<"given fame to the students featured therein, especially those with a notable superlative.\n";
	cout<<"\nHere you are. On your last day of your last year at Wilton High.\n";
	cout<<"The yearbook is not done being edited and your last class of the day is with \n\n   THE EDITOR\n\n";
	cout<<"Your objective to get THE EDITOR to put you in as Most Popular, \nsealing your fate as the next Brad Pitt.";
	cout<<"You must converse with your classmates \nin each class to gain enough favor to show THE EDITOR you are worthy...\n";
	cout<<"Or you can stir up enough fear to intimidate THE EDITOR into giving you \nMost Popular.";
	cout<<"\nBut be careful! \nTalking to your fellow students will help you gain either fear or favor,";
	cout<<"\nBut talk too much and the teacher may give you a strike. \nThese strikes carry from class to class,";
	cout<<"and just two of them will send you to.. DETENTION\n";
	cout<<"perhaps there's something good to be gained from mingling\nwith the detention kids...";
	cout<<"If you don't get a strike in detention you can return\nto your classes, having missed only one period,";
	cout<<"but if you get a single strike \nfrom the detention teacher... you are expelled(strict I know).\n";
	cout<<"So. Here you are. In home room. Everything is at stake in...";
	SetConsoleTextAttribute(hConsole, 12);
	cout<<"\n\n\nQuest for Yearbook Fame\n\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	
	player1.setname();
	
	/*Style*/SetConsoleTextAttribute(hConsole, 10);
	cout<<"\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nThe Bell rings and you're off to first period.\n";
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"\nWho would you like to interact with?\n1)Borris: Just dropped her backpack\n2)Dan: Is scratching profanity into the desk\n3)Brad: Is studying for AP Math\n4)Move on to the next class\n\n";
	cout<<"\nPick a number: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin>>interactionchoice;
	interactioncheck[interactionchoice-1]=1;
	while(interactionchoice!=4){
		Interaction(interactionchoice,responses);
		strike++;
		strikechance=(rand()%(difficulty-strike)+strike);
		if(strikechance==strike){
			player1.hpHit();
		}
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"\nWho would you like to interact with?\n1)Borris: Just dropped her backpack\n2)Dan: Is scratching profanity into the desk\n3)Brad: Is studying for AP Math\n4)Move on to the next class\n\n";
		cout<<"\nPick a number: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin>>interactionchoice;
		while(interactioncheck[interactionchoice-1]==1){
			cout<<"\nThey don't want to talk anymore...\nTry someone else or choose 4";
			SetConsoleTextAttribute(hConsole, 10);
			cout<<"\nWho would you like to interact with?\n1)Borris: Just dropped her backpack\n2)Dan: Is scratching profanity into the desk\n3)Brad: Is studying for AP Math\n4)Move on to the next class\n\n";
			cout<<"\nPick a number: ";
			SetConsoleTextAttribute(hConsole, 15);
			cin>>interactionchoice;
		}
		interactioncheck[interactionchoice-1]=1;
		Interaction(interactionchoice,responses);
		
	}
	strike=0;
	interactioncheckreset(interactioncheck);
	
	
	/*Style*/SetConsoleTextAttribute(hConsole, 10);
	cout<<"\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nThe Bell rings and you're off to second period.\n";
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	SetConsoleTextAttribute(hConsole, 10);
	
	cout<<"Who would you like to interact with?\n1)Megan: Just answered three of the teacher's questions\n2)Nicole: Eating her lunch sneakily below the desk\n3)Mike: Blatantly building a model car on his desk\n\n";
	cout<<"Pick a number: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin>>interactionchoice;
	interactioncheck[interactionchoice-1]=1;
	while(interactionchoice!=4){
		Interaction(interactionchoice+3,responses);
		strike++;
		strikechance=(rand()%(difficulty-strike)+strike);
		if(strikechance==strike){
			player1.hpHit();
		}
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"Who would you like to interact with?\n1)Megan: Just answered three of the teacher's questions\n2)Nicole: Eating her lunch sneakily below the desk\n3)Mike: Blatantly building a model car on his desk\n4)Move on to the next class\n\n";
		cout<<"Pick a number: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin>>interactionchoice;
		while(interactioncheck[interactionchoice-1]==1){
			cout<<"\nThey don't want to talk anymore...\nTry someone else or choose 4";
			SetConsoleTextAttribute(hConsole, 10);
			cout<<"Who would you like to interact with?\n1)Megan: Just answered three of the teacher's questions\n2)Nicole: Eating her lunch sneakily below the desk\n3)Mike: Blatantly building a model car on his desk\4)Move on to the next class\n\n";
			cout<<"Pick a number: ";
			SetConsoleTextAttribute(hConsole, 15);
			cin>>interactionchoice;
		}
		interactioncheck[interactionchoice-1]=1;
		Interaction(interactionchoice+3,responses);
	}
	strike=0;
	interactioncheckreset(interactioncheck);
	
	
	/*Style*/SetConsoleTextAttribute(hConsole, 10);
	cout<<"\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nThe Bell rings and you're off to third period. This is your last class before...\nyour class with THE EDITOR\n";
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~~ ~ ~\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	SetConsoleTextAttribute(hConsole, 10);
	
	cout<<"Who would you like to talk to?\n1)Ned: Making spitballs for the war to come\n2)Jeffery: Whispering about sports to his friends\n3)Nancy: Sharpening her pencil...for war, and notes.\n4)Move on to the next class\n\n";
	cout<<"Pick a number: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin>>interactionchoice;
	interactioncheck[interactionchoice-1]=1;
	while(interactionchoice!=4){
		Interaction(interactionchoice+6,responses);
		strike++;
		strikechance=(rand()%(difficulty-strike)+strike);
		if(strikechance==strike){
			player1.hpHit();
		}
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"Who would you like to talk to?\n1)Ned: Making spitballs for the war to come\n2)Jeffery: Whispering about sports to his friends\n3)Nancy: Sharpening her pencil...for war, and notes.\n4)Move on to the next class\n\n";
		cout<<"Pick a number: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin>>interactionchoice;
		while(interactioncheck[interactionchoice-1]==1){
			cout<<"\nThey don't want to talk anymore...\nTry someone else or choose 4";
			SetConsoleTextAttribute(hConsole, 10);
			cout<<"Who would you like to talk to?\n1)Ned: Making spitballs for the war to come\n2)Jeffery: Whispering about sports to his friends\n3)Nancy: Sharpening her pencil...for war, and notes.\n4)Move on to the next class\n\n";
			cout<<"Pick a number: ";
			SetConsoleTextAttribute(hConsole, 15);
			cin>>interactionchoice;
		}
		interactioncheck[interactionchoice-1]=1;
		Interaction(interactionchoice+6,responses);
	}
	strike=0;
	interactioncheckreset(interactioncheck);
	
	
	SetConsoleTextAttribute(hConsole, 12);
	/*Style*/cout<<"\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"This is it! Final period. There they are, in their usual spot up front...\nTHE EDITOR";
	SetConsoleTextAttribute(hConsole, 12);
	cout<<"\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~~ ~ ~ ~ ~ ~ ~ ~\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"Do you approach? Or do you give up under the pressure?";
	cout<<"Enter 1 to approach and 2 to give up: ";
	cin>>victoryORdefeat;
	if(victoryORdefeat==1){
		player1.victoryCheck();
	}else if(victoryORdefeat==2){
		int easteregg;
		easteregg=(1+rand()%10);
		if(easteregg==1){
			cout<<"Good call! It's a trap. Nothing is real. Escape this matrix!\n\nVICTORY BY RED PILL!";
		}else{
		cout<<"Priobably wise. I knew you'd collapse under the pressure.\n\nYOU LOSE";
		}
	}
	
	
	
	
	
	
	
	

}